/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:36:58 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/04/18 18:08:19 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_algorithm(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	if (stack_a->size == 3)
		sort_3(stack_a);
}

void	sort_3(t_stack *stk)
{
	if (stk->top->nbr > stk->top->next->nbr && stk->top->next->nbr
		< stk->top->previous->nbr && stk->top->nbr < stk->top->previous->nbr)
		swap(stk);
	if (stk->top->nbr > stk->top->next->nbr && stk->top->next->nbr
		> stk->top->previous->nbr && stk->top->nbr > stk->top->previous->nbr)
	{
		swap(stk);
		reverse_rotate(stk);
	}
	if (stk->top->nbr > stk->top->next->nbr && stk->top->next->nbr
		< stk->top->previous->nbr && stk->top->nbr > stk->top->previous->nbr)
		rotate(stk);
	if (stk->top->nbr > stk->top->next->nbr && stk->top->next->nbr
		> stk->top->previous->nbr && stk->top->nbr < stk->top->previous->nbr)
	{
		swap(stk);
		rotate(stk);
	}
	if (stk->top->nbr < stk->top->next->nbr && stk->top->next->nbr
		> stk->top->previous->nbr && stk->top->nbr > stk->top->previous->nbr)
		reverse_rotate(stk);
}
