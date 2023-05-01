/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:54:32 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/05/01 20:37:08 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		ft_printf("%i\n", stack->top->nbr);
		stack->top = stack->top->next;
		i++;
	}
}

void	free_list(t_stack *stack)
{
	while (stack->size > 0)
	{
		delete_top_node(stack);
		stack->size--;
	}
	free(stack);
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

void	free_array(char **array, int y)
{
	int	i;

	i = 0;
	while (i < y)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

t_stack	*copy_stack( t_stack *stack)
{
	t_stack	*copy;

	copy = malloc(sizeof (t_stack));
	copy->size = stack->size;
	copy->top = stack->top;
	copy->id = stack->id;
	return (copy);
}
