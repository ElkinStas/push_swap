/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhudson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 14:56:19 by bhudson           #+#    #+#             */
/*   Updated: 2019/07/24 14:56:23 by bhudson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	doop(t_push *push, char **oper, int i)
{
	if (ft_strcmp(oper[i], "ra") == 0)
		rotate_operations(push, 'a');
	else if (ft_strcmp(oper[i], "rb") == 0)
		rotate_operations(push, 'b');
	else if (ft_strcmp(oper[i], "rr") == 0)
		rotate_operations(push, 'r');
	else if (ft_strcmp(oper[i], "rra") == 0)
		reverse_rotate_operations(push, 'a');
	else if (ft_strcmp(oper[i], "rrb") == 0)
		reverse_rotate_operations(push, 'b');
	else if (ft_strcmp(oper[i], "rrr") == 0)
		reverse_rotate_operations(push, 'r');
	else if (ft_strcmp(oper[i], "pa") == 0)
		push_operations(push, 'a');
	else if (ft_strcmp(oper[i], "pb") == 0)
		push_operations(push, 'b');
	else if (ft_strcmp(oper[i], "sa") == 0)
		swap_operations(push, 'a');
	else if (ft_strcmp(oper[i], "sb") == 0)
		swap_operations(push, 'b');
	else
		ft_out();
}

void	ft_valid_buf(char **buff)
{
	int i;

	i = 0;
	while (buff[i] != NULL)
	{
		if ((ft_strcmp(buff[i], "ra") == 0) || (ft_strcmp(buff[i], "rb") == 0)
		|| (ft_strcmp(buff[i], "rr") == 0) || (ft_strcmp(buff[i], "rra") == 0)
		|| (ft_strcmp(buff[i], "rrb") == 0) || (ft_strcmp(buff[i], "rrr") == 0)
		|| (ft_strcmp(buff[i], "pa") == 0) || (ft_strcmp(buff[i], "pb") == 0)
		|| (ft_strcmp(buff[i], "sa") == 0) || (ft_strcmp(buff[i], "sb") == 0))
			i++;
		else
			ft_out();
	}
	return ;
}

char	**ft_strfree(char ***arr)
{
	int i;

	i = 0;
	while ((*arr)[i])
		i++;
	while (i >= 0)
	{
		free((*arr)[i]);
		(*arr)[i] = NULL;
		i--;
	}
	free(*arr);
	*arr = NULL;
	return (NULL);
}

void	read_input2(t_push **push, char ***oper, char **temp)
{
	(*push)->i = -1;
	(*oper) = ft_strsplit(*temp, '\n');
	while ((*oper)[++(*push)->i] != NULL)
		doop(*push, *oper, (*push)->i);
	ft_strfree(&(*oper));
	free(*temp);
}

void	read_input(t_push *push)
{
	char	buff[BUFF_SIZE + 1];
	char	*del;
	int		ret;
	char	*temp;
	char	**oper;

	push->i = 0;
	temp = ft_strnew(0);
	while ((ret = read(0, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		del = temp;
		temp = ft_strjoin(temp, buff);
		free(del);
		push->i++;
		oper = ft_strsplit(temp, '\n');
		ft_valid_buf(oper);
		ft_strfree(&oper);
	}
	if (push->i == 0)
	{
		free(temp);
		return ;
	}
	read_input2(&push, &oper, &temp);
}
