/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:06:42 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/05/01 22:46:38 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	struct s_node		*top;
	int					size;
	char				id;
}						t_stack;

typedef struct s_node
{
	int					nbr;
	struct s_node		*next;
	struct s_node		*previous;
}						t_node;

typedef struct s_utils
{
	int		a_data;
	int		b_data;
	int		a_revrotate;
	int		a_rotate;
	int		b_revrotate;
	int		b_rotate;
	int		rr;
	int		rrr;
	int		sum;
}			t_utils;

int		str_to_int_list(t_stack *stack, char *str);
t_node	*create_node(int nbr);
void	stack_change(t_node *new_node, t_stack *stack);
void	initialize(t_stack *stack_a, t_stack *stack_b);
void	print_list(t_stack *stack);
void	ft_print_array(char **array);
int		arg_to_int_list(char **argv, int argc, t_stack *stack);
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
int		find_posmin(t_stack *stack);
int		find_posmax(t_stack *stack);
void	nbr_rotates(t_stack *stack_a, t_stack *stack_b, int position);
int		check_order(t_stack *stack);
int		check_revorder(t_stack *stack);
int		check_dups(char **array, int i);
int		checks(t_stack *stack_a);
int		is_nbr(char *str);
t_utils	sort(t_stack *stack_a, t_stack *stack_b);
int		find_match(t_stack *stack, int nbr);
int		find_max(t_stack *stack);
int		find_min(t_stack *stack);
int		find_index(int nbr, t_stack *stack);
void	count_moves(int nbr, t_stack *stack, t_utils *utils);
void	init_utils(t_utils *utils);
int		sum_moves(t_utils *utils);
void	convert_rotates(t_utils *utils);
void	execute(t_utils *utils, t_stack *stack_a, t_stack *stack_b);
void	sort_big(t_stack *stack_a, t_stack *stack_b);
t_stack	*copy_stack( t_stack *stack);
void	execute_two(t_utils *utils, t_stack *stack_a, t_stack *stack_b);
void	free_lists(t_stack *stack_a, t_stack *stack_b);
void	str_handler(t_stack *stack_a, t_stack *stack_b, char **argv);
void	argv_handler(t_stack *stack_a, t_stack *stack_b, char **argv, int argc);
int		parse_array(char **array, int len, t_stack *stack);
int		check_dups_argc(char **array, int i);

#endif
