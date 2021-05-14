/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 13:12:04 by minhkim           #+#    #+#             */
/*   Updated: 2021/05/11 13:12:05 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	reset_player(t_game *game)
{
	game->player.x = game->win.width / 2;
	game->player.y = game->win.height / 2;
	game->player.rot_angle = 0;
}
