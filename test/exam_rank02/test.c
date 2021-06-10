#include <unistd.h>
#include <stdio.h>

int main(void)
{
    char str[2][5] = {"good", "hi"};

    printf("%c\n", *(str[0]));
    printf("%c\n", (*str)[0]);
    return 0;
}