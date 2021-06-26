/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 10:29:34 by minhkim           #+#    #+#             */
/*   Updated: 2021/06/12 10:49:19 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
// 스택 b가 내림차순으로 정렬되어 있으면 길이 매개변수만큼 pa연산을 실행하고 1을 반환하고 정렬되어 있지 않고 길이 매개변수가 3보다 작으면 정렬해서 pa연산을 실행하는 함수. 아니면 0을 반환한다
int             return_case_b(t_stack **a, t_stack **b, t_op **op, int len)
{
    int         i;

    i = 0;
    if (sorted_check_b(b, len))
    {
        while (len--)
            get_operation_list(op, "pa", a, b);
        return (1);
    }
    if (len <= 3)
    {
        if (len == get_num_of_stack_node(b))
            sort_just_three_b(a, b, op);
        else
            sort_less_than_three_b(a, b, op, len);
        while (i++ < len)
            get_operation_list(op, "pa", a, b);
        return (1);
    }
    return (0);
}
//스택 b가 내림차순으로 정렬되어 있으면 pa 연산을 해서 넘겨버리고, 아니면 길이 매개변수만큼 pa연산을 실행한다. 이를 재귀적으로 실행한다.
void            sort_main_b(t_stack **a, t_stack **b, t_op **op, int len)
{
    int         mid;
    int         push;
    int         rotate;
    int         i;

    mid = get_mid_value(b, len);
    push = 0;
    rotate = 0;
    i = 0;
    if (return_case_b(a, b, op, len))
        return ;
    while (i++ < len)
    {
        if ((*b)->n >= mid && ++push)
            get_operation_list(op, "pa", a, b);
        else if ((*b)->n < mid && ++rotate)
            get_operation_list(op, "rb", a, b);
    }
    while (rotate--)
        get_operation_list(op, "rrb", a, b);
    sort_main_a(a, b, op, push);
    sort_main_b(a, b, op, len - push);
}