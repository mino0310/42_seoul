#include "ft_printf.h"

static int      write_on_condition(char *form, va_list ap, t_tag *tag)
{
    if (*form == 'c')
        return (pre_process_char(ap, tag));
    else if (*form == 's')
        return (pre_process_string(ap, tag));
    else if (*form == 'd' || *form == 'i')
        return (pre_process_int(ap, tag));
    else if (*form == 'u')
        return (pre_process_unsigned_int(ap, tag));
    else if (*form == 'x')
        return (pre_process_hexa(ap, tag, HEX_LOW, 'x'));
    else if (*form == 'X')
        return (pre_process_hexa(ap, tag, HEX_HIGH, 'X'));
    else if (*form == 'p')
        return (print_pointer(ap, tag));
    else if (*form == 'n')
        return (store_nbyte(ap, tag));
    else
        return (ERROR);
}

