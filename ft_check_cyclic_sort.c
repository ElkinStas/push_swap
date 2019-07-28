/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cyclic_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhudson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 14:56:02 by bhudson           #+#    #+#             */
/*   Updated: 2019/07/24 17:46:42 by bhudson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check_cyclic_sort(t_push *push)
{
	int i;

	i = 0;
	while (push->stack_a[i] != push->min)
		i++;
	while (i + 1 < push->size_a)
	{
		if (push->stack_a[i] < push->stack_a[i + 1])
			i++;
		else
			return (0);
	}
	if (push->stack_a[0] > push->stack_a[i])
		i = 0;
	else
		return (0);
	while (push->stack_a[i + 1] != push->min)
	{
		if (push->stack_a[i] < push->stack_a[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

void	ft_do_separate(t_push *push)
{
	if (push->i < push->size_a - push->i)
	{
		while (push->i > 0)
		{
			ft_printf("ra\n");
			rotate_operations(push, 'a');
			push->i--;
		}
	}
	else
	{
		while (push->size_a - push->i > 0)
		{
			ft_printf("rra\n");
			reverse_rotate_operations(push, 'a');
			push->i++;
		}
	}
	ft_printf("pb\n");
	push_operations(push, 'b');
	push->i = 0;
}

void	ft_separate_stack(t_push *push)
{
	push->i = 0;
	while (push->size_a > 3)
	{
		if ((push->stack_a[push->i] != push->min)
		&& (push->stack_a[push->i] != push->max))
			ft_do_separate(push);
		else
			push->i++;
	}
	if (push->size_a == 3 && ft_check_sort_elements(push) == 0)
		ft_sort_three_item(push);
	push->i = 0;
}

int		ft_check_sort_elements(t_push *push)
{
	if ((push->stack_a[0] < push->stack_a[1]
	&& push->stack_a[1] < push->stack_a[2])
	|| (push->stack_a[0] == push->max && push->stack_a[1] < push->stack_a[2])
	|| (push->stack_a[0] < push->stack_a[1] && push->stack_a[2] == push->min))
		return (1);
	else
		return (0);
}

void	printstack(t_push *push)
{
	int	i;
	int	t;

	t = (push->size_a > push->size_b ? push->size_a : push->size_b);
	i = -1;
	if (push->vis)
	{
		ft_printf("----------------------------\n");
		ft_printf("|%-11c ||" "%11c |\n", 'a', 'b');
		ft_printf("----------------------------");
		ft_printf("\n");
		while (++i < t)
		{
			if (i < push->size_a)
				ft_printf("|%11ld |", push->stack_a[i]);
			else
				ft_printf("|%11s |", " ");
			if (i < push->size_b)
				ft_printf("|%11ld |\n", push->stack_b[i]);
			else
				ft_printf("|%11s |\n", " ");
		}
		ft_printf("----------------------------\n\n");
	}
}
