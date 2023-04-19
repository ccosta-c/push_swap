/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 20:06:08 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/04/19 10:32:40 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	struct s_node		*top;
	int					size;
}						t_stack;

typedef struct s_node
{
	int					nbr;
	struct s_node		*next;
	struct s_node		*previous;
}						t_node;

void	str_to_int_list(t_stack *stack, char *str);
t_node	*create_node(int nbr);
void	stack_change(t_node *new_node, t_stack *stack);
void	initialize(t_stack *stack_a, t_stack *stack_b);
void	print_list(t_stack *stack);
void	ft_print_array(char **array);
void	arg_to_int_list(char **argv, int argc, t_stack *stack);
int		swap(t_stack *stack);
int		ss(t_stack *stack_a, t_stack *stack_b);
int		push(t_stack *source, t_stack *destination);
void	delete_top_node(t_stack *stack);
int		reverse_rotate(t_stack *stack);
int		rrr(t_stack *stack_a, t_stack *stack_b);
int		rotate(t_stack *stack);
int		rr(t_stack *stack_a, t_stack *stack_b);
void	sort_3(t_stack *stk, t_stack *stk_b);
void	free_list(t_stack *stack);
void	free_array(char **array, int y);
void	check_algorithm(t_stack *stack_a, t_stack *stack_b);
void	run_operations(t_stack *stack_a, t_stack *stack_b, char *operation);
void	run_operations_2(t_stack *stack_a, t_stack *stack_b, char *operation);
void	sort_2(t_stack *stack_a, t_stack *stack_b);
void	sort_5(t_stack *stack_a, t_stack *stack_b);

#endif
