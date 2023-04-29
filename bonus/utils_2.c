/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:51:03 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/04/29 17:24:34 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_nbr(char *str)
{
	if (str[0] == '0' && ft_atoi(str) == 0 && str[0] == '\0')
		return (1);
	else if (ft_atoi(str) == 0)
		return (-1);
	else if (ft_atol(str) >= INT_MIN && ft_atol(str) <= INT_MAX)
		return (1);
	return (-1);
}

void	init_utils(t_utils *utils)
{
	utils->a_rotate = 0;
	utils->b_rotate = 0;
	utils->a_data = 0;
	utils->b_data = 0;
	utils->a_revrotate = 0;
	utils->b_revrotate = 0;
	utils->rr = 0;
	utils->rrr = 0;
}
