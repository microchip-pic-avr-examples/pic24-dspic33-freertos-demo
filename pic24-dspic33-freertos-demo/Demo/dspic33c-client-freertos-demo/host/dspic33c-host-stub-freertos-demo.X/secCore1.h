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
#ifndef SEC_CORE1_H
#define SEC_CORE1_H

// Section: Included Files

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include "secCoreTypes.h"

// Section: Data Type Definitions


/**
 * @ingroup  sec_coredriver
 * @brief    Structure object of type SEC_CORE_INTERFACE with the custom name given by 
 *           the user in the Melody Driver User interface. The default name 
 *           e.g. Secondary1 can be changed by the user in the SEC_CORE user interface. 
 *           This allows defining a structure with application specific name using 
 *           the 'Custom Name' field. Application specific name allows the API Portability.
*/
extern const struct SEC_CORE_INTERFACE MSIInterface;

/**
 * @ingroup  sec_coredriver
 * @brief    This macro defines the Custom Name for \ref SEC_CORE1_Initialize API
 */
#define MSIInterface_Initialize SEC_CORE1_Initialize

/**
 * @ingroup  sec_coredriver
 * @brief    This macro defines the Custom Name for \ref SEC_CORE1_Deinitialize API
 */
#define MSIInterface_Deinitialize SEC_CORE1_Deinitialize

/**
 * @ingroup  sec_coredriver
 * @brief    This macro defines the Custom Name for \ref SEC_CORE1_Program API
 */
#define MSIInterface_Program SEC_CORE1_Program

/**
 * @ingroup  sec_coredriver
 * @brief    This macro defines the Custom Name for \ref SEC_CORE1_Strat API
 */
#define MSIInterface_Strat SEC_CORE1_Strat

/**
 * @ingroup  sec_coredriver
 * @brief    This macro defines the Custom Name for \ref SEC_CORE1_InterruptRequestGenerate API
 */
#define MSIInterface_InterruptRequestGenerate SEC_CORE1_InterruptRequestGenerate

/**
 * @ingroup  sec_coredriver
 * @brief    This macro defines the Custom Name for \ref SEC_CORE1_IsInterruptRequestAcknowledged API
 */
#define MSIInterface_IsInterruptRequestAcknowledged SEC_CORE1_IsInterruptRequestAcknowledged

/**
 * @ingroup  sec_coredriver
 * @brief    This macro defines the Custom Name for \ref SecCore1InterruptRequestComplete API
 */
#define MSIInterface_InterruptRequestComplete SecCore1InterruptRequestComplete

/**
 * @ingroup  sec_coredriver
 * @brief    This macro defines the Custom Name for \ref SecCore1IsInterruptRequested API
 */
#define MSIInterface_IsInterruptRequested SecCore1IsInterruptRequested

/**
 * @ingroup  sec_coredriver
 * @brief    This macro defines the Custom Name for \ref SecCore1InterruptRequestAcknowledge API
 */
#define MSIInterface_InterruptRequestAcknowledge SecCore1InterruptRequestAcknowledge

/**
 * @ingroup  sec_coredriver
 * @brief    This macro defines the Custom Name for \ref SecCore1InterruptRequestAcknowledgeComplete API
 */
#define MSIInterface_InterruptRequestAcknowledgeComplete SecCore1InterruptRequestAcknowledgeComplete

/**
 * @ingroup  sec_coredriver
 * @brief    This macro defines the Custom Name for \ref SecCore1GetResetCause API
 */
#define MSIInterface_GetResetCause SecCore1GetResetCause

/**
 * @ingroup  sec_coredriver
 * @brief    This macro defines the Custom Name for \ref SecCore1ResetCauseClear API
 */
#define MSIInterface_ResetCauseClear SecCore1ResetCauseClear

/**
 * @ingroup  sec_coredriver
 * @brief    This macro defines the Custom Name for \ref SecCore1SystemStatusGet API
 */
#define MSIInterface_SystemStatusGet SecCore1SystemStatusGet

/**
 * @ingroup  sec_coredriver
 * @brief    This macro defines the Custom Name for \ref SecCore1WriteFIFOEnable API
 */
#define MSIInterface_WriteFIFOEnable SecCore1WriteFIFOEnable

/**
 * @ingroup  sec_coredriver
 * @brief    This macro defines the Custom Name for \ref SecCore1WriteFIFODisable API
 */
#define MSIInterface_WriteFIFODisable SecCore1WriteFIFODisable

/**
 * @ingroup  sec_coredriver
 * @brief    This macro defines the Custom Name for \ref SecCore1ReadFIFOEnable API
 */
#define MSIInterface_ReadFIFOEnable SecCore1ReadFIFOEnable

/**
 * @ingroup  sec_coredriver
 * @brief    This macro defines the Custom Name for \ref SecCore1ReadFIFODisable API
 */
#define MSIInterface_ReadFIFODisable SecCore1ReadFIFODisable

/**
 * @ingroup  sec_coredriver
 * @brief    This macro defines the Custom Name for \ref SecCore1FIFORead API
 */
#define MSIInterface_FIFORead SecCore1FIFORead

/**
 * @ingroup  sec_coredriver
 * @brief    This macro defines the Custom Name for \ref SecCore1FIFOWrite API
 */
#define MSIInterface_FIFOWrite SecCore1FIFOWrite

/**
 * @ingroup  sec_coredriver
 * @brief    This macro defines the Custom Name for \ref SecCore1FIFOReadIsFull API
 */
#define MSIInterface_FIFOReadIsFull SecCore1FIFOReadIsFull

/**
 * @ingroup  sec_coredriver
 * @brief    This macro defines the Custom Name for \ref SecCore1FIFOReadIsEmpty API
 */
#define MSIInterface_FIFOReadIsEmpty SecCore1FIFOReadIsEmpty

/**
 * @ingroup  sec_coredriver
 * @brief    This macro defines the Custom Name for \ref SecCore1FIFOWriteIsFull API
 */
#define MSIInterface_FIFOWriteIsFull SecCore1FIFOWriteIsFull

/**
 * @ingroup  sec_coredriver
 * @brief    This macro defines the Custom Name for \ref SecCore1FIFOWriteIsEmpty API
 */
#define MSIInterface_FIFOWriteIsEmpty SecCore1FIFOWriteIsEmpty

/**
 * @ingroup  sec_coredriver
 * @brief    This macro defines the Custom Name for \ref SecCore1ProtocolWrite API
 */
#define MSIInterface_ProtocolWrite SecCore1ProtocolWrite

/**
 * @ingroup  sec_coredriver
 * @brief    This macro defines the Custom Name for \ref SecCore1ProtocolRead API
 */
#define MSIInterface_ProtocolRead SecCore1ProtocolRead

/**
 * @ingroup  sec_coredriver
 * @brief    This macro defines the Custom Name for \ref SecCore1ProtocolIsFull API
 */
#define MSIInterface_ProtocolIsFull SecCore1ProtocolIsFull

/**
 * @ingroup  sec_coredriver
 * @brief    This macro defines the Custom Name for \ref SecCore1ProtocolIsEmpty API
 */
#define MSIInterface_ProtocolIsEmpty SecCore1ProtocolIsEmpty


// Section: SEC_CORE1 Module APIs

/**
 * @ingroup  sec_coredriver
 * @brief    This routine initializes the MSI driver.
 *           This routine must be called before any other MSI routine is called.
 *           This routine should only be called once during system initialization.
 * @param    none
 * @return   none  
 */
void SecCore1Initialize(void);

/**
 * @ingroup  sec_coredriver
 * @brief    Deinitializes SEC_CORE1 to POR values.
 * @param    none
 * @return   none 
 */
void SecCore1Deinitialize(void);

/**
 * @ingroup  sec_coredriver
 * @brief    This routine enables secondary core.
 * @param    none
 * @return   none  
 */        
void SecCore1Start(void);

/**
 * @ingroup  sec_coredriver
 * @brief    This routine programs secondary.
 * @param    none
 * @return   none  
 */
void SecCore1Program(void);

/**
 * @ingroup  sec_coredriver
 * @brief    This routine generates interrupt to SEC_CORE1.
 * @param    none
 * @return   none  
 */
void SecCore1InterruptRequestGenerate(void);

/**
 * @ingroup  sec_coredriver
 * @brief    This routine returns the status of interrupt request acknowledge from the  SEC_CORE1.
 * @param    none
 * @return   True  - when SEC_CORE1 has acknowledged Main MSI interrupt request.
 * @return   False - when SEC_CORE1 has not acknowledged Main MSI interrupt request.  
 */       
bool SecCore1IsInterruptRequestAcknowledged(void);    

/**
 * @ingroup  sec_coredriver
 * @brief    This routine clears interrupt to SEC_CORE1.
 * @param    none
 * @return   none  
 */       
void SecCore1InterruptRequestComplete(void);    

/**
 * @ingroup  sec_coredriver
 * @brief    This routine returns the status of interrupt request from the  SEC_CORE1.
 * @param    none
 * @return   True  - when SEC_CORE1 has issued interrupt to Main Core.
 * @return   False - when SEC_CORE1 has not issued interrupt to Main Core.  
 */     
bool SecCore1IsInterruptRequested(void);    

/**
 * @ingroup  sec_coredriver
 * @brief    This routine acknowledges interrupt received from SEC_CORE1.
 * @param    none
 * @return   none  
 */       
void SecCore1InterruptRequestAcknowledge(void);    

/**
 * @ingroup  sec_coredriver
 * @brief    This routine clears acknowledge for interrupt received from SEC_CORE1.
 * @param    none
 * @return   none  
 */       
void SecCore1InterruptRequestAcknowledgeComplete(void);

/**
 * @ingroup  sec_coredriver
 * @brief    This routine returns the cause for SEC_CORE1 reset.
 * @param    none
 * @return   SECONDARY_RESET_CAUSE: Enum which provides the cause for SEC_CORE1 reset.  
 */
enum SEC_CORE_RESET_CAUSE SecCore1GetResetCause(void);    

/**
 * @ingroup  sec_coredriver
 * @brief    This routine clears the cause for SEC_CORE1 reset.
 * @pre      SECONDARY_RESET_CAUSE: Enum which provides the cause for SEC_CORE1 reset.
 * @param    resetCause - reset to be cleared
 * @return   none  
 */     
void SecCore1ResetCauseClear(enum SEC_CORE_RESET_CAUSE resetCause);    

/**
 * @ingroup  sec_coredriver
 * @brief    This routine returns Secondary system status.
 * @param    none
 * @return   SEC_CORE_SYSTEM_STATUS: Enum which provides the status of SEC_CORE1.  
 */       
enum SEC_CORE_SYSTEM_STATUS SecCore1SystemStatusGet(void);    

/**
 * @ingroup    sec_coredriver
 * @brief      This routine reads FIFO data sent from the SEC_CORE1.
 * @pre        SecCore1ReadFIFOEnable should be called before calling this routine.
 * @param[in]  *pData      - Pointer to an array to store the read data
 * @param[in]  wordCount   - Number of words to be read.     
 * @return     Number of words read.  
 */     
uint16_t SecCore1FIFORead(uint16_t *pData, uint16_t wordCount);    

/**
 * @ingroup    sec_coredriver
 * @brief      This routine transfers FIFO data to SEC_CORE1.
 * @pre        SecCore1WriteFIFOEnable() should be called before calling this routine.
 * @param[in]  *pData      - Pointer to an array which has data for transmission.
 * @param[in]  wordCount   - Number of words to be transfer.  
 * @return     Number of words transferred.  
 */       
uint16_t SecCore1FIFOWrite(uint16_t *pData, uint16_t wordCount);

/** 
 * @ingroup  sec_coredriver
 * @brief    This inline function Enables the Write FIFO. 
 * @param    none
 * @return   none
 */ 
inline static void SecCore1WriteFIFOEnable(void)
{
    MSI1FIFOCSbits.WFEN = 1U;
}

/** 
 * @ingroup  sec_coredriver
 * @brief    This inline function Disables the Write FIFO. 
 * @param    none
 * @return   none
 */ 
inline static void SecCore1WriteFIFODisable(void)
{
    MSI1FIFOCSbits.WFEN = 0U;
}

/** 
 * @ingroup  sec_coredriver
 * @brief    This inline function Enables the Read FIFO. 
 * @param    none
 * @return   none
 */ 
inline static void SecCore1ReadFIFOEnable(void)
{
    MSI1FIFOCSbits.RFEN = 1U;
}

/** 
 * @ingroup  sec_coredriver
 * @brief    This inline function Disables the Read FIFO. 
 * @param    none
 * @return   none
 */ 
inline static void SecCore1ReadFIFODisable(void)
{
    MSI1FIFOCSbits.RFEN = 0U;
}

/** 
 * @ingroup  sec_coredriver
 * @brief    This inline function checks whether the status of Read FIFO is full. 
 *           last write by Secondary core to Read FIFO (RFDATA) was into the last free location
 * @return   true   -    Read FIFO is full
 * @return   false  -    Read FIFO is not full
 */ 
inline static bool SecCore1FIFOReadIsFull(void)
{
    return(MSI1FIFOCSbits.RFFULL);
}

/** 
 * @ingroup  sec_coredriver
 * @brief    This inline function checks whether the status of Read FIFO is Empty. 
 *           Returns true if last read by Main core from Read FIFO (RFDATA) emptied the 
 *           FIFO of all valid data or FIFO is disabled (and initialized to the empty state)
 * @return   true   -    Read FIFO is Empty
 * @return   false  -    Read FIFO is not Empty (Read FIFO contains valid data not yet read by the Main core)
 */
inline static bool SecCore1FIFOReadIsEmpty(void)
{
    return(MSI1FIFOCSbits.RFEMPTY);
}

/** 
 * @ingroup  sec_coredriver
 * @brief    This inline function checks whether the status of Write FIFO is Full. 
 *           Returns true if last write by Main core to Write FIFO (WFDATA) was into 
 *           the last free location
 * @return   true   -    Write FIFO is full
 * @return   false  -    Write FIFO is not full
 */ 
inline static bool SecCore1FIFOWriteIsFull(void)
{
    return(MSI1FIFOCSbits.WFFULL);
}

/** 
 * @ingroup  sec_coredriver
 * @brief    This inline function checks whether the status of Write FIFO is Empty. 
 *           Returns true if last write by Main core to Write FIFO (WFDATA) was into 
 *           the last free location
 * @return   true   -    Write FIFO is Empty
 * @return   false  -    Write FIFO is not Empty (Write FIFO contains valid data not yet read by the Secondary core)
 */ 
inline static bool SecCore1FIFOWriteIsEmpty(void)
{
    return(MSI1FIFOCSbits.WFEMPTY);
}

/**
 * @ingroup    sec_coredriver
 * @brief      This routine writes data to mailbox.
 * @param[in]  protocolName - Selected protocol 
 * @param[in]  *pData      - Pointer to a structure which has data for transmission.  
 * @return     true   -    successful write
 * @return     false  -    unsuccessful write  
 */      
bool SecCore1ProtocolWrite(enum SEC_CORE_PROTOCOLS protocolName, uint16_t *pData);

/** 
 * @ingroup    sec_coredriver
 * @brief      This routine reads data from mailbox.
 * @param[in]  protocolName - Selected protocol 
 * @param[in]  *pData       - Pointer to a structure to store the read data  
 * @return     true   -    successful read
 * @return     false  -    unsuccessful read  
 */   
bool SecCore1ProtocolRead(enum SEC_CORE_PROTOCOLS protocolName, uint16_t *pData);

/** 
 * @ingroup    sec_coredriver
 * @brief      This inline function checks whether mailbox is full. 
 *             Returns true if new data are ready to read. Returns false when 
 *             no data are available to be read by secondary
 * @param[in]  protocolName - Selected protocol 
 * @return     true   -    Mailbox is full
 * @return     false  -    Mailbox is empty 
 */ 
inline static bool SecCore1ProtocolIsFull(enum SEC_CORE_PROTOCOLS protocolName)
{
    bool status = false;
    switch(protocolName)
    {
        case MSI1_ProtocolA:
            status =  MSI1MBXSbits.DTRDYA;
            break;
        case MSI1_ProtocolB:
            status =  MSI1MBXSbits.DTRDYB;
            break;
        default:
            break;   
    }  
    return status;   
}

/** 
 * @ingroup    sec_coredriver
 * @brief      This inline function checks whether mailbox is empty. 
 *             Returns true if Protocol is empty indicating mailbox is ready to 
 *             write by secondary. Returns false indicating write operation cannot 
 *             be performed by secondary
 * @param[in]  protocolName - Selected protocol 
 * @return     true   -    Mailbox is empty
 * @return     false  -    Mailbox is full
 */ 
inline static bool SecCore1ProtocolIsEmpty(enum SEC_CORE_PROTOCOLS protocolName)
{
    bool status = false;
    switch(protocolName)
    {
        case MSI1_ProtocolA:
            status =  !MSI1MBXSbits.DTRDYA;
            break;
        case MSI1_ProtocolB:
            status =  !MSI1MBXSbits.DTRDYB;
            break;
        default:
            break;   
    }  
    return status; 
}



#endif //SEC_CORE1_H
