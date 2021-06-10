/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 10:09:28 by minhkim           #+#    #+#             */
/*   Updated: 2021/06/10 10:40:22 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack			*create_stack_node(int n)
{
	t_stack		*node;

	node = (t_stack *)malloc(sizeof(t_stack)); // 여기도 에러체크가 빠졌네
	node->n = n;
	node->next = NULL;
	return (node);
}

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

void			add_stack_node_front(t_stack **head, t_stack *node)
{
	node->next = *head;
	*head = node;
}

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
