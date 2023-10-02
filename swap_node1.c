/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_node1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:28:39 by ksho              #+#    #+#             */
/*   Updated: 2023/10/02 17:41:29 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **node)
{
	t_stack	*first;
	t_stack	*second;

	if (node == NULL || (*node)->next == NULL)
		return ;
	first = *node;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*node = second;
	ft_printf("sa\n");
}

void	sb(t_stack **node)
{
	t_stack	*first;
	t_stack	*second;

	if (*node == NULL || (*node)->next == NULL)
		return ;
	first = *node;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*node = second;
	ft_printf("sb\n");
}




void pa(t_stack **node1,t_stack **node2)
{
	if((*node1) -> next == NULL || (*node1) == NULL)
		return;
	*node2 = insert_head(*node2, (*node1)->value);
	if(!node2)
		return ;
	*node1 = delete_first_node(*node1);
	if(!node1)
		return ;
	ft_printf("pa\n");
}

void pb(t_stack **node1,t_stack **node2)
{
	if((*node1) -> next == NULL || (*node1) == NULL)
		return;
	*node2 = insert_head(*node2, (*node1)->value);
	if(!node2)
		return ;
	*node1 = delete_first_node(*node1);
	if(!node1)
		return ;
	ft_printf("pb\n");
}



void ra(t_stack **node)
{
	if((*node) -> next == NULL || !(*node) || !node)
		return ;
	t_stack *head;
	t_stack *head_next;
	t_stack *tail;
	
	head = (*node);
	head_next =(*node) -> next;
	tail = (*node);
	while(tail -> next != NULL)
		tail = tail -> next;
	head_next -> prev = NULL;
	head -> prev = tail;
	tail -> next = head;
	head -> next = NULL;
	*node = head_next;
	ft_printf("ra\n");
	
}