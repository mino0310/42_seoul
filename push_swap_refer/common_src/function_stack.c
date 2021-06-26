/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 10:09:28 by minhkim           #+#    #+#             */
/*   Updated: 2021/06/11 09:52:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
// n을 값으로 하는 노드를 만들어 반환하는 함수
t_stack			*create_stack_node(int n)
{
	t_stack		*node;

	node = (t_stack *)malloc(sizeof(t_stack)); // 여기도 에러체크가 빠졌네
	node->n = n;
	node->next = NULL;
	return (node);
}
// 연결리스트의 노드의 총 개수를 반환하는 함수
int				get_num_of_stack_node(t_stack **head)
{
	t_stack		*index;
	int			num;

	index = *head;
	num = 0;
	if (index == NULL)
		return (0);
	while (index != NULL)
	{
		index = index->next;
		num++;
	}
	return (num);
}
// 스택 노드의 가장 앞에 해당 노드를 추가하는 함수
void			add_stack_node_front(t_stack **head, t_stack *node)
{
	node->next = *head;
	*head = node;
}
// 스택 노드의 가장 뒤에 해당 노드를 추가하는 함수
void			add_stack_node_back(t_stack **head, t_stack *node)
{
	t_stack		*index;

	index = *head;
	if (*head == NULL)
		*head = node;
	else
	{
		while (index->next != NULL)
			index = index->next;
		index->next = node;
	}
}
