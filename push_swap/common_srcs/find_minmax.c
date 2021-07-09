/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_minmax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 13:40:16 by minhkim           #+#    #+#             */
/*   Updated: 2021/07/09 13:42:42 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_max(t_struct *head)
{
	int			max;
	t_struct	*temp;

	temp = head->next;
	max = temp->value;
	while (temp != NULL)
	{
		if (max < temp->value)
			max = temp->value;
		temp = temp->next;
	}
	return (max);
}

int	find_min(t_struct *head)
{
	int			min;
	t_struct	*temp;

	temp = head->next;
	min = temp->value;
	while (temp != NULL)
	{
		if (min > temp->value)
			min = temp->value;
		temp = temp->next;
	}
	return (min);
}
