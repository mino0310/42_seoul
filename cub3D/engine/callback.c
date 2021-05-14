/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 13:14:35 by minhkim           #+#    #+#             */
/*   Updated: 2021/05/11 13:14:35 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		exit_callback(t_game *game)
{
	free(game);
	exit(0);
}

int		key_press_callback(int keycode, t_game *game)
{
	if (keycode >= 300)
		return (-1);
	game->key_check[keycode] = 1;
	if (keycode == KEY_ESCAPE)
		exit(0);
	return (0);
}

int		key_release_callback(int keycode, t_game *game)
{
	if (keycode >= 300)
		return (-1);
	game->key_check[keycode] = 0;
	return (0);
}
