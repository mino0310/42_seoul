/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_than_three_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:06:54 by marvin            #+#    #+#             */
/*   Updated: 2021/06/11 11:06:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
// 2개 이하인 스택 b를 내림차순으로 정렬하는 함수
void            sort_less_than_two_b(t_stack **b, t_op **op)
{
    if ((*b)->n < (*b)->next->n)
        get_operation_list(op, "sb", NULL, b);
}
// 2번째가 최솟값인 스택 b를 내림차순으로 정렬하는 함수
void            min_is_two_b(t_stack **a, t_stack **b, t_op **op)
{
    get_operation_list(op, "rb", a, b);
    get_operation_list(op, "sb", a, b);
    get_operation_list(op, "rrb", a, b);
    sort_less_than_two_b(b, op);
}
// 3개 이하인 스택 b를 내림차순으로 정렬하는 함수
int             sort_less_than_three_b(t_stack **a, t_stack **b, t_op **op, int len)
{
    int         min;
    int         min_idx;

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