/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:36:58 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/04/19 10:15:14 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_algorithm(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 3)
		sort_3(stack_a, stack_b);
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
