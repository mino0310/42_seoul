/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_than_three_a.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:49:00 by minhkim           #+#    #+#             */
/*   Updated: 2021/06/28 15:55:29 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void				sort_less_than_two_a(t_stack **a, t_op **op)
{
	if ((*a)->n > (*a)->next->n)
		get_operation_list(op, "sa", a, NULL);
}

void				max_is_two_a(t_stack **a, t_stack **b, t_op **op)
{
	get_operation_list(op, "ra", a, b);
	get_operation_list(op, "sa", a, b);
	get_operation_list(op, "rra", a, b);
	sort_less_than_two_a(a, op);
}

int					sort_less_than_three_a(t_stack **a, t_stack **b, t_op **op, int len)
{
	int				max;
	int				max_idx;

	if (len == 2)
		sort_less_than_two_a(a, op);
	else if (len == 3)
	{
		max = get_max_value(a, len);
		max_idx = get_value_index(a, max);
		if (max_idx == 3)
			sort_less_than_two_a(a, op);
		else if (max == 2)
	}
}
