/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv_to_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 08:54:51 by minhkim           #+#    #+#             */
/*   Updated: 2021/06/11 09:48:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
// 에러를 출력하는 함수
int				write_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}
// 들어온 정수값이 int형을 넘어서는지 판별하는 함수
int				error_check_int(long long n)
{
	if (n > 2147483647)
		return (1);
	if (n < -2147483648)
		return (1);
	return (0);
}
// 문자열이 정수로 표현될 때의 에러를 체크하는 함수
int				error_check_atoi(const char *str)
{
	int			i;

	i = 0;
	while (str[i] && (str[i] == '\f' || str[i] == '\t' || str[i] == ' ' ||
				str[i] == '\n' || str[i] == '\r' || str[i] == '\v'))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '\0')
		return (0);
	else
		return (1);
}
// 연결 리스트에 같은 값이 있는지 체크하는 함수
int				error_check_overlap(t_stack **a)
{
	t_stack		*a_x;
	t_stack		*a_y;

	a_y = *a;
	while (a_y != NULL)
	{
		a_x = a_y->next;
		while (a_x != NULL)
		{
			if (a_y->n == a_x->n)
				return (1);
			a_x = a_x->next;
		}
		a_y = a_y->next;
	}
	return (0);
}
// main 함수의 매개변수를 에러체크하는 함수
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
		if (error_chec_int(n))
			return (1);
		add_stack_node_front(a, create_stack_node(n));
		i--;
	}
	if (error_check_overlap(a))
		return (1);
	return (0);
}
