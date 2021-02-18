#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#define TYPE "csdiupxX%"

typedef struct s_info
{
    int minus;
    int zero;
    int width;
    int prec;
    char type;
    int nbr_base;
    int nbr_sign;
}   t_info;

int parse_format(va_list ap, char *format) 
{
    int i;
    int print_len;
    t_info *info;

    i = 0;
    print_len = 0;
    if(!(info = malloc(sizeof(t_info))))
        return (-1);
    while (format[i] != '\0') {
        
    } 
    
}



int ft_printf(const char *format, ...)
{
    int print_len;
    va_list ap;

    va_start(ap, format);
    print_len = parse_format(ap, (char *)format);
    va_end(ap);
    return (print_len);
}