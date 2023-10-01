/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_free_and_error.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:49:13 by ksho              #+#    #+#             */
/*   Updated: 2023/10/01 19:31:06 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_linked_list(t_stack *head)
{
	t_stack *p;

	p = head;
	while (p)
	{
		t_stack *next;
		next = p->next;
		free(p);
		p = next;
	}
}