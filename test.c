#include "push_swap.h"
#include <libc.h>
#include <time.h>
__attribute__((destructor)) static void destructor()
{
	system("leaks -q a.out");
}

#include "push_swap.h"
#include <stdio.h>

// static int	*min_next_min(t_stack *stack_a)
// {
// 	int	*min12;

// 	min12 = (int *)malloc(sizeof(int) * 2);
// 	if (!min12)
// 		exit(EXIT_FAILURE);
// 	min12[0] = stack_a->value;
// 	min12[1] = min12[0];
// 	while (stack_a != NULL)
// 	{
// 		if (stack_a->value < min12[1] || min12[0] == min12[1])
// 			min12[1] = stack_a->value;
// 		if (stack_a->value < min12[0])
// 		{
// 			min12[1] = min12[0];
// 			min12[0] = stack_a->value;
// 		}
// 		stack_a = stack_a->next;
// 	}
// 	return (min12);
// }
#include <stdio.h>

int	*coodinate_compression(int *i, int argc)
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

#include <stdio.h>

int	main(int argc, char **argv)
{
	int		*i;
	int		j;
	t_stack	*stack_a;

	i = (int *)malloc(sizeof(int) * (argc - 1));
	if (!i)
		exit(EXIT_FAILURE);
	j = 0;
	stack_a = NULL;
	while (j < argc - 1)
	{
		i[j] = ft_atoi(argv[j + 1]);
		j++;
	}
	float start = clock();
	i = coodinate_compression(i, argc);
	j = 0;
	while (argc - 1)
	{
		printf("%d\n", i[j]);
		j++;
		argc--;
	}
	float end = clock();
	printf("%f\n", ((double)(end - start)) / CLOCKS_PER_SEC);
	free(i);
}

// int	main(int argc, char **argv)
// {
// 	int *min;
// 	int i;
// 	min = NULL;
// 	t_stack *stack_a;
// 	// t_stack *stack_b;
// 	i = 1;
// 	while (argc - 1 >= i)
// 	{
// 		link_list(&stack_a, ft_atoi(argv[i]));
// 		i++;
// 	}
// 	min = min_next_min(stack_a);
// 	ft_printf("%d %d\n", min[0], min[1]);
// 	free_linked_list(stack_a);
// 	free(min);
// 	return (0);
// }