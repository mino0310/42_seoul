/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_than_three_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:05:03 by minhkim           #+#    #+#             */
/*   Updated: 2021/06/28 16:25:14 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void				sort_less_than_two_b(t_stack **b, t_op **op)
{
	if ((*b)->n < (*b)->next->n)
		get_operation_list(op, "sb", NULL, b);
}

void				min_is_two_b(t_stack **a, t_stack **b, t_op **op)
{
	get_operation_list(op, "rb", a, b);
	get_operation_list(op, "sb", a, b);
	get_operation_list(op, "rrb", a, b);
	sort_less_than_two_b(b, op);
}

int					sort_less_than_three_b(t_stack **a, t_stack **b,
		t_op **op, int len)
{
	int				min;
	int				min_idx;

	if (len == 1)
		get_operation_list(op, "pa", a, b);
	else if (len == 2)
		sort_less_than_two_b(b, op);
	else if (len == 3)
	{
		min = get_min_value(b, len);
		min_idx = get_value_index(b, min);
		if (min_idx == 3)
			sort_less_than_two_b(b, op);
		else if (min_idx == 2)
			min_is_two_b(a, b, op);
		else
		{
			get_operation_list(op, "sb", a, b);
			min_is_two_b(a, b, op);
		}
	}
	return (1);
}
