#include <xc.h>
#include <libpic30.h>
#include "RTOSDemo_Slave.h"

#pragma config FNOSC = FRC    //Master Oscillator Source Selection->Internal Fast RC (FRC)
#pragma config ICS = PGD3     //Master ICD Communication Channel Select bits->Communicate on PGC3 and PGD3

// FCFGPRA0
#pragma config CPRA0 = SLV1    //Pin RA0 Ownership Bits->Slave 1 core owns pin.
#pragma config CPRA1 = SLV1    //Pin RA1 Ownership Bits->Slave 1 core owns pin.
#pragma config CPRA2 = SLV1    //Pin RA2 Ownership Bits->Slave 1 core owns pin.
#pragma config CPRA3 = SLV1    //Pin RA3 Ownership Bits->Slave 1 core owns pin.
#pragma config CPRA4 = SLV1    //Pin RA4 Ownership Bits->Slave 1 core owns pin.

// FCFGPRB0
#pragma config CPRB0 = SLV1    //Pin RB0 Ownership Bits->Master core owns pin.
#pragma config CPRB1 = SLV1    //Pin RB1 Ownership Bits->Master core owns pin.
#pragma config CPRB2 = SLV1    //Pin RB2 Ownership Bits->Master core owns pin.
#pragma config CPRB3 = SLV1    //Pin RB3 Ownership Bits->Master core owns pin.
#pragma config CPRB4 = SLV1    //Pin RB4 Ownership Bits->Master core owns pin.
#pragma config CPRB5 = SLV1    //Pin RB5 Ownership Bits->Master core owns pin.
#pragma config CPRB6 = SLV1    //Pin RB6 Ownership Bits->Master core owns pin.
#pragma config CPRB7 = SLV1    //Pin RB7 Ownership Bits->Master core owns pin.
#pragma config CPRB8 = SLV1    //Pin RB8 Ownership Bits->Master core owns pin.
#pragma config CPRB9 = SLV1    //Pin RB9 Ownership Bits->Master core owns pin.
#pragma config CPRB10 = SLV1    //Pin RB10 Ownership Bits->Master core owns pin.
#pragma config CPRB11 = SLV1    //Pin RB11 Ownership Bits->Master core owns pin.
#pragma config CPRB12 = SLV1    //Pin RB12 Ownership Bits->Master core owns pin.
#pragma config CPRB13 = SLV1    //Pin RB13 Ownership Bits->Master core owns pin.
#pragma config CPRB14 = SLV1    //Pin RB14 Ownership Bits->Master core owns pin.
#pragma config CPRB15 = SLV1    //Pin RB15 Ownership Bits->Master core owns pin.

// FCFGPRC0
#pragma config CPRC0 = SLV1    //Pin RC0 Ownership Bits->Slave 1 core owns pin.
#pragma config CPRC1 = SLV1    //Pin RC1 Ownership Bits->Slave 1 core owns pin.
#pragma config CPRC2 = SLV1    //Pin RC2 Ownership Bits->Slave 1 core owns pin.
#pragma config CPRC3 = SLV1    //Pin RC3 Ownership Bits->Slave 1 core owns pin.
#pragma config CPRC4 = SLV1    //Pin RC4 Ownership Bits->Slave 1 core owns pin.
#pragma config CPRC5 = SLV1    //Pin RC5 Ownership Bits->Slave 1 core owns pin.
#pragma config CPRC6 = SLV1    //Pin RC6 Ownership Bits->Slave 1 core owns pin.
#pragma config CPRC7 = SLV1    //Pin RC7 Ownership Bits->Slave 1 core owns pin.
#pragma config CPRC8 = SLV1    //Pin RC8 Ownership Bits->Slave 1 core owns pin.
#pragma config CPRC9 = SLV1    //Pin RC9 Ownership Bits->Slave 1 core owns pin.
#pragma config CPRC10 = SLV1    //Pin RC10 Ownership Bits->Slave 1 core owns pin.
#pragma config CPRC11 = SLV1    //Pin RC11 Ownership Bits->Slave 1 core owns pin.
#pragma config CPRC12 = SLV1    //Pin RC12 Ownership Bits->Slave 1 core owns pin.
#pragma config CPRC13 = SLV1    //Pin RC13 Ownership Bits->Slave 1 core owns pin.
#pragma config CPRC14 = SLV1    //Pin RC14 Ownership Bits->Slave 1 core owns pin.
#pragma config CPRC15 = SLV1    //Pin RC15 Ownership Bits->Slave 1 core owns pin.

// FCFGPRE0
#pragma config CPRE0 = SLV1    //Pin RE0 Ownership Bits->Slave 1 core owns pin.
#pragma config CPRE1 = SLV1    //Pin RE1 Ownership Bits->Slave 1 core owns pin.
#pragma config CPRE2 = SLV1    //Pin RE2 Ownership Bits->Slave 1 core owns pin.
#pragma config CPRE3 = SLV1    //Pin RE3 Ownership Bits->Slave 1 core owns pin.
#pragma config CPRE4 = SLV1    //Pin RE4 Ownership Bits->Slave 1 core owns pin.
#pragma config CPRE5 = SLV1    //Pin RE5 Ownership Bits->Slave 1 core owns pin.
#pragma config CPRE6 = SLV1    //Pin RE6 Ownership Bits->Slave 1 core owns pin.
#pragma config CPRE7 = SLV1    //Pin RE7 Ownership Bits->Slave 1 core owns pin.
#pragma config CPRE8 = SLV1    //Pin RE8 Ownership Bits->Slave 1 core owns pin.
#pragma config CPRE9 = SLV1    //Pin RE9 Ownership Bits->Slave 1 core owns pin.
#pragma config CPRE10 = SLV1    //Pin RE10 Ownership Bits->Slave 1 core owns pin.
#pragma config CPRE11 = SLV1    //Pin RE11 Ownership Bits->Slave 1 core owns pin.
#pragma config CPRE12 = SLV1    //Pin RE12 Ownership Bits->Slave 1 core owns pin.
#pragma config CPRE13 = SLV1    //Pin RE13 Ownership Bits->Slave 1 core owns pin.
#pragma config CPRE14 = SLV1    //Pin RE14 Ownership Bits->Slave 1 core owns pin.
#pragma config CPRE15 = SLV1    //Pin RE15 Ownership Bits->Slave 1 core owns pin.


#pragma config S1FCKSM = CSECMD    //Clock Switching Mode bits->Clock switching is enabled,Fail-safe Clock Monitor is disabled
#pragma config S1ICS = PGD2        //SLAVE ICD Communication Channel Select bits->Communicate on PGC2 and PGD2
#pragma config S1FNOSC = FRC       //Oscillator Source Selection->Internal Fast RC (FRC)

#define SLAVE_NUMBER    1
#define SLAVE_IMAGE     RTOSDemo_Slave

void SLAVE1_Start();
void SLAVE1_Program();


int main()
{
    //Program and enable slave
    SLAVE1_Program();
    SLAVE1_Start();
    while(1);
}

void SLAVE1_Start()
{
    _start_slave();
}

void SLAVE1_Program()               
{
    _program_slave(SLAVE_NUMBER, 0, SLAVE_IMAGE);
}
