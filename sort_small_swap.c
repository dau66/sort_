/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:13:47 by ksho              #+#    #+#             */
/*   Updated: 2023/10/05 14:38:33 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define CHECK 1
static int	*min_next_min(t_stack *stack_a)
{
	int	*min12;

	min12 = (int *)malloc(sizeof(int) * 2);
	if (!min12)
		exit(EXIT_FAILURE);
	min12[0] = stack_a->value;
	min12[1] = min12[0];
	while (stack_a != NULL)
	{
		if (stack_a->value < min12[1] || min12[0] == min12[1])
			min12[1] = stack_a->value;
		if (stack_a->value < min12[0])
		{
			min12[1] = min12[0];
			min12[0] = stack_a->value;
		}
		stack_a = stack_a->next;
	}
	return (min12);
}

static void	sort_3(t_stack **stack_a)
{
	size_t	check;
	t_stack	*first;

	first = *stack_a;
	check = value_compare(first);
	if (check == 0)
	{
		rra(&first, 1);
		sa(&first, 1);
	}
	else if (check == 1)
		sa(&first, 1);
	else if (check == 2)
		ra(&first, 1);
	else if (check == 3)
		sa(&first, 1);
	else if (check == 4)
	{
		ra(&first, 1);
		sa(&first, 1);
	}
	*stack_a = first;
}


static void	until_5(t_stack **stack_a, t_stack **stack_b, size_t count)
{
	int		*min;
	t_stack	*first;
	t_stack	*second;

	first = *stack_a;
	second = *stack_b;
	min = min_next_min(first);
	#if (CHECK)
	if (count == 4)
	{
		while (first->value != min[0])
			ra(&first,1);
		pb(&first,&second);
	}
	else if(count == 5)
	{
		while(first->value != min[0])
			ra(&first,1);
		pa(&first,&second);
		while(first->value != min[1])
			ra(&first,1);
		pa(&first,&second);
	}
	#endif
	sort_3(&first);
	while(second != NULL)
		pa(&second,&first);
	free(min);
	*stack_a = first;
	*stack_b = second;
}



void	sort_small_swap(t_stack **stack_a, t_stack **stack_b, int argc)
{
	t_stack *first;
	t_stack *second;

	first = *stack_a;
	second = *stack_b;
	if (argc - 1 == 3)
		sort_3(&first);
	else if (argc - 1 == 4)
		until_5(&first,&second,4);
	else if(argc - 1 == 5)
		until_5(&first,&second,5);
	*stack_a = first;
	*stack_b = second;
}