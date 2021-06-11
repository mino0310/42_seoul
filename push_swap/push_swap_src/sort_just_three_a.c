/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_just_three_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:23:04 by marvin            #+#    #+#             */
/*   Updated: 2021/06/11 11:23:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
// 스택 a가 2개인 경우에 오름차순으로 정렬하는 함수
void        case_two_a(t_stack **a, t_op **op)
{
    if ((*a)->n > (*a)->next->n)
        get_operation_list(op, "sa", a, NULL);
}
// 스택 a가 3개인 경우에 오름차순으로 정렬하는 함수
void        case_three_a(t_stack **a, t_op **op, int len)
{
    int     max;
    int     max_idx;

    max = get_max_value(a, len);
    max_idx = get_value_index(a, max);
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
// 스택 a의 길이가 2개나 3개일 경우에 오름차순으로 정렬하는 함수
int         sort_just_three_a(t_stack **a, t_op **op)
{
    int     len;

    len = get_num_of_stack_node(a);
    if (len == 2)
        case_two_a(a, op);
    else if (len == 3)
        case_three_a(a, op, len);
    return (0);
}