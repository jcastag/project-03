
#ifndef LETTER_H
#define LETTER_H

#include <string.h>
#include <stdint.h>

class Letter
{
public:
    Letter();
    ~Letter();

    int getTo();
    int getFrom();
    int setTo();
    int setFrom();

private:
    uint16_t toId;
    uint16_t fromId;
    uint16_t numOfMbox;
};

#endif