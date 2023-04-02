/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 21:18:32 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/04/02 22:46:26 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	str_array_to_int_list (char *str)
{
	char 	**word_array;
	int		qtt;
	int		i;
	t_list	*nbrs;
	int		tmp;

	i = 0;
	word_array = ft_split(str, ',');
	qtt = c_words(str, ',');
		
	tmp = ft_atoi(word_array[i]);
	nbrs = ft_lstnew((void*) &tmp);
	ft_printf("%i", nbrs->content);
	free_array(word_array, qtt);
}

int	main(int argc, char **argv)
{
    if (argc == 2)
    {
    	str_array_to_int_list(argv[1]);
    }
    return(0);
}
