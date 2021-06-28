/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 10:40:50 by minhkim           #+#    #+#             */
/*   Updated: 2021/06/28 13:39:03 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
// 스택 노드의 첫번째 값과 두번째 값을 바꿔주는 함수
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
// 두번째 매개변수의 스택의 상단값을 첫번째 매개변수의 스택의 상단으로 옮기는 함수
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
// 스택 노드의 최상단 노드를 최하단으로 옮기는 함수
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
// 스택 노드의 최하단 노드를 최상단으로 옮기는 함수
void			bot_stack_node_to_top(t_stack **head)
{
	t_stack		*temp;
	t_stack		*last;

	temp = *head;
	if (*head != NULL && (*head)->next != NULL)
	{
		while (temp->next->next != NULL)
			temp = temp->next;
		last = temp->next;
		temp->next = NULL;
		add_stack_node_front(head, last);
	}
}
