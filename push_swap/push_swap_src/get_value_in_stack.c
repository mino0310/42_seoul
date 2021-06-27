/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_in_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 14:26:40 by minhkim           #+#    #+#             */
/*   Updated: 2021/06/27 14:39:26 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int					*get_stack_array(t_stack **head, int num)
{
	int				i;
	int				*sort;
	t_stack			*count;

	if (!(sort = (int *)malloc(sizeof(int) * num)))
		return (NULL);
	i = 0;
	count = *head;
	while (i < num)
	{
		sort[i] = count->n;
		count = count->next;
		i++;
	}
	return (sort);
}

int					get_mid_value(t_stack **head, int len)
{
	int				*sort;
	int				mid_value;

	sort = get_stack_array(head, len);
	quick_sort(sort, 0, len - 1);
	mid_value = sort[len / 2];
	free(sort);
	return (mid_value);
}

int					get_min_value(t_stack **head, int len)
{
	int				*sort;
	int				min_value;

	sort = get_stack_array(head, len);
	quick_sort(sort, 0, len - 1);
	min_value = sort[0];
	free(sort);
	return (min_value);
}

int					get_max_value(t_stack **head, int len)
{
	int				*sort;
	int				max_value;

	sort = get_stack_array(head, len);
	quick_sort(sort, 0, len - 1);
	max_value = sort[len - 1];
	free(sort);
	return (max_value);
}

int					get_value_index(t_stack **head, int value)
{
	int				idx;
	t_stack			*count;

	idx = 1;
	count = *head;
	while (count != NULL)
	{
		if (count->n == value)
			return (idx);
		count = count->next;
		idx++;
	}
	return (0);
}
