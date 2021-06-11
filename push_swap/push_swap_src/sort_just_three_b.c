/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_just_three_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:42:16 by marvin            #+#    #+#             */
/*   Updated: 2021/06/11 11:42:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
// 갯수가 2개인 스택 b를 내림차순으로 정렬하는 함수
void            case_two_b(t_stack **b, t_op **op)
{
    if ((*b)->n < (*b)->next->n)
        get_operation_list(op, "sb", NULL, b);
}
// 개수가 3개인 스택 b를 내림차순으로 정렬하는 함수
void            case_three_b(t_stack **b, t_op **op, int len)
{
    int         min;
    int         min_idx;

    min = get_min_value(b, len);
    min_idx = get_value_index(b, min);
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
// 개수가 2개 혹은 3개인 스택 b를 내림차순으로 정렬하는 함수
int             sort_just_three_b(t_stack **a, t_stack **b, t_op **op)
{
    int         len;

    len = get_num_of_stack_node(b);
    if (len == 1)
        get_operation_list(op, "pa", a, b);
    else if (len == 2)
        case_two_b(b, op);
    else if (len == 3)
        case_three(b, op, len);
    return (0);
}