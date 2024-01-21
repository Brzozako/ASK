#include <iostream>
#include <stdint.h>
using namespace std;

int main()
{
    uint8_t y = 0;
    uint8_t a = 0x12;
    int licznik = 0;
    int pom;

    for (int i = 0; i < 8; i++) {
        pom = a;
        pom = pom & 1;
        licznik = licznik + pom;
        a = a >> 1;
    }
    y = 8 - licznik;
    printf("C   y: %d\n", y);

    y = 0;
    a = 0x12;

    _asm {
        mov bl, 0;
        mov al, a;
    petla:
        mov cl, al;
        and cl, 1;
        add bl, cl;
        shr al, 1;
        jnz petla;

        mov dl, 8;
        sub dl, bl;
        mov y, dl;
    }printf("ASM   y: %d\n", y);
    

}