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
    int zero_flag = 0;      // 0 플래그
    int minus_flag = 0;     // 마이너스 플래그 왼쪽 정렬하는 플래그.

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
            // 너비를 제외한 다른 플래그를 켜는 단계. 너비에서 포인터 연산을 하므로 여기에서 다른 플래그를 처리할 필요가 있음.
            if (format_on == 1 && *format == '0')           // %가 유효하고 다음 서식문자열의 문자가 0일 경우 == 0 플래그가 있다는 말.
            {
                zero_flag = 1;                              // 제로 플래그를 켜준다.
                format++;                                   // 다음 서식 문자열을 검색할 수 있도록 증가 연산을 해준다.
            }
            // 마이너스 (왼쪽정렬) 플래그를 켜는 단계
            if (format_on == 1 && *format == '-')
            {
                minus_flag = 1;
                format++;
                printf("on!!\n");
            }
            // 이제 본격적으로 서식 문자를 찾아서 출력해주는 부분.
            // ㅌ비를 구하고 너비 플래그를 켜는 단계
            if (format_on == 1 && ft_isdigit(*format)){     // %가 유효하고, 서식문자가 숫자를 나타내는 문자라면 (너비 파악)
                if (ft_isdigit(*(format + 1)))              // 너비가 2자리 수이면 이리로 들어온다. 너비는 99까지 하기로 했으니 이것이 한계. 
                {
                    width = (*format - '0') * 10 + (*(format + 1) - '0'); // 너비의 정수값을 구한다.
                    width_on = 1;                           // 2자리수 너비가 들어왔으므로 너비 플래그를 켠다.
                    format += 2;                            // 포인터를 두칸 이동시켜서 다음문자가 있는지 체크.
                }
                else
                {
                    width = *format++ - '0';                // 서식문자에 나와있는 숫자문자를 숫자로 만들어서 너비로 지정 -> 서식문자 포인터 다음 것 가리키게. 
                    width_on = 1;
                }
            }
            if (format_on == 1 && (*format == 'd' || *format == 'i')) {          // %가 유효하고, 서식문자가 d 문자라면 정수를 출력하라는 이야기.
                output_int =va_arg(ap, int);                // 가변인자 목록에서 정수형 크기만큼 데이터르르 가져오라는 말.
                if (width_on){                              // 너비 플래그가 켜져 있으면 이하 실행.
                    width -= intlen(output_int);            // 출력할 가변 인자의 길이를 폭에서 뺀다. 
                    if (width <= 0) width = 0;              // 길이를 뺀 값이 음수가 되어버리면 너비를 0으로 한다. 굳이 너비를 둘 필요가 없다.
                    if (minus_flag)
                    {
                        ft_putnbr(output_int);
                        if (zero_flag)                          // 제로 플래그가 켜져 있으면
                        {
                            while (width--)
                            {
                                write(1, "0", 1);               // 출력해야할 문자를 제외한 나머지 너비만큼 0을 채운다.
                            }
                        }
                        else 
                        {
                            while (width--) {                   // 너비가 양수라면 너비의 개수만큼
                            write(1, " ", 1);                   // 출력해야할 문자를 제외한 나머지 너비만큼 빈칸을 채운다.
                            }
                        }
                    }
                    else
                    {
                        if (zero_flag)                          // 제로 플래그가 켜져 있으면
                        {
                            while (width--)
                            {
                                write(1, "0", 1);               // 출력해야할 문자를 제외한 나머지 너비만큼 0을 채운다.
                            }
                        }
                        else 
                        {
                            while (width--) {                   // 너비가 양수라면 너비의 개수만큼
                            write(1, " ", 1);                   // 출력해야할 문자를 제외한 나머지 너비만큼 빈칸을 채운다.
                            }
                        }
                        ft_putnbr(output_int);
                    }
                }
            }
            
            else if (format_on == 1 && *format == 'c') {    // %가 유효하고, 서식문자가 c라면 문자형 정수를 출력하라는 이야기.
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
            else if (format_on == 1 && *format == 's') {    // %가 유효하고, 서식문자가 s라면 문자열을 출력하라는 이야기
                //printf("%%s call\n");                     
                output_str = va_arg(ap, char *);            // 문자 포인터 크기 만큼 변수를 가져온다.
                if (width_on){                              // 너비 플래그가 켜져 있으면 이하 실행.
                    width -= ft_strlen(output_str);         // 출력할 가변 인자의 길이를 폭에서 뺀다. 문자형의 경우는 자리가 1개이므로 1을 뺐다. 
                    if (width <= 0) width = 0;              // 길이를 뺀 값이 음수가 되어버리면 너비를 0으로 한다. 굳이 너비를 둘 필요가 없다.
                    while (width--) {                       // 너비가 양수라면 너비의 개수만큼
                        write(1, " ", 1);                   // 빈칸을 출력한다.
                    }
                }         
                ft_putstr(output_str);                      // 문자열을 출력한다.
            }
            else if (format_on == 1 && *format == 'x') {    // %가 유효하고, 서식문자가 x라면 16진수를 소문자로 출력하라는 이야기
                //printf("%%x call\n");
                output_hex = va_arg(ap, int);               // int 자료형 크기만큼 가변인자목록에서 가져온다.
                print_hex(output_hex);                      // 가져온 변수를 16진수 소문자 표기법으로 출력한다. 
            }
            else if (format_on == 1 && *format == 'X') {    // %가 유효하고, 서식문자가 X라면 16진수를 대문자로 출력하라는 이야기
                //printf("%%X call\n");         
                output_HEX = va_arg(ap, int);               // int 자료형 크기만큼 가변인자목록에서 가져온다.
                print_HEX(output_HEX);                      // 가져온 변수를 16진수 대문자 표기법으로 출력한다.
            }
            else if (format_on == 1 && *format == 'p') {    // %가 유효하고, 서식문자가 p라면 해당 변수가 갖고 있는 값은 16진수로 출력하라는 이야기. 
                //printf("%%p call\n");
                output_ptr = va_arg(ap, void*);             // 포인터 자료형 크기만큼 가변인자목록에서 가져온다.
                write(1, "0x", 2);                          // 앞에 출력할 0x를 적는다.
                print_ptr(output_ptr);                      // 가져온 변수를 16진수 표기법으로 출력한다.
            }
            else if (format_on == 1 && *format == 'u') {
                //printf("%%u call\n");
                output_u = va_arg(ap, unsigned int);
                print_nbr_u(output_u);
            }
            // 남은 것은 i 구만
        }
        else                                                // 어디에도 해당되지 않는다면 서식문자 없이 문자열만 들어왔다는 소리
        {
            write(1, just_string, 1);                       // 들어온 문자를 출력한다.
            //just_string++;                                // 문자열 전진 리팩토링 과정에서 보니 없어도 상관없었음.
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
    printf("%15c\n", 'h');
    ft_printf("%15c\n", 'h');
    printf("just string\n");
    ft_printf("just string\n");
    printf("%11s", "cg\n");
    ft_printf("%11s", "cg\n");
    printf("%i\n", 0x55);
    printf("%d\n", 0x55);
    ft_printf("%d\n", 055);
    ft_printf("%i\n", 055);
    printf("%010d\n", 123);
    ft_printf("%010d\n", 123);
    printf("%-5d\n", 123);
    ft_printf("%-5d\n", 123);

    return 0;
}

// 그냥 %가 하나만 들어있는지 확인하는 함수 1개, 각 서식 문자가 1개만 들어있는지 확인하는 함수 한개씩 이렇게 구성하는 게 낫지 않나?
// 그렇게 해서 함수를 중첩으로 선언하는 편이 나아보이는데
// 우선 이렇게라도 구현을 해보자 
// 1.24 두자리 너비 구현완료
// 1.26 i 구현 완료, 0 구현 완료, 
// to do. '.*' 플래그 관리  ... 최소 필드 너비 관리
//리팩토링에 대한 생각. 필드 너비, 각종 플래그 등 다양한 자료들을 여러번 반복적으로 체크해야 하는 번거로움이 있음. 다양한 자료형을 다루니 배열보단 구조체로 정리해서
// 사용하는 것이 코드의 가독성, 간결성 측면에서 좋다고 생각. 여러 군데서 사용할 수 있으니 전역으로 선언하는 편이 낫지 않나. 
// 오늘은 여기까지.