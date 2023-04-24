/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 20:17:10 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/04/24 10:40:00 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_whitespace(const char *str, int *ptr_i)
{
	int	i;
	int	minus;

	i = 0;
	minus = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
	{
		i++;
	}
	if (str[i] == '-')
	{
		minus *= -1;
		i++;
	}
	if (str[i] == '+')
	{
		i++;
	}
	*ptr_i = i;
	return (minus);
}

long	ft_atol(const char *nptr)
{
	int		i;
	long	sign;
	long	result;

	result = 0;
	sign = ft_whitespace(nptr, &i);
	while (nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
	{
		result *= 10;
		result += nptr[i] - 48;
		i++;
	}
	result *= sign;
	return (result);
}
