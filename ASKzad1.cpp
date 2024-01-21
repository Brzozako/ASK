#include <iostream>
using namespace std;

int main()
{
    unsigned char a = 15;
    unsigned short y;
    y = (unsigned short)(a << 4) + (unsigned short)(a << 2);
    printf("C   y: %d\n", y);
    _asm {
        xor eax, eax
        xor ebx, ebx
        mov al, a
        shl ax, 4
        mov bl, a
        shl bx, 2
        add ax, bx
        mov y, ax
    }printf("ASM    y: %d\n", y);


}
