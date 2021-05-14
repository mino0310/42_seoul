/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 13:13:46 by minhkim           #+#    #+#             */
/*   Updated: 2021/05/11 13:13:48 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		shading(double distance, int color)
{
	double	divide;

	divide = distance / 50;
	if (divide <= 1.)
		return (color);
	return (((int)(((0xFF0000 & color) >> 16) / divide) << 16)
		+ ((int)(((0x00FF00 & color) >> 8) / divide) << 8)
		+ ((int)((0x0000FF & color) / divide)));
}
