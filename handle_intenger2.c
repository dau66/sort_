/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_intenger2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:03:06 by ksho              #+#    #+#             */
/*   Updated: 2023/10/07 18:19:41 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	signed_checker(char **argv, int i)
{
	int	k;

	k = 0;
	if (((argv[i + 1][0] == '-') || (argv[i + 1][0] == '+')) && (argv[i
			+ 1][1] == '\0'))
		k++;
	if (('0' > argv[i + 1][0] || argv[i + 1][0] > '9') && (argv[i
			+ 1][0] != '-') && (argv[i + 1][0] != '+'))
		k++;
	return (k);
}

int	ft_isdigit_renova(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < argc - 1)
	{
		if (signed_checker(argv, i))
			return (0);
		while (argv[i + 1][j] != '\0')
		{
			if (('0' <= argv[i + 1][j] && argv[i + 1][j] <= '9'))
				j++;
			else
				return (0);
		}
		j = 1;
		i++;
	}
	return (1);
}
