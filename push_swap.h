/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 20:06:08 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/04/18 18:40:20 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	struct s_node		*top;
	int					size;
	char				stack_char;
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
void	swap(t_stack *stack);
void	push(t_stack *source, t_stack *destination);
void	delete_top_node(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	rotate(t_stack *stack);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	sort_3(t_stack *stack_a);
void	free_list(t_stack *stack);
void	free_array(char **array, int y);
void	check_algorithm(t_stack *stack_a, t_stack *stack_b);

#endif
