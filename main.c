/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:42:25 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/04/15 19:27:38 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	str_to_int_list(t_stack *stack, char *str)
{
	int		i;
	char	**array;
	int		tmp;

	array = ft_split(str, ' ');
	i = 0;
	while (array[i] != NULL)
		i++;
	i--;
	while (i >= 0)
	{
		tmp = ft_atoi(array[i]);
		stack_change(create_node(tmp), stack);
		i--;
	}
}

void	arg_to_int_list(char **argv, int argc, t_stack *stack)
{
	int	tmp;

	argc -= 1;
	while (argc > 0)
	{
		tmp = ft_atoi(argv[argc]);
		stack_change(create_node(tmp), stack);
		argc--;
	}
}

void	initialize(t_stack *stack)
{
	stack->size = 0;
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;

	if (argc == 2)
	{
		initialize(&stack_a);
		str_to_int_list(&stack_a, argv[1]);
		print_list(&stack_a);
	}
	if (argc > 2)
	{
		initialize(&stack_a);
		arg_to_int_list(argv, argc, &stack_a);
		print_list(&stack_a);
	}
	return (0);
}
