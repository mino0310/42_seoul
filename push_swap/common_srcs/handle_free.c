/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 13:40:40 by minhkim           #+#    #+#             */
/*   Updated: 2021/07/09 13:42:41 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_struct *node)
{
	t_struct	*index;
	t_struct	*temp;

	index = node;
	while (index->next != NULL)
	{
		temp = index;
		index = index->next;
		free(temp);
	}
	free(index);
}

void	free_operation(t_oper *op)
{
	t_oper		*index;
	t_oper		*temp;

	index = op->next;
	while (index->next != NULL)
	{
		temp = index;
		index = index->next;
		free(temp->operation);
		free(temp);
	}
	free(index);
	free(op);
}

void	handle_free(t_struct *head_a, t_struct *head_b, t_oper *op)
{
	free_stack(head_a);
	free_operation(op);
	free(head_b);
}
