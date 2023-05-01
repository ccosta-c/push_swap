/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:51:03 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/05/01 18:51:37 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_nbr(char *str)
{
	if (str[0] == '0' && ft_atoi(str) == 0 && str[1] == '\0')
		return (1);
	else if (ft_atoi(str) == 0)
		return (-1);
	else if (ft_atol(str) >= INT_MIN && ft_atol(str) <= INT_MAX)
		return (1);
	return (-1);
}

void	initialize(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->size = 0;
	stack_b->size = 0;
	stack_a->id = 'a';
	stack_b->id = 'b';
}

void	free_lists(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->size > 0)
	{
		delete_top_node(stack_a);
		stack_a->size--;
	}
	free(stack_a);
	while (stack_b->size > 0)
	{
		delete_top_node(stack_b);
		stack_b->size--;
	}
	free(stack_b);
}
