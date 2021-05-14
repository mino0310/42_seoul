/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 13:06:53 by minhkim           #+#    #+#             */
/*   Updated: 2021/05/11 13:06:56 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GET_NEXT_LINE_H
# define __GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*ft_strndup(char *src, int size);
void	ft_src_set(char **src, int temp);
int		ft_has_new_line(char *src);
int		ft_get_next_size(char *src);
void	ft_strcat(char **src, char *buf, int bufsize, int srcsize);
int		ft_reading(int fd, char **src);
int		get_next_line(int fd, char **line);
int		ft_strlen_gnl(char *s);

#endif
