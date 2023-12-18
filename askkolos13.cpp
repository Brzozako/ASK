#include <iostream>
using namespace std;

int main()
{
    typedef union {
        unsigned char BYTE;
        struct {
            unsigned char a : 2;
            unsigned char b : 3;
            unsigned char c : 3;
        }bits;
    }un_X;
    un_X x;
    //cccb bbaa

    x.BYTE = 0b00100011;
    if (x.bits.c == 1) x.bits.a = x.bits.b;
    printf("%x\n", x.BYTE);
    unsigned char a = (x.BYTE & 0b00000011) >> 0;
    unsigned char b = (x.BYTE & 0b00011100) >> 2;
    unsigned char c = (x.BYTE & 0b11100000) >> 5;
    if (c == 1){
        a = b;
    }

    x.BYTE = 0;
    x.BYTE |= (a & 0b00000011) << 0;
    x.BYTE |= (b & 0b00000111) << 2;
    x.BYTE |= (c & 0b00000111) << 5;
    
    printf("%x\n", x.BYTE);

    _asm {
        xor al, al;
        xor bl, bl;
        xor cl, cl;

        mov al, x.BYTE;
        and al, 3
        shr al, 0

        mov bl, x.BYTE;
        and bl, 0x1c
        shr bl, 2

        mov cl, x.BYTE;
        and cl, 0xe0
        shr cl, 5

        sub cl, 1
        jnz falsz
        mov al, bl

        falsz:

        add cl, 1

            /*x.BYTE = 0;
            x.BYTE |= (a & 0b00000011) << 0;
            x.BYTE |= (b & 0b00000111) << 2;
            x.BYTE |= (c & 0b00000111) << 5;*/

        mov x.BYTE, 0;
        and al, 0b00000011
            shl al, 0
            or x.BYTE, al;

        and bl, 0b00000111
            shl bl, 2
            or x.BYTE, bl;

        and cl, 0b00000111
            shl cl, 5
            or x.BYTE, cl;
    }

    printf("BYTE = %02X\r\n", x.BYTE);
    printf("   a = %d\r\n", x.bits.a);
    printf("   b = %d\r\n", x.bits.b);
    printf("   c = %d\r\n", x.bits.c);


}

