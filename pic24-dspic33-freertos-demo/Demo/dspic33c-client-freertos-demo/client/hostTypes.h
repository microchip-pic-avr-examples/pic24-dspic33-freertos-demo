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
#ifndef HOST_TYPES_H
#define HOST_TYPES_H

/**
 @ingroup   main_coredriver
 @enum      HOST_SYSTEM_STATUS
 @brief     Defines the status enumeration for main_core.
*/
enum HOST_SYSTEM_STATUS
{
    HOST_SYSTEM_STATUS_NOT_IN_LOW_POWER_MODE = 0,   /**< main_core status is in Low power mode */
    HOST_SYSTEM_STATUS_SLEEP_MODE            = 1,   /**< main_core status is in Sleep mode */
    HOST_SYSTEM_STATUS_IDLE_MODE             = 2,   /**< main_core status is in Idle mode */
    HOST_SYSTEM_STATUS_RUNNING_STATE         = 3,   /**< main_core status is in Running state */
    HOST_SYSTEM_STATUS_IN_RESET_STATE        = 4    /**< main_core status is in Reset state */
};

/**
 @ingroup   main_coredriver
 @enum      HOST_PROTOCOLS
 @brief     Defines the list of Protocols configured for HOST_driver. 
 @note      These Protocols are required to create the buffer by the application
*/
enum HOST_PROTOCOLS
{
    MSI1_ProtocolA,      /**< Custom-name of Protocol A for read operation only */
    MSI1_ProtocolB,      /**< Custom-name of Protocol B for write operation only */
};

/**
 @ingroup   main_coredriver
 @enum      HOST_PROTOCOL_SIZE
 @brief     Defines the size for Protocols.
 @note      Size not required for the driver but will be required for application to create the buffers
*/
enum HOST_PROTOCOL_SIZE
{
    MSI1_ProtocolA_SIZE = 1,     /**< Size of Protocol A in 16-bit word*/
    MSI1_ProtocolB_SIZE = 1,     /**< Size of Protocol B in 16-bit word*/
};

#endif    /* HOST_TYPES_H */