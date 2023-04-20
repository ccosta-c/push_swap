/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:36:58 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/04/20 12:55:52 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_algorithm(t_stack *stack_a, t_stack *stack_b)
{
 	if (stack_a->size == 3)
		sort_3(stack_a, stack_b);
	if (stack_a->size == 2)
		sort_2(stack_a, stack_b);
	if (stack_a->size == 5)
		sort_5(stack_a, stack_b);
}

void	sort_3(t_stack *stk, t_stack *stk_b)
{
	if (stk->top->nbr > stk->top->next->nbr && stk->top->next->nbr
		< stk->top->previous->nbr && stk->top->nbr < stk->top->previous->nbr)
		run_operations(stk, stk_b, "sa");
	if (stk->top->nbr < stk->top->next->nbr && stk->top->next->nbr
		> stk->top->previous->nbr && stk->top->nbr > stk->top->previous->nbr)
		run_operations(stk, stk_b, "rra");
	if (stk->top->nbr > stk->top->next->nbr && stk->top->next->nbr
		> stk->top->previous->nbr && stk->top->nbr > stk->top->previous->nbr)
	{
		run_operations(stk, stk_b, "sa");
		run_operations(stk, stk_b, "rra");
	}
	if (stk->top->nbr > stk->top->next->nbr && stk->top->next->nbr
		< stk->top->previous->nbr && stk->top->nbr > stk->top->previous->nbr)
		run_operations(stk, stk_b, "ra");
	if (stk->top->nbr < stk->top->next->nbr && stk->top->next->nbr
		> stk->top->previous->nbr && stk->top->nbr < stk->top->previous->nbr)
	{
		run_operations(stk, stk_b, "sa");
		run_operations(stk, stk_b, "ra");
	}
}

void	sort_2(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->top->nbr > stack_a->top->previous->nbr)
		run_operations(stack_a, stack_b, "sa");
}

void	sort_5(t_stack *stack_a, t_stack *stack_b)
{
	int	position;

	position = find_min(stack_a);
	if (position == 1)
		run_operations(stack_a, stack_b, "pb");
	if (position > 1 && position <= 3)
	{
		while (position > 1)
		{
			run_operations(stack_a, stack_b, "ra");
			position--;
		}
	}
	run_operations(stack_a, stack_b, "pb");
	sort_3(stack_a, stack_b);
	if (stack_a->size == 4)
	{

	}
}