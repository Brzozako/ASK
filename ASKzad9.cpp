#include <iostream>
#include <stdint.h>
using namespace std;

int main()
{
    uint16_t y = 0;
    uint8_t a = 4;
    uint8_t b = 5;
    int d = 0;
    while (b != 0) {
        if (b & 1) { d += a; }
        a <<= 1;
        b >>= 1;
    }

    y = d;
    printf("C   y: %d\n", y);

    y = 0;
    a = 4;
    b = 5;
    d = 0;
    _asm {
        mov al, a;
        mov ah, 0;
        mov bl, b;
        mov dx, 0;
    warunek:
        test bl, 1;
        jz petla;
        add dx, ax;
    petla:
        shl ax, 1;
        shr bl, 1;
        jnz warunek;
        mov y, dx;

    }printf("ASM   y: %d\n", y);

}