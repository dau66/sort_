/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:49:20 by ksho              #+#    #+#             */
/*   Updated: 2023/10/07 13:29:44 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sorted_checker(t_stack *stack_a)
{
	int	i;

	i = 0;
	while (stack_a->next != NULL)
	{
		if (stack_a->value != i)
			return (0);
		i++;
		stack_a = stack_a->next;
	}
	return (1);
}

static void	radix_sort(t_stack **stack_a, t_stack **stack_b, size_t size,
		size_t i)
{
	size_t	j;
	t_stack	*first;
	t_stack	*second;

	j = 0;
	first = *stack_a;
	second = *stack_b;
	while (sorted_checker(first) == 0)
	{
		while (j < size)
		{
			if ((first->value >> i) & 1)
				ra(&first, 1);
			else
				pb(&first, &second);
			j++;
		}
		j = 0;
		i++;
		while (second)
			pa(&second, &first);
	}
	*stack_a = first;
	*stack_b = second;
}

void	sort_big_swap(t_stack **stack_a, t_stack **stack_b)
{
	size_t	size;
	t_stack	*first;
	t_stack	*second;

	first = *stack_a;
	second = *stack_b;
	size = struct_count(first);
	radix_sort(&first, &second, size, 0);
	*stack_a = first;
	*stack_b = second;
}

// while (sorted_checker(first) == 0)
// {
// 	while(j < size)
// 	{
// 		if ((first->value >> i) & 1)
// 			ra(&first, 1);
// 		else
// 			pb(&first,&second);
// 		j ++;
// 	}
// 	j = 0;
// 	i ++;
// 	while(second)
// 		pa(&second,&first);
// }