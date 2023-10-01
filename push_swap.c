/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:19:40 by ksho              #+#    #+#             */
/*   Updated: 2023/10/01 19:31:53 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}

#include "push_swap.h"
#include <stdio.h>
#define CHECK 0

int	main(int argc, char **argv)
{
	int				i;
	t_stack	*stack_a;
	// t_stack *stack_b;

	i = 1;
	stack_a = NULL;
	while (argc - 1 >= i)
	{
		link_list(&stack_a, ft_atoi(argv[i]));
		i++;
	}
#if (CHECK)
	create_circulater_list(stack_a);
#endif
	stack_a = sa(stack_a);
	// while (stack_a->next)
	// 	stack_a = stack_a->next;
	while(stack_a)
	{
		printf("%d\n",stack_a->value);
		stack_a = stack_a->next;
	}
	free_linked_list(stack_a);
	// ft_printf("%d\n,stack_a->value);
}

// int main()
// {
// 	ft_printf("aaa");
// }

// int	main(int argc, char **argv)
// {
// 	size_t	i;

// 	i = 0;
// 	ft_printf("%d\n", argc);
// 	while (argv[i] != NULL)
// 	{
// 		ft_printf("%s\n", argv[i]);
// 		i++;
// 	}
// }

// insert_next(stack_a,100);
// create_circulater_list(stack_a);
// while(stack_a)
// {
// 	ft_printf("%d\n",stack_a->value);
// 	stack_a = stack_a->next;
// }
// free(stack_a);
// while (argc--)
// {
// 	ft_printf("%d\n", ft_atoi(argv[i]));
// 	i++;
// }