/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_operation_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 15:14:08 by minhkim           #+#    #+#             */
/*   Updated: 2021/06/27 15:17:36 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int					get_num_of_op_list_node(t_op **head)
{
	t_op			*idx;
	int				num;

	idx = *head;
	num = 0;
	if (idx == NULL)
		return (0);
	while (idx != NULL)
	{
		idx = idx->next;
		num++;
	}
	return (num);
}

void				print_operation_list(t_op **head)
{
	t_op			*idx;

	idx = *head;
	while (idx != NULL)
	{
		if (idx->s != NULL)
		{
			write(1, idx->s, ft_strlen(idx->s));
			write(1, "\n", 1);
		}
		idx = idx->next;
	}
}
