/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_node2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:20:05 by ksho              #+#    #+#             */
/*   Updated: 2023/10/03 14:05:53 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_stack **node, int bool)
{
	t_stack	*head;
	t_stack	*head_next;
	t_stack	*tail;

	if ((*node)->next == NULL || !(*node) || !node)
		return ;
	head = (*node);
	head_next = (*node)->next;
	tail = (*node);
	while (tail->next != NULL)
		tail = tail->next;
	head_next->prev = NULL;
	head->prev = tail;
	tail->next = head;
	head->next = NULL;
	*node = head_next;
	if (bool)
		ft_printf("rb\n");
}

void	rra(t_stack **node, int bool)
{
	t_stack	*head;
	t_stack	*tail_prev;
	t_stack	*tail;

	if ((*node)->next == NULL || !(*node) || !node)
		return ;
	head = (*node);
	tail = (*node);
	while (tail->next != NULL)
		tail = tail->next;
	tail_prev = tail->prev;
	tail_prev->next = NULL;
	head->prev = tail;
	tail->next = head;
	tail->prev = NULL;
	if (bool)
		ft_printf("rra\n");
	(*node) = tail;
}

void	rrb(t_stack **node, int bool)
{
	t_stack	*head;
	t_stack	*tail_prev;
	t_stack	*tail;

	if ((*node)->next == NULL || !(*node) || !node)
		return ;
	head = (*node);
	tail = (*node);
	while (tail->next != NULL)
		tail = tail->next;
	tail_prev = tail->prev;
	tail_prev->next = NULL;
	head->prev = tail;
	tail->next = head;
	tail->prev = NULL;
	if (bool)
		ft_printf("rrb\n");
	(*node) = tail;
}
void	ss(t_stack **node1, t_stack **node2)
{
	t_stack *first;
	t_stack *second;

	first = *node1;
	second = *node2;
	if ((*node1)->next == NULL || (*node2)->next == NULL)
		return ;
	sa(&first, 0);
	sb(&second, 0);
	*node1 = first;
	*node2 = second;
	ft_printf("ss\n");
}

void	rr(t_stack **node1, t_stack **node2)
{
	t_stack *first;
	t_stack *second;

	first = *node1;
	second = *node2;
	if ((*node1)->next == NULL || (*node2)->next == NULL)
		return ;
	ra(&first, 0);
	rb(&second, 0);
	*node1 = first;
	*node2 = second;
	ft_printf("rr\n");
}
