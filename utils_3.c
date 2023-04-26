/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 01:55:04 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/04/26 23:55:09 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index(int nbr, t_stack *stack)
{
	int     i;
	t_stack *copy;

	copy = copy_stack(stack);
	i = 0;
	while (copy->top->nbr != nbr)
	{
		i++;
		copy->top = copy->top->next;
	}
	free_list(copy);
	return (i);
}

int	find_match(t_stack *stack, int nbr)
{
	t_stack *copy;
	int match;

	copy = copy_stack(stack);
	match = find_min(copy);
	if (nbr > find_max(copy))
		return (find_max(copy));
	else
	{
		while (copy->size > 0)
		{
			if(copy->top->nbr < nbr && copy->top->nbr > match)
				match = copy->top->nbr;
			copy->top = copy->top->next;
			copy->size--;
		}
	}
	free_list(copy);
	return (match);
}

//check
void	init_utils(t_utils *utils)
{
	utils->a_rotate = 0;
	utils->b_rotate = 0;
	utils->a_data = 0;
	utils->b_data = 0;
	utils->a_revrotate = 0;
	utils->b_revrotate = 0;
	utils->rr = 0;
	utils->rrr = 0;
}

//check
int	sum_moves(t_utils *utils)
{
	int	total;

	total = 0;
	convert_rotates(utils);
	if (utils->a_rotate)
		total += utils->a_rotate;
	if (utils->b_rotate)
		total += utils->b_rotate;
	if (utils->a_revrotate)
		total += utils->a_revrotate;
	if (utils->b_revrotate)
		total += utils->b_revrotate;
	if (utils->rr)
		total += utils->rr;
	if (utils->rrr)
		total += utils->rrr;
	return (total);
}

//check
void	convert_rotates(t_utils *utils)
{
	while (utils->a_rotate >= 1 && utils->b_rotate >= 1)
	{
		utils->rr += 1;
		utils->a_rotate -= 1;
		utils->b_rotate -= 1;
	}
	while (utils->a_revrotate >= 1 && utils->b_revrotate >= 1)
	{
		utils->rrr += 1;
		utils->a_revrotate -= 1;
		utils->b_revrotate -= 1;
	}
}

t_stack *copy_stack( t_stack *stack)
{
	t_stack *copy;
	int i;
	int ref;

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