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

//------------------------------------------------------------------------------
//  Main Function
//------------------------------------------------------------------------------
int main(void) {
    init_device(); // Initialize the device

    while(1) {
        // Check SW1 (P1.0) for Green
        if (!(P1IN & BIT0)) { // If SW1 is pressed
            P2OUT &= ~BIT0; // Turn off Green LED
        } else {
            P2OUT |= BIT0; // Turn on Green LED
        }

        // Check SW2 (P1.1) for Blue
        if (!(P1IN & BIT1)) { // If SW2 is pressed
            P2OUT &= ~BIT1; // Turn off Blue LED
        } else {
            P2OUT |= BIT1; // Turn on Blue LED
        }

        // Check SW3 (P1.2) for Red
        if (!(P1IN & BIT2)) { // If SW3 is pressed
            P2OUT &= ~BIT2; // Turn off Red LED
        } else {
            P2OUT |= BIT2; // Turn on Red LED
        }
    }
    return 0; // This line will never be reached
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

