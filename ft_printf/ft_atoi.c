#include "libft.h"
// 문자열 알파벳을 정수로 바꾸어주는 함수
int         ft_atoi(char *str)
{
    int return_val;    // 반환값
    int sign;       // 부호값

    sign = 1;
    return_val = 0;
    while (*str == '-' || *str == '+')
    {
        sign = (*str == '-') ? -sign : sign;
        str++;
    }
    if (!is_in_set(*str, DIGIT))
    {
        return (0);
    }
    while (*str >= '0' && *str <= '9')
    {
        return_val = return_val * 10 + (*str - '0');
        str++;
    }
    return (return_val * sign);
}