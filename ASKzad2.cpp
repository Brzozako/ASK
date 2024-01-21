#include <iostream>
using namespace std;

int main()
{
    unsigned char a=0x32; //a = 0011 0010
    unsigned short y;
    if (a == 0x32)
        y = 0;
    else
        y = 1;
    printf("C   y: %d\n", y);
    _asm {
        mov al, a;
        sub al, 0x32;
        jnz falsz;
        mov y, 0;
        jmp koniec;
        
    falsz:
        mov y, 1;

        koniec:
    }printf("ASM   y: %d\n", y);
}