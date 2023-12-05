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
#include <stddef.h>
#include "hostTypes.h"
#include "host.h"


void vHostInitialize(void)
{
    //MRSTIE disabled; MTSIACK disabled; STMIRQ disabled; RFITSEL Trigger data valid interrupt when 1st FIFO entry is written by Slave; 
    SI1CON = 0x0U;    
}

void vHostInterruptRequestGenerate(void)
{
    SI1CONbits.STMIRQ = 1U;
}

bool HOSTIsInterruptRequestAcknowledged(void)
{
    return(SI1STATbits.STMIACK);
    
}

void vHostInterruptRequestComplete(void)
{
    SI1CONbits.STMIRQ = 0U; 
}
 
bool HostIsInterruptRequested(void)
{
    return(SI1STATbits.MTSIRQ);
}
void vHostInterruptRequestAcknowledge(void)
{
    SI1CONbits.MTSIACK = 1U;
}

void vHostInterruptRequestAcknowledgeComplete(void)
{
    SI1CONbits.MTSIACK = 0U;
}
 
enum HOST_SYSTEM_STATUS HostSystemStatusGet(void)
{
    enum HOST_SYSTEM_STATUS systemStatus = HOST_SYSTEM_STATUS_RUNNING_STATE;
    
    if(SI1STATbits.MSTRST)
    {
        systemStatus = HOST_SYSTEM_STATUS_IN_RESET_STATE;
    }
    else
    {
        switch(SI1STATbits.MSTPWR)
        {
            case 0: systemStatus = HOST_SYSTEM_STATUS_NOT_IN_LOW_POWER_MODE;
                    break;
            case 1: systemStatus = HOST_SYSTEM_STATUS_IDLE_MODE;
                    break;
            case 2: systemStatus = HOST_SYSTEM_STATUS_SLEEP_MODE;
                    break;
            default:systemStatus = HOST_SYSTEM_STATUS_RUNNING_STATE;
                    break;             
        }
    }
    return systemStatus;
}

uint16_t HostFIFORead(uint16_t *pData, uint16_t wordCount)
{
    uint16_t readCountStatus = 0U;
    
    while(wordCount)
    {
        if(!HostFIFOReadIsEmpty())
        {
            *pData++ = SRMWFDATA;
            wordCount--;
            readCountStatus++;
        }
        else
        {
            break;
        }
    }
    return readCountStatus;  
}

uint16_t HOST_FIFOWrite(uint16_t *pData, uint16_t wordCount)
{
    uint16_t writeCountStatus = 0U;
    
    while(wordCount)
    {
        if(!HostFIFOWriteIsFull())
        {
            SWMRFDATA = *pData++;
            wordCount--;
            writeCountStatus++;
        }
        else
        {
            break;
        }
    }
    return writeCountStatus;
}
 
bool HostProtocolWrite(enum HOST_PROTOCOLS protocolName, uint16_t *pData)
{
    bool status = false;
    switch(protocolName)
    {
        case MSI1_ProtocolB:
            if(HostProtocolIsEmpty(MSI1_ProtocolB))
            {
                SI1MBX1D = pData[0];
                status = true;
            }    
            else
            {
                status = false;
            }
            break;
        default:
            break; 
    }
    return status;    
}

bool HostProtocolRead(enum HOST_PROTOCOLS protocolName, uint16_t *pData)
{
    bool status = false;   
    switch(protocolName)
    {
        case MSI1_ProtocolA:
            if(HostProtocolIsFull(MSI1_ProtocolA))
            {
                pData[0] = SI1MBX0D;

                status = true;
            }
            else
            {
                status = false;
            }
            break;
        default:
            break; 
	}
    return status;
}










