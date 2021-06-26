/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 19:33:39 by minhkim           #+#    #+#             */
/*   Updated: 2021/06/26 19:56:47 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void					swap_stack_node(t_stack **head)
{
	int					tmp;

	if (*head != NULL && (*head)->next != NULL)
	{
		tmp = (*head)->n;
		(*head)->n = (*head)->next->n;
		(*head)->next->n = tmp;
	}
}

void					move_stack_node(t_stack **dest, t_stack **src)
{
	t_stack				**tmp;

	if (*src != NULL)
	{
		tmp = (*src)->next;
		add_stack_node_front(dest, *src);
		*src = tmp;
	}
}

void					top_stack_node_to_bot(t_stack **head)
{
	t_stack				*tmp;

	if (*head != NULL && (*head)->next != NULL)
	{
		tmp = *head;
		*head = (*head)->next;
		tmp->next = NULL;
		add_stack_node_back(head, tmp);
	}
}

void					bot_stack_node_to_top(t_stack **head)
{
	t_stack				*tmp;
	t_stack				*last;

	tmp = *head;
	if (*head != NULL && (*head)->next != NULL)
	{
		while (tmp->next->next != NULL)
		{
			tmp = tmp->next;
		}
		last = tmp->next;
		tmp->next = NULL;
		add_stack_node_front(head, last);
	}
}
