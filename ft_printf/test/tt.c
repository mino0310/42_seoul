#include <stdio.h>

int main(void)
{
	printf("%10.5d\n", 123);
	printf("%5.10d\n", 123);
	printf("%0.10d\n", -123456);
	printf("%010d\n", -123456);
	printf("%05.2d\n", 123);
	return 0;
}
