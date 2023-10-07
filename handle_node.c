/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:09:39 by ksho              #+#    #+#             */
/*   Updated: 2023/10/07 18:29:29 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*insert_head(t_stack *head, int value)
{
	t_stack	*newnode;

	newnode = create_node(value);
	newnode->next = head;
	newnode->prev = NULL;
	if (head != NULL)
		head->prev = newnode;
	return (newnode);
}

t_stack	*delete_first_node(t_stack *head)
{
	size_t	i;
	t_stack	*new_head;

	i = struct_count(head);
	if (i == 1)
	{
		free(head);
		return (NULL);
	}
	if (!head)
		return (NULL);
	new_head = head->next;
	new_head->prev = NULL;
	free(head);
	return (new_head);
}

t_stack	*create_node(int num)
{
	t_stack	*newnode;

	newnode = (t_stack *)malloc(sizeof(t_stack));
	if (!newnode)
		return (NULL);
	newnode->value = num;
	newnode->prev = NULL;
	newnode->next = NULL;
	return (newnode);
}

void	link_list(t_stack **head, int num)
{
	size_t	i;
	t_stack	*new;
	t_stack	*p;

	i = 0;
	p = *head;
	if (!p)
	{
		*head = create_node(num);
		if ((*head) == NULL)
			exit_free();
		return ;
	}
	new = create_node(num);
	if (!new)
	{
		free_linked_list(&p);
		*head = p;
		exit_free();
	}
	while (p->next != NULL)
		p = p->next;
	p->next = new;
	new->prev = p;
}
