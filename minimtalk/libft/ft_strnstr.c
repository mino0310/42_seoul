/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 17:17:41 by minhkim           #+#    #+#             */
/*   Updated: 2021/08/29 15:51:59 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *b, const char *s, size_t l)
{
	size_t	s_len;
	size_t	b_len;
	size_t	size;

	if (*s == '\0')
		return ((char *)b);
	s_len = ft_strlen(s);
	b_len = ft_strlen(b);
	if (b_len < s_len || l < s_len)
		return (0);
	if (b_len > l)
		size = l;
	else
		size = b_len;
	while (size-- >= s_len)
	{
		if (ft_memcmp(b, s, s_len) == 0)
			return ((char *)b);
		b++;
	}
	return (0);
}
