#include "push_swap.h"



void	ft_balance_a(t_flist **alpha, t_flist **beta, int count)//балансировка ветвей по середине
{
int lists_lenght;
	int search;
	int stop_sort;
	int step;
	int step2;
	int huy;
	t_flist *searcher;
	t_flist *searcher2;
	searcher = *alpha;
	lists_lenght = ft_list_size(*alpha);
	search =  find_center(*alpha, lists_lenght);
		searcher2 = *beta;

	stop_sort = lists_lenght;
	while (stop_sort > 0)
	{
			if(searcher->number > search)
			{
				ft_push_back_b(&(*alpha), &(*beta));
				ft_printf("pb\n");

			}
			else
			{
				ft_push_back_b(&(*alpha), &(*beta));
				ft_printf("pb\n");
				if(ft_list_size(*beta) >= 2)
				{
					ft_rotate_b(&(*beta));//после ётого б меняется заголовок
					ft_printf("rb\n");
				}
			}

			searcher= searcher->next;
			stop_sort--;
	}
	step = ft_list_size(*beta)/count;
	step2 = ft_list_size(*beta);
	huy = ft_list_size(*beta)/count + ft_list_size(*beta)%count;
	search =  find_center(*beta, ft_list_size(*beta)/count + ft_list_size(*beta)%count);// вот это нужно оптимизировать. как-то
	while(ft_list_size(*beta)!= 0)
	{
		searcher2 = *beta;
		stop_sort = step;
		if (huy < step2)
		search =  find_center(*beta, huy);
		if(step2 >= step)
		{
			while (stop_sort > 0)
			{


			if(searcher2->number > search)
			{
				ft_push_back_a(&(*beta), &(*alpha));
				ft_printf("pa\n");

			}
			else
			{
				ft_push_back_a(&(*beta), &(*alpha));
				ft_printf("pa\n");
				if(ft_list_size(*alpha) >= 2)
				{
					ft_rotate_a(&(*alpha));
					ft_printf("ra\n");
				}

			}

			searcher2= searcher2->next;
			stop_sort--;
			step2--;
			}
		}
		else
		{
			search =  find_center(*alpha, step2);
			while (step2 > 0)
			{
				if(searcher2->number > search)
				{
					ft_push_back_a(&(*beta), &(*alpha));
					ft_printf("pa\n");
					}
				else
				{
					ft_push_back_a(&(*beta), &(*alpha));
					ft_printf("pa\n");
					if(ft_list_size(*alpha) >= 2)
					{
						ft_rotate_a(&(*alpha));
						ft_printf("ra\n");
					}

				}
				step2--;
		}
		}
	}
}


void	ft_balance_a2(t_flist **alpha, t_flist **beta, int count)//балансировка ветвей по середине
{
int lists_lenght;
	int search;
	int stop_sort;
	int step;
	int step2;
	int huy;
	t_flist *searcher;
	t_flist *searcher2;
	searcher = *alpha;
	lists_lenght = ft_list_size(*alpha);
	search =  find_center(*alpha, lists_lenght);
		searcher2 = *beta;

	stop_sort = lists_lenght;

	step = ft_list_size(*alpha)/count;
	step2 = ft_list_size(*alpha);
	huy = ft_list_size(*alpha)/count + ft_list_size(*alpha)%count;
	search =  find_center(*alpha, ft_list_size(*alpha)/count + ft_list_size(*alpha)%count );// вот это нужно оптимизировать. как-то
	while(ft_list_size(*alpha) != 0)
	{
			searcher2 = *alpha;
			stop_sort = step;
			if (huy < step2)
			search =  find_center(*alpha, huy);
			if(step2 >= step)
			{
			while (stop_sort > 0)
			{


			if(searcher2->number > search)
			{
				ft_push_back_b(&(*alpha), &(*beta));
				ft_printf("pb\n");

			}
			else
			{
				ft_push_back_a(&(*alpha), &(*beta));
				ft_printf("pb\n");
				if(ft_list_size(*beta) >= 2)
				{
					ft_rotate_a(&(*beta));
					ft_printf("rb\n");
				}

			}

			searcher2= searcher2->next;
			stop_sort--;
			step2--;
			}
		}
		else
		{
			search =  find_center(*alpha, step2);
			while (step2 > 0)
			{
				if(searcher2->number > search)
				{
					ft_push_back_a(&(*alpha), &(*beta));
					ft_printf("pb\n");
					}
				else
				{
					ft_push_back_a(&(*alpha), &(*beta));
					ft_printf("pb\n");
					if(ft_list_size(*alpha) >= 2)
					{
						ft_rotate_a(&(*beta));
						ft_printf("rb\n");
					}

				}
				step2--;
		}
		}

	}
}

void	ft_balance_a22(t_flist **alpha, t_flist **beta, int count)//балансировка ветвей по середине
{
int lists_lenght;
	int search;
	int stop_sort;
	int step;
	int step2;
	int huy;
	t_flist *searcher;
	t_flist *searcher2;
	searcher = *alpha;
	lists_lenght = ft_list_size(*alpha);
	search =  find_center(*alpha, lists_lenght);
		searcher2 = *beta;

	stop_sort = lists_lenght;

	step = 2;
	step2 = ft_list_size(*alpha);
	huy = 2;
	search =  find_center(*alpha, 2);// вот это нужно оптимизировать. как-то
	while(ft_list_size(*alpha) != 0)
	{
			searcher2 = *alpha;
			stop_sort = step;

			search =  find_center(*alpha, huy);
			if(step2 >= step)
			{
			while (stop_sort > 0)
			{


			if(searcher2->number > search)
			{
				ft_push_back_b(&(*alpha), &(*beta));
				ft_printf("pb\n");

			}
			else
			{
				ft_push_back_a(&(*alpha), &(*beta));
				ft_printf("pb\n");
				if(ft_list_size(*beta) >= 2)
				{
					ft_rotate_a(&(*beta));
					ft_printf("rb\n");
				}

			}

			searcher2= searcher2->next;
			stop_sort--;
			step2--;
			}
		}
		else
		{
			search =  find_center(*alpha, step2);
			while (step2 > 0)
			{
				if(searcher2->number > search)
				{
					ft_push_back_a(&(*alpha), &(*beta));
					ft_printf("pb\n");
					}
				else
				{
					ft_push_back_a(&(*alpha), &(*beta));
					ft_printf("pb\n");
					if(ft_list_size(*alpha) >= 2)
					{
						ft_rotate_a(&(*beta));
						ft_printf("rb\n");
					}

				}
				step2--;
		}
		}

	}
}






void	ft_balance_a3(t_flist **alpha, t_flist **beta, int count)//балансировка ветвей по середине
{
int lists_lenght;
	int search;
	int stop_sort;
	int step;
	int step2;
	int huy;
	t_flist *searcher;
	t_flist *searcher2;
	searcher = *alpha;
	lists_lenght = ft_list_size(*alpha);
	search =  find_center(*alpha, lists_lenght);
		searcher2 = *beta;

	stop_sort = lists_lenght;

	step = ft_list_size(*beta)/count;
	step2 = ft_list_size(*beta);
	huy = ft_list_size(*beta)/count + ft_list_size(*beta)%count;
	search =  find_center(*beta, ft_list_size(*beta)/count + ft_list_size(*beta)%count );// вот это нужно оптимизировать. как-то
	while(ft_list_size(*beta)!= 0)
	{
		searcher2 = *beta;
		stop_sort = step;
		if (huy < step2)
		search =  find_center(*beta, huy);
		if(step2 >= step )
		{
			while (stop_sort > 0)
			{


			if(searcher2->number > search)
			{
				ft_push_back_a(&(*beta), &(*alpha));
				ft_printf("pa\n");

			}
			else
			{
				ft_push_back_a(&(*beta), &(*alpha));
				ft_printf("pa\n");
				if(ft_list_size(*alpha) >= 2)
				{
					ft_rotate_a(&(*alpha));
					ft_printf("ra\n");
				}

			}

			searcher2= searcher2->next;
			stop_sort--;
			step2--;
			}
		}
		else
		{
			search =  find_center(*beta, step2);
			while (step2 > 0)
			{
				if(searcher2->number > search)
				{
					ft_push_back_a(&(*beta), &(*alpha));
					ft_printf("pa\n");
					}
				else
				{
					ft_push_back_a(&(*beta), &(*alpha));
					ft_printf("pa\n");
					if(ft_list_size(*alpha) >= 2)
					{
						ft_rotate_a(&(*alpha));
						ft_printf("ra\n");
					}

				}
				step2--;
		}
		}
	}
}






void algosort_small_a(t_flist **alpha, t_flist **beta)
{
	t_flist *first_a;
	t_flist *second_a;
	t_flist *last_a;
	int i;
	first_a = *alpha;
	second_a = *alpha;
	last_a = *alpha;

	i = ft_list_size(*alpha);
	second_a = second_a->next;
	while(i> 1)
	{
		last_a = last_a->next;
		i--;
	}
		if (first_a->number < second_a->number)
		{
			ft_swap_a(&(*alpha), (*alpha)->next, *alpha, 0);
			ft_printf("sa\n");
		}
		 if ((first_a->number > second_a->number) && (first_a->number < last_a->number))
		{
			ft_reverse_rotate_a(&(*alpha));
			ft_printf("rra\n");
			ft_reverse_rotate_a(&(*alpha));
			ft_printf("rra\n");
		}

		  if ((first_a->number < second_a->number) && (first_a->number < last_a->number)&& (ft_list_size(*alpha) <= 2))
		{
			ft_rotate_a(&(*alpha));
			ft_printf("ra\n");
		}

}



void ft_algos(t_flist **alpha, t_flist **beta)


{
		int check;
	int i;
 	t_flist *first_b;
	t_flist *second_b;
	t_flist *last_b;

	  while((ft_list_size(*beta) > 24))
	{
		first_b = *beta;
		second_b = *beta;
		last_b= *beta;
		i = ft_list_size(*beta);
		second_b = second_b->next;
		while(i> 1)
		{
		last_b = last_b->next;
		i--;
		}

		if (ft_list_size(*beta) == 1)
		{
			ft_push_back_a(&(*beta), &(*alpha));
				ft_printf("pa\n");
		}



		else if ((first_b->number > second_b->number) && (first_b->number > last_b->number) && (ft_list_size(*beta) >= 3) && (second_b->number > last_b->number))
		{
			ft_reverse_rotate_b(&(*beta));
			ft_printf("rrb\n");
		}
		else if ((first_b->number > second_b->number) && (first_b->number > last_b->number) && (ft_list_size(*beta) >= 2) && (second_b->number <= last_b->number))
		{
			ft_rotate_b(&(*beta));
			ft_printf("rb\n");
		}
		else if ((first_b->number > second_b->number) && (first_b->number < last_b->number))
		{
			ft_swap_b(&(*beta), (*beta)->next, *beta, 0);
			ft_printf("sb\n");

		}
		else if (((first_b->number < second_b->number) && (first_b->number < last_b->number)))
		{
				ft_push_back_a(&(*beta), &(*alpha));
				ft_printf("pa\n");
		}
		else if (((ft_list_size(*beta) >= 3) && (first_b->number < second_b->number) && (first_b->number > last_b->number)))
		{
			ft_reverse_rotate_b(&(*beta));
			ft_printf("rrb\n");

		}


		//для стека б
		if ((ft_list_size(*alpha) >= 2))
		{
			algosort_small_a(&(*alpha), &(*beta));
		}
		check = checksort(&(*alpha));
	}
}
void ft_algosrt_big(t_flist **alpha, t_flist **beta)//запускает большой алгоритм
{
	int i = 4;
	ft_balance_a(&(*alpha), &(*beta), i);
	i = 4;
	ft_balance_a2(&(*alpha), &(*beta), i);
	i = 4;
	ft_balance_a3(&(*alpha), &(*beta), i);
	//i = 2;
	//ft_balance_a2(&(*alpha), &(*beta), i);
		ft_balance_a2(&(*alpha), &(*beta), i);
	i = 16;
	//ft_balance_a3(&(*alpha), &(*beta), i);
	//ft_balance(&(*alpha), &(*beta));
	ft_algos(&(*alpha), &(*beta));
	//ft_balance_a(&(*alpha), &(*beta));
	//ft_balance_a(&(*alpha), &(*beta));//балансировка ветвей
	//algosort_small(&(*alpha), &(*beta));
}
