#include <iostream>
using namespace std;

int main()
{
    unsigned char a=0x12, r=0;
    for (int i = 0; i < 8; i++) {
        char tmp=a;
        tmp = tmp & 1;
        r = r << 1;
        r = r | tmp;
        a = a >> 1;


    }printf("%x",r );



}

