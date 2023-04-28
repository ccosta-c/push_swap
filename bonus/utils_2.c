/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:51:03 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/04/22 21:03:21 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	find_posmin(t_stack *stack)
{
	int	position;
	int	min;
	int	i;

	i = 1;
	min = 0;
	position = 0;
	while (stack->size >= i)
	{
		if (i == 1)
		{
			min = stack->top->nbr;
			position = 1;
		}
		if (stack->top->nbr < min)
		{
			min = stack->top->nbr;
			position = i;
		}
		stack->top = stack->top->next;
		i++;
	}
	return (position);
}

int	find_posmax(t_stack *stack)
{
	int	position;
	int	max;
	int	i;

	i = 1;
	while (stack->size >= i)
	{
		if (i == 1)
		{
			max = stack->top->nbr;
			position = 1;
		}
		if (stack->top->nbr > max)
		{
			max = stack->top->nbr;
			position = i;
		}
		stack->top = stack->top->next;
		i++;
	}
	return (position);
}

int	is_nbr(char *str)
{
	if (str[0] == '0' && ft_atoi(str) == 0 && str[0] == '\0')
		return (1);
	else if (ft_atoi(str) == 0)
		return (-1);
	else if (ft_atol(str) >= INT_MIN && ft_atol(str) <= INT_MAX)
		return (1);
	return (-1);
}

int	find_max(t_stack *stack)
{
	int	max;
	int	i;

	i = 1;
	while (stack->size >= i)
	{
		if (i == 1)
		{
			max = stack->top->nbr;
		}
		if (stack->top->nbr > max)
		{
			max = stack->top->nbr;
		}
		stack->top = stack->top->next;
		i++;
	}
	return (max);
}

int	find_min(t_stack *stack)
{
	int	min;
	int	i;

	i = 1;
	min = 0;
	while (stack->size >= i)
	{
		if (i == 1)
		{
			min = stack->top->nbr;
		}
		if (stack->top->nbr < min)
		{
			min = stack->top->nbr;
		}
		stack->top = stack->top->next;
		i++;
	}
	return (min);
}
