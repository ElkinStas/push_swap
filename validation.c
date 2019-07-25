/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhudson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 14:59:03 by bhudson           #+#    #+#             */
/*   Updated: 2019/07/24 14:59:07 by bhudson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check_repeat(t_push *push)
{
	int	i;
	int j;

	i = 0;
	while (i < push->size_a)
	{
		j = 0;
		while (j < push->size_a)
		{
			if (i == j || push->stack_a[i] != push->stack_a[j])
				j++;
			else
				ft_out();
		}
		i++;
	}
	return (1);
}

int		ft_skip_null_znak(char *argv)
{
	int i;

	i = 0;
	while (argv[i] == '0' || argv[i] == '+')
		i++;
	return (i);
}
