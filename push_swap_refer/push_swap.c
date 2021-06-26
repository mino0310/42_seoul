/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 08:51:08 by minhkim           #+#    #+#             */
/*   Updated: 2021/06/10 08:54:32 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		main(void)
{
	t_stack *a;
	t_stack *b;
	t_op	*op;
	int		len;

	a = NULL;
	b = NULL;
	op = NULL;
	if (check_argv_to_stack(&a, argc, argv))
		return (write_error());

	return 0;
}
