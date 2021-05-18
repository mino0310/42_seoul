/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:35:01 by minhkim           #+#    #+#             */
/*   Updated: 2020/11/29 15:16:00 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int				read_line(char **line, char **backup, char *newline_ptr)
{
	char				*tmp;

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

int						get_next_line(int fd, char **line)
{
	static char			*backup[OPEN_MAX];
	char				*buf;
	char				*newline_ptr;
	char				*tmp_ptr;
	int					byte;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || fd > OPEN_MAX ||
			!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
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
	free(buf);
	if (byte < 0)
		return (-1);
	return (read_line(line, &backup[fd], newline_ptr));
}
