/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:21:33 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/05/01 15:39:17 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_stack *stack)
{
	if (stack->size < 2)
		return (1);
	stack->top = stack->top->next;
	return (0);
}

int	rr(t_stack *stack_a, t_stack *stack_b)
{
	if (rotate(stack_a) == 1)
		return (1);
	if (rotate(stack_b) == 1)
		return (1);
	return (0);
}

int	reverse_rotate(t_stack *stack)
{
	if (stack->size < 2)
		return (1);
	stack->top = stack->top->previous;
	return (0);
}

int	rrr(t_stack *stack_a, t_stack *stack_b)
{
	if (reverse_rotate(stack_a) == 1)
		return (1);
	if (reverse_rotate(stack_b) == 1)
		return (1);
	return (0);
}

void	initialize(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->size = 0;
	stack_b->size = 0;
	stack_a->id = 'a';
	stack_b->id = 'b';
}
