/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 10:40:50 by minhkim           #+#    #+#             */
/*   Updated: 2021/06/10 11:15:05 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void			swap_stack_node(t_stack **head)
{
	int			temp;

	if (*head != NULL && (*head)->next != NULL)
	{
		temp = (*head)->n;
		(*head)->n = (*head)->next->n;
		(*head)->next->n = temp;
	}
}

void			move_stack_node(t_stack **dest, t_stack **src)
{
	t_stack		*temp;

	if(*src != NULL)
	{
		temp = (*src)->next;
		add_stack_node_front(dest, *src);
		*src = temp;
	}
}

void			top_stack_node_to_bot(t_stack **head)
{
	t_stack		*temp;

	if (*head != NULL && (*head)->next != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		temp->next = NULL;
		add_stack_node_back(head, temp);
	}
}

void			bot_stack_node_to_top(t_stack **head)
{
	t_stack		*temp;
	t_stack		*last;

	temp = *head;
	if (*head != NULL & (*head)->next != NULL)
	{
		while (temp->next->next != NULL)
			temp = temp->next;
		last = temp->next;
		temp->next = NULL;
		add_stack_node_front(head, last);
	}
}
