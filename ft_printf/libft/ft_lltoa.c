#include "libft.h"

char    *ft_lltoa(long long n)
{
    long long       div;
    int             len;
    char            *res;

    div = n;
    len = (n <= 0) ? 1 : 0;
    while (div != 0)
    {
        div /= 10;
        len++;
    }
    if (!(res = malloc(sizeof(char) * (len + 1))))
        return (0);
    res[len] = '\0';
    if (n <= 0)
        res[0] = (n == 0) ? '0' : '-';
    while (n != 0)
    {
        len--;
        res[len] = (n > 0) ? (n % 10) + '0' : -(n % 10) + '0';
        n /= 10;
    }
    return (res);
}