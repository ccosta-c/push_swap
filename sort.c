/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:40:03 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/04/25 19:23:02 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort(t_stack *stack_a, t_stack *stack_b)
{
	//t_utils	utils;

	run_operations(stack_a, stack_b, "pb");
	run_operations(stack_a, stack_b, "pb");
	if (check_revorder(stack_b) == -1)
		run_operations(stack_a, stack_b, "ra");
	find_match(stack_b, stack_a->top->nbr);
	return (0);
}

int	find_match(t_stack *stack, int nbr)
{
	int	slot;

	slot = find_max(stack);
	if (nbr > slot)
		return (find_min(stack));
	while (stack->size > 0)
	{
		if (stack->top->nbr > nbr && stack->top->nbr < slot)
		{
			slot = stack->top->nbr;
		}
		stack->top = stack->top->next;
		stack->size--;
	}
	return (slot);
}
