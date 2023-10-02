/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_free_and_error.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:49:13 by ksho              #+#    #+#             */
/*   Updated: 2023/10/02 14:41:37 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_linked_list_circulation(t_stack *head)
{
    if (head == NULL)
        return; 
    t_stack *current = head;
    t_stack *next;

    while (1) {
        next = current;
		current = current -> next;
        free(next);

        if (current == head)
		{
			ft_printf("%p\n",current);
            break;
		}
    }
}

void free_linked_list(t_stack* head) {
    t_stack* current = head;
	t_stack* temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
}