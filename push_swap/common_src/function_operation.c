/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_operation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 17:01:47 by minhkim           #+#    #+#             */
/*   Updated: 2021/06/26 17:20:34 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_op				*create_op_list_node(char *s)
{
	t_op			*node;

	node = (t_op *)malloc(sizeof(t_op));
	node->s = ft_strdup(s);
	node->next = NULL;
	return (node);
}

void				add_op_list_front(t_op **head, t_op *node)
{
	node->next = *head;
	*head = node;
}

void				add_op_list_back(t_op **head, t_op *node)
{
	t_op			*idx;

	idx = *head;
	if (idx == NULL)
		*head = node;
	else
	{
		while (idx->next != NULL)
			idx = idx->next;
		idx->next = node;
	}
}

void				add_op_list_middle(t_op **head, t_op *node, int n)
{
	t_op			*idx;
	t_op			*tmp;

	idx = *head;
	if (n == 1)
	{
		add_op_list_front(head, node);
		return ;
	}
	n -= 2;
	while (n--)
		idx = idx->next;
	tmp = idx->next;
	idx->next = node;
	node->next = tmp;
}

void				del_op_list(t_op **head, int n)
{
	t_op			*idx;
	t_op			*tmp;

	idx = *head;
	if (n == 1)
	{
		*head = (*head)->next;
		free(idx->s);
		free(idx);
		return ;
	}
	n -= 2;
	while (n--)
		idx = idx->next;
	tmp = idx->next;
	idx->next = tmp->next;
	free(tmp->s);
	free(tmp);
}
