/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_just_three_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 15:40:24 by minhkim           #+#    #+#             */
/*   Updated: 2021/06/27 16:08:23 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void				case_two_a(t_stack **a, t_op **op)
{
	if ((*a)->n > (*a)->next->n)
		get_operation_list(op, "sa", a, NULL);
}

void				case_three_a(t_stack **a, t_op **op, int len)
{
	int				max;
	int				max_idx;

	max = get_max_value(a, len);
	max_idx = get_value_idx(a, max);
	if (max_idx == 1)
	{
		get_operation_list(op, "ra", a, NULL);
		case_two_a(a, op);
	}
	else if (max_idx == 2)
	{
		get_operation_list(op, "rra", a, NULL);
		case_two_a(a, op);
	}
	else if (max_idx == 3)
		case_two_a(a, op);
}

int					sort_just_three_a(t_stack **a, t_op **op)
{
	int				len;

	len = get_num_of_stack_node(a);
	if (len == 2)
		case_two_a(a, op);
	else if (len == 3)
		case_three_a(a, op, len);
	return (0);
}
