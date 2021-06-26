/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_operation_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 09:58:16 by marvin            #+#    #+#             */
/*   Updated: 2021/06/11 09:58:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
// 연산 연결 리스트의 개수를 반환하는 함수
int             get_num_of_op_list_node(t_op **head)
{
    t_op        *index;
    int         num;

    index = *head;
    num = 0;
    if (index == NULL)
        return (0);
    while (index != NULL)
    {
        index = index->next;
        num++;
    }
    return (num);
}
//연산 연결 리스트를 출력하는 함수
void            print_operation_list(t_op **head)
{
    t_op        *index;

    index = *head;
    while (index != NULL)
    {
        if(index->s != NULL)
        {
            write(1, index->s, ft_strlen(index->s));
            write(1, "\n", 1);
        }
        index = index->next;
    }
}