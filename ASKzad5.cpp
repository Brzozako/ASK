#include <iostream>
#include <stdint.h>
using namespace std;

int main()
{
    uint32_t y = 0;

    while (y != 5) y += 1;

    printf("C   y: %d\n", y);
    _asm {
        mov eax, y;
    petla:
        sub eax, 5;
        jz koniec;
        add eax, 5;
        add eax, 1;
        jmp petla;

    koniec:
        add eax, 5;
        mov y, eax;

    }printf("ASM   y: %d\n", y);
    printf("-----------------------------------------\n");
    y = 0;

    do { y += 1; } while (y != 5);

    printf("C   y: %d\n", y);
    _asm {
        mov eax, y;
    petla1:
        add eax, 1;
        sub eax, 5;
        jz koniec1;
        add eax, 5;
        jmp petla1;

    koniec1:
        add eax, 5;
        mov y, eax;

    }printf("ASM   y: %d\n", y);

}