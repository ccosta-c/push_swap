/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:03:07 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/04/24 12:40:50 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checks(t_stack *stack_a)
{
	if (check_order(stack_a) == -1)
		return (-1);
	return (0);
}

int	check_order(t_stack *stack_a)
{
	int	i;

	i = stack_a->size;
	while (i > 1)
	{
		if (stack_a->top->nbr > stack_a->top->next->nbr)
			return (0);
		stack_a->top = stack_a->top->next;
		i--;
	}
	stack_a->top = stack_a->top->next;
	return (-1);
}

int	check_duplicates(char **array, int i)
{
	int	j;

	while (i >= 0)
	{
		j = i - 1;
		while (j > 0)
		{
			if (ft_atoi(array[j]) == ft_atoi(array[i]))
				return (-1);
			j--;
		}
		i--;
	}
	return (0);
}
