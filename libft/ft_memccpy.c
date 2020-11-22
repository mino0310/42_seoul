/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:13:29 by minhkim           #+#    #+#             */
/*   Updated: 2020/10/15 16:53:45 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*n_dest;
	unsigned char	*n_src;
	unsigned char	find;
	size_t			i;

	n_dest = (unsigned char *)dest;
	n_src = (unsigned char *)src;
	find = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		n_dest[i] = n_src[i];
		if (n_src[i] == find)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
