//------------------------------------------------------------------------------
//   MSP430G2553 C Template
//   Ensure jumpers are set to use Hardware UART not Software UART (turn horizontally)
//   Remove all jumpers along the bottom of the board
//------------------------------------------------------------------------------
#include "msp430g2553.h"

//------------------------------------------------------------------------------
//  Function Prototypes
//------------------------------------------------------------------------------
void init_device(void);
void dly_ms(unsigned int dly_time);

//------------------------------------------------------------------------------
//  Main Function
//------------------------------------------------------------------------------
int main(void){
    init_device();
        while(1){
            dly_ms(1500);
        P2OUT ^= BIT3|BIT5;
        P2OUT ^= BIT4;
        }

    return 0;
}

//------------------------------------------------------------------------------
//  Functions
//------------------------------------------------------------------------------
void init_device(void){
  WDTCTL = WDTPW + WDTHOLD; //Setup watch dog timer
  P1DIR = 0x24; //00100100b rotB|rotA|spk|ldr|pot|tx|rx|ir
  P2DIR = 0xF8; //11111000b led1_g|led1_b|led1_r|led2|led3|sw3|sw2|sw1
  P1SEL = 0x00; //Disable pin special functions
  P2SEL = 0x00; //Disable pin special functions
  P1REN = 0xC0; //Internal pullups for RotA and RotB
  BCSCTL1 = CALBC1_8MHZ; //Use 8MHz Clock
  DCOCTL = CALDCO_8MHZ;  //Use 8MHz Clock
}

void dly_ms (unsigned int dly_time) {
    int i;
    for (i=0; i<dly_time; i++){
        __delay_cycles(1500);
    }
}
