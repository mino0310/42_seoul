/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack_operation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 09:34:11 by minhkim           #+#    #+#             */
/*   Updated: 2021/06/11 09:49:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
// 연결리스트의 모든 노드를 free 시켜주는 함수
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
// 연산 연결리스트를 모두 메모리 해제 시키는 함수
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
