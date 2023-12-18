#include <iostream>
using namespace std;

int main()
{
	uint16_t y;
	uint8_t a=10;
	y = a * 20;
	printf("%x", y);
	_asm {
		xor al, al
		xor bl, bl
		
		shl al, 2
		shl bl, 4
		add al, bl
		mov y, ax


	} printf("%x", y)



}
