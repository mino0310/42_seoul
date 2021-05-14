/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_crosshair.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 13:23:12 by minhkim           #+#    #+#             */
/*   Updated: 2021/05/11 13:23:13 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	make_crosshair(t_game *game)
{
	t_pos	pos[2];
	double	centerx;
	double	centery;

	centerx = game->win.width / 2;
	centery = game->win.height / 2;
	set_pos(&pos[0], centerx - 10, centery - 1);
	set_pos(&pos[1], centerx - 4, centery + 1);
	make_rectangle(game, pos, COLOR_GREEN);
	set_pos(&pos[0], centerx + 4, centery - 1);
	set_pos(&pos[1], centerx + 10, centery + 1);
	make_rectangle(game, pos, COLOR_GREEN);
	set_pos(&pos[0], centerx - 1, centery - 10);
	set_pos(&pos[1], centerx + 1, centery - 4);
	make_rectangle(game, pos, COLOR_GREEN);
	set_pos(&pos[0], centerx - 1, centery + 4);
	set_pos(&pos[1], centerx + 1, centery + 10);
	make_rectangle(game, pos, COLOR_GREEN);
}
