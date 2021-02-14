/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 12:27:41 by minhkim           #+#    #+#             */
/*   Updated: 2021/02/13 16:45:18 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

# define TYPE "csdiupxX%"

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

int					ft_printf(const char *format, ...);
int					parse_format(va_list ap, char *format);
void				check_info(va_list ap, char *format,
		t_info *info, int i);
void				check_width_and_prec(va_list ap, char *format,
		t_info *info, int i);
int					print_by_type(va_list ap, t_info *info);
int					print_char(int c, t_info *info);
int					write_width_by_flag(int width, int len, int zero_flag);
int					print_string(char *str, t_info *info);
char				*parse_buf(char *str, int end, int len);
int					fill_padding_by_flag(char **buf, t_info *info);
int					print_nbr(unsigned long long nbr, t_info *info);
int					put_prec_str(unsigned long long nbr,
		t_info *info, char **buf);
int					put_minus(t_info *info, char **buf);
int					put_minus2(int buf_len, t_info *info, char **buf);
int					join_hexa_prefix(char **buf);
void				init_info(t_info *info);
int					ft_nbrlen(unsigned long long nbr, t_info *info);
char				*ft_baseset(char type);

#endif
