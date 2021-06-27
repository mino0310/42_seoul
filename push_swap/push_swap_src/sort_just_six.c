/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_just_six.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 15:37:05 by minhkim           #+#    #+#             */
/*   Updated: 2021/06/27 15:39:51 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int				sort_just_six(t_stack **a, t_stack **b, t_op **op, int len)
{
	int			mid;
	int			i;

	mid = get_mid_value(a, len);
	i = 0;
	while (i < len / 2)
	{
		if ((*a)->n < mid)
		{
			get_operation_list(op, "pb", a, b);
			i++;
		}
		else
			get_operation_list(op, "ra", a, b);
	}
	sort_just_three_a(a, op);
	sort_just_three_b(a, b, op);
	while (i--)
		get_operation_list(op, "pa", a, b);
	return (0);
}
