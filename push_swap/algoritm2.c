/*
void	algoritm2(t_flist **list, t_flist **list2)//обучаем алгоритм для стека !а!
{

	int check;
	int i;
 	t_flist *first;
	t_flist *second;
	t_flist *last;
	first = *list;
	second = *list;
	last= *list;
	i = ft_list_size(*list);
	second = second->next;
	while(i> 1)
	{
		last = last->next;
		i--;
	}
	check = checksort(&(*list));
	if(ft_list_size(*list2) > 3)
	algoritm3(&(*list), &(*list2));
      while(check!= 1)
	{
		first = *list;
		second = *list;
		last= *list;
		i = ft_list_size(*list);
		second = second->next;
		while(i> 1)
		{
		last = last->next;
		i--;
		}
		if ((first->number > second->number) && (first->number < last->number) && (first->number < second->next->number))//когда первое больше второго и меньше последнего и больше 3
		{
			ft_swap_a(&(*list), (*list)->next, *list, 0);
			ft_printf("sa\n");
		}
		else if (((first->number > last->number) && (first->number > second->next->number))||((first->number > last->number) && (ft_list_size(*list) <= 3)))//когда первое больше последнего и больше 3
		{
			ft_rotate_a(&(*list));
			ft_printf("ra\n");
		}
		else if((first->number > second->number) && (first->number < second->next->number) && (ft_list_size(*list) > 3))//когда первое больше второгоб но меньше 3
		{
			ft_push_back_b(&(*list), &(*list2));
			ft_printf("pb\n");
			ft_push_back_b(&(*list), &(*list2));
			ft_printf("pb\n");
			ft_reverse_rotate_a(&(*list));
			ft_printf("rra\n");
			ft_swap_a(&(*list), (*list)->next, *list, 0);
			ft_printf("sa\n");
			ft_rotate_a(&(*list));
			ft_printf("ra\n");
			ft_rotate_a(&(*list));
			ft_printf("ra\n");
			ft_push_back_a(&(*list2), &(*list));
			ft_printf("pa\n");
			ft_push_back_a(&(*list2), &(*list));
			ft_printf("pa\n");
		}
		check = checksort(&(*list));
	}
}
*/
/*void	algoritm3(t_flist **list, t_flist **list2)//обучаем алгоритм для стека !б!
{

	int check;
	int i;
 	t_flist *first;
	t_flist *second;
	t_flist *last;
	first = *list2;
	second = *list2;
	last= *list2;
	i = ft_list_size(*list2);
	second = second->next;
	while(i> 1)
	{
		last = last->next;
		i--;
	}
	check = checksort(&(*list2));
	while(check!= 1)
	{
		first = *list2;
		second = *list2;
		last= *list2;
		i = ft_list_size(*list2);
		second = second->next;
		while(i> 1)
		{
		last = last->next;
		i--;
		}
		if ((first->number > second->number) && (first->number < last->number))//когда первое больше второго и меньше последнего и больше 3
		{
			ft_swap_a(&(*list2), (*list2)->next, *list2, 0);
			ft_printf("sa\n");
		}
		else if ((first->number > last->number) && (first->number > second->next->number))//когда первое больше последнего и больше 3
		{
			ft_rotate_a(&(*list2));
			ft_printf("ra\n");
		}
		else if((first->number > second->number) && (first->number < second->next->number))//когда первое больше второгоб но меньше 3
		{
			ft_push_back_a(&(*list2), &(*list));
			ft_printf("pa\n");
			ft_push_back_a(&(*list2), &(*list));
			ft_printf("pa\n");
			ft_reverse_rotate_b(&(*list2));
			ft_printf("rrb\n");
			ft_swap_b(&(*list2), (*list2)->next, *list2, 0);
			ft_printf("sb\n");
			ft_rotate_b(&(*list2));
			ft_printf("rb\n");
			ft_rotate_b(&(*list2));
			ft_printf("ra\n");
			ft_push_back_b(&(*list), &(*list2));
			ft_printf("pb\n");
			ft_push_back_b(&(*list), &(*list2));
			ft_printf("pb\n");
		}
		check = checksort(&(*list2));
	}

}
*/
