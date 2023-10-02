/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_node1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:28:39 by ksho              #+#    #+#             */
/*   Updated: 2023/10/02 15:44:12 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*sa(t_stack *node)
{
	t_stack	*first;
	t_stack	*second;

	if (node == NULL || node->next == NULL)
	{
		// リストがNULLまたはノードが1つしかない場合は何もしない
		return (node);
	}
	first = node;
	second = first->next;
	first->next = second->next;
	second->next = first;
	node = second;
	ft_printf("sa\n");
	return (node);
}

// t_stack *sa(t_stack *node)
// {
// 	t_stack *first;
// 	t_stack *second;

// 	first = node;
// 	second = first->next;
// 	first->next = second->next;
// 	second->next = first;
// 	node = second;
// 	ft_printf("sa\n");
// 	// free(second);
// 	return (node);
// }

t_stack	*sb(t_stack *node)
{
	t_stack	*first;
	t_stack	*second;

	first = node;
	second = first->next;
	first->next = second->next;
	second->next = first;
	node = second;
	ft_printf("sb\n");
	free(second);
	return (node);
}

// void pa(t_stack **node1,t_stack **node2)
// {
// 	t_stack *tmp;
// 	*node2 = insert_head(*node2, (*node1)->value);
// 	if(!node2)
// 		return (NULL);
// }

// void pb(t_stack **node1,t_stack **node2)
// {

// }
