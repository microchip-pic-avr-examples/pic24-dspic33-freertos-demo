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
#ifndef HOST_H
#define HOST_H

// Section: Included Files

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include "hostTypes.h"

/**
 * @ingroup  main_coredriver
 * @brief    This routine initializes the MSI driver.
 *           This routine must be called before any other MSI routine is called.
 *           This routine should only be called once during system initialization.
 * @param    none
 * @return   none  
 */
void vHostInitialize(void);


/**
 * @ingroup  main_coredriver
 * @brief    This routine generates interrupt to HOST.
 * @param    none
 * @return   none  
 */
void vHostInterruptRequestGenerate(void);

/**
 * @ingroup  main_coredriver
 * @brief    This routine returns the status of interrupt request acknowledge from the  HOST.
 * @param    none
 * @return   True  - when HOST has acknowledged Main MSI interrupt request.
 * @return   False - when HOST has not acknowledged Main MSI interrupt request.  
 */       
bool HostIsInterruptRequestAcknowledged(void);    

/**
 * @ingroup  main_coredriver
 * @brief    This routine clears interrupt to HOST.
 * @param    none
 * @return   none  
 */        
void vHostInterruptRequestComplete(void);    

/**
 * @ingroup  main_coredriver
 * @brief    This routine returns the status of interrupt request from the HOST(main core).
 * @param    none
 * @return   True  - when HOST has issued interrupt to Secondary Core.
 * @return   False - when HOST has not issued interrupt to Secondary Core.  
 */     
bool HostIsInterruptRequested(void);    

/**
 * @ingroup  main_coredriver
 * @brief    This routine acknowledges interrupt received from Main MSI.
 * @param    none
 * @return   none  
 */    
void vHostInterruptRequestAcknowledge(void);    

/**
 * @ingroup  main_coredriver
 * @brief    This routine clears acknowledge for interrupt received from Main MSI.
 * @param    none
 * @return   none  
 */       
void vHostInterruptRequestAcknowledgeComplete(void);

/**
 * @ingroup  main_coredriver
 * @brief    This routine returns Main system status.
 * @param    none
 * @return   HOST_SYSTEM_STATUS: Enum which provides the status of HOST.  
 */      
enum HOST_SYSTEM_STATUS HostSystemStatusGet(void);    

/**
 * @ingroup    main_coredriver
 * @brief      This routine reads FIFO data sent from the Main Core.
 * @param[in]  *pData      - Pointer to an array to store the read data
 * @param[in]  wordCount   - Number of words to be read.  
 * @return     Number of words read.  
 */
uint16_t HostFIFORead(uint16_t *pData, uint16_t wordCount);    

/**
 * @ingroup    main_coredriver
 * @brief      This routine transfers FIFO data to Main Core.
 * @pre        HostInitialize() should be called before calling this routine.
 * @param[in]  *pData      - Pointer to an array which has data for transmission.
 * @param[in]  wordCount   - Number of words to be transfer.  
 * @return     Number of words transferred.  
 */
uint16_t HostFIFOWrite(uint16_t *pData, uint16_t wordCount);

/** 
 * @ingroup  main_coredriver
 * @brief    This inline function checks whether the status of Read FIFO is full. 
 *           last write by Secondary core to Read FIFO (RFDATA) was into the last free location
 * @return   true   -    Read FIFO is full
 * @return   false  -    Read FIFO is not full
 */ 
inline static bool HostFIFOReadIsFull(void)
{
    return(SI1FIFOCSbits.SRFFULL);
}

/** 
 * @ingroup  main_coredriver
 * @brief    This inline function checks whether the status of Read FIFO is Empty. 
 *           Returns true if last read by Main core from Read FIFO (RFDATA) emptied the 
 *           FIFO of all valid data or FIFO is disabled (and initialized to the empty state)
 * @return   true   -    Read FIFO is Empty
 * @return   false  -    Read FIFO is not Empty (Read FIFO contains valid data not yet read by the Main core)
 */
inline static bool HostFIFOReadIsEmpty(void)
{
    return(SI1FIFOCSbits.SRFEMPTY);
}

/** 
 * @ingroup  main_coredriver
 * @brief    This inline function checks whether the status of Write FIFO is Full. 
 *           Returns true if last write by Main core to Write FIFO (WFDATA) was into 
 *           the last free location
 * @return   true   -    Write FIFO is full
 * @return   false  -    Write FIFO is not full
 */ 
inline static bool HostFIFOWriteIsFull(void)
{
    return(SI1FIFOCSbits.SWFFULL);
}

/** 
 * @ingroup  main_coredriver
 * @brief    This inline function checks whether the status of Write FIFO is Empty. 
 *           Returns true if last write by Main to Write FIFO (WFDATA) was into 
 *           the last free location
 * @return   true   -    Write FIFO is Empty
 * @return   false  -    Write FIFO is not Empty (Write FIFO contains valid data not yet read by the Secondary core)
 */ 
inline static bool HostFIFOWriteIsEmpty(void)
{
    return(SI1FIFOCSbits.SWFEMPTY);
}

/**
 * @ingroup    main_coredriver
 * @brief      This routine writes data to mailbox.
 * @param[in]  protocolName - Selected protocol 
 * @param[in]  *pData      - Pointer to a structure which has data for transmission.  
 * @return     true   -    successful write
 * @return     false  -    unsuccessful write  
 */      
bool HostProtocolWrite(enum HOST_PROTOCOLS protocolName, uint16_t *pData);

/** 
 * @ingroup    main_coredriver
 * @brief      This routine reads data from mailbox.
 * @param[in]  protocolName - Selected protocol 
 * @param[in]  *pData       - Pointer to a structure to store the read data  
 * @return     true   -    successful read
 * @return     false  -    unsuccessful read  
 */   
bool HostProtocolRead(enum HOST_PROTOCOLS protocolName, uint16_t *pData);

/** 
 * @ingroup    main_coredriver
 * @brief      This inline function checks whether mailbox is full. 
 *             Returns true if New data are ready to read. Returns false when 
 *             No data are available to be read by Main core.
 * @param[in]  protocolName - Selected protocol 
 * @return     true   -    Protocol is full
 * @return     false  -    Protocol is empty 
 */ 
inline static bool HostProtocolIsFull(enum HOST_PROTOCOLS protocolName)
{
    bool status = false;
    switch(protocolName)
    {
        case MSI1_ProtocolA:
            status =  SI1MBXSbits.DTRDYA;
            break;
        case MSI1_ProtocolB:
            status =  SI1MBXSbits.DTRDYB;
            break;
        default:
            break;   
    }  
    return status;   
}

/** 
 * @ingroup    main_coredriver
 * @brief      This inline function checks whether mailbox is empty. 
 *             Returns true if Protocol is empty indicating mailbox is ready to 
 *             write by Main core. returns false indicating write operation cannot 
 *             be performed by Main core.
 * @param[in]  protocolName - Selected protocol 
 * @return     true   -    Protocol is empty
 * @return     false  -    Protocol is full
 */ 
inline static bool HostProtocolIsEmpty(enum HOST_PROTOCOLS protocolName)
{
    bool status = false;
    switch(protocolName)
    {
        case MSI1_ProtocolA:
            status =  !SI1MBXSbits.DTRDYA;
            break;
        case MSI1_ProtocolB:
            status =  !SI1MBXSbits.DTRDYB;
            break;
        default:
            break;   
    }  
    return status; 
}



#endif //HOST_H



