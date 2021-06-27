/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 15:17:46 by minhkim           #+#    #+#             */
/*   Updated: 2021/06/27 15:36:57 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int					get_partition(int *sort, int start, int end)
{
	int				pivot;
	int				i;
	int				idx;
	int				tmp;

	pivot = sort[end];
	idx = start;
	i = start;
	while (i < end)
	{
		if (sort[i] <= pivot)
		{
			tmp = sort[i];
			sort[i] = sort[idx];
			sort[idx] = tmp;
			idx++;
		}
		i++;
	}
	tmp = sort[idx];
	sort[idx] = sort[end];
	sort[end] = tmp;
	return (idx);
}

void				quick_sort(int *sort, int start, int end)
{
	int				idx;

	if (start < end)
	{
		idx = get_partition(sort, start, end);
		quick_sort(sort, start, idx - 1);
		quick_sort(sort, idx + 1, end);
	}
}
