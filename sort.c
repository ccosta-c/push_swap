/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:40:03 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/05/01 15:14:29 by ccosta-c         ###   ########.fr       */
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

t_utils	sort(t_stack *stack_a, t_stack *stack_b)
{
	t_utils		utils;
	t_utils		best_utils;
	t_stack		*copy;
	int			i;
	int			sum;

	copy = copy_stack(stack_a);
	i = 0;
	init_utils(&utils);
	count_moves(stack_a->top->nbr, stack_a, &utils);
	count_moves(find_match(stack_b, stack_a->top->nbr), stack_b, &utils);
	best_utils = utils;
	sum = sum_moves(&utils);
	init_utils(&utils);
	while (i < copy->size)
	{
		count_moves(copy->top->nbr, stack_a, &utils);
		count_moves(find_match(stack_b, copy->top->nbr), stack_b, &utils);
		if (sum_moves(&utils) == 0)
		{
			best_utils = utils;
			break ;
		}
		if (sum_moves(&utils) < sum)
		{
			best_utils = utils;
			sum = sum_moves(&utils);
			init_utils(&utils);
		}
		else
			init_utils(&utils);
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
