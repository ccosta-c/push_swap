/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 18:32:42 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/05/02 00:27:46 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	run_operations(t_stack *stack_a, t_stack *stack_b, char *operation)
{
	if (ft_strncmp("sa\n", operation, 3) == 0)
		return (swap(stack_a));
	if (ft_strncmp("sb\n", operation, 3) == 0)
		return (swap(stack_b));
	if (ft_strncmp("ss\n", operation, 3) == 0)
		return (ss(stack_a, stack_b));
	if (ft_strncmp("pa\n", operation, 3) == 0)
		return (push(stack_b, stack_a));
	if (ft_strncmp("pb\n", operation, 3) == 0)
		return (push(stack_a, stack_b));
	if (ft_strncmp("ra\n", operation, 3) == 0)
		return (rotate(stack_a));
	if (ft_strncmp("rb\n", operation, 3) == 0)
		return (rotate(stack_b));
	if (ft_strncmp("rra\n", operation, 4) == 0)
		return (reverse_rotate(stack_a));
	if (ft_strncmp("rrb\n", operation, 4) == 0)
		return (reverse_rotate(stack_b));
	if (ft_strncmp("rrr\n", operation, 4) == 0)
		return (rrr(stack_a, stack_b));
	if (ft_strncmp("rr\n", operation, 3) == 0)
		return (rr(stack_a, stack_b));
	return (-1);
}

int	swap(t_stack *stack)
{
	int	tmp;

	if (stack->size < 2)
		return (1);
	tmp = stack->top->nbr;
	stack->top->nbr = stack->top->next->nbr;
	stack->top->next->nbr = tmp;
	return (0);
}

int	ss(t_stack *stack_a, t_stack *stack_b)
{
	if (swap(stack_a) == 1)
		return (1);
	if (swap(stack_b) == 1)
		return (1);
	return (0);
}

int	push(t_stack *source, t_stack *destination)
{
	if (source->size == 0)
		return (1);
	stack_change(create_node(source->top->nbr), destination);
	delete_top_node(source);
	source->size -= 1;
	return (0);
}
