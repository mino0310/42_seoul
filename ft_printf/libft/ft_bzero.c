/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 10:50:26 by minhkim           #+#    #+#             */
/*   Updated: 2021/02/07 10:56:55 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_bzero(void *b, size_t n)
{
	unsigned char	*dest;
	size_t			i;

	dest = (unsigned char *)b;
	i = 0;
	while (i++ < n)
		*dest++ = 0;
}
