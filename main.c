/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:42:25 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/04/18 18:40:51 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	str_to_int_list(t_stack *stack, char *str)
{
	int		i;
	char	**array;
	int		tmp;
	int		size;

	array = ft_split(str, ' ');
	i = 0;
	while (array[i] != NULL)
		i++;
	size = i;
	i--;
	while (i >= 0)
	{
		tmp = ft_atoi(array[i]);
		stack_change(create_node(tmp), stack);
		i--;
	}
	free_array(array, size);
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

void	initialize(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->size = 0;
	stack_b->size = 0;
	stack_a->stack_char = 'a';
	stack_b->stack_char = 'b';
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc == 2)
	{
		initialize(&stack_a, &stack_b);
		str_to_int_list(&stack_a, argv[1]);
		check_algorithm(&stack_a, &stack_b);
		//print_list(&stack_a);
		free_list(&stack_a);
		free_list(&stack_b);
	}
	if (argc > 2)
	{
		initialize(&stack_a, &stack_b);
		arg_to_int_list(argv, argc, &stack_a);
		check_algorithm(&stack_a, &stack_b);
		//print_list(&stack_a);
		free_list(&stack_a);
		free_list(&stack_b);
	}
	return (0);
}
