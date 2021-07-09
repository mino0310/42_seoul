/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 13:41:14 by minhkim           #+#    #+#             */
/*   Updated: 2021/07/09 13:42:39 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sort_check_a(t_struct *head_a)
{
	t_struct	*temp;
	int			n;

	temp = head_a->next;
	while (temp->next != NULL)
	{
		n = temp->value;
		if (temp->next != NULL && n > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	sort_check_b(t_struct *head_b)
{
	t_struct	*temp;
	int			n;

	temp = head_b->next;
	while (temp->next != NULL)
	{
		n = temp->value;
		if (temp->next != NULL && n < temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	already_sort(t_struct *head)
{
	t_struct	*temp;
	int			n;

	temp = head->next;
	while (temp->next != NULL)
	{
		n = temp->value;
		if (temp->next != NULL && n > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}
