/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_node3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:25:30 by ksho              #+#    #+#             */
/*   Updated: 2023/10/07 13:59:20 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack **node1, t_stack **node2)
{
	t_stack	*first;
	t_stack	*second;

	first = *node1;
	second = *node2;
	if (!node1 || !(*node1) || !node2 || !(*node2) || (*node1)->next == NULL
		|| (*node2)->next == NULL)
		return ;
	rra(&first, 0);
	rrb(&second, 0);
	*node1 = first;
	*node2 = second;
	ft_printf("rrr\n");
}

size_t	value_compare(t_stack *first)
{
	if ((first->value < first->next->value)
		&& (first->next->value > first->next->next->value)
		&& (first->value < first->next->next->value))
		return (0);
	else if ((first->value < first->next->value)
		&& (first->next->value > first->next->next->value)
		&& (first->value > first->next->next->value))
		return (1);
	else if ((first->value > first->next->value)
		&& (first->next->value < first->next->next->value)
		&& (first->value > first->next->next->value))
		return (2);
	else if ((first->value > first->next->value)
		&& (first->next->value < first->next->next->value)
		&& (first->value < first->next->next->value))
		return (3);
	else if ((first->value > first->next->value)
		&& (first->next->value > first->next->next->value))
		return (4);
	else
		return (5);
}

size_t	struct_count(t_stack *nodes)
{
	size_t	i;

	i = 0;
	while (nodes)
	{
		nodes = nodes->next;
		i++;
	}
	return (i);
}
