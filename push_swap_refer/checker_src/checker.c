/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:02:34 by minhkim           #+#    #+#             */
/*   Updated: 2021/06/12 12:20:22 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
// rr 이 들어간 연산을 처리하는 함수
void                operation_rr_checker(t_stack **a, t_stack **b, char *s)
{
    if (s[0] == 'r' && s[1] == 'r' && s[2] == 'a')
        bot_stack_node_to_top(a);
    if (s[0] == 'r' && s[1] == 'r' && s[2] == 'b')
        bot_stack_node_to_top(b);
    if (s[0] == 'r' && s[1] == 'r' && s[2] == '\0')
    {
        top_stack_node_to_bot(a);
        top_stack_node_to_bot(b);
    }
    if (s[0] == 'r' && s[1] == 'r' && s[2] == 'r')
    {
        bot_stack_node_to_top(a);
        bot_stack_node_to_top(b);
    }
}

void                operation_checker(t_stack **a, t_stack **b, char *s)
{
    if (s[0] == 'p' && s[1] == 'a')
        move_stack_node(a, b);
    if (s[0] == 'p' && s[1] == 'b')
        move_stack_node(b, a);
    if (s[0] == 's' && s[1] == 'a')
        swap_stack_node(a);
    if (s[0] == 's' && s[1] == 'b')
        swap_stack_node(b);
    if (s[0] == 'r' && s[1] == 'a')
        top_stack_node_to_bot(a);
    if (s[0] == 'r' && s[1] == 'b')
        top_stack_node_to_bot(b);
    if (s[0] == 'r' && s[1] == 'r')
        operation_rr_checker(a, b, s);
}

int                 main(int argc, char **argv)
{
    t_stack         *a;
    t_stack         *b;
    char            *line;
    int             len;

    a = NULL;
    b = NULL;
    if (check_argv_to_stack(&a, argc, argv))
        return (write_error());
    len = get_num_of_stack_node(&a);
    while (get_next_line(&line) > 0)
    {
        operation_checker(&a, &b, line);
        free(line);
    }
    operation_checker(&a, &b, line);
    free(line);
    if (sorted_check_a(&a, len))
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);
    free_stack(&a);
    return (0);    
}