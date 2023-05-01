/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:03:07 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/05/01 22:53:25 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checks(t_stack *stack_a)
{
	if (check_order(stack_a) == 0)
		return (-1);
	return (0);
}

int	check_order(t_stack *stack)
{
	int		i;
	t_stack	*copy;

	copy = copy_stack(stack);
	i = stack->size;
	while (i > 1)
	{
		if (copy->top->nbr > copy->top->next->nbr)
		{
			free(copy);
			return (-1);
		}
		copy->top = copy->top->next;
		i--;
	}
	free(copy);
	return (0);
}

int	check_dups(char **array, int i)
{
	int	j;

	while (i >= 0)
	{
		j = i - 1;
		while (j >= 0)
		{
			if (ft_atoi(array[j]) == ft_atoi(array[i]))
				return (-1);
			j--;
		}
		i--;
	}
	return (0);
}

int	check_revorder(t_stack *stack)
{
	int		i;
	t_stack	*copy;

	copy = copy_stack(stack);
	i = stack->size;
	while (i > 1)
	{
		if (copy->top->nbr < copy->top->next->nbr)
		{
			free(copy);
			return (-1);
		}
		copy->top = copy->top->next;
		i--;
	}
	free(copy);
	return (0);
}

int	parse_array(char **array, int len, t_stack *stack)
{
	int	i;
	int	tmp;

	tmp = 0;
	i = len - 1;
	while (i >= 0)
	{
		if (is_nbr(array[i]) == -1)
			return (-1);
		tmp = ft_atoi(array[i]);
		stack_change(create_node(tmp), stack);
		i--;
	}
	return (0);
}
