/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:19:40 by ksho              #+#    #+#             */
/*   Updated: 2023/10/02 15:43:42 by ksho             ###   ########.fr       */
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
#define CHECK_sa 1
#define DEBUG 1
#if(DEBUG)
static void print_list(t_stack *node)
{
	t_stack *current = node;
	while(current != NULL)
	{
		ft_printf("value -> %d\n",current->value);
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
	// t_stack *stack_b;
	t_stack *tmp;

	i = 1;
	stack_a = NULL;
	while (argc - 1 >= i)
	{
		link_list(&stack_a, ft_atoi(argv[i]));
		i++;
	}
	tmp = stack_a;
#if (CHECK_circulater)
	create_circulater_list(stack_a);
#endif
#if(CHECK_sa)
	stack_a = sa(stack_a);
#endif
	
	print_list(stack_a);
	free_linked_list(tmp);
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