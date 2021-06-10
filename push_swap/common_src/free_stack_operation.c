/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack_operation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 09:34:11 by minhkim           #+#    #+#             */
/*   Updated: 2021/06/10 09:43:22 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		free_stack(t_stack **a)
{
	t_stack *index;
	t_stack *temp;

	index = *a;
	while (index != NULL)
	{
		temp = index;
		index = index->next;
		free(temp);
	}
	*a = NULL;
}

void		free_operation(t_op **op)
{
	t_op	*index;
	t_op	*temp;

	index = *op;
	while (index != NULL)
	{
		temp = index;
		index = index->next;
		free(temp->s);
		free(temp);
	}
	*op = NULL;
}
