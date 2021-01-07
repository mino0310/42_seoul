#include "libft.h"
// 확장 자료형 문자를 받아서 그것의 바이트 수를 반환해주는 함수 //
int     get_atouni_width(wchar_t wc)
{
    if (wc < 0x80)
        return (1);
    else if (wc < 0x800)
        return (2);
    else if (wc < 0x10000)
        return (3);
    else
        return (4);
    
}