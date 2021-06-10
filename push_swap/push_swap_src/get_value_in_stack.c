/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_in_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:37:54 by minhkim           #+#    #+#             */
/*   Updated: 2021/06/10 11:56:35 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int				*get_stack_array(t_stack **head, int num)
{
	int			i;
	int			*sort;
	t_stack		*count;

	if (!(sort = (int *)malloc(sizeof(int) *num)))
		return (NULL);
	i = 0;
	count = *head;
	while (i < num)
	{
		sort[i] = count->n;
		count = count->next;
		i++;
	}
	return (sort); // stack_array 라고 명명하는 게 나을 듯?
}

int				get_mid_value(t_stack **head, int len)
{
	int			*sort;
	int			mid_value;

	sort = get_stack_array(head, len);
	quick_sort(sort, 0, len - 1);
	mid_value = sort[len / 2];
	free(sort);
	return (mid_value);
}

int				get_max_value(t_stack **head, int len)
{
	int			*sort;
	int			max_value;

	sort = get_stack_array(head, len);
	quick_sort(sort, 0, len - 1);
	max_value = sort[len - 1];
	free(sort);
	return (max_value);
}

int				get_value_index(t_stack **head, int value)
{
	int			*sort;
	int			max_value;

	sort = get_stack_array(head, len);
	quick_sort(sort, 0, len - 1);
	max_value = sort[len - 1];
	free(sort);
	return (max_value);
}

int				get_value_index(t_stack **head, int value)
{
	int			index;
	t_stack		*count;

	index = 1; // 왜 인덱스를 1로 잡았지? 0부터 시작하는 개념이 아니어야 하는 이유가 있
	count = *head;
	while (count != NULL)
	{
		if (count->n == value)
			return (index);
		count = count->next;
		index++;
	}
}
