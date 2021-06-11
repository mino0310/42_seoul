/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_in_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:37:54 by minhkim           #+#    #+#             */
/*   Updated: 2021/06/11 09:46:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
// 연결 리스트를 배열로 반환하는 함수
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
//길이값에 따라 연결 리스트의 중간값을 반환하는 함수
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
// 길이 값에 따라 연결 리스트의 최소 값을 반환하는 함수.
int				get_min_value(t_stack **head, int len)
{
	int			*sort;
	int			min_value;

	sort = get_stack_array(head, len);
	quick_sort(sort, 0, len - 1);
	min_value = sort[0];
	free(sort);
	return (min_value);
}

// 길이 값에 따라 연결 리스트의 최대 값을 반환하는 함수 
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
// 해당 값을 가지고 있는 연결 리스트의 노드의 인덱스를 반환하는 함수
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
	return (0);
}
