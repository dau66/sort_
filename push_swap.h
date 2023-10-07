/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:15:55 by ksho              #+#    #+#             */
/*   Updated: 2023/10/07 17:18:50 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# define TRUE 1
# define FALSE 0

typedef struct list
{
	struct list	*prev;
	int			value;
	struct list	*next;
}				t_stack;

t_stack			*create_node(int num);
void			link_list(t_stack **head, int num);
void			rotate_left(t_stack **node);
void			rotate_right(t_stack **node);
void			sa(t_stack **node, int bool);
void			sb(t_stack **node, int bool);
void			pa(t_stack **node1, t_stack **node2);
void			pb(t_stack **node1, t_stack **node2);
void			ra(t_stack **node, int bool);
void			rb(t_stack **node, int bool);
void			rra(t_stack **node, int bool);
void			rrb(t_stack **node, int bool);
void			ss(t_stack **node1, t_stack **node2);
void			rr(t_stack **node1, t_stack **node2);
void			rrr(t_stack **node1, t_stack **node2);
void			free_linked_list(t_stack **head);
t_stack			*delete_first_node(t_stack *head);
t_stack			*insert_head(t_stack *head, int value);
size_t			value_compare(t_stack *first);
void			sort_small_swap(t_stack **stack_a, t_stack **stack_b, int argc);
void			sort_big_swap(t_stack **stack_a, t_stack **stack_b);
size_t			struct_count(t_stack *nodes);
int				ft_atoi_puwap_ver(const char *nptr);
int				over_under_checker(int *i, int argc);
void			exit_free(void);
int				ft_duplicate(char **argv, int argc);
int				ft_isdigit_renova(int argc, char **argv);

#endif