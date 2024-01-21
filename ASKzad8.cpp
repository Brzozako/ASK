#include <iostream>
#include <stdint.h>
using namespace std;

int main()
{
    uint8_t y = 0;
    uint8_t a = 0x01;
    uint8_t c = 0;
    unsigned char al, ah, cl, ch;

    al = a;
    cl = c;
    ch = 0x80;

    while (ch != 0) {
        ah = al;

        if ((ah & 1) == 0) {
            cl = (cl << 1) | 0;
        }
        else {
            cl = (cl << 1) | 1;
        }

        al >>= 1;
        ch >>= 1;
    }

    y = cl;

    printf("C   y: %d\n", y);

    y = 0;
    a = 0x01;

    _asm {
        mov al, a;
        mov cl, c;
        mov ch, 0x80;
    petla:
        mov ah, al;
        test ah, 1;
        jz rowne0;
        jnz rowne1;

    rowne0:
        shl cl, 1;
        or cl, 0;
        jmp kontynuacja;

    rowne1:
        shl cl, 1;
        or cl, 1;
        jmp kontynuacja;

    kontynuacja:
        shr al, 1;
        shr ch, 1;
        jnz petla;
        mov y, cl

    }printf("ASM   y: %d\n", y);

}