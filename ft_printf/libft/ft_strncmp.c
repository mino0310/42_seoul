/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 17:23:03 by minhkim           #+#    #+#             */
/*   Updated: 2020/10/26 15:03:08 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*b1;
	unsigned char	*b2;

	b1 = (unsigned char *)s1;
	b2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while ((b1[i] != '\0') && (b2[i] != '\0') && i < (n - 1))
	{
		if (b1[i] != b2[i])
			break ;
		i++;
	}
	return (b1[i] - b2[i]);
}
