/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack_ab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:15:19 by minhkim           #+#    #+#             */
/*   Updated: 2021/06/10 11:21:22 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

void		print_stack_ab(t_stack **a, t_stack **b)
{
	t_stack *index_a;
	t_stack *index_b;

	index_a = *a;
	index_b = *b;
	printf("|A|");
	printf("%d|", get_num_of_stack_node(a));
	while (index_a != NULL)
	{
		printf(" %d", index_a->n);
		index_a = index_a->next;
	}
	printf("\n");
	printf("|B|");
	printf("%d|", get_num_of_stack_node(b));
	while (index_b != NULL)
	{
		printf(" %d", index_b->n);
		index_b = index_b->next;
	}
	printf("\n\n");
}
