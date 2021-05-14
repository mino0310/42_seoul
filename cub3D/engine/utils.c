/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 13:13:58 by minhkim           #+#    #+#             */
/*   Updated: 2021/05/11 13:14:00 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	arg_parse(t_game *game, int argc, char **argv)
{
	int		i;

	if (argc == 1)
		return ;
	game->map.name = argv[1];
	game->flags.save = 0;
	game->flags.debug = 0;
	i = 2;
	while (i < argc)
	{
		if (!ft_strncmp(argv[i], "--save", 6))
			game->flags.save = 1;
		else if (!ft_strncmp(argv[i], "--debug", 7))
			game->flags.debug = 1;
		i++;
	}
}

void	error_exit(t_game *game, int code, char *message)
{
	printf("ERROR\n");
	printf("%s\n", message);
	free(game);
	exit(code);
}

void	specify_angle(double *angle)
{
	if (*angle < 0)
		*angle += 360;
	else if (*angle > 360)
		*angle -= 360;
}

void	specify_radian(double *radian)
{
	if (*radian < 0)
		*radian += 2 * M_PI;
	else if (*radian > 2 * M_PI)
		*radian -= 2 * M_PI;
}
