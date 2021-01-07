#include <unistd.h>
#include <stdio.h>

void print_hex(int n)
{
    if ( n >= 16 )
        print_hex(n / 16);
    write(1, &"0123456789abcdef"[n % 16], 1);
}

int main() {

    int input = 32;

    print_hex(32);
    printf("\n");
    print_hex(49);
    printf("\n");
    print_hex(16);
    

    return 0;
}   