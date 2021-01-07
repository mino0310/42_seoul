#include "ft_printf.h"

int     pre_process_char(va_list ap, t_tag *tag)
{
    wint_t      w;
    char        *res;
    char        c;

    if (tag->len_mod == DISABLED)
    {
        c = (char)va_arg(ap, int);
        return (print_char(tag, c));
    }

}