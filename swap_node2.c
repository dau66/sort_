/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_node2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:20:05 by ksho              #+#    #+#             */
/*   Updated: 2023/10/02 17:37:21 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_stack **node)
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
	ft_printf("rb\n");
}

void	rra(t_stack **node)
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
	tail -> next = head;
	tail -> prev = NULL;
	ft_printf("rra\n");
	(*node) = tail; 
	
}

