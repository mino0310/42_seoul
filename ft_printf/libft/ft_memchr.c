/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:46:56 by minhkim           #+#    #+#             */
/*   Updated: 2020/10/15 13:23:52 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *b, int c, size_t n)
{
	unsigned char	*new_b;
	unsigned char	find;

	new_b = (unsigned char *)b;
	find = c;
	while (n--)
	{
		if (*new_b++ == find)
			return ((void *)(new_b - 1));
	}
	return (0);
}
