/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 12:35:19 by minhkim           #+#    #+#             */
/*   Updated: 2021/08/29 15:48:16 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *l, void *(*f)(void *), void (*d)(void *))
{
	t_list		*result;
	t_list		*temp;

	if (l == NULL || f == NULL)
		return (NULL);
	result = NULL;
	while (l)
	{
		temp = ft_listnew(f(l->content));
		if (!temp)
		{
			ft_lstclear(&result, d);
			return (NULL);
		}
		ft_lstadd_back(&result, temp);
		lst = lst->next;
	}
	return (result);
}
