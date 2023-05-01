/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:21:30 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/05/01 22:04:06 by ccosta-c         ###   ########.fr       */
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

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	result = 0;
	sign = ft_whitespace(nptr, &i);
	while (nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
	{
		result *= 10;
		result += nptr[i] - 48;
		i++;
	}
	if (nptr[i] == '\0')
	{
		result *= sign;
		return (result);
	}
	return (0);
}
