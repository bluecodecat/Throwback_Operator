#ifndef __OPL3_H__
#define __OPL3_H__
#include <Arduino.h>
#include "Bus.h"

#define nop __asm__ __volatile__ ("nop\n\t")

class OPL3
{
private:
    uint8_t IC = PA15;
    uint8_t CS = PA8;
    uint8_t A0 = PC13;
    uint8_t A1 = PC14;
    uint8_t WR = PB5;
    uint32_t clkfrq;
public:
    OPL3(/* args */);
    ~OPL3();
    void write(uint8_t addr, uint8_t data, bool setA1);
    void setOPLMode(bool isOPL3);
    void reset();
};


#endif

/*
PB8   -   D0
PB9   -   D1
PB10 -   D2
PB11 -   D3
PB12 -   D4
PB13 -   D5
PB14 -   D6
PB15 -   D7

PC13   -   A0
PC14   -   A1

PB5   -  WR
PULLED HIGH   -  RD

PA15   -   IC
PA8 -   CS
*/