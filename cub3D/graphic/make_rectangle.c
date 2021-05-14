/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_rectangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 13:27:17 by minhkim           #+#    #+#             */
/*   Updated: 2021/05/11 13:27:18 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	make_rectangle(t_game *game, t_pos pos[2], int color)
{
	double	movex;

	while (pos[0].y < pos[1].y)
	{
		movex = pos[0].x;
		while (movex < pos[1].x)
		{
			game->img.data[to_coord(game, movex, pos[0].y)] = color;
			movex += 1;
		}
		pos[0].y += 1;
	}
}
