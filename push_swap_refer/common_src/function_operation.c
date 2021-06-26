/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_operation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 09:49:34 by minhkim           #+#    #+#             */
/*   Updated: 2021/06/11 09:50:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
// 문자열을 연산값으로 한 연산 노드를 만들어 반환하는 함수
t_op			*create_op_list_node(char *s)
{
	t_op		*node;

	node = (t_op *)malloc(sizeof(t_op)); // 여기서 에러체크가 필요할 듯
	node->s = ft_strdup(s);
	node->next = NULL;
	return (node);
}
// 연결리스트의 가장 앞에 해당 노드를 추가하는 함수
void			add_op_list_front(t_op **head, t_op *node)
{
	node->next = *head;
	*head = node;
}
// 연결리스트의 가장 뒤에 해당 노드를 추가하는 함수
void			add_op_list_back(t_op **head, t_op *node)
{
	t_op		*index;

	index = *head;
	if (index == NULL)
		*head = node;
	else
	{
		while (index->next != NULL)
			index = index->next;
		index->next = node;
	}
}
//연결리스트의 n번째에 해당 노드를 추가하는 함수
void			add_op_list_middle(t_op **head, t_op *node, int n)
{
	t_op		*index;
	t_op		*temp;

	index = *head;
	if (n == 1)
	{
		add_op_list_front(head, node);
		return ;
	}
	n = n - 2;
	while (n--)
		index = index->next;
	temp = index->next;
	index->next = node;
	node->next = temp;
}
// 연산 연결리스트 중 n 번째 연산 노드를 제거하는 함수
void			del_op_list(t_op **head, int n)
{
	t_op		*index;
	t_op		*temp;

	index = *head;
	if (n == 1)
	{
		*head = (*head)->next;
		free(index->s);
		free(index);
		return ;
	}
	n = n - 2;
	while (n--)
		index = index->next;
	temp = index->next;
	index->next = temp->next;
	free(temp->s);
	free(temp);
}
