/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 16:19:23 by minhkim           #+#    #+#             */
/*   Updated: 2020/11/29 18:49:11 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			read_line(char **line, char **backup, char *newline_ptr)
{
	char			*tmp;

	if (newline_ptr)
	{
		*line = ft_strndup(*backup, newline_ptr - *backup);
		tmp = ft_strndup(newline_ptr + 1, ft_strlen(newline_ptr + 1));
		free(*backup);
		*backup = tmp;
		return (1);
	}
	if (*backup)
	{
		*line = *backup;
		*backup = NULL;
	}
	else
		*line = ft_strndup("", 1);
	return (0);
}

int					get_next_line(int fd, char **line)
{
	static char		*backup[OPEN_MAX];
	char			buf[BUFFER_SIZE + 1];
	char			*newline_ptr;
	char			*tmp_ptr;
	int				byte;

	byte = 0;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!backup[fd])
		backup[fd] = ft_strndup("", 1);
	while (!(newline_ptr = ft_strchr(backup[fd], '\n'))
			&& (byte = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[byte] = '\0';
		tmp_ptr = ft_strjoin(backup[fd], buf);
		if (backup[fd])
			free(backup[fd]);
		backup[fd] = tmp_ptr;
	}
	if (byte < 0)
		return (-1);
	return (read_line(line, &backup[fd], newline_ptr));
}
