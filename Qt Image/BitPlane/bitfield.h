#ifndef BITFIELD_H
#define BITFIELD_H

typedef struct
{
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char bit2 : 1;
    unsigned char bit3 : 1;
    unsigned char bit4 : 1;
    unsigned char bit5 : 1;
    unsigned char bit6 : 1;
    unsigned char bit7 : 1;
}_bits;

typedef union
{
    _bits bit;
    unsigned char byte;
}MyByte;


#endif // BITFIELD_H

