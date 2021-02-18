/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:45:41 by minhkim           #+#    #+#             */
/*   Updated: 2021/02/18 20:41:20 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#define TYPE "csdiupxX%"

typedef struct		s_info
{
    int				minus;
    int				zero;
    int				width;
    int				prec;
    char			type;
    int				nbr_base;
    int				nbr_sign;
}					t_info;

void				init_flag(t_info *flag_struct)
{
	flag_struct->minus = 0;
	flag_struct->zero = 0;
	flag_struct->width = 0;
	flag_struct->prec = -1;
	flag_struct->type = 0;
	flag_struct->nbr_base = 10;
	flag_struct->nbr_sign = 1;
}

int					ft_nbrlen(unsigned long long nbr, t_info *flag_struct)
{
	int				i;

	if (nbr == 0 && flag_struct->prec != 0) // 0 이면 잘리니까.
		return (1);
	i = 0;
	while (nbr)
	{
		i++;
		nbr /= flag_struct->nbr_base;
	}
	return (i);
}

char				*ft_baseset(char type)
{
	if (type == 'u' || type == 'd' || type == 'i')
		return ("0123456789");
	else if (type == 'x' || type == 'p')
		return ("0123456789abcdef");
	else if (type == 'X')
		return ("0123456789ABCDEF");
	return (0);
}

size_t				ft_strlen(const char *s)
{
	size_t			i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int					ft_putchar(char c)
{
	return (write(1, &c, 1));
}

char				ft_strchr(const char *s, int c)
{
	char			find;
	size_t			i;

	find = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == find)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == find)
		return ((char *)s + i);
	return (0);
}

int					ft_putstr(char *s)
{
	int				i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

char				*ft_strjoin(char *s1, char *s2, int free_target)
{
	char			*result;
	int				i;
	int				j;
	int				s1_len;
	int				s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (0);
	i = -1;
	while (++i < s1_len)
		result[i] = s[i];
	if (free_target == 1 || free_target == 3)
		free(s1);
	j = 0;
	while (j < s2_len)
		result[i++] = s2[j++];
	if (free_target == 2 || free_target == 3)
		free(s2);
	result[i] = 0;
	return (result);
}

int					print_space_or_zero(int width, int str_len, int zero_flag)
{
	int				print_len;

	print_len = 0;
	while (str_len < width)
	{
		if (zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		print_len++;
		str_len++;
	}
	return (print_len);
}

int					print_char(int c, t_info *flag_struct)
{
	int				print_len;

	print_len = 0;
	if (flag_struct->type == '%' && flag_struct->minus == 1)
		info->zero = 0;
	if (flag_struct->minus == 1)
		print_len += ft_putchar(c);
	print_len += print_space_or_zero(flag_struct->width, 1, flag_struct->zero);
}

char				*parse_buf(char *str, int prec, int str_len)
{
	int				index;
	char			*buf;

	prec = prec < str_len ? prec : str_len;
	if (!(buf = (char *)malloc(sizeof(char) * prec + 1)))
		return (NULL);
	index = 0;
	while (index < prec)
	{
		buf[index] = str[index];
		index++;
	}
	buf[index] = '\0';
	return (buf);
}

int					fill_space_or_zero(char **buf, t_info *flag_struct)
{
	char			*flag_buf;
	int				i;

	if (flag_struct->width <= (int)ft_strlen(*buf))
		return ((int)ft_strlen(*buf));
	flag_buf = (char *)malloc(sizeof(char) *
			(flag_struct->width - ft_strlen(*buf) + 1));
	i = 0;
	while ((size_t)i < flag_struct->width - ft_strlen(*buf))
	{
		flag_buf[i] = (flag_struct->zero == 1) ? '0' : ' ';
		i++;
	}
	flag_buf[i] = '\0';
	if (flag_struct->minus == 0)
		*buf = ft_strjoin(flag_buf, *buf, 3);
	else
		*buf = ft_strjoin(*buf, flag_buf, 3);
	return (flag_buf->width);
	
}

int					print_string(char *str, t_info *flag_struct)
{
	int				print_len;
	char			*print_buf;

	print_len = 0;
	if (str == NULL)
		str = "(null)";
	if (flag_struct->prec == -1 ||
			(size_t)flag_struct->prec > ft_strlen(str))
		flag_struct->prec = ft_strlen(str);
	print_buf = parse_buf(str, flag_struct->prec, ft_strlen(str));
	print_len = fill_space_or_zero(char *str, t_info *flag_struct);
	ft_putstr(print_buf);
	free(buf);
	return (print_len);
}

int					write_nbr_by_prec(unsigned long long nbr,
		t_info *flag_struct, char **buf)
{
	int				nbr_len;
	int				buf_len;
	int				i;

	nbr_len = ft_nbrlen(nbr, flag_struct);
	buf_len = (flag_struct->prec > nbr_len) ?
		flag_struct->prec : nbr_len;
	if (!(*buf = (char *)malloc(sizeof(char) * buf_len + 1)))
		return (0);
	i = 0;
	(*buf)[buf_len] = '\0';
	while (i < buf_len - nbr_len)
	{
		(*buf)[i] = '0';
		i++;
	}
	i = 1;
	if (nbr == 0 && flag_struct->prec != 0)
		(*buf)[buf_len - i] = '0';
	while (nbr)
	{
		(*buf)[buf_len - i] = ft_baseset(flag_struct->type)[nbr %
			flag_struct->nbr_base];
		nbr /= flag_struct->nbr_base;
		i++;
	}
	return (nbr_len);
}

int					join_minus(t_info *flag_struct, char **buf)
{
	int				len_to_print;

	len_to_print = 0;
	if ((flag_struct->type == 'i' || flag_struct->type == 'd') &&
			flag_struct->zero == 0 && flag_struct->nbr_sign == -1)
	{
		*buf = ft_strjoin("-", *buf, 2);
		len_to_print = 1;
	}
	return (len_to_print);
}

int					join_hexa_prefix(char **buf)
{
	*buf = ft_strjoin("0x", *buf, 2);
	return (ft_strlen(*buf));
}

int					join_minus2(int buf_len, t_info *flag_struct, char **buf)
{
	int				len_to_print;

	len_to_print = 0;
	if (flag_struct->nbr_sign == -1 && flag_struct->zero == 1)
	{
		if (buf_len >= flag_struct->width)
		{
			*buf = ft_strjoin("-", *buf, 2);
			len_to_print = 1;
		}
		else if (buf_len < flag_struct->width)
			*buf[0] = '-';
	}
	return (len_to_print);
}

int					print_nbr(unsigned long long nbr, t_info *flag_struct)
{
	char			*buf;
	int				buf_len;
	int				print_len;

	if (flag_struct->type == 'x' || flag_struct->type == 'X' ||
			flag_struct->type == 'p')
		flag_struct->nbr_base = 16;
	if ((flag_struct->type == 'd' || flag_struct->type == 'i') &&
			(int)nbr < 0)
	{
		flag_struct->nbr_sign = -1;
		nbr = -nbr;
	}
	buf_len = write_nbr_by_prec(nbr, flag_struct, &buf);
	buf_len += join_minus(flag_struct, &buf);
	if (flag_struct->type == 'p')
		buf_len = join_hexa_prefix(&buf, flag_struct);
	print_len = fill_space_or_zero(&buf, flag_struct);
	print_len += join_minus2(buf_len, flag_struct, &buf);
	ft_putstr(buf);
	free(buf);
	return (print_len);
}



void				fill_width_or_prec(va_list ap, char *format,
		t_info *flag_struct, int format_index)
{
	if (ft_isdigit(format[i]))
	{
		if (flag_struct->prec == -1)
			flag_struct->width = flag_struct->width * 10 + format[i] - 48;
		else
			flag_struct->prec = flag_struct->prec * 10 + format[i] - 48;
	}
	else if (format[i] == '*')
	{
		if (flag_struct->prec == -1) 
		{
			flag_struct->width = va_arg(ap, int);
			if (flag_struct->width < 0)
			{
				flag_struct->minus = 1;
				flag_struct->width *= -1;
			}
		}
		else
			flag_struct->prec = va_arg(ap, int):
	}
}

void				fill_flag(va_list ap, char *format, t_info *flag_struct, int format_index)
{
	if (format[format_index] == '0' && flag_struct->width == 0 &&
			flag_struct->prec == -1)
		flag_struct->zero = 1;
	else if (format[format_index] == '-')
		flag_struct->minus = 1;
	else if (format[format_index] == '.')
		flag_struct->prec = 0;
	else if (ft_isdigit(format[i]) || format[i] == '*')
		fill_width_or_prec(ap, format, flag_struct, format_index);
}

int					print_by_type(va_list ap, t_info *flag_struct)
{
	int				print_len;
	char			type;

	print_len = 0;
	type = flag_struct->type;
	if (type == 'c')
		print_len = print_char(va_arg(ap, int), flag_struct);
	else if (type == '%')
		print_len = print_char('%', flag_struct);
	else if (type == 's')
		print_len = print_string(va_arg(ap, char *), flag_struct);
	else if (type == 'd' || type == 'i')
		print_len = print_nbr(va_arg(ap, int), flag_struct);
	else if (type == 'x' || type == 'X' || type == 'u')
		print_len = print_nbr(va_arg(ap, unsigned int), flag_struct);
	else if (type == 'p')
		print_len = print_nbr(va_arg(ap, unsigned long long), flag_struct);
	return (print_len);
}


int parse_format(va_list ap, char *format) 
{
    int i;
    int print_len;
    t_info *flag_struct;

    i = 0;
    print_len = 0;
    if(!(flag_struct = malloc(sizeof(t_info))))
        return (-1);
    while (format[i] != '\0') {
        while (format[i] != '%' && format[i] != '\0')
			print_len += ft_putchar(format[i++]);
		if (format[i] == '%')
		{
			init_flag(flag_struct);
			while (format[++i] != '\0' && !(ft_strchr(TYPE, format[i])))
				fill_flag(ap, format, flag_struct, i);
			flag_struct->type = format[i++];
			if ((flag_struct->minus == 1 || flag_struct->prec > -1) && flag_struct->type != '%')
					flag_struct->zero = 0; // prec > -1 일 경우엔 빈칸이 출력되는데?
			print_len += print_by_type(ap, flag_struct);
		}
    }
	free(flag_struct);
	return (print_len);
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
