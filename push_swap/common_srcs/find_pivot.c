/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 13:40:25 by minhkim           #+#    #+#             */
/*   Updated: 2021/07/09 13:42:42 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*fill_arr(t_struct *node, int *arr, int len)
{
	t_struct	*temp;
	int			index;

	temp = node;
	index = 0;
	arr = (int *)malloc(sizeof(int) * len);
	while (index < len)
	{
		temp = temp->next;
		arr[index] = temp->value;
		index++;
	}
	return (arr);
}

int	get_partition(int *arr, int start, int end)
{
	int			pivot;
	int			i;
	int			index;
	int			temp;

	pivot = arr[end];
	index = start;
	i = start;
	while (i < end)
	{
		if (arr[i] <= pivot)
		{
			temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;
			index++;
		}
		i++;
	}
	temp = arr[index];
	arr[index] = arr[end];
	arr[end] = temp;
	return (index);
}

void	quick_sort(int *arr, int start, int end)
{
	int			index;

	if (start < end)
	{
		index = get_partition(arr, start, end);
		quick_sort(arr, start, index - 1);
		quick_sort(arr, index + 1, end);
	}
}

int	check_pivot(t_struct *node, int len)
{
	int			*arr;
	int			pivot;

	arr = NULL;
	arr = fill_arr(node, arr, len);
	quick_sort(arr, 0, len - 1);
	pivot = arr[len / 2];
	if (len % 2 == 0)
		pivot = arr[len / 2 - 1];
	free(arr);
	return (pivot);
}
