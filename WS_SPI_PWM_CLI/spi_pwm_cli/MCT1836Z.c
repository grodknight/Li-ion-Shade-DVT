/***************************************************************************//**
 * @file
 * @brief handler for the TI MCT8316ZR motor controller 
 *******************************************************************************
 * # License
 * <b>Copyright Crestron
 *******************************************************************************
 * The licensor of this software is Crestron Inc. Your use of this
 * software is governed by 
 *
 ******************************************************************************/
// #include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include "spidrv.h"  
#include "spidrv_usart_master_baremetal.h"
#include "sl_spidrv_instances.h"

// #include "sl_sleeptimer.h"
#include "MCT18316Z_REGS.h"

 bool mct8316z_init(SPIDRV_Callback_t callback);
 bool mct8316z_write_reg(uint8_t reg, uint8_t value);
 bool mct8316z_read_reg(uint8_t reg, uint8_t *value);
 void MCT8316_ReadAllRegs(void);
 void mct8316z_UnlockRegs(void);
 void mct8316z_disableSleep(void);
 void setClockwise(bool clockwise);
 bool isClockwise(void);
 bool motorOn(void);
 bool motorOff(void);


//==++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#define SPI_HANDLE                  sl_spidrv_usart_exp_handle

extern bool transfer_complete;  // volatile
// static char rx_buffer[APP_BUFFER_SIZE];

static uint16_t build_write_frame(uint8_t reg, uint8_t data); 
static uint16_t build_read_frame(uint8_t reg);
static bool parityCheck_write(uint8_t addr, uint8_t data);
static bool parityCheck_read(uint8_t addr);

volatile unsigned char dataMSB, dataLSB;
volatile uint16_t frame = 0;

const uint8_t MCTregMasks[] = {
  STATUS_REGISTER_MASK,
  STATUS_REGISTER_MASK,
  STATUS_REGISTER_MASK,
  CONTROL_REGISTER_1_MASK,
  CONTROL_REGISTER_2_MASK, 
  CONTROL_REGISTER_2_MASK, 
  CONTROL_REGISTER_3_MASK, 
  CONTROL_REGISTER_4_MASK, 
  CONTROL_REGISTER_5_MASK, 
  CONTROL_REGISTER_6_MASK, 
  CONTROL_REGISTER_7_MASK, 
  CONTROL_REGISTER_8_MASK, 
  CONTROL_REGISTER_9_MASK, 
  CONTROL_REGISTER_10_MASK,
};

struct {
	bool  regAccess:1; // print on reg read or write
	bool  b:1; //  add debug flags per line
	bool  c:1; // 
	bool  d:1; // 
	bool  e:1; // 
	bool  f:1; // 
	bool  g:1; // 
	bool  h:1; // 
} mct_debug_flags;


typedef struct
{
  SPIDRV_HandleData_t *spi_handle;

  GPIO_PORT_TypeDef cs_port;
  uint8_t cs_pin;

} mct8316z_t;

bool waitTransferComplete(void)
{
  //  to do: put timeout return false
  while(!transfer_complete);
  
  return true;

}

bool motorOn(void)
{
    IC_Control_Register4 reg4;

    if (!mct8316z_read_reg(MCT_REG_CTRL4,&reg4.data))
      return false;
    
  reg4.fields.DRV_OFF |= MCT_DRV_ENABLE_MASK;

  return mct8316z_write_reg(MCT_REG_CTRL4,reg4.data);
}

bool motorOff(void)
{
    IC_Control_Register4 reg4;

    if (!mct8316z_read_reg(MCT_REG_CTRL4,&reg4.data))
      return false;
    
  reg4.fields.DRV_OFF &= ~MCT_DRV_ENABLE_MASK;

  return mct8316z_write_reg(MCT_REG_CTRL4,reg4.data);
}

void setClockwise(bool clockwise)
{
    IC_Control_Register7 reg7;

    if (!mct8316z_read_reg(MCT_REG_CTRL7,&reg7.data))
      return ;

  if(clockwise)
  {
    printf("Set clockwise\r\n");
    reg7.fields.DIR = CONTROL_REGISTER_7_DIR_CW;
  }
  else {
    printf("Set Counter-clockwise\r\n");
    reg7.fields.DIR = CONTROL_REGISTER_7_DIR_CCW;
  }

  mct8316z_write_reg( MCT_REG_CTRL7,  reg7.data);
}
  
 bool isClockwise(void)
{
  IC_Control_Register7 reg7;

  mct8316z_read_reg ( MCT_REG_CTRL7,  &reg7.data);  
  if(reg7.fields.DIR & 1) {
    printf("Direction Read = %s\r\n","Counter Clockwise");
    return false;
  }
  else {
   printf("Direction Read = %s\r\n","Clockwise" );
   return true;
  }
 
}

void test(void)
{
  MCT8316_ReadAllRegs(); // before tests

#if 0   // Clockwise tests  
  isClockwise();
  setClockwise(MCT_CLOCKWISE);
  isClockwise();
  setClockwise(MCT_COUNTER_CLOCKWISE);
  isClockwise();

  setClockwise(MCT_CLOCKWISE);
  isClockwise(); 
#endif  // Clockwise tests  

  MCT8316_ReadAllRegs(); // after tests

}

static SPIDRV_Callback_t transfer_callback;

bool mct8316z_init(SPIDRV_Callback_t callback)
{
  transfer_callback = callback;

   mct8316z_disableSleep();
   mct8316z_UnlockRegs();
   MCT8316_ReadAllRegs();

   return true;
}

void mct8316z_disableSleep(void)
{
  printf("nSLEEP SET HI\r\n");
  sl_gpio_set_pin(PB6);     // disable sleep
}

static uint8_t valBefore;
static uint8_t valAfter;

 void mct8316z_UnlockRegs(void)
{ 
	mct8316z_read_reg( MCT_REG_CTRL1,&valBefore); 

	mct8316z_write_reg(MCT_REG_CTRL1, 3); 
	mct8316z_read_reg( MCT_REG_CTRL1, &valAfter); 

	printf("\r\nUnlock Regs: MCT_REG_CTRL1\tBefore= %x\tAfter= %x\r\n\n",
		valBefore, valAfter);
}

void MCT8316_ReadAllRegs(void)
{
  uint8_t reg, result;

  for(reg=0; reg < MCT8316_NUM_REGS; 
    mct8316z_read_reg(reg++,&result));

}


bool mct8316z_write_reg(uint8_t reg, uint8_t value) {
   uint16_t frame;
   Ecode_t result;    // Ecode_t
  uint16_t rx;

	if (reg >= MCT8316_NUM_REGS)
	{
		printf("mct8316z_write_reg: Bad Reg number\n\r"); 
		return false;
	}


  frame = build_write_frame(reg, value);
  result =  SPIDRV_MTransfer(SPI_HANDLE, &frame, &rx, 1, transfer_callback);

  waitTransferComplete();


  if(true || mct_debug_flags.regAccess)
    printf("MCT8316 Set Reg %02d = %02xh    Mask= %02xh  Frame=%xh  status= %08lxh\r\n", 
                        reg,       value, MCTregMasks[reg], frame, result );

  return (result == ECODE_EMDRV_SPIDRV_OK);
}

bool mct8316z_read_reg(uint8_t reg, uint8_t *value) 
{
  uint16_t frame;
  uint16_t rx;
  Ecode_t result;    // Ecode_t

   if (reg >= MCT8316_NUM_REGS)
   {
		printf("mct8316z_read_reg: Bad Reg number\n\r"); 
  		return false;
   }

   
    frame = build_read_frame( reg);

    result =  SPIDRV_MTransfer(SPI_HANDLE, &frame, &rx, 1, transfer_callback);

    waitTransferComplete();


  *value = rx & 0xFF;

  if(true || mct_debug_flags.regAccess)
    printf("MCT8316 Get Reg %02d = %02xh    Mask= %02xh  Frame=%xh  status= %08lxh\r\n",
 		                    reg,     *value, MCTregMasks[reg], frame,   result);
 
  return true;
}

static uint16_t build_write_frame(uint8_t reg,
                                  uint8_t data)
{
   volatile unsigned char addr, dat;

   frame = 0;
   dat = data;
   addr = reg;

   addr = ((addr << 1) & 0x7E);        //line up A5-A0 in MSB
   dat = (dat & 0xFF);                 //line up D7-D0 in LSB

   bool parity = parityCheck_write(addr,dat);

   dataLSB = data;                      //LSB = D7-D0
   dataMSB = (addr | parity);           //MSB = W0=0, A5-A0, P

   frame  =  ((uint16_t) dataMSB << 8) | dataLSB;
 //  frame |= MCTregMasks[reg];         // set masked bits

  return frame;
}

static uint16_t build_read_frame(uint8_t reg)
{
    reg = ((reg << 1) & 0x7E);           //line up A5-A0 in MSB

    bool parity = parityCheck_read(reg);

    dataLSB = 0xFF;                     //LSB = dummy data (D7-D0)
    dataMSB = (0x80 | reg | parity);    //MSB = W0=1, A5-A0, P

    frame  =  ((uint16_t) dataMSB << 8) | dataLSB;

    return frame;

}

static bool parityCheck_write(uint8_t addr, uint8_t data)
{
    volatile unsigned char parity = 0, parity_check = 0, i = 0;
    volatile unsigned int parity_word = (addr << 8) | data;
    for (i=0;i<14;i++)
    {
        parity_check = (parity_word >> i) & 1;
        if (parity_check == 1)
        {
            parity ^= 1;
        }
    }
    return parity;
}

static bool parityCheck_read(uint8_t addr)
{
    volatile unsigned char parity = 0, parity_check = 0, i = 0;
    volatile unsigned int parity_word = (addr << 8);
    for (i=0;i<14;i++)
    {
        parity_check = (parity_word >> i) & 1;
        if (parity_check == 1)
        {
            parity ^= 1;
        }
    }
    return parity;
}


