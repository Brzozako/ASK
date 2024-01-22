#include <iostream>
#include <stdint.h>
using namespace std;

int main()
{
    uint8_t y = 0;
    uint8_t a = 0x05;

    if (a < 0x05)
        y = 0;
    else
        y = 1;
    

    printf("C   y: %d\n", y);

    _asm {
        mov al, a;
        sub al, 0x05;
        jc prawda;
        mov y, 1;
    prawda:


    }printf("ASM   y: %d\n", y);

    y = 0;
    a = 0x05;

    if (a < 0x05)
        y = 0;
    else
        y = 1;


    printf("C   y: %d\n", y);

    _asm {
        mov al, a;
        cmp al, 0x05;
        jc prawda2;
        mov y, 1;
    prawda2:


    }printf("ASM   y: %d\n", y);
    printf("---------------------------");
    y = 0;
    a = 0x05;

    if (a <= 0x05)
        y = 0;
    else
        y = 1;


    printf("C   y: %d\n", y);

    _asm {
        mov al, a;
        sub al, 0x05;
        jc prawda3;
        mov y, 1;
    prawda3:


    }printf("ASM   y: %d\n", y);

    //jeżeli a>0x05;
    //to sub al, -0xfa;  <--- negatyw wyniku
}