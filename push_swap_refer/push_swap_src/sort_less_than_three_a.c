/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_than_three_a.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 10:48:19 by marvin            #+#    #+#             */
/*   Updated: 2021/06/11 10:48:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
//2개 이하인 스택 a를 오름차순으로 정렬하는 함수
void            sort_less_than_two_a(t_stack **a, t_op **op)
{
    if ((*a)->n > (*a)->next->n)
        get_operation_list(op, "sa", a, NULL);
}

// 2번쨰 값이 최대 값을 경우에 스택 a를 오름차순으로 정렬하는 함수
void            max_is_two_a(t_stack **a, t_stack **b, t_op **op)
{
    get_operation_list(op, "ra", a, b);
    get_operation_list(op, "sa", a, b);
    get_operation_list(op, "rra", a, b);
    sort_less_than_two_a(a, op); // 이걸 굳이 왜 또 다시 해주는 것이징?
}
// 3개 이하인 스택 a를 오름차순으로 정렬하는 함수
int             sort_less_than_three_a(t_stack **a, t_stack **b, t_op **op, int len)
{
    int         max;
    int         max_idx;

    if (len == 2)
        sort_less_than_two_a(a, op);
    else if (len == 3)
    {
        max = get_max_value(a, len);
        max_idx = get_value_index(a, max);
        if (max_idx == 3)
            sort_less_than_two_a(a, op);
        else if (max_idx == 2)
            max_is_two_a(a, b, op);
        else
        {
            get_operation_list(op, "sa", a, b);
            max_is_two_a(a, b, op);
        }
    }
    return (1);
}