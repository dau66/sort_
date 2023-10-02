/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:15:55 by ksho              #+#    #+#             */
/*   Updated: 2023/10/02 15:38:52 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct list
{
	struct list	*prev;
	int			value;
	struct list	*next;
}				t_stack;

t_stack			*create_node(int num);
void			link_list(t_stack **head, int num);
void			create_circulater_list(t_stack *node);
void			free_linked_list_circulation(t_stack *head);
void			rotate_left(t_stack **node);
void			rotate_right(t_stack **node);
t_stack			*sa(t_stack *node);
t_stack			*sb(t_stack *node);
void			pa(t_stack **node1, t_stack **node2);
void			pb(t_stack **node1, t_stack **node2);
void			free_linked_list(t_stack *head);
t_stack			*delete_first_node(t_stack *head);
t_stack			*insert_head(t_stack *head,int value);
#endif