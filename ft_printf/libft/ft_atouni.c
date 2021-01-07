#include "libft.h"

char        *ft_atouni(wchar_t w)
{
    int         n;
    int         i;
    char        *utf;
    int         utf_frame;

    n = get_atouni_width(w);
    if ((utf = malloc(n + 1)) == NULL)
        return (NULL);
    utf[n] = '\0';
    n == 1 ? utf[0] == w : 0;
    if (n == 1)
        return (utf);
    // 여기까지 왔다는 건 바이트가 2개 이상이라는 이야기
    i = 0;
    utf_frame = 0b10000000;
    while (0 <= n - 1 - i)
    {
        // 확장 문자형을 0b00111111 과 논리곱연산: 110 을 날려버리고 숫자만 남긴다
        // 그 다음에 0b10000000 과 논리합연산: 최상위비트를 1로 둬서 1바이트로 문자표시
        utf[n - 1 - i] = ((w >> (6 * i)) & 0b00111111) | utf_frame;
        i++;
    }
    while (n-- > 1)
    {
        utf_frame = utf_frame >> 1 | 0b10000000;
        utf[0] = utf[0] | utf_frame;
    }
    return (utf);
}