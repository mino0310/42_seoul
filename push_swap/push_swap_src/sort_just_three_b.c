/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_just_three_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:40:47 by minhkim           #+#    #+#             */
/*   Updated: 2021/06/28 14:45:47 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void				case_two_b(t_stack **b, t_op **op)
{
	if ((*b)->n < (*b)->next->n)
		get_operation_list(op, "sb", NULL, b);
}

void				case_three_b(t_stack **b, t_op **op, int len)
{
	int				min;
	int				min_idx;

	min = get_min_value(b, len);
	min_idx = get_value_idx(b, min);
	if (min_idx == 1)
	{
		get_operation_list(op, "rb", NULL, b);
		case_two_b(b, op);
	}
	else if (min_idx == 2)
	{
		get_operation_list(op, "rrb", NULL, b);
		case_two_b(b, op);
	}
	else if (min_idx == 3)
	{
		case_two_b(b, op);
	}
}

int					sort_just_three_b(t_stack **a, t_stack **b, t_op **op)
{
	int				len;

	len = get_num_of_stack_node(b);
	if (len == 1)
		get_operation_list(op, "pa", a, b);
	else if (len == 2)
		case_two_b(b, op);
	else if (len == 3)
		case_three_b(b, op, len);
	return (0);
}
