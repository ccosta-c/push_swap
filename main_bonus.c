/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:22:12 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/04/28 17:07:47 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char **argv)
{
	char	*txt;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 2)
	{
		stack_a = malloc(sizeof (t_stack));
		stack_b = malloc(sizeof (t_stack));
		initialize(stack_a, stack_b);
		str_to_int_list(stack_a, argv[1]);
		print_list(stack_a);
		txt = get_next_line(0);
		ft_printf("!!!%s", txt);
	}
}
