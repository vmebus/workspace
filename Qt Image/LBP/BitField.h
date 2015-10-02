#ifndef BITFILED_H
#define BITFILED_H

typedef struct
{
bool bit0  : 1;
bool bit1  : 1;
bool bit2  : 1;
bool bit3  : 1;
bool bit4  : 1;
bool bit5  : 1;
bool bit6  : 1;
bool bit7  : 1;

}_bits;


// counterclockwise
//typedef struct
//{
//bool bit7  : 1;
//bool bit6  : 1;
//bool bit5  : 1;
//bool bit4  : 1;
//bool bit3  : 1;
//bool bit2  : 1;
//bool bit1  : 1;
//bool bit0  : 1;

//}_bits;

typedef union
{
   _bits bit;
   unsigned char byte;
}MyByte;

#endif // BITFILED_H
