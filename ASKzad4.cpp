#include <iostream>
#include <stdint.h>
using namespace std;

int main()
{
    uint32_t y=0;
    
    for (int i = 0; i != 5; i++) {
        y += i;
    }

    printf("C+   y: %d\n", y);
    _asm {
        mov y, 0
        mov eax, 0;
    petla:
        sub eax, 5;
        jz koniec;
        add eax, 5;
        add y, eax;
        add eax, 1;
        jmp petla;
    koniec:

    }printf("ASM+   y: %d\n", y);

    y = 0;

    for (int i = 5; i != 0; i--) {
        y -= i;
    }
    
    printf("C-   y: %d\n", y);
    _asm {
        xor eax, eax;
        mov eax, 5;
    petla2:
        jz koniec1;
        add y, eax;
        sub eax, 1;
        jmp petla2;
    koniec1:

    }printf("ASM-   y: %d\n", y);
}