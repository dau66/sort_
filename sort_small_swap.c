/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:13:47 by ksho              #+#    #+#             */
/*   Updated: 2023/10/04 15:50:58 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	until_6(t_stack **stack_a, t_stack **stack_b,size_t count)
{
	
}


void	sort_3(t_stack **stack_a)
{
	size_t check;
	t_stack	*first;

	first = *stack_a;
	check = value_compare(first);
	
	if(check == 0)
	{
		rra(&first,1);
		sa(&first, 1);
	}
	else if(check == 1)
		sa(&first,1);
	else if(check == 2)
		ra(&first,1);
	else if(check == 3)
		sa(&first,1);
	else if(check == 4)
	{
		ra(&first,1);
		sa(&first,1);
	}
	
	*stack_a = first;
}

void	sort_small_swap(t_stack **stack_a, t_stack **stack_b, int argc)
{
	t_stack *first;
	t_stack *second;

	first = *stack_a;
	second = *stack_b;
	if (argc - 1 == 3)
		sort_3(&first);
	// else if (argc - 1 == 4)
	// 	sort_4(&first, &second);
	// else if (argc - 1 == 5)
	// 	sort_5(&first, &second);
	// else if (argc - 1 == 6)
	// sort_6(&first, &second);
	*stack_a = first;
	*stack_b = second;
}