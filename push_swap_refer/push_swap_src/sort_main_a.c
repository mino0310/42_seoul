/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 10:47:21 by marvin            #+#    #+#             */
/*   Updated: 2021/06/11 10:47:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
// 스택 a가 정렬되어 있거나, 정렬이 되면 정렬하고 1을 반환하고 아니면 0을 반환하는 함수. 3개가 넘으면 0을 반환한다.
int             return_case_a(t_stack **a, t_stack **b, t_op **op, int len)
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
//스택 a가 오름차순으로 정렬되어 있으면 pa 연산을 해서 넘겨버리고, 아니면 길이 매개변수만큼 pa연산을 실행한다. 이를 재귀적으로 실행한다.
void            sort_main_a(t_stack **a, t_stack **b, t_op **op, int len)
{
    int         mid;
    int         push;
    int         rotate;
    int         i;

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