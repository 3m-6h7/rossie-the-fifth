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
        if (!(P1IN & BIT0)) {
            P1OUT |= BIT1;
        } else {
            P1OUT &= ~BIT1;
        }
        P1OUT &= ~(BIT2|BIT3|BIT4);
    }
    return 0;
}

//------------------------------------------------------------------------------
//  Functions
//------------------------------------------------------------------------------
void init_device(void) {
    WDTCTL = WDTPW + WDTHOLD; // Setup watchdog timer
    P1DIR = 0x24; // Set P1.2 and P1.5 as output (rotB|rotA|spk|ldr|pot|tx|rx|ir)
    P2DIR = 0xF8; // Set P2.3 to P2.7 as output (led1_g|led1_b|led1_r|led2|led3|sw3|sw2|sw1)
    P1SEL = 0x00; // Disable pin special functions
    P2SEL = 0x00; // Disable pin special functions
    P1REN = 0xC0; // Enable internal pull-ups for RotA and RotB
    P1OUT |= BIT0;
    BCSCTL1 = CALBC1_8MHZ; // Use 8MHz Clock
    DCOCTL = CALDCO_8MHZ;  // Use 8MHz Clock
}
