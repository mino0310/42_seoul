/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 19:58:11 by minhkim           #+#    #+#             */
/*   Updated: 2021/06/26 20:22:34 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int					sorted_check_a(t_stack **a, int len)
{
	t_stack			*idx;
	int				low;
	int				i;

	idx = (*a)->next;
	low = (*a)->n;
	i = 0;
	if (idx == NULL)
		return (1);
	while (idx != NULL && i < len)
	{
		if (low < idx->n)
			low = idx->n;
		else
			return (0);
		idx = idx->next;
		i++;
	}
	return (1);
}

int					sorted_check_b(t_stack **b, int len)
{
	t_stack			*idx;
	int				high;
	int				i;

	idx = (*b)->next;
	high = (*b)->n;
	i = 0;
	if (idx == NULL)
		return (1);
	while (idx != NULL && i < len)
	{
		if (high > idx->n)
			high = idx->n;
		else
			return (0);
		idx = idx->next;
		i++;
	}
	return (1);
}
