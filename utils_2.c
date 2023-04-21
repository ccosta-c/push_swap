/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:51:03 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/04/20 19:55:23 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *stack)
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

int	find_max(t_stack *stack)
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
