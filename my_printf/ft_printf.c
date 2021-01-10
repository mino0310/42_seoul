#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

void        ft_putnbr(int n);
void        ft_putchar(char c);
void        ft_putstr(char *str);
int         ft_strlen(char *str);
void        print_hex(int n);
void        print_HEX(int n);
void        print_ptr(void *ptr);
void        print_nbr_u(unsigned int n);
int         ft_isdigit(int n);
int         intlen(int n);


int         ft_printf(const char *format, ...)
{
    va_list ap;
    int output_int;
    int len = 0;
    char output_char;
    char *output_str;
    char *just_string;
    int output_hex;
    int output_HEX;
    void *output_ptr;
    unsigned int output_u;
    int width; 
    int width_on = 0;       // 너비 플래그
    int format_on = -1;     // 서식 % 플래그

    va_start(ap, format);

    while (*format) { // 서식문자열을 끝까지 탐색한다 서식문자열을 탐색하다가 특정 문자가 나오면 뒤의 가변인자목록을 해당 타입으로 출력하는 형식.
        just_string = (char *)format;                       // 서식 문자열을 형변환한다음 문자열 포인터에 대입.
        if (*format++ == '%' || format_on == 1) {           /* 서식문자가 '%'이면 서식문자가 입력되었다는 것이니까 -1을 곱해서 플래그를 켠다. 
        만약 format_on 플래그가 켜져있다면, 이미 %가 등장했다는 것이니까 -1을 해서 %를 서식문자로 인식했던 것을 해제 */
            format_on *= -1;
            // 그리고 해당 서식문자 다음을 탐색. 어떤 서식 문자가 오는지 보는 것. 
            if (format_on == 1 && *format == '%'){          // 유효한 %가 앞에 왔고 내가 %라면 그것은 %를 표시하라는 뜻
                ft_putchar('%');                            // 따라서 %를 출력
            }
            // 이제 본격적으로 서식 문자를 찾아서 출력해주는 부분.
            if (format_on == 1 && ft_isdigit(*format)){     // %가 유효하고, 서식문자가 숫자를 나타내는 문자라면 (너비 파악)
                width = *format++ - '0';                    // 서식문자에 나와있는 숫자문자를 숫자로 만들어서 너비로 지정 -> 서식문자 포인터 다음 것 가리키게. 
                //printf("width is = %d\n", width);
                width_on = 1;
            }
            if (format_on == 1 && *format == 'd'){          // %가 유효하고, 서식문자가 d 문자라면 정수를 출력하라는 이야기.
                output_int =va_arg(ap, int);                // 가변인자 목록에서 정수형 크기만큼 데이터르르 가져오라는 말.
                if (width_on){                              // 너비 플래그가 켜져 있으면 이하 실행.
                    //printf("여긴 들어오나 \n");
                    width -= intlen(output_int);            // 출력할 가변 인자의 길이를 폭에서 뺀다. 
                    if (width <= 0) width = 0;              // 길이를 뺀 값이 음수가 되어버리면 너비를 0으로 한다. 굳이 너비를 둘 필요가 없다.
                    while (width--) {                       // 너비가 양수라면 너비의 개수만큼
                        write(1, " ", 1);                   // 빈칸을 출력한다.
                    }
                }
                ft_putnbr(output_int);                      // 가변인자 목록에서 받은 정수를 출력한다. 
            }
            else if (format_on == 1 && *format == 'c') {    // %가 유효하고, 서식문자가 c라면 문자형 정수를 출력하라는 이야기.
                //printf("%%c call\n");
                output_char = va_arg(ap, int);
                if (width_on){                              // 너비 플래그가 켜져 있으면 이하 실행.
                    width -= 1;                             // 출력할 가변 인자의 길이를 폭에서 뺀다. 문자형의 경우는 자리가 1개이므로 1을 뺐다. 
                    if (width <= 0) width = 0;              // 길이를 뺀 값이 음수가 되어버리면 너비를 0으로 한다. 굳이 너비를 둘 필요가 없다.
                    while (width--) {                       // 너비가 양수라면 너비의 개수만큼
                        write(1, " ", 1);                   // 빈칸을 출력한다.
                    }
                }              
                ft_putchar(output_char);                    // 가변인자 목록에서 입력받은 문자형 정수를 출력한다.
            }
            else if (format_on == 1 && *format == 's') {    // %r가 유효하고, 서식문자가 s라면 ㅁ
                //printf("%%s call\n");
                output_str = va_arg(ap, char *);
                ft_putstr(output_str);
            }
            else if (format_on == 1 && *format == 'x') {
                //printf("%%x call\n");
                output_hex = va_arg(ap, int);
                print_hex(output_hex);
            }
            else if (format_on == 1 && *format == 'X') {
                //printf("%%X call\n");
                output_HEX = va_arg(ap, int);
                print_HEX(output_HEX);
            }
            else if (format_on == 1 && *format == 'p') {
                //printf("%%p call\n");
                output_ptr = va_arg(ap, void*);
                write(1, "0x", 2);
                print_ptr(output_ptr);
            }
            else if (format_on == 1 && *format == 'u') {
                //printf("%%u call\n");
                output_u = va_arg(ap, unsigned int);
                print_nbr_u(output_u);
            }
            // 남은 것은 i 구만
        }
        else
        {
            //printf("just_string call\n");
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
// 문자열의 길이를 반환하는 함수
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
// 정수를 입력받아 0~9와 알파벳 소문자를 사용해 16진수를 출력하는 함수.
void        print_hex(int n)
{
    if ( n >= 16 )
        print_hex(n / 16);
    write(1, &"0123456789abcdef"[n % 16], 1);
}
// 정수를 입력받아 0~9와 알파벳 대문자를 이용해 16진수를 출력하는 함수.
void        print_HEX(int n)
{
    if ( n >= 16 )
        print_hex(n / 16);
    write(1, &"0123456789ABCDEF"[n % 16], 1);
}
// 부호 없는 정수형을 입력 받아 포인터의 주소를 출력하는 함수. 
void        take_ptr(long unsigned int n) {
    if (n >= 16)
        take_ptr(n / 16);
    write(1, &"0123456789abcdef"[n % 16], 1);   //메모리 주소가 16진수로 되어있으므로 16진수로 출력한다.
}
// 포인터를 입력받아 포인터가 갖고 있는 값을 출력하는 함수.=
void        print_ptr(void *ptr)
{
    long unsigned int n = (long unsigned int)ptr;   // 데이터의 잘림 방지를 위해서 형 변환해서 long unsigned int  에 대입
    take_ptr(n);
}
// unsigned int 형을 입력받아 출력해주는 함수.
void		print_nbr_u(unsigned int n)
{
	if (n >= 10)
		print_nbr_u(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

// 부호있는 정수를 받아서 숫자의 길이를 반환하는 함수
int         intlen(int n)
{
    int len = 0;

    while (n)
    {
        n /= 10;
        len++;
    }

    return len;
}
// 부호없는 정수를 입력 받아서 숫자의 길이를 반환하는 함수
int     uintlen(unsigned int n)
{
    int len = 0;

    while (n)
    {
        n /= 10;
        len++;
    }

    return len;
}

// 숫자인지 아닌지 판별하는 함수

int         ft_isdigit(int a)
{
    if (a >= '0' && a <= '9') {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int main(){

    ft_printf("%%%d\n", 123);
    printf("%%%d\n", 123);
    ft_printf("ft_pirntf(\"%%d\", 123) = %d\n", 123);
    printf("%x\n", 16);
    ft_printf("%x\n", 16);
    printf("%X\n", 32);
    ft_printf("%X\n", 32);
    printf("%p\n", "aaa5454");
    ft_printf("%p\n", "aaa5454");
    printf("%u\n", -1);
    ft_printf("%u\n", -1);
    printf("%5d\n", 123456);
    ft_printf("%5d\n", 123456);
    printf("%5c\n", 'h');
    ft_printf("%5c\n", 'h');


    return 0;
}