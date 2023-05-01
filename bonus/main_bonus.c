/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:22:12 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/05/01 14:27:06 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	arg_to_int_list(char **argv, int argc, t_stack *stack)
{
	int	tmp;

	argc -= 1;
	if (check_duplicates(argv, argc) == -1)
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

void	initialize(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->size = 0;
	stack_b->size = 0;
	stack_a->id = 'a';
	stack_b->id = 'b';
}

int	create_check(t_stack *stack_a, t_stack *stack_b, char **argv, int argc)
{
	if (arg_to_int_list(argv, argc, stack_a) == -1)
	{
		free_list (stack_a);
		free_list (stack_b);
		write (2, "Error\n", 6);
		return (-1);
	}
	if (check_order(stack_a) == 0)
	{
		free_list (stack_a);
		free_list (stack_b);
		return (-1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc > 2)
	{
		stack_a = malloc(sizeof (t_stack));
		stack_b = malloc(sizeof (t_stack));
		initialize(stack_a, stack_b);
		if (create_check(stack_a, stack_b, argv, argc) == -1)
			return (-1);
		if (parse_operations(stack_a, stack_b) == -1)
			return (-1);
		if (check_order(stack_a) == 0 && stack_b->size == 0)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		free_list (stack_a);
		free_list (stack_b);
	}
}

int	parse_operations(t_stack *stack_a, t_stack *stack_b)
{
	char	*txt;

	while (1)
	{
		txt = get_next_line(0);
		if (!txt)
			break ;
		if (run_operations(stack_a, stack_b, txt) != 0)
		{
			free_list (stack_a);
			free_list (stack_b);
			free(txt);
			write (2, "ERROR\n", 6);
			return (-1);
		}
		free(txt);
	}
	free (txt);
	return (0);
}
