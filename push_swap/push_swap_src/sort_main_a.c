/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:26:50 by minhkim           #+#    #+#             */
/*   Updated: 2021/06/28 16:35:09 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int					return_case_a(t_stack **a, t_stack **b, t_op **op, int len)
{
	if (sorted_check_a(a, len))
		return (1);
	if (len <= 3)
	{
		if (len == get_num_of_stack_node(a))
			sort_just_three_a(a, op);
		else
			sort_less_than_three_a(a, b, op, len);
		return (1);
	}
	return (0);
}

void				sort_main_a(t_stack **a, t_stack **b, t_op **op, int len)
{
	int				mid;
	int				push;
	int				rotate;
	int				i;

	mid = get_mid_value(a, len);
	push = 0;
	rotate = 0;
	i = 0;
	if (return_case_a(a, b, op, len))
		return ;
	while (i++ < len)
	{
		if ((*a)->n < mid && ++push)
			get_operation_list(op, "pb", a, b);
		else if ((*a)->n >= mid && ++rotate)
			get_operation_list(op, "ra", a, b);
	}
	while (rotate--)
		get_operation_list(op, "rra", a, b);
	sort_main_a(a, b, op, len - push);
	sort_main_b(a, b, op, push);
}
