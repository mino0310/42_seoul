/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 13:14:27 by minhkim           #+#    #+#             */
/*   Updated: 2021/05/11 13:14:28 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		is_option_valid(t_game *game)
{
	int		i;

	i = 0;
	while (i < 5)
	{
		if (game->map.s[i] == NULL)
			return (0);
		i++;
	}
	if (game->map.ceil == 0 || game->map.floor == 0)
		return (0);
	return (1);
}

int		is_map_element(char c)
{
	if (c == 1 || c == 0 || c == ' '
			|| c == 'N' || c == 'S' || c == 'W'
			|| c == 'E' || c == 2)
		return (1);
	return (0);
}

int		is_map_position(char c)
{
	if (c == 'N' || c == 'S' || c == 'W'
			|| c == 'E')
		return (1);
	return (0);
}
