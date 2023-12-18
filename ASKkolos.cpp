#include <iostream>
using namespace std;

int main()
{
    typedef union {
        unsigned char BYTE;
        struct {
            unsigned char a : 1;
            unsigned char b : 3;
            unsigned char c : 4;

        }bits;
    }un_X;

    un_X x;
    //cccc bbba
    
    x.BYTE = 0xff;
    x.bits.c = x.bits.a * x.bits.b;
    printf("%x\n", x.BYTE);

    unsigned char a = (x.BYTE & 0x01) >> 0;
    unsigned char b = (x.BYTE & 0x0e) >> 1;
    unsigned char c = (x.BYTE & 0xf0) >> 4;
    c = a * b;

    x.BYTE = 0;
    x.BYTE |= (a & 1) << 0;
    x.BYTE |= (b & 7) << 1;
    x.BYTE |= (c & 0x0f) << 4;
    printf("%x\n", x.BYTE);

    _asm {
        xor al, al;
        xor bl, bl;
        xor cl, cl;

        mov al, x.BYTE;
        and al, 1;

        mov bl, x.BYTE;
        and bl, 0x0e;
        shr bl, 1;

        mov cl, x.BYTE;
        and cl, 0xf0;
        shr cl, 4;

        sub al, 0;
        jnz jesli_jeden;
        mov bl, 0;
        jesli_jeden:


        mov x.BYTE, 0;
        and al, 1;
        shl al, 0;
        or x.BYTE, al;

        and bl, 7;
        shl bl, 1;
        or x.BYTE, bl;

        and cl, 0x0f;
        shl cl, 4;
        or x.BYTE, cl;

    }

    printf("BYTE = %02X\r\n", x.BYTE);
    printf("   a = %d\r\n", x.bits.a);
    printf("   b = %d\r\n", x.bits.b);
    printf("   c = %d\r\n", x.bits.c);


}

