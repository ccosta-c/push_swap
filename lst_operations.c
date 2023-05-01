/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:41:38 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/04/28 10:52:46 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int nbr)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	new->nbr = nbr;
	new->previous = NULL;
	new->next = NULL;
	return (new);
}

void	stack_change(t_node *new_node, t_stack *stack)
{
	if (stack->size == 0)
	{
		stack->top = new_node;
		stack->top->next = new_node;
		stack->top->previous = new_node;
		stack->size += 1;
		return ;
	}
	new_node->next = stack->top;
	new_node->previous = stack->top->previous;
	stack->top->previous->next = new_node;
	stack->top->previous = new_node;
	stack->top = new_node;
	stack->size += 1;
}

void	delete_top_node(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top;
	stack->top = stack->top->next;
	stack->top->previous->previous->next = stack->top;
	stack->top->previous = stack->top->previous->previous;
	free(tmp);
}

void	execute(t_utils *utils, t_stack *stack_a, t_stack *stack_b)
{
	while (utils->rr)
	{
		run_operations(stack_a, stack_b, "rr");
		utils->rr--;
	}
	while (utils->rrr)
	{
		run_operations(stack_a, stack_b, "rrr");
		utils->rrr--;
	}
	while (utils->a_rotate)
	{
		run_operations(stack_a, stack_b, "ra");
		utils->a_rotate--;
	}
	execute_two(utils, stack_a, stack_b);
}

void	execute_two(t_utils *utils, t_stack *stack_a, t_stack *stack_b)
{
	while (utils->b_rotate)
	{
		run_operations(stack_a, stack_b, "rb");
		utils->b_rotate--;
	}
	while (utils->a_revrotate)
	{
		run_operations(stack_a, stack_b, "rra");
		utils->a_revrotate--;
	}
	while (utils->b_revrotate)
	{
		run_operations(stack_a, stack_b, "rrb");
		utils->b_revrotate--;
	}
	run_operations(stack_a, stack_b, "pb");
}
