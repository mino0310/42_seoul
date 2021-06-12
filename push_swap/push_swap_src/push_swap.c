/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 10:58:31 by minhkim           #+#    #+#             */
/*   Updated: 2021/06/12 11:05:40 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int         main(int argc, char **argv)
{
    t_stack     *a;
    t_stack     *b;
    t_op        *op;
    int         len;

    a = NULL;
    b = NULL;
    op = NULL;
    if (check_argv_to_stack(&a, argc, argv))
        return (write_error());
    len = get_num_of_stack_node(&a);
    if (sorted_check_a(&a, len))
        return (0);
    if (len <= 3)
        sort_just_three_a(&a, &op);
    else if (len <= 6)
        sort_just_six(&a, &b, &op, len);
    else
        sort_main_a(&a, &b, &op, len);
    minimize_operation_list(&op);
    print_operation_list(&op);
    free_stack(&a);
    free_operation(&op);
    return (0); 
}