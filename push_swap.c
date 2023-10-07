/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:19:40 by ksho              #+#    #+#             */
/*   Updated: 2023/10/07 17:55:22 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <libc.h>
#include <stdio.h>

__attribute__((destructor)) static void destructor()
{
	system("leaks -q push_swap");
}

static int	*handle_compression(int *i, int *u, int argc)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
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
	return (u);
}

static int	*coodinate_compression(int *i, int argc)
{
	int	*u;
	int	j;
	int	k;

	j = 0;
	k = 0;
	u = (int *)malloc(sizeof(int) * (argc - 1));
	if (!u)
	{
		free(i);
		exit_free();
	}
	u = handle_compression(i, u, argc);
	free(i);
	return (u);
}

// while (j < argc - 1)
// {
// 	u[j] = 0;
// 	while (k < argc - 1)
// 	{
// 		if (i[k] < i[j])
// 			u[j] += 1;
// 		k++;
// 	}
// 	k = 0;
// 	j++;
// }

static void	fit_number(int **i, int argc, char **argv)
{
	int	k;
	int	*j;

	k = 0;
	j = *i;
	if (ft_isdigit_renova(argc, argv) == 0 || ft_duplicate(argv, argc) == 0)
	{
		free(j);
		*i = j;
		exit_free();
	}
	while (k < (argc - 1))
	{
		if (ft_atol(argv[k + 1]) > INT_MAX || ft_atol(argv[k + 1]) < INT_MIN)
		{
			ft_printf("Error\n");
			free(j);
			*i = j;
			exit(EXIT_FAILURE);
		}
		j[k] = ft_atol(argv[k + 1]);
		k++;
	}
	*i = j;
}

int	main(int argc, char **argv)
{
	int		*i;
	size_t	j;
	t_stack	*stack_a;
	t_stack	*stack_b;

	i = (int *)malloc(sizeof(int) * (argc - 1));
	if (!i)
		exit_free();
	j = 0;
	fit_number(&i, argc, argv);
	i = coodinate_compression(i, argc);
	while (j < (size_t)(argc - 1))
	{
		link_list(&stack_a, i[j]);
		j++;
	}
	if (argc - 1 < 6)
		sort_small_swap(&stack_a, &stack_b, argc);
	else
		sort_big_swap(&stack_a, &stack_b);
	free_linked_list(&stack_a);
	free_linked_list(&stack_b);
	free(i);
	exit(EXIT_SUCCESS);
}
