/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 17:24:04 by minhkim           #+#    #+#             */
/*   Updated: 2021/06/26 17:29:37 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack				*create_stack_node(int n)
{
	t_stack			*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	node->n = n;
	node->next = NULL;
	return (node);
}

int					get_num_of_stack_node(t_stack **head)
{
	t_stack			*idx;
	int				num;

	idx = *head;
	num = 0;
	if (idx == NULL)
		return (0);
	while (idx != NULL)
	{
		idx = idx->next;
		num++;
	}
	return (num);
}

void				add_stack_node_front(t_stack **head, t_stack *node)
{
	node->next = *head;
	*head = node;
}

void				add_stack_node_back(t_stack **head, t_stack *node)
{
	t_stack			*idx;

	idx = *head;
	if ((*head) == NULL)
		(*head) = node;
	else
	{
		while (idx->next != NULL)
			idx = idx->next;
		idx->next = node;
	}
}
