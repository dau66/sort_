/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:19:40 by ksho              #+#    #+#             */
/*   Updated: 2023/10/03 15:32:19 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}

#include "push_swap.h"
#include <stdio.h>
#define CHECK_circulater 0
#define CHECK_sa 0
#define CHECK_pa 0
#define DEBUG 1
#if(DEBUG)
static void print_list(t_stack *node)
{
	t_stack *current = node;
	while(current != NULL)
	{
		ft_printf("value -> %d[]\n",current->value);
		current = current -> next;
	}
	ft_printf("NULL\n");
}
#endif
int	main(int argc, char **argv)
{
	int				i;
	// int				j = 0;
	t_stack	*stack_a;
	t_stack *stack_b;
	i = 1;
	stack_a = NULL;
	while (argc - 1 >= i)
	{
		link_list(&stack_a, ft_atoi(argv[i]));
		i++;
	}
	sort_small_swap(&stack_a,&stack_b,argc);
#if (CHECK_circulater)
	create_circulater_list(stack_a);
#endif
#if(CHECK_sa)
	sa(&stack_a,1);
#endif
#if(CHECK_pa)
	pa(&stack_a,&stack_b);
	pa(&stack_a,&stack_b);
	pa(&stack_a,&stack_b);
	rr(&stack_a,&stack_b);
#endif
	print_list(stack_a);
	print_list(stack_b);
	free_linked_list(stack_a);
	free_linked_list(stack_b);
	// free_linked_list(tmp1);
	// ft_printf("%d\n,stack_a->value);
}

