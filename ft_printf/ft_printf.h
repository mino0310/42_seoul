/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 10:56:05 by minhkim           #+#    #+#             */
/*   Updated: 2021/02/21 11:28:26 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
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
void				init_flag(t_info *flag_struct);
int					ft_nbrlen(unsigned long long nbr, t_info *flag_struct);
char				*ft_baseset(char type);
int					print_space_or_zero(int width, int str_len, int zero_flag);
int					print_char(int c, t_info *flag_struct);
char				*parse_buf(char *str, int prec, int str_len);
int					fill_space_or_zero(char **buf, t_info *flag_struct);
int					print_string(char *str, t_info *flag_struct);
int					write_nbr_by_prec(unsigned long long nbr,
		t_info *flag_struct, char **buf);
int					join_minus(t_info *flag_struct, char **buf);
int					join_hexa_prefix(char **buf);
int					join_minus2(int buf_len, t_info *flag_struct, char **buf);
int					print_nbr(unsigned long long nbr, t_info *flag_struct);
void				fill_width_or_prec(va_list ap, char *format,
		t_info *flag_struct, int format_index);
void				fill_flag(va_list ap, char *format,
		t_info *flag_struct, int format_index);
int					print_by_type(va_list ap, t_info *flag_struct);
int					parse_format(va_list ap, char *format);
int					ft_isdigit(int c);

#endif
