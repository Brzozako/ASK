#include <iostream>
#include <stdint.h>
using namespace std;

int main()
{
    uint16_t y = 0;
    uint16_t a = 8;
    uint16_t b = 0;

    b = a >> 3;
    y = a + b;

    printf("C   y: %d\n", y);

    
    _asm {
        mov ax, a;
        mov bx, a;
        shr bx, 3;
        add ax, bx;
        mov y, ax;

    }printf("ASM   y: %d\n", y);

}