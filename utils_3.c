/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 01:55:04 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/04/26 02:15:34 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_index(int nbr, t_stack *stack)
{
	int pos;

	pos = 1;
	while (stack->size > 0)
	{
		if (stack->top->nbr == nbr)
		{
			while (stack->size > 0)
			{
				stack->top = stack->top->next;
				return (pos);
			}
		}
		stack->top = stack->top->next;
		pos++;
	}
	return (-1);
}
