/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 13:16:27 by minhkim           #+#    #+#             */
/*   Updated: 2021/05/11 13:16:28 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	to_radian(double x)
{
	return (M_PI / 180 * x);
}

double	to_degree(double x)
{
	return (x * 180 / M_PI);
}

void	show_map(t_game *game)
{
	int		i;
	int		j;

	printf("-----mapstart-----\n");
	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.columns)
		{
			printf("%d", g_my_map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("-----mapend-----\n");
}

int		check_sprite(t_game *game, double x, double y)
{
	int		coord_x;
	int		coord_y;

	coord_x = floor(x / game->common_tsize);
	coord_y = floor(y / game->common_tsize);
	if (coord_x < 0)
		coord_x = 0;
	if (coord_y < 0)
		coord_y = 0;
	if (coord_x > game->map.columns - 1)
		coord_x = game->map.columns - 1;
	if (coord_y > game->map.rows - 1)
		coord_y = game->map.rows - 1;
	if (g_my_map[coord_y][coord_x] == 2)
		return (1);
	return (0);
}
