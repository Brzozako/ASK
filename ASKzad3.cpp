#include <iostream>
using namespace std;

int main()
{
    unsigned char a = 0x32; //a = 0011 0010
    bool y;
    if (a == 0x32)
        y = false;
    else
        y = true;
    printf("C   y: %d\n", y);
    _asm {
        mov a, al;
        sub a, 0x32;
        jnz falsz;
        mov y, 1;
        jmp koniec;

    falsz:
        mov y, 0;

        koniec:
    }printf("ASM   y: %d\n", y);
}