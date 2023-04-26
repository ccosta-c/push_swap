/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:40:03 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/04/26 03:10:12 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort(t_stack *stack_a, t_stack *stack_b)
{
	t_utils utils;
	t_utils best_utils;
	int     i;
	int     sum;

	i = 0;
	init_utils(&utils);
	run_operations(stack_a, stack_b, "pb");
	run_operations(stack_a, stack_b, "pb");
	if (check_revorder(stack_b) == -1)
		run_operations(stack_a, stack_b, "rb");
	count_moves(stack_a->top->nbr, stack_a, &utils);
	count_moves(find_match(stack_b, stack_a->top->nbr), stack_b, &utils);
	best_utils = utils;
	sum = sum_moves(&utils);
	init_utils(&utils);
	while (i < stack_a->size)
	{
		count_moves((stack_a->top->nbr, stack_a, &utils);
		count_moves(find_match(stack_b, stack_a->top->nbr), stack_b, &utils);
	}
	return (0);
}

void    count_moves(int nbr, t_stack *stack, t_utils *utils)
{
	int nbr_pos;
	int middle_stack;

	nbr_pos = find_index(nbr, stack);
	middle_stack = stack->size / 2;
	if (stack->id == 'a')
		utils->a_data = nbr;
	else if (stack->id == 'b')
		utils->b_data = nbr;
	if (nbr_pos == middle_stack || nbr_pos < middle_stack)
	{
		if (stack->id == 'a')
			utils->a_rotate = nbr_pos;
		if (stack->id == 'b')
			utils->b_rotate = nbr_pos;
	}
	if (nbr_pos > middle_stack)
	{
		if (stack->id == 'a')
			utils->a_revrotate = nbr_pos;
		if (stack->id == 'b')
			utils->b_revrotate = nbr_pos;
	}
}