/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:21:33 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/04/18 18:43:13 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->top = stack->top->next;
	ft_printf("r%c\n", stack->stack_char);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

void	reverse_rotate(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->top = stack->top->previous;
	ft_printf("rr%c\n", stack->stack_char);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
