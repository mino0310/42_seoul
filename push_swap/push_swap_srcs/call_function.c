/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 13:41:33 by minhkim           #+#    #+#             */
/*   Updated: 2021/07/09 13:42:37 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	call_ra(t_struct *head_a, int *ra_cnt, t_oper *op)
{
	ra(head_a, op);
	(*ra_cnt)++;
}

void	call_rb(t_struct *head_b, int *rb_cnt, t_oper *op)
{
	rb(head_b, op);
	(*rb_cnt)++;
}

void	call_pa(t_struct *head_a, t_struct *head_b, int *pa_cnt, t_oper *op)
{
	pa(head_a, head_b, op);
	(*pa_cnt)++;
}

void	call_pb(t_struct *head_a, t_struct *head_b, int *pb_cnt, t_oper *op)
{
	pb(head_a, head_b, op);
	(*pb_cnt)++;
}
