/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_operation_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 20:24:19 by minhkim           #+#    #+#             */
/*   Updated: 2021/06/26 20:56:15 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void				get_operation_list(t_op **op, char *s, t_stack **a, t_stack **b)
{
	t_op			*new;

	new = create_op_list_node(s);
	add_op_list_back(op, new);
	if (s[0] == 'p' && s[1] == 'a')
		move_stack_node(a, b);
	if (s[0] == 'p' && s[1] == 'b')
		move_stack_node(b, a);

}
