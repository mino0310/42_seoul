/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack_operation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 16:58:19 by minhkim           #+#    #+#             */
/*   Updated: 2021/06/26 17:00:19 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void				free_stack(t_stack **a)
{
	t_stack			*idx;
	t_stack			*tmp;

	idx = *a;
	while (idx != NULL)
	{
		tmp = idx;
		idx = idx->next;
		free(tmp);
	}
	*a = NULL;
}

void				free_operation(t_op **op)
{
	t_op			*idx;
	t_op			*tmp;

	idx = *op;
	while (idx != NULL)
	{
		tmp = idx;
		idx = idx->next;
		free(tmp->s);
		free(tmp);
	}
	*op = NULL;
}
