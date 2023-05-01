/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:54:32 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/04/28 11:14:17 by ccosta-c         ###   ########.fr       */
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
	int		i;
	int		ref;

	copy = malloc(sizeof (t_stack));
	copy->size = 0;
	copy->id = stack->id;
	i = stack->size;
	ref = stack->top->nbr;
	stack->top = stack->top->previous;
	while (i > 0)
	{
		stack_change(create_node(stack->top->nbr), copy);
		stack->top = stack->top->previous;
		i--;
	}
	while (stack->top->nbr != ref)
		stack->top = stack->top->next;
	return (copy);
}
