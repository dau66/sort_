/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_intenger.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:56:36 by ksho              #+#    #+#             */
/*   Updated: 2023/10/07 17:01:21 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	over_max_che(char *str, int sign)
{
	long	i;

	i = 0;
	while ('0' <= *str && *str <= '9')
	{
		if (i > LONG_MAX / 10)
			return (LONG_MAX);
		i = i * 10;
		if (i > LONG_MAX - (*str - '0'))
			return (LONG_MAX);
		i = i + *str - '0';
		str++;
	}
	return (i * sign);
}

static long	over_min_che(char *str, int sign)
{
	long	i;

	i = 0;
	while ('0' <= *str && *str <= '9')
	{
		if (i * sign < LONG_MIN / 10)
			return (LONG_MIN);
		i = 10 * i;
		if (i * sign < LONG_MIN + (*str - '0'))
			return (LONG_MIN);
		i = i + *str - '0';
		str++;
	}
	return (i * sign);
}

long	ft_atol(const char *nptr)
{
	int		sign;
	long	i;

	sign = 1;
	i = 0;
	while ((8 < *nptr && *nptr < 14) || (*nptr == 32))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	if (47 < *nptr && *nptr < 58)
	{
		if (sign < 0)
			i = over_min_che((char *)nptr, sign);
		else
			i = over_max_che((char *)nptr, sign);
	}
	return (i);
}

static int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0')
		i++;
	return (str1[i] - str2[i]);
}

int	ft_duplicate(char **argv, int argc)
{
	int	i;
	int	k;

	i = 0;
	k = 1;
	while (i < argc - 1)
	{
		while (k < argc - 1)
		{
			if (ft_strcmp(argv[i + 1], argv[k + 1]) == 0)
				return (0);
			k++;
		}
		i++;
		k = i + 1;
	}
	return (1);
}
