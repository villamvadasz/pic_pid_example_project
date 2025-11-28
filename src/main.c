/*****************************************************************************/
/**                                                                         **/
/**                               m a i n . c                               **/
/**                                                                         **/
/*****************************************************************************/
/**                                                                         **/
/**                  Copyrights(c) 2008 by Andras Huszti,                   **/
/**                              Budapest                                   **/
/**                                                                         **/
/** Project   :    PID library                                              **/
/** Date      :    22.08.2008                                               **/
/** Author    :    A. Huszti                                                **/
/**                                                                         **/
/*****************************************************************************/
/** Content: Short description / summary                                    **/
/**                                                                         **/
/*****************************************************************************/
/** Date       Author        Rev  Changes:                                  **/
/** 22.08.2008 A. Huszti     1.0  Start:                                    **/
/**                                                                         **/
/*****************************************************************************/

/*********************** Compiler options ( #pragma ) ************************/

	#pragma config PLLDIV   = 5         // (20 MHz crystal on PICDEM FS USB board)
	#pragma config CPUDIV   = OSC1_PLL2	
	#pragma config USBDIV   = 2         // Clock source from 96MHz PLL/2
	#pragma config FOSC     = HSPLL_HS
	#pragma config FCMEN    = OFF
	#pragma config IESO     = OFF
	#pragma config PWRT     = ON
	#pragma config BOR      = ON
	#pragma config BORV     = 3
	#pragma config VREGEN   = OFF		//USB Voltage Regulator
	#pragma config WDT      = OFF
	#pragma config WDTPS    = 32768
	#pragma config MCLRE    = ON
	#pragma config LPT1OSC  = OFF
	#pragma config PBADEN   = OFF
//	#pragma config CCP2MX   = ON
	#pragma config STVREN   = ON
	#pragma config LVP      = OFF
//	#pragma config ICPRT    = OFF       // Dedicated In-Circuit Debug/Programming
	#pragma config XINST    = OFF       // Extended Instruction Set
	#pragma config CP0      = OFF
	#pragma config CP1      = OFF
//	#pragma config CP2      = OFF
//	#pragma config CP3      = OFF
	#pragma config CPB      = OFF
//	#pragma config CPD      = OFF
	#pragma config WRT0     = OFF
	#pragma config WRT1     = OFF
//	#pragma config WRT2     = OFF
//	#pragma config WRT3     = OFF
	#pragma config WRTB     = OFF       // Boot Block Write Protection
	#pragma config WRTC     = OFF
//	#pragma config WRTD     = OFF
	#pragma config EBTR0    = OFF
	#pragma config EBTR1    = OFF
//	#pragma config EBTR2    = OFF
//	#pragma config EBTR3    = OFF
	#pragma config EBTRB    = OFF

/******************* Header / include files ( #include ) *********************/

#include <p18f4550.h>
#include "global.h"
#include "main.h"
#include <stdio.h>
#include "controller.h"
#include "hyst.h"
#include "pid.h"
#include "scaler.h"

/***************** Constant / macro definitions ( #define ) ******************/

/*********************** Type definitions ( typedef ) ************************/

/************************* Global data definitions ***************************/
double alap = 0;
double ellenorzo = 0;
double heat = 0;
double cold = 0;

/****************** Global constant definitions ( const ) ********************/

/******************* Modul global data segment ( static ) ********************/

/***************** Modul global constants ( static const ) *******************/

/****************** Local func/proc prototypes ( static ) ********************/
void InterruptHandlerHigh (void);
	
/** EndOfHeader **************************************************************/

/*****************************************************************************/
/**                                                                         **/
/** Function  :                                                             **/
/** Param In  :                                                             **/
/** Param Out :                                                             **/
/** Return    :                                                             **/
/** Data In   :                                                             **/
/** Data Out  :                                                             **/
/** Remarks   :                                                             **/
/*****************************************************************************/
void main (void) {

/************************** Local data declaration ***************************/

/************************* Static data declaration ***************************/

/****************************** Function Code ********************************/

	//init PWM and TMR2
	CCP1CON = 0b00001100;
	CCP2CON = 0b00001100;

	CCPR1L = 0x00;
	CCP1CONbits.DC1B0 = 0;
	CCP1CONbits.DC1B1 = 0;

	CCPR2L = 0x00;
	CCP2CONbits.DC2B0 = 0;
	CCP2CONbits.DC2B1 = 0;

	PR2 = 0xFF;
	TRISCbits.TRISC1 = OUT;
	TRISCbits.TRISC2 = OUT;

	T2CON = 0b00000000;
	T2CONbits.TMR2ON = 1;
	PIR1bits.TMR2IF = 0;
	PIE1bits.TMR2IE = 0;
	IPR1bits.TMR2IP = 0;

	//init AD using AD0,AD1
	TRISAbits.TRISA0 = IN;
	TRISAbits.TRISA1 = IN;

	ADCON0 = 0b00000001;
	ADCON1 = 0b00001101;
	ADCON2 = 0b10010110;
	ADCON0bits.GO = 1;

	IPR1bits.ADIP = 0;
	PIR1bits.ADIF = 0;
	PIE1bits.ADIE = 1;

	//TMR0	100ms 4 * (256 * 148) * 32 / 48000000 = 174 //6C 00
	T0CON = 0b10000100;
	TMR0H = 0x6C;
	TMR0L = 0x00;
	INTCONbits.TMR0IF = 0;
	INTCONbits.TMR0IE = 1;

	//init Interrupt
	INTCONbits.PEIE = 1;
	INTCONbits.GIE = 1;

	//PID init
	setParameters(1, 0, 0, 5, 1); /* PID parameter settings */
	setTimeSlice(100);		/* Time sclice where doControling is called
						1000 = 1000ms = 1s */
	while (1);
}
/** EndOfFunction ************************************************************/


/*****************************************************************************/
/**                                                                         **/
/** Function  :                                                             **/
/** Param In  :                                                             **/
/** Param Out :                                                             **/
/** Return    :                                                             **/
/** Data In   :                                                             **/
/** Data Out  :                                                             **/
/** Remarks   :                                                             **/
/*****************************************************************************/
#pragma code InterruptVectorHigh = 0x08
void InterruptVectorHigh (void) {
  _asm
    goto InterruptHandlerHigh //jump to interrupt routine
  _endasm
}
/** EndOfFunction ************************************************************/

/*****************************************************************************/
/**                                                                         **/
/** Function  :                                                             **/
/** Param In  :                                                             **/
/** Param Out :                                                             **/
/** Return    :                                                             **/
/** Data In   :                                                             **/
/** Data Out  :                                                             **/
/** Remarks   :                                                             **/
/*****************************************************************************/
#pragma code
#pragma interrupt InterruptHandlerHigh
void InterruptHandlerHigh () {

/************************** Local data declaration ***************************/

	double adresult_temp = 0;

/************************* Static data declaration ***************************/

/****************************** Function Code ********************************/

	if ((PIR1bits.ADIF) && (PIE1bits.ADIE)) {
		adresult_temp = ADRESL + (ADRESH << 8);
		if ((ADCON0 & 0b00111100) == 0b00000000) {	//AN0
			ADCON0 = (ADCON0 & 0b11000011) | 0b00000100;
			alap = adresult_temp;
		} else if ((ADCON0 & 0b00111100) == 0b00000100) {	//AN1
			ADCON0 = (ADCON0 & 0b11000011) | 0b00000000;
			ellenorzo = adresult_temp;
		} else {	// ???
			ADCON0 = (ADCON0 & 0b11000011) | 0b00000000;
		}
		ADCON0bits.GO = 1;
	}

	if ((INTCONbits.TMR0IF) && (INTCONbits.TMR0IE)) {	//100ms
		INTCONbits.TMR0IF = 0;
		TMR0H = 0x6C;
		TMR0L = 0x00;
		doControling(alap,ellenorzo,&heat,&cold);
		CCPR1L = (((unsigned int) heat) >> 2) & 0xFF;
		CCP1CONbits.DC1B0 = (((unsigned int) heat) >> 8) & 0x01;
		CCP1CONbits.DC1B1 = (((unsigned int) heat) >> 9) & 0x01;

		CCPR2L = (((unsigned int) cold) >> 2) & 0xFF;
		CCP2CONbits.DC2B0 = (((unsigned int) cold) >> 8) & 0x01;
		CCP2CONbits.DC2B1 = (((unsigned int) cold) >> 9) & 0x01;		
	}
}
/** EndOfFunction ************************************************************/

/** EndOfFile main.c *********************************************************/
