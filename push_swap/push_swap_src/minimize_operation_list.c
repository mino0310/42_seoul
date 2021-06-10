/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimize_operation_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 12:03:10 by minhkim           #+#    #+#             */
/*   Updated: 2021/06/10 12:10:35 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int				get_merge_case(t_op *i)
{
	if (ft_strcmp(i->s, "ra") && ft_strcmp(i->next->s, "rb"))
		return (1);
	if (ft_strcmp(i->s, "rb") && ft_strcmp(i->next->s, "ra"))
		return (1);
	if (ft_strcmp(i->s, "rra") && ft_strcmp(i->next->s, "rrb"))
		return (2);
	if (ft_strcmp(i->s, "rrb") && ft_strcmp(i->next->s, "rra"))
		return (2);
	return (0);
}

int				get_delete_case(t_op *i)
{ㅑ
	if (ft_strcmp(i->s, "pa") && ft_strcmp(i->next->s, "pb"))
		return (1);
	if (ft_strcmp(i->s, "pb") && ft_strcmp(i->next->s, "pa"))
		return (1); // 대체 무슨 의미가 있지.. 궁금하네:
	if (
}
