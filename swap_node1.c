/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_node1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:28:39 by ksho              #+#    #+#             */
/*   Updated: 2023/10/01 19:32:12 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
t_stack *sa(t_stack *node)
{
	t_stack *first;
	t_stack *second;
	
	first = node;
	second = first->next;
	first->next = second->next;
	second->next = first;
	node = second;

	return node;
}

// void sb(t_stack **node)
// {
	
// }

// void pa(t_stack **node1,t_stack **node2)
// {
	
// }

// void pb(t_stack **node1,t_stack **node2)
// {
	
// }


