/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhudson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 14:58:05 by bhudson           #+#    #+#             */
/*   Updated: 2019/07/24 14:58:08 by bhudson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(long *a, long *b)
{
	long tmp_a;

	tmp_a = *a;
	*a = *b;
	*b = tmp_a;
}

void	swap_operations(t_push *push, char letter)
{
	if (push->size_a > 1 && letter == 'a')
		ft_swap(&push->stack_a[0], &push->stack_a[1]);
	if (push->size_a > 1 && letter == 'b')
		ft_swap(&push->stack_b[0], &push->stack_b[1]);
	if (letter == 's')
	{
		swap_operations(push, 'a');
		swap_operations(push, 'b');
	}
	printstack(push);
}

void	ft_do_rra(t_push *push, int *i)
{
	while ((*i) > 0)
	{
		push->stack_a[*i] = push->stack_a[*i - 1];
		(*i)--;
	}
}

void	reverse_rotate_double(t_push *push)
{
	reverse_rotate_operations(push, 'a');
	reverse_rotate_operations(push, 'b');
}

void	reverse_rotate_operations(t_push *push, char letter)
{
	long	tmp;
	int		i;

	i = letter == 'a' ? push->size_a - 1 : push->size_b - 1;
	if (i != -1)
		tmp = letter == 'a' ? push->stack_a[i] : push->stack_b[i];
	if (letter == 'a' && push->size_a > 0)
	{
		ft_do_rra(push, &i);
		push->stack_a[0] = tmp;
	}
	else if (letter == 'b' && push->size_b > 0)
	{
		while (i > 0)
		{
			push->stack_b[i] = push->stack_b[i - 1];
			i--;
		}
		push->stack_b[0] = tmp;
	}
	else if (letter == 'r')
		reverse_rotate_double(push);
	printstack(push);
}
