#include "push_swap.h"



void	ft_balance_a(t_flist **alpha, t_flist **beta)//балансировка ветвей по середине
{
int lists_lenght;
	int search;
	int stop_sort;
	int step;
	int step2;
	t_flist *searcher;
	t_flist *searcher2;
	searcher = *alpha;
	lists_lenght = ft_list_size(*alpha);
	search =  find_center(*alpha, lists_lenght);
		searcher2 = *beta;

	stop_sort = lists_lenght;
	while (stop_sort > 0)
	{
			if(searcher->number <= search)
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
	step = ft_list_size(*beta)/4;
	step2 = ft_list_size(*beta);
	search =  find_center(*beta, ft_list_size(*beta)/4 );// вот это нужно оптимизировать. как-то
	while(ft_list_size(*beta)!= 0)
	{
		searcher2 = *beta;
		stop_sort = step;

		if(step2 >= step)
		{
			while (stop_sort >= 0)
			{


			if(searcher2->number <= search)
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
			while (step2 > 0)
			{
				if(searcher2->number <= search)
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
	/*search =  find_center(*beta, ft_list_size(*beta));
	searcher = *beta;
	stop_sort = ft_list_size(*beta);
	while (searcher2 != NULL)
	{
			if(searcher2->number >= search)
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
	}*/
}


void	ft_balance_twice(t_flist **alpha, t_flist **beta)
{
	int lists_lenght;
	int search;
	int stop_sort;
	t_flist *searcher;
	t_flist *searcher2;

	while (ft_list_size(*alpha)/2 != 0)
	{
		searcher = *alpha;
		search =  find_center(*alpha, 2);
		stop_sort = 2;
		while(stop_sort > 0)
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
				if(ft_list_size(*beta) <= 2)
				{
					ft_rotate_b(&(*beta));//после ётого б меняется заголовок
					ft_printf("rb\n");
				}
			}

			searcher= searcher->next;
			stop_sort--;
		}
	}
	if ((ft_list_size(*alpha)%2 != 0) && (ft_list_size(*alpha) != 0))
	{
		ft_push_back_b(&(*alpha), &(*beta));
				ft_printf("pb\n");
	}
}

void	ft_balance_b(t_flist **alpha, t_flist **beta)
{
	int lists_lenght;
	int search;
	int stop_sort;
	t_flist *searcher;
	t_flist *searcher2;
	searcher = *alpha;
	lists_lenght = ft_list_size(*alpha);
	search =  find_center(*alpha, lists_lenght);
		searcher2 = *beta;

	stop_sort = lists_lenght;
	while (stop_sort > 0)
	{
			if(searcher->number >= search)
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
}

void ft_checkus_b (t_flist **beta)
{
		t_flist *searcher;
		t_flist *searcher2;
		searcher = *beta;
		searcher2 = *beta;
		if (ft_list_size(*beta) > 1)
		{
			searcher2 = searcher2->next;
			if (searcher->number < searcher2->number)
			{
				ft_rotate_b(&(*beta));//после ётого б меняется заголовок
				ft_printf("rb\n");
			}
		}
}
void ft_checkus_a (t_flist **alpha)
{
		t_flist *searcher;
		t_flist *searcher2;
		searcher = *alpha;
		searcher2 = *alpha;
		if (ft_list_size(*alpha) > 1)
		{
			searcher2 = searcher2->next;
			if (searcher->number < searcher2->number)
			{
				ft_rotate_b(&(*alpha));//после ётого б меняется заголовок
				ft_printf("ra\n");
			}
		}
}

void	ft_balance_four(t_flist **alpha, t_flist **beta)
{
	int lists_lenght;
	int search;
	int stop_sort;
	t_flist *searcher;
	t_flist *searcher2;

	while (ft_list_size(*alpha)/4 != 0)
	{
		searcher = *alpha;
		search =  find_center(*alpha, 4);
		stop_sort = 4;
		while(stop_sort > 0)
		{
			if(searcher->number >=  search)
			{
				ft_push_back_b(&(*alpha), &(*beta));
				ft_printf("pb\n");
				ft_checkus_b(&(*beta));

			}
			else
			{
				ft_push_back_b(&(*alpha), &(*beta));
				ft_printf("pb\n");
				if(ft_list_size(*beta) >= 2)
				{
					ft_rotate_a(&(*beta));//после ётого б меняется заголовок
					ft_printf("rb\n");
				}
			}

			searcher= searcher->next;
			stop_sort--;
		}
	}
	if ((ft_list_size(*alpha)%4 != 0) && (ft_list_size(*alpha) != 0))
	{
		stop_sort = ft_list_size(*alpha);
		search =  find_center(*alpha, stop_sort);
		while(stop_sort > 0)
		{
			if(searcher->number >= search)
			{
				ft_push_back_b(&(*alpha), &(*beta));
				ft_printf("pb\n");
				ft_checkus_b(&(*beta));

			}
			else
			{
				ft_push_back_a(&(*alpha), &(*beta));
				ft_printf("pb\n");
				if(ft_list_size(*beta) <= 2)
				{
					ft_rotate_b(&(*beta));//после ётого б меняется заголовок
					ft_printf("rb\n");
				}
			}

			searcher= searcher->next;
			stop_sort--;
		}
	}
}
void	ft_balance_four2(t_flist **alpha, t_flist **beta)
{
	int lists_lenght;
	int search;
	int stop_sort;
	t_flist *searcher;
	t_flist *searcher2;

	while (ft_list_size(*beta)/4 != 0)
	{
		searcher = *beta;
		search =  find_center(*beta, 4);
		stop_sort = 4;
		while(stop_sort > 0)
		{
			if(searcher->number >= search)
			{
				ft_push_back_b(&(*beta), &(*alpha));
				ft_printf("pa\n");
				ft_checkus_a(&(*alpha));

			}
			else
			{
				ft_push_back_b(&(*beta), &(*alpha));
				ft_printf("pa\n");
				if(ft_list_size(*alpha) >= 2)
				{
					ft_rotate_a(&(*alpha));//после ётого б меняется заголовок
					ft_printf("ra\n");
				}
			}

			searcher= searcher->next;
			stop_sort--;
		}
	}
	if ((ft_list_size(*beta)%4 != 0) && (ft_list_size(*beta) != 0))
	{
		stop_sort = ft_list_size(*beta);
		search =  find_center(*beta, stop_sort);
		while(stop_sort > 0)
		{
			if(searcher->number >= search)
			{
				ft_push_back_b(&(*beta), &(*alpha));
				ft_printf("pa\n");
						ft_checkus_a(&(*alpha));

			}
			else
			{
				ft_push_back_a(&(*beta), &(*alpha));
				ft_printf("pa\n");
				if(ft_list_size(*alpha) <= 2)
				{
					ft_rotate_b(&(*alpha));//после ётого б меняется заголовок
					ft_printf("ra\n");
				}
			}

			searcher= searcher->next;
			stop_sort--;
		}
	}
}
void	ft_balance_three(t_flist **alpha, t_flist **beta)
{
	int lists_lenght;
	int search;
	int stop_sort;
	t_flist *searcher;
	t_flist *searcher2;

	while (ft_list_size(*alpha)/3 != 0)
	{
		searcher = *alpha;
		search =  find_center(*alpha, 3);
		stop_sort = 3;
		while(stop_sort > 0)
		{
			if(searcher->number >=  search)
			{
				ft_push_back_b(&(*alpha), &(*beta));
				ft_printf("pb\n");
				ft_checkus_b(&(*beta));

			}
			else
			{
				ft_push_back_b(&(*alpha), &(*beta));
				ft_printf("pb\n");
				if(ft_list_size(*beta) >= 2)
				{
					ft_rotate_a(&(*beta));//после ётого б меняется заголовок
					ft_printf("rb\n");
				}
			}

			searcher= searcher->next;
			stop_sort--;
		}
	}
	if ((ft_list_size(*alpha)%3 != 0) && (ft_list_size(*alpha) != 0))
	{
		stop_sort = ft_list_size(*alpha);
		search =  find_center(*alpha, stop_sort);
		while(stop_sort > 0)
		{
			if(searcher->number >= search)
			{
				ft_push_back_b(&(*alpha), &(*beta));
				ft_printf("pb\n");
				ft_checkus_b(&(*beta));

			}
			else
			{
				ft_push_back_a(&(*alpha), &(*beta));
				ft_printf("pb\n");
				if(ft_list_size(*beta) <= 2)
				{
					ft_rotate_b(&(*beta));//после ётого б меняется заголовок
					ft_printf("rb\n");
				}
			}

			searcher= searcher->next;
			stop_sort--;
		}
	}
}
void	ft_balance_three2(t_flist **alpha, t_flist **beta)
{
	int lists_lenght;
	int search;
	int stop_sort;
	t_flist *searcher;
	t_flist *searcher2;

	while (ft_list_size(*beta)/3 != 0)
	{
		searcher = *beta;
		search =  find_center(*beta, 3);
		stop_sort = 3;
		while(stop_sort > 0)
		{
			if(searcher->number >= search)
			{
				ft_push_back_b(&(*beta), &(*alpha));
				ft_printf("pa\n");
				ft_checkus_a(&(*alpha));

			}
			else
			{
				ft_push_back_b(&(*beta), &(*alpha));
				ft_printf("pa\n");
				if(ft_list_size(*alpha) >= 2)
				{
					ft_rotate_a(&(*alpha));//после ётого б меняется заголовок
					ft_printf("ra\n");
				}
			}

			searcher= searcher->next;
			stop_sort--;
		}
	}
	if ((ft_list_size(*beta)%3 != 0) && (ft_list_size(*beta) != 0))
	{
		stop_sort = ft_list_size(*beta);
		search =  find_center(*beta, stop_sort);
		while(stop_sort > 0)
		{
			if(searcher->number >= search)
			{
				ft_push_back_b(&(*beta), &(*alpha));
				ft_printf("pa\n");
						ft_checkus_a(&(*alpha));

			}
			else
			{
				ft_push_back_a(&(*beta), &(*alpha));
				ft_printf("pa\n");
				if(ft_list_size(*alpha) <= 2)
				{
					ft_rotate_b(&(*alpha));//после ётого б меняется заголовок
					ft_printf("ra\n");
				}
			}

			searcher= searcher->next;
			stop_sort--;
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
		if (((first_a->number > second_a->number) && (first_a->number < last_a->number)))
		{
			ft_swap_a(&(*alpha), (*alpha)->next, *alpha, 0);
			ft_printf("sa\n");
		}
		else if ((first_a->number < second_a->number) && (first_a->number > last_a->number))
		{
			ft_reverse_rotate_a(&(*alpha));
			ft_printf("rra\n");
		}

		else if ((first_a->number > second_a->number) && (first_a->number > last_a->number)&& (ft_list_size(*alpha) <= 2))
		{
			ft_rotate_a(&(*alpha));
			ft_printf("ra\n");
		}
		/*else if ((first_a->number < second_a->number) && (first_a->number < last_a->number) && (checksort(&(*alpha)) != 1))
		{
			ft_push_back_b(&(*alpha), &(*beta));
			ft_printf("pb\n");
			ft_swap_b(&(*beta), (*beta)->next, *beta, 0);
			ft_printf("sb\n");
		}*/
}


void ft_algos(t_flist **alpha, t_flist **beta)


{
		int check;
	int i;
 	t_flist *first_b;
	t_flist *second_b;
	t_flist *last_b;
	//check = checksort(&(*alpha));
	  while((ft_list_size(*beta) != 0))
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

		else if (((first_b->number > second_b->number) && (first_b->number > last_b->number)))
		{
				ft_push_back_a(&(*beta), &(*alpha));
				ft_printf("pa\n");
		}
		else if ((first_b->number < second_b->number) && (first_b->number > last_b->number))
		{
			ft_swap_b(&(*beta), (*beta)->next, *beta, 0);
			ft_printf("sb\n");
			//ft_push_back_a(&(*beta), &(*alpha));
			//ft_printf("pa\n");
		}
		else if ((first_b->number < second_b->number) && (first_b->number < last_b->number) && (ft_list_size(*beta) >= 2) && (second_b->number >= last_b->number))
		{
			ft_rotate_b(&(*beta));
			ft_printf("rb\n");
		}
		else if ((first_b->number < second_b->number) && (first_b->number < last_b->number) && (ft_list_size(*beta) >= 3) && (second_b->number < last_b->number))
		{
			ft_reverse_rotate_b(&(*beta));
			ft_printf("rrb\n");
		}
		else if (((ft_list_size(*beta) >= 3) && (first_b->number > second_b->number) && (first_b->number < last_b->number)))
		{
			ft_reverse_rotate_b(&(*beta));
			ft_printf("rrb\n");
			//ft_push_back_a(&(*beta), &(*alpha));
			//ft_printf("pa\n");
		}

		/*else if  ((ft_list_size(*beta) >= 2))
		{
			algosort_small_b(&(*beta));
		}*/


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

	ft_balance_a(&(*alpha), &(*beta));
	//ft_balance_twice(&(*alpha), &(*beta));

	//ft_balance_three(&(*alpha), &(*beta));
	//ft_balance_three2(&(*alpha), &(*beta));

	//ft_balance_four(&(*alpha), &(*beta));
	//ft_balance_four2(&(*alpha), &(*beta));
	//ft_balance_four(&(*alpha), &(*beta));
	//ft_balance_four2(&(*alpha), &(*beta));
	//ft_balance_four(&(*alpha), &(*beta));
	//ft_balance_twice(&(*alpha), &(*beta));
	//ft_balance_four2(&(*alpha), &(*beta));
	//ft_balance_four(&(*alpha), &(*beta));
	//ft_balance_four2(&(*alpha), &(*beta));
	//ft_balance_four(&(*alpha), &(*beta));
	//ft_balance_four2(&(*alpha), &(*beta));

	//ft_balance_four(&(*alpha), &(*beta));
	//ft_balance_twice(&(*alpha), &(*beta));
	//ft_balance_four(&(*alpha), &(*beta));
	//ft_balance_b(&(*alpha), &(*beta));



	//ft_balance_b(&(*alpha), &(*beta));

	//ft_balance_four(&(*alpha), &(*beta));
	//ft_balance_b(&(*alpha), &(*beta));
	//ft_balance_four(&(*alpha), &(*beta));
	//ft_balance_b(&(*alpha), &(*beta));

	//ft_balance(&(*alpha), &(*beta));
	//ft_algos(&(*alpha), &(*beta));
	//ft_balance_a(&(*alpha), &(*beta));
	//ft_balance_a(&(*alpha), &(*beta));//балансировка ветвей
	//algosort_small(&(*alpha), &(*beta));
}
