/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:19:40 by ksho              #+#    #+#             */
/*   Updated: 2023/10/05 15:03:11 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include "push_swap.h"
#include <stdio.h>
#define CHECK_circulater 0
#define CHECK_sa 0
#define CHECK_pa 0
#define DEBUG 1
#if (DEBUG)
// static void	print_list(t_stack *node)
// {
// 	t_stack	*current;

// 	current = node;
// 	while (current != NULL)
// 	{
// 		ft_printf("value -> %d[]\n", current->value);
// 		current = current->next;
// 	}
// 	ft_printf("NULL\n");
// }

static int	*coodinate_compression(int *i, int argc)
{
	int	*u;
	int	j;
	int	k;

	j = 0;
	k = 0;
	u = (int *)malloc(sizeof(int) * (argc - 1));
	if (!u)
		exit(EXIT_FAILURE);
	while (j < argc - 1)
	{
		u[j] = 0;
		while (k < argc - 1)
		{
			if (i[k] < i[j])
				u[j] += 1;
			k++;
		}
		k = 0;
		j++;
	}
	free(i);
	return (u);
}

#endif
int	main(int argc, char **argv)
{
	int		*i;
	size_t	j;
	t_stack	*stack_a;
	t_stack	*stack_b;

	i = (int *)malloc(sizeof(int) * (argc - 1));
	if (!i)
		exit(EXIT_FAILURE);
	j = 0;
	stack_a = NULL;
	while (j < (size_t)(argc - 1))
	{
		i[j] = ft_atoi(argv[j + 1]);
		j++;
	}
	j = 0;
	i = coodinate_compression(i,argc);
	while(j < (size_t)argc - 1)
		link_list(&stack_a, i[j++]);
	if(argc - 1 < 6)	
		sort_small_swap(&stack_a, &stack_b, argc);
	else
		sort_big_swap(&stack_a,&stack_b);
#if (CHECK_circulater)
	create_circulater_list(stack_a);
#endif
#if (CHECK_sa)
	sa(&stack_a, 1);
#endif
#if (CHECK_pa)
	pa(&stack_a, &stack_b);
	pa(&stack_a, &stack_b);
	pa(&stack_a, &stack_b);
	rr(&stack_a, &stack_b);
#endif
	// print_list(stack_a);
	// print_list(stack_b);
	free_linked_list(stack_a);
	free_linked_list(stack_b);
	free(i);
	// free_linked_list(tmp1);
	// ft_printf("%d\n,stack_a->value);
}
