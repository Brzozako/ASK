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
    
    licznik = licznik & 1;
    licznik = licznik ^ 1;
    y = licznik;

    printf("C   y: %d\n", y);

    y = 0;
    a = 0x12;

    _asm {
        mov al, a;
    petla:
        mov ah, al;
        and ah, 1;
        add cl, ah;
        shr al, 1;
        jnz petla;
        and cl, 1;
        xor cl, 1;
        mov y, cl;

    }printf("ASM   y: %d\n", y);

}