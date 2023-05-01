/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:42:25 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/05/01 19:35:02 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	str_to_int_list(t_stack *stack, char *str)
{
	int		i;
	char	**array;
	int		len;

	array = ft_split(str, ' ');
	i = 0;
	while (array[i] != NULL)
		i++;
	len = i;
	i--;
	if (check_dups(array, i) == -1 || parse_array(array, len, stack) == -1)
	{
		free_array(array, len);
		return (-1);
	}
	free_array(array, len);
	return (0);
}

int	arg_to_int_list(char **argv, int argc, t_stack *stack)
{
	int	tmp;

	argc -= 1;
	if (check_dups(argv, argc) == -1)
		return (-1);
	while (argc > 0)
	{
		if (is_nbr(argv[argc]) == -1)
			return (-1);
		tmp = ft_atoi(argv[argc]);
		stack_change(create_node(tmp), stack);
		argc--;
	}
	return (0);
}

void	str_handler(t_stack *stack_a, t_stack *stack_b, char **argv)
{
	if (str_to_int_list(stack_a, argv[1]) == -1)
	{
		write(2, "Error\n", 6);
		free_lists(stack_a, stack_b);
		return ;
	}
	if (checks(stack_a) == -1)
	{
		free_lists(stack_a, stack_b);
		return ;
	}
	check_algorithm(stack_a, stack_b);
	free_lists(stack_a, stack_b);
}

void	argv_handler(t_stack *stack_a, t_stack *stack_b, char **argv, int argc)
{
	if (arg_to_int_list(argv, argc, stack_a) == -1)
	{
		write(2, "Error\n", 6);
		free_lists(stack_a, stack_b);
		return ;
	}
	if (checks(stack_a) == -1)
	{
		free_lists(stack_a, stack_b);
		return ;
	}
	check_algorithm(stack_a, stack_b);
	free_lists(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = malloc(sizeof (t_stack));
	stack_b = malloc(sizeof (t_stack));
	initialize(stack_a, stack_b);
	if (argc == 2)
		str_handler(stack_a, stack_b, argv);
	if (argc > 2)
		argv_handler(stack_a, stack_b, argv, argc);
	return (0);
}
