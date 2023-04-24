/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:40:03 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/04/24 15:49:49 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort(t_stack *stack_a, t_stack *stack_b)
{
	run_operations(stack_a, stack_b, "pb");
	run_operations(stack_a, stack_b, "pb");
	if (check_revorder(stack_b) == -1)
		run_operations(stack_a, stack_b, "ra");

	return (0);
}
