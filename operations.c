/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 18:32:42 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/04/18 18:44:05 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->top->nbr;
	stack->top->nbr = stack->top->next->nbr;
	stack->top->next->nbr = tmp;
	ft_printf("s%c\n", stack->stack_char);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

void	push(t_stack *source, t_stack *destination)
{
	if (source->size == 0)
		return ;
	stack_change(create_node(source->top->nbr), destination);
	delete_top_node(source);
	source->size -= 1;
	ft_printf("p%c\n", destination->stack_char);
}
