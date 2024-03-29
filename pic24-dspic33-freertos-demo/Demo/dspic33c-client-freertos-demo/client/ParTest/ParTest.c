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

unsigned portBASE_TYPE uxOutput;

/*-----------------------------------------------------------
 * Simple parallel port IO routines.
 *-----------------------------------------------------------*/

void vParTestInitialise( void )
{
	TRISE = ptOUTPUT;
	PORTE = ptALL_OFF;
	uxOutput = ptALL_OFF;
}
/*-----------------------------------------------------------*/

void vParTestSetLED( unsigned portBASE_TYPE uxLED, signed portBASE_TYPE xValue )
{
unsigned portBASE_TYPE uxLEDBit;

	/* Which port A bit is being modified? */
	uxLEDBit = 1 << uxLED;

	if( xValue )
	{
		/* Turn the LED on. */
		portENTER_CRITICAL();
		{
			uxOutput |= uxLEDBit;
			PORTE = uxOutput;
		}
		portEXIT_CRITICAL();
	}
	else
	{
		/* Turn the LED off. */
		portENTER_CRITICAL();
		{
			uxOutput &= ~uxLEDBit;
			PORTE = uxOutput;
		}
		portEXIT_CRITICAL();
	}
}
/*-----------------------------------------------------------*/

void vParTestToggleLED( unsigned portBASE_TYPE uxLED )
{
unsigned portBASE_TYPE uxLEDBit;

	uxLEDBit = 1 << uxLED;
	portENTER_CRITICAL();
	{
		/* If the LED is already on - turn it off.  If the LED is already
		off, turn it on. */
		if( uxOutput & uxLEDBit )
		{
			uxOutput &= ~uxLEDBit;
			PORTE = uxOutput;
		}
		else
		{
			uxOutput |= uxLEDBit;
			PORTE = uxOutput;
		}
	}
	portEXIT_CRITICAL();
}

