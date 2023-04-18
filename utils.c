/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:54:32 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/04/18 16:29:04 by ccosta-c         ###   ########.fr       */
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

void	ft_print_array(char **array)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 3)
	{
		while (array && array[i][j] != '\0')
		{
			ft_printf("%c", array[i][j]);
			j++;
		}
		i++;
		j = 0;
		ft_printf("\n");
	}
}

void	free_list(t_stack *stack)
{
	while (stack->size > 0)
	{
		delete_top_node(stack);
		stack->size--;
	}
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
