/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 13:08:42 by minhkim           #+#    #+#             */
/*   Updated: 2021/05/11 13:08:44 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_splited(char ***splited)
{
	int		i;

	i = 0;
	while ((*splited)[i])
	{
		if ((*splited)[i])
			free((*splited)[i]);
		(*splited)[i] = NULL;
		i++;
	}
	if (*splited)
		free(*splited);
	*splited = NULL;
}

void	free_line(char **line)
{
	if (*line)
		free(*line);
	*line = NULL;
}
