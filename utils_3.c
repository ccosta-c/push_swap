/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 01:55:04 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/04/26 15:55:45 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index(int nbr, t_stack *stack)
{
	int	pos;
	int	size_copy;
	int	top;

	top = stack->top->nbr;
	size_copy = stack->size;
	pos = 0;
	while (size_copy > 0)
	{
		if (stack->top->nbr == nbr)
		{
			while (stack->top->nbr != top)
			{
				stack->top = stack->top->next;
			}
			return (pos);
		}
		stack->top = stack->top->next;
		pos++;
	}
	return (-1);
}

int	find_match(t_stack *stack, int nbr)
{
	int	slot;
	int	i;

	i = stack->size;
	slot = find_max(stack);
	if (nbr > slot)
		return (slot);
	while (i > stack->size)
	{
		if (stack->top->nbr > nbr && stack->top->nbr < slot)
		{
			slot = stack->top->nbr;
		}
		stack->top = stack->top->next;
		i--;
	}
	return (slot);
}

void	init_utils(t_utils *utils)
{
	utils->a_rotate = 0;
	utils->b_rotate = 0;
	utils->a_data = 0;
	utils->b_data = 0;
	utils->a_revrotate = 0;
	utils->b_revrotate = 0;
	utils->rr = 0;
	utils->rrr = 0;
}

int	sum_moves(t_utils *utils)
{
	int	total;

	total = 0;
	convert_rotates(utils);
	if (utils->a_rotate)
		total += utils->a_rotate;
	if (utils->b_rotate)
		total += utils->b_rotate;
	if (utils->a_revrotate)
		total += utils->a_revrotate;
	if (utils->b_revrotate)
		total += utils->b_revrotate;
	return (total);
}

void	convert_rotates(t_utils *utils)
{
	while (utils->a_rotate >= 1 && utils->b_rotate >= 1)
	{
		utils->rr += 1;
		utils->a_rotate -= 1;
		utils->b_rotate -= 1;
	}
	while (utils->a_revrotate >= 1 && utils->b_revrotate >= 1)
	{
		utils->rrr += 1;
		utils->a_revrotate -= 1;
		utils->b_revrotate -= 1;
	}
}
