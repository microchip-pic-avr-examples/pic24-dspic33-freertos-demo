    #include "FreeRTOSConfig.h"
   
    .global _portYIELD
    .extern _vTaskSwitchContext
    .equ    MAX_RAM_LIM_ADDRESS, 0x7FFC
    .section .text
_portYIELD:
    CTXTSWP #0x0

    ; save context
    NOP
    NOP

    MOV.l   SR, [W15++]
    PUSH.l  W0
    PUSH.l  W1
    PUSH.l  W2
    PUSH.l  W3
    PUSH.l  W4
    PUSH.l  W5
    PUSH.l  W6
    PUSH.l  W7
    PUSH.l  W8
    PUSH.l  W9
    PUSH.l  W10
    PUSH.l  W11
    PUSH.l  W12
    PUSH.l  W13
    PUSH.l  W14

    PUSH.l  F0
    PUSH.l  F1
    PUSH.l  F2
    PUSH.l  F3
    PUSH.l  F4
    PUSH.l  F5
    PUSH.l  F6
    PUSH.l  F7
    PUSH.l  F8
    PUSH.l  F9
    PUSH.l  F10
    PUSH.l  F11
    PUSH.l  F12
    PUSH.l  F13
    PUSH.l  F14
    PUSH.l  F15
    PUSH.l  F16
    PUSH.l  F17
    PUSH.l  F18
    PUSH.l  F19
    PUSH.l  F20
    PUSH.l  F21
    PUSH.l  F22
    PUSH.l  F23
    PUSH.l  F24
    PUSH.l  F25
    PUSH.l  F26
    PUSH.l  F27
    PUSH.l  F28
    PUSH.l  F29
    PUSH.l  F30
    PUSH.l  F31
    PUSH.l  FCR
    PUSH.l  FSR
    PUSH.l  FEAR

    PUSH.l  RCOUNT
    PUSH.l  CORCON
    PUSH.l  MODCON
    PUSH.l  XMODSRT
    PUSH.l  XMODEND
    PUSH.l  YMODSRT
    PUSH.l  YMODEND
    PUSH.l  XBREV

    SLAC.l  A, [W15++]
    SAC.l   A, [W15++]
    SUAC.l  A, [W15++]
    SLAC.l  B, [W15++]
    SAC.l   B, [W15++]
    SUAC.l  B, [W15++]

    MOV.l   _uxCriticalNesting, W0
    PUSH.l  W0
    PUSH.l  SPLIM

    MOV.l   _pxCurrentTCB, W0
    MOV.l   W15, [W0]

    CALL    _vTaskSwitchContext

    MOV.l     #MAX_RAM_LIM_ADDRESS, W0
    MOV.l     W0, SPLIM

    ; Restore context
    NOP
    NOP

    MOV.l   _pxCurrentTCB, W0
    MOV.l   [W0], W15
    POP.l   SPLIM
    POP.l   W0
    MOV.l   W0, _uxCriticalNesting

    LUAC.l  [--W15], B
    LAC.l   [--W15], B
    LLAC.l  [--W15], B
    LUAC.l  [--W15], A
    LAC.l   [--W15], A
    LLAC.l  [--W15], A

    POP.l   XBREV
    POP.l   YMODEND
    POP.l   YMODSRT
    POP.l   XMODEND
    POP.l   XMODSRT
    POP.l   MODCON
    POP.l   CORCON
    POP.l   RCOUNT

    POP.l   FEAR
    POP.l   FSR
    POP.l   FCR
    POP.l   F31
    POP.l   F30
    POP.l   F29
    POP.l   F28
    POP.l   F27
    POP.l   F26
    POP.l   F25
    POP.l   F24
    POP.l   F23
    POP.l   F22
    POP.l   F21
    POP.l   F20
    POP.l   F19
    POP.l   F18
    POP.l   F17
    POP.l   F16
    POP.l   F15
    POP.l   F14
    POP.l   F13
    POP.l   F12
    POP.l   F11
    POP.l   F10
    POP.l   F9
    POP.l   F8
    POP.l   F7
    POP.l   F6
    POP.l   F5
    POP.l   F4
    POP.l   F3
    POP.l   F2
    POP.l   F1
    POP.l   F0

    POP.l   W14
    POP.l   W13
    POP.l   W12
    POP.l   W11
    POP.l   W10
    POP.l   W9
    POP.l   W8
    POP.l   W7
    POP.l   W6
    POP.l   W5
    POP.l   W4
    POP.l   W3
    POP.l   W2
    POP.l   W1
    POP.l   W0
    MOV.l   [--W15], SR

    ; Enable interrupts
    DISICTL #0x0

    RETFIE   
 
    .section .text
    .global __T1Interrupt
    .extern _xTaskIncrementTick
    .extern _portYIELD
__T1Interrupt:
    BCLR.B 0x96, #0
    RCALL _xTaskIncrementTick
    CP.L W0, #0
    NEOP
    BRA Z, _T1Interrupt_Exit
    MOV.L  #configKERNEL_INTERRUPT_PRIORITY, W0
    INC  W0, W1
    MOV.L    W1, W0
    DISICTL   W0
    GOTO _portYIELD
   
_T1Interrupt_Exit:
    retfie  
    
    
    .section .text
    .global __GeneralTrap
    .extern _portYIELD
__GeneralTrap:    
    MOV.SL #0x83, W0
    ZE.BZ [W0], W0 
    LSR.W W0, #7, W0
    MOV.BZ W0, W0
    CP.B W0, #1
    BRA NZ, _GeneralTrapExit
    BCLR.b 0x83, #7
    GOTO _portYIELD
    
_GeneralTrapExit:
    retfie
    
