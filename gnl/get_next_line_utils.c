/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 16:06:54 by minhkim           #+#    #+#             */
/*   Updated: 2020/11/19 17:32:50 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char				*ft_strchr(const char *s, int c)
{
	char			find;

	find = (char)c;
	while (*s)
	{
		if (*s == find)
			return ((char *)s);
		s++;
	}
	if (*s == find)
		return ((char *)s);
	return (0);
}

size_t				ft_strlen(const char *s)
{
	int				len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

char				*ft_strndup(const char *str, size_t size)
{
	size_t			i;
	char			*new_str;

	if (!(new_str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size && str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

size_t				ft_strlcpy(char *dest, char const *src, size_t size)
{
	size_t			i;

	i = 0;
	while (i < size - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (i < size)
		dest[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

char				*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	int				s1_len;
	int				s2_len;

	if (!s2 && !s2)
		return (NULL);
	else if (!(s1) || !(s2))
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (NULL);
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcpy(str + s1_len, s2, s2_len + 1);
	return (str);
}
