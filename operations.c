/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 18:32:42 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/04/18 19:49:05 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_operations(t_stack *stack_a, t_stack *stack_b, char *operation)
{
	if (ft_strncmp("sa", operation, 2) == 0)
		if (swap(stack_a) == 0)
			ft_printf("sa\n");
	if (ft_strncmp("sb", operation, 2) == 0)
		if (swap(stack_b) == 0)
			ft_printf("sb\n");
	if (ft_strncmp("ss", operation, 2) == 0)
		if (ss(stack_a, stack_b) == 0)
			ft_printf("ss\n");
	if (ft_strncmp("pa", operation, 2) == 0)
		if (push(stack_b, stack_a) == 0)
			ft_printf("pa\n");
	if (ft_strncmp("pb", operation, 2) == 0)
		if (push(stack_a, stack_b) == 0)
			ft_printf("pb\n");
	if (ft_strncmp("ra", operation, 2) == 0)
		if (rotate(stack_a) == 0)
			ft_printf("ra\n");
	if (ft_strncmp("rb", operation, 2) == 0)
		if (rotate(stack_a) == 0)
			ft_printf("rb\n");
	run_operations_2(stack_a, stack_b, operation);
}

void	run_operations_2(t_stack *stack_a, t_stack *stack_b, char *operation)
{
	if (ft_strncmp("rr", operation, 2) == 0)
		if (rr(stack_a, stack_b) == 0)
			ft_printf("rr\n");
	if (ft_strncmp("rra", operation, 3) == 0)
		if (reverse_rotate(stack_a) == 0)
			ft_printf("rra\n");
	if (ft_strncmp("rrb", operation, 3) == 0)
		if (reverse_rotate(stack_b) == 0)
			ft_printf("rrb\n");
	if (ft_strncmp("rrr", operation, 3) == 0)
		if (rrr(stack_a, stack_b) == 0)
			ft_printf("rrr\n");
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
