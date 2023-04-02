/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 21:58:11 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/04/02 22:11:11 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(char **array, int y)
{
	int	i;

	i = 0;
	while (i < y)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_print_array(char **array, int limit)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < limit)
	{
		while (array && array[i][j] != '\0')
		{
			ft_printf("%c", array[i][j]);
			j++;
		}
		i++;
		j = 0;
		ft_printf("\n");
	}
}