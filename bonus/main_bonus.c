/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:22:12 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/04/29 00:42:58 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	str_to_int_list(t_stack *stack, char *str)
{
	int		i;
	char	**array;
	int		tmp;
	int		len;

	array = ft_split(str, ' ');
	i = 0;
	while (array[i] != NULL)
		i++;
	len = i;
	i--;
	if (check_duplicates(array, i) == -1)
	{
		free_array(array, len);
		return (-1);
	}
	while (i >= 0)
	{
		if (is_nbr(array[i]) == -1)
		{
			free_array(array, len);
			return (-1);
		}
		tmp = ft_atoi(array[i]);
		stack_change(create_node(tmp), stack);
		i--;
	}
	free_array(array, len);
	return (0);
}

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
