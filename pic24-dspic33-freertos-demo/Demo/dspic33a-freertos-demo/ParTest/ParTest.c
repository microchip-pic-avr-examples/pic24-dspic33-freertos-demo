/*
 * FreeRTOS V202212.01
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * https://www.FreeRTOS.org
 * https://github.com/FreeRTOS
 *
 */

/* Scheduler includes. */
#include "FreeRTOS.h"

/* Demo app includes. */
#include "partest.h"

#define ptOUTPUT 	0
#define ptALL_OFF	0
#define RED_LED_OFFSET 4


unsigned portBASE_TYPE uxOutput;

/*-----------------------------------------------------------
 * Clock Initialization.
 *-----------------------------------------------------------*/

void vClockInitialise()
{
       /*  
        System Clock Source                             :  PLL1 Out output
        System/Generator 1 frequency (Fosc)             :  50 MHz
        
        Clock Generator 2 frequency                     : 8 MHz
        Clock Generator 3 frequency                     : 8 MHz
        Clock Generator 8 frequency                     : 8 MHz
        
        PLL 1 frequency                                 : 200 MHz
        PLL 1 VCO Out frequency                         : 1000 MHz

    */
    // TUN 0x0; 
    FRCTUN = 0x0UL;
    // TUN 0x0; 
    BFRCTUN = 0x0UL;
    
    OSCCTRLbits.FRCEN = 1U;
    while(OSCCTRLbits.FRCRDY == 0U){}; 
    OSCCTRLbits.BFRCEN = 1U;
    while(OSCCTRLbits.BFRCRDY == 0U){};
    
    // NOSC FRC Oscillator; OE enabled; SIDL disabled; ON enabled; BOSC Serial Test Mode clock (PGC); FSCMEN disabled; DIVSWEN disabled; OSWEN disabled; EXTCFSEL disabled; EXTCFEN disabled; FOUTSWEN disabled; RIS disabled; PLLSWEN disabled; 
    PLL1CON = 0x9100UL;
    // POSTDIV2 1x divide; POSTDIV1 5x divide; PLLFBDIV 125; PLLPRE 1; 
    PLL1DIV = 0x1007D29UL;
    //Enable PLL Input and Feedback Divider update
    PLL1CONbits.PLLSWEN = 1U;
    while (PLL1CONbits.PLLSWEN == 1){};
    PLL1CONbits.FOUTSWEN = 1U;
    while (PLL1CONbits.FOUTSWEN == 1U){};
    //enable clock switching
    PLL1CONbits.OSWEN = 1U; 
    //wait for switching
    while(PLL1CONbits.OSWEN == 1U){}; 
    //wait for clock to be ready
    while(OSCCTRLbits.PLL1RDY == 0U){};    
    
    //Configure VCO Divider
    // INTDIV 0; 
    VCO1DIV = 0x0UL;
    //enable PLL VCO divider
    PLL1CONbits.DIVSWEN = 1U; 
    //wait for setup complete
    while(PLL1CONbits.DIVSWEN == 1U){}; 
    
    // NOSC PLL1 Out output; OE enabled; SIDL disabled; ON enabled; BOSC FRC Oscillator; FSCMEN disabled; DIVSWEN disabled; OSWEN disabled; EXTCFSEL External clock fail detection module #1; EXTCFEN disabled; RIS disabled; 
    CLK1CON = 0x19500UL;
    // FRACDIV 0; INTDIV 2; 
    CLK1DIV = 0x20000UL;
    //enable divide factors
    CLK1CONbits.DIVSWEN = 1U; 
    //wait for divide factors to get updated
    while(CLK1CONbits.DIVSWEN == 1U){};
    //enable clock switching
    CLK1CONbits.OSWEN = 1U; 
    //wait for clock switching complete
    while(CLK1CONbits.OSWEN == 1U){};
    
    // NOSC FRC Oscillator; OE enabled; SIDL disabled; ON enabled; BOSC FRC Oscillator; FSCMEN disabled; DIVSWEN disabled; OSWEN disabled; EXTCFSEL External clock fail detection module #1; EXTCFEN disabled; RIS disabled; 
    CLK2CON = 0x19101UL;
    //enable clock switching
    CLK2CONbits.OSWEN = 1U; 
    //wait for clock switching complete
    while(CLK2CONbits.OSWEN == 1U){};
    
    // NOSC Backup FRC Oscillator; OE enabled; SIDL disabled; ON enabled; BOSC Backup FRC Oscillator; FSCMEN disabled; DIVSWEN disabled; OSWEN disabled; EXTCFSEL External clock fail detection module #1; EXTCFEN disabled; RIS disabled; 
    CLK3CON = 0x29202UL;
    //enable clock switching
    CLK3CONbits.OSWEN = 1U; 
    //wait for clock switching complete
    while(CLK3CONbits.OSWEN == 1U){};
    
    // NOSC FRC Oscillator; OE enabled; SIDL disabled; ON enabled; BOSC Serial Test Mode clock (PGC); FSCMEN disabled; DIVSWEN disabled; OSWEN disabled; EXTCFSEL External clock fail detection module #1; EXTCFEN disabled; RIS disabled; 
    CLK8CON = 0x9100UL;
    // FRACDIV 0x0; INTDIV 0x0; 
    CLK8DIV = 0x0UL;
    //enable clock switching
    CLK8CONbits.OSWEN = 1U; 
    //wait for clock switching complete
    while(CLK8CONbits.OSWEN == 1U){};
     
}

/*-----------------------------------------------------------
 * Simple parallel port IO routines.
 *-----------------------------------------------------------*/

void vParTestInitialise( void )
{
    TRISA = ptOUTPUT;
    TRISC = ptOUTPUT;
    TRISDbits.TRISD0 = ptALL_OFF;
    TRISDbits.TRISD2 = ptALL_OFF;
	PORTC = ptALL_OFF;
    TRISA = ptALL_OFF;
	uxOutput = ptALL_OFF;
}
/*-----------------------------------------------------------*/

void vParTestSetLED( unsigned portBASE_TYPE uxLED, signed portBASE_TYPE xValue )
{
    unsigned portBASE_TYPE uxLEDBit;

	/* Which port A bit is being modified? */
	uxLEDBit = LED_START << uxLED;

	if( xValue )
	{
		/* Turn the LED on. */
		portENTER_CRITICAL();
		{
			uxOutput |= uxLEDBit;
			PORTC = (PORTC & RED_LED_OFFSET) | uxOutput;
		}
		portEXIT_CRITICAL();
	}
	else
	{
		/* Turn the LED off. */
		portENTER_CRITICAL();
		{
			uxOutput &= ~uxLEDBit;
			PORTC = (PORTC & RED_LED_OFFSET) | uxOutput;
		}
		portEXIT_CRITICAL();
	}
}
/*-----------------------------------------------------------*/

void vParTestToggleLED( unsigned portBASE_TYPE uxLED )
{
    unsigned portBASE_TYPE uxLEDBit;

	uxLEDBit = LED_START << uxLED;
	portENTER_CRITICAL();
	{
		/* If the LED is already on - turn it off.  If the LED is already
		off, turn it on. */
		if( uxOutput & uxLEDBit )
		{
			uxOutput &= ~uxLEDBit;
			PORTC = (PORTC & RED_LED_OFFSET) | uxOutput;;
		}
		else
		{
			uxOutput |= uxLEDBit;
			PORTC = (PORTC & RED_LED_OFFSET) | uxOutput;
		}
	}
	portEXIT_CRITICAL();
}

