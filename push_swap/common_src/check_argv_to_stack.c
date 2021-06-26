/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv_to_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 16:43:32 by minhkim           #+#    #+#             */
/*   Updated: 2021/06/26 16:57:25 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int				write_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int				error_check_int(long long n)
{
	if (n > 2147483647)
		return (1);
	if (n < -2147483648)
		return (1);
	return (0):
}

int				error_check_atoi(const char *str)
{
	int			i;

	i = 0;
	while (str[i] && (str[i] == '\f' || str[i] == '\t' || str[i] == ' ' ||
				str[i] == '\n' || str[i] == '\r' || str[i] == '\v'))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	else
		return (1);
}

int				error_check_overlap(t_stack **a)
{
	t_stack		*a_i;
	t_stack		*a_j;

	a_i = *a;
	while (a_i != NULL)
	{
		a_j = a_i->next;
		while (a_j != NULL)
		{
			if (a_j->n == a_i->n)
			{
				return (1);
			}
			a_j = a_j->next;
		}
		a_i = a_i->next;
	}
}

int				check_argv_to_stack(t_stack **a, int argc, char **argv)
{
	int			i;
	long long	n;

	i = argc - 1;
	if (i == 0)
		return (1);
	while (i > 0)
	{
		if (error_check_atoi(argv[i]))
				return (1);
		n = ft_atoi(argv[i]);
		if (error_check_int(n))
			return (1);
		add_stack_node_front(a, create_stack_node(n));
		i--;
	}
	if (error_check_overlap(a))
		return (1);
	return (0);
}
