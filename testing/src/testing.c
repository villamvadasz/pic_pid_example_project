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

/******************* Header / include files ( #include ) *********************/

#include "main.h"
#include <stdio.h>
#include "controller.h"
#include "hyst.h"
#include "pid.h"
#include "scaler.h"

/***************** Constant / macro definitions ( #define ) ******************/

/*********************** Type definitions ( typedef ) ************************/

/************************* Global data definitions ***************************/

Scaler	input_scaler = {-255,255,0,1023,0};
Hyst	hyst_switch = {0 , -10, 10, 0, 1 , 0};

/****************** Global constant definitions ( const ) ********************/

/******************* Modul global data segment ( static ) ********************/

/***************** Modul global constants ( static const ) *******************/

/****************** Local func/proc prototypes ( static ) ********************/
	
static void test1(void);
static void test2(void);
static void test3(void);
static void test4(void);

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
	test1();
	test2();
	test3();
	test4();
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
void test1(void) {
/************************** Local data declaration ***************************/

/************************* Static data declaration ***************************/

/****************************** Function Code ********************************/
	printf("Test 1\n");
	hyst_switch.input = -11;
	printf("Hyst inpuit : %f Hyst Output : %f\n", hyst_switch.input, doHyst(&hyst_switch));
	hyst_switch.input = -10;
	printf("Hyst inpuit : %f Hyst Output : %f\n", hyst_switch.input, doHyst(&hyst_switch));
	hyst_switch.input = -1;
	printf("Hyst inpuit : %f Hyst Output : %f\n", hyst_switch.input, doHyst(&hyst_switch));
	hyst_switch.input = 0;
	printf("Hyst inpuit : %f Hyst Output : %f\n", hyst_switch.input, doHyst(&hyst_switch));
	hyst_switch.input = 1;
	printf("Hyst inpuit : %f Hyst Output : %f\n", hyst_switch.input, doHyst(&hyst_switch));
	hyst_switch.input = 10;
	printf("Hyst inpuit : %f Hyst Output : %f\n", hyst_switch.input, doHyst(&hyst_switch));
	hyst_switch.input = 11;
	printf("Hyst inpuit : %f Hyst Output : %f\n", hyst_switch.input, doHyst(&hyst_switch));
	hyst_switch.input = 10;
	printf("Hyst inpuit : %f Hyst Output : %f\n", hyst_switch.input, doHyst(&hyst_switch));
	hyst_switch.input = 1;
	printf("Hyst inpuit : %f Hyst Output : %f\n", hyst_switch.input, doHyst(&hyst_switch));
	hyst_switch.input = 0;
	printf("Hyst inpuit : %f Hyst Output : %f\n", hyst_switch.input, doHyst(&hyst_switch));
	hyst_switch.input = -1;
	printf("Hyst inpuit : %f Hyst Output : %f\n", hyst_switch.input, doHyst(&hyst_switch));
	hyst_switch.input = -10;
	printf("Hyst inpuit : %f Hyst Output : %f\n", hyst_switch.input, doHyst(&hyst_switch));
	hyst_switch.input = -11;
	printf("Hyst inpuit : %f Hyst Output : %f\n", hyst_switch.input, doHyst(&hyst_switch));
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
void test2(void) {
/************************** Local data declaration ***************************/

/************************* Static data declaration ***************************/

/****************************** Function Code ********************************/
	printf("Test 2\n");
	input_scaler.input = -256;
	printf("Scaler input : %f Scaler Output : %f\n",input_scaler.input , doScaling(&input_scaler));
	input_scaler.input = -255;
	printf("Scaler input : %f Scaler Output : %f\n",input_scaler.input , doScaling(&input_scaler));
	input_scaler.input = -1;
	printf("Scaler input : %f Scaler Output : %f\n",input_scaler.input , doScaling(&input_scaler));
	input_scaler.input = 0;
	printf("Scaler input : %f Scaler Output : %f\n",input_scaler.input , doScaling(&input_scaler));
	input_scaler.input = 1;
	printf("Scaler input : %f Scaler Output : %f\n",input_scaler.input , doScaling(&input_scaler));
	input_scaler.input = 255;
	printf("Scaler input : %f Scaler Output : %f\n",input_scaler.input , doScaling(&input_scaler));
	input_scaler.input = 256;
	printf("Scaler input : %f Scaler Output : %f\n",input_scaler.input , doScaling(&input_scaler));
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
void test3(void) {
/************************** Local data declaration ***************************/

/************************* Static data declaration ***************************/

/****************************** Function Code ********************************/
	int i = 0;
	printf("Test 3\n");
	printf("PID example usage\n");
	setTimeSlice(1000);
	setParameters(1, 1, 1, 1, 1);

	for (i = 0; i < 15; i++) {
		printf("PID output is: %f\n", doPID(1));
	}

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
void test4(void) {
/************************** Local data declaration ***************************/

/************************* Static data declaration ***************************/

/****************************** Function Code ********************************/
	int i = 0;
	double alap = 1;	/* should be updated with real signal, 
					maybe from a potentiometer or
					from the user interface
					DESIRED OUTPUT */
	double ellenorzo = 0;	/* should be updated with real signal, 
					maybe from the AD converter
					with the signal from the
					controlled object
					ACTUAL REFERENCE or
					FEEDBACK */
	double heat;		/* output of the PID should be forwarded
					to the controlled object */
	double cold;		/* optional output for heat/cold application */
	printf("Test 4\n");
	setParameters(1, 1, 1, 1, 1); /* PID parameter settings */
	setTimeSlice(1000);		/* Time sclice where doControling is called
						1000 = 1000ms = 1s */
	for (i = 0; i < 15; i++) {
		doControling(alap,ellenorzo,&heat,&cold);	/* Calculating PID output */
		printf("PID output is: %f\n", heat);
	}
}
/** EndOfFunction ************************************************************/

/** EndOfFile main.c *********************************************************/
