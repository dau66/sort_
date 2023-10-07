/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_free_and_error.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:49:13 by ksho              #+#    #+#             */
/*   Updated: 2023/10/07 15:18:47 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_free(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

int	over_under_checker(int *i, int argc)
{
	int	j;

	j = 0;
	while (j < argc - 1)
	{
		if (i[j] > INT_MAX || i[j] < INT_MIN)
		{
			free(i);
			ft_printf("Error\n");
			return (0);
		}
		j++;
	}
	return (1);
}

void	free_linked_list(t_stack **head)
{
	t_stack	*current;
	t_stack	*temp;

	current = *head;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}
