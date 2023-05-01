/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:40:03 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/05/01 19:33:24 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_stack *stack_a, t_stack *stack_b)
{
	t_utils		utils;
	int			i;

	init_utils(&utils);
	run_operations(stack_a, stack_b, "pb");
	run_operations(stack_a, stack_b, "pb");
	if (check_revorder(stack_b) == -1)
		run_operations(stack_a, stack_b, "rb");
	while (stack_a->size > 0)
	{
		utils = sort(stack_a, stack_b);
		execute(&utils, stack_a, stack_b);
	}
	count_moves(find_max(stack_b), stack_b, &utils);
	execute(&utils, stack_a, stack_b);
	i = stack_b->size;
	while (i > 0)
	{
		run_operations(stack_a, stack_b, "pa");
		i--;
	}
}

int	pls_work(t_utils *best_utils, t_utils *utils)
{
	if (sum_moves(utils) == 0)
	{
		*best_utils = *utils;
		return (-1);
	}
	if (sum_moves(utils) < (*best_utils).sum)
	{
		*best_utils = *utils;
		(*best_utils).sum = sum_moves(utils);
	}
	return (0);
}

t_utils	sort(t_stack *stack_a, t_stack *stack_b)
{
	t_utils		utils;
	t_utils		best_utils;
	t_stack		*copy;
	int			i;

	copy = copy_stack(stack_a);
	i = 0;
	init_utils(&utils);
	count_moves(stack_a->top->nbr, stack_a, &utils);
	count_moves(find_match(stack_b, stack_a->top->nbr), stack_b, &utils);
	best_utils = utils;
	best_utils.sum = sum_moves(&utils);
	while (i < copy->size)
	{
		init_utils(&utils);
		count_moves(copy->top->nbr, stack_a, &utils);
		count_moves(find_match(stack_b, copy->top->nbr), stack_b, &utils);
		if (pls_work(&best_utils, &utils) == -1)
			break ;
		copy->top = copy->top->next;
		i++;
	}
	free_list(copy);
	return (best_utils);
}

void	count_moves(int nbr, t_stack *stack, t_utils *utils)
{
	int	nbr_pos;
	int	middle_stack;

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
			utils->a_revrotate = (stack->size - nbr_pos);
		if (stack->id == 'b')
			utils->b_revrotate = (stack->size - nbr_pos);
	}
}
