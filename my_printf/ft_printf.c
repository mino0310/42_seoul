#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

void        ft_putnbr(int n);
void        ft_putchar(char c);
void        ft_putstr(char *str);
int         ft_strlen(char *str);
void        print_hex(int n);
void        print_HEX(int n);

int         ft_printf(const char *format, ...)
{
    va_list ap;
    int output_int;
    int len = 0;
    char output_char;
    char *output_str;
    char *just_string;
    int format_on = -1;
    int output_hex;
    int output_HEX;

    va_start(ap, format);

    while (*format) {
        just_string = (char *)format;
        if (*format++ == '%' || format_on == 1) {
            format_on *= -1;
            if (format_on == 1 && *format == '%'){
                //printf("%% print!\n");
                ft_putchar('%');
            }
            else if (format_on == 1 && *format == 'd'){
                output_int =va_arg(ap, int);
                //printf("ft_putnbr call\n");
                ft_putnbr(output_int);
            }
            else if (format_on == 1 && *format == 'c') {
                output_char = va_arg(ap, int);
                //printf("ft_putchar call\n");
                ft_putchar(output_char);
            }
            else if (format_on == 1 && *format == 's') {
                output_str = va_arg(ap, char *);
                //printf("ft_putstr call\n");
                ft_putstr(output_str);
            }
            else if (format_on == 1 && *format == 'x') {
                output_hex = va_arg(ap, int);
                print_hex(output_hex);
            }
            else if (format_on == 1 && *format == 'X') {
                output_HEX = va_arg(ap, int);
                print_HEX(output_HEX);
            }
            // 남은 것은 p , i, u 구만
        }
        else
        {
            //printf("just print! \n");
            write(1, just_string, 1);
            just_string++;
            }
    }

    return (0);
}
// 숫자를 화면에 문자로 출력해주는 함수의 내부함수
void			print_nbr(int n)
{
	if (n >= 10)
		print_nbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}
// 숫자를 화면에 문자로 출력해주는 함수
void			ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	print_nbr(n);
}
// 문자를 화면에 문자로 출력해주는 함수
void        ft_putchar(char c)
{
    write(1, &c, 1);
}
// 문자열을 화면에 출력해주는 함수
void        ft_putstr(char *str)
{
    while(*str)
    {
        write(1, str, 1);
        str++;
    }
}

int        ft_strlen(char *str)
{
    int len = 0;
    while (*str)
    {
        str++;
        len++;
    }
    return (len);
}

void        print_hex(int n)
{
    if ( n >= 16 )
        print_hex(n / 16);
    write(1, &"0123456789abcdef"[n % 16], 1);
}

void        print_HEX(int n)
{
    if ( n >= 16 )
        print_hex(n / 16);
    write(1, &"0123456789ABCDEF"[n % 16], 1);
}


int main(){

    ft_printf("%%%d\n", 123);
    printf("%%%d\n", -123);
    ft_printf("ft_pirntf(\"%%d\", 123) = %d\n", 123);
    printf("%x\n", 16);
    printf("%X\n", 32);
    printf("%u", -123);


    return 0;
}