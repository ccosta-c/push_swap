/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 20:06:08 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/04/15 15:38:47 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct			s_stack
{
	struct s_node		*top;
	int					size;
}						t_stack;

typedef struct			s_node
{
	int					content;
	struct s_node		*next;
	struct s_node		*previous;
}						t_node;

void	str_to_int_list (t_stack *stack, char *str);
t_node  *create_node(int nbr);
void	stack_change(t_node *new_node, t_stack *stack);
void	initialize(t_stack *stack);
void    print_list(t_stack *stack);
void	ft_print_array(char **array);
void    arg_to_int_list(char **argv, int argc, t_stack *stack);

#endif
