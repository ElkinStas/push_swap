#include "push_swap.h"



void	ft_balance_a(t_flist **alpha, t_flist **beta)//балансировка ветвей по середине
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
			if(searcher->number < search)
			{
				ft_push_back_b(&(*alpha), &(*beta));
				ft_printf("pb\n");

			}
			else
			{
				ft_push_back_b(&(*alpha), &(*beta));
				ft_printf("pb\n");
				if(ft_list_size(*beta) > 2)
				{
					ft_rotate_b(&(*beta));//после ётого б меняется заголовок
					ft_printf("rb\n");
				}
			}

			searcher= searcher->next;
			stop_sort--;
	}
	search =  find_center(*beta, ft_list_size(*beta)/2 + ft_list_size(*beta)%2);// вот это нужно оптимизировать. как-то
	searcher2 = *beta;
	stop_sort = ft_list_size(*beta)/2 + ft_list_size(*beta)%2 ;
	while (stop_sort >= 0)
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
				if(ft_list_size(*alpha) > 2)
				{
					ft_rotate_a(&(*alpha));
					ft_printf("ra\n");
				}

			}

			searcher2= searcher2->next;
			stop_sort--;
	}
	search =  find_center(*beta, ft_list_size(*beta));
	searcher = *beta;
	stop_sort = ft_list_size(*beta);
	while (searcher2 != NULL)
	{
			if(searcher2->number < search)
			{
				ft_push_back_a(&(*beta), &(*alpha));
				ft_printf("pa\n");

			}
			else
			{
				ft_push_back_a(&(*beta), &(*alpha));
				ft_printf("pa\n");
				if(ft_list_size(*alpha) > 2)
				{
					ft_rotate_a(&(*alpha));
					ft_printf("ra\n");
				}
			}

			searcher2= searcher2->next;
			stop_sort--;
	}
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
			if(searcher->number < search)
			{
				ft_push_back_b(&(*alpha), &(*beta));
				ft_printf("pb\n");

			}
			else
			{
				ft_push_back_b(&(*alpha), &(*beta));
				ft_printf("pb\n");
				if(ft_list_size(*beta) > 2)
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




void	ft_balance(t_flist **alpha, t_flist **beta)//балансировка ветвей по середине
{
	int lists_lenght;
	int search;
	t_flist *searcher;
	searcher = *alpha;

	lists_lenght = ft_list_size(*alpha);
	search =  find_center(*alpha, lists_lenght);
	searcher = *alpha;
	while(searcher)
		{
			//search =  find_center(*alpha);
			if(searcher->number > search)
			{
				ft_push_back_b(&(*alpha), &(*beta));
				ft_printf("pb\n");
				//if(ft_list_size(*beta) >= 2)
					//algosort_big_b(&(*alpha), &(*beta));
			}
			else
			{
				ft_push_back_b(&(*alpha), &(*beta));
				ft_printf("pb\n");
				if(ft_list_size(*beta) > 2)
				{
					ft_rotate_b(&(*beta));//после ётого б меняется заголовок
					ft_printf("rb\n");
				}
			}

			searcher= searcher->next;
		}
}


void algosort_small_a(t_flist **alpha)
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
		if (((first_a->number > second_a->number) && (first_a->number > last_a->number) && (ft_list_size(*alpha) > 3))||((first_a->number > second_a->number) && (first_a->number < last_a->number)))
		{
			ft_swap_a(&(*alpha), (*alpha)->next, *alpha, 0);
			ft_printf("sa\n");
		}
		else if ((first_a->number < second_a->number) && (first_a->number > last_a->number))
		{
			ft_reverse_rotate_a(&(*alpha));
			ft_printf("rra\n");
		}

		else if ((first_a->number > second_a->number) && (first_a->number > last_a->number)&& (ft_list_size(*alpha) <= 3))
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
			ft_push_back_a(&(*beta), &(*alpha));
			ft_printf("pa\n");
		}
		else if ((first_b->number < second_b->number) && (first_b->number < last_b->number) && (ft_list_size(*beta) >= 2))
		{
			ft_swap_b(&(*beta), (*beta)->next, *beta, 0);
			ft_printf("sb\n");
		}
		else if ((ft_list_size(*beta) > 3) && (first_b->number > second_b->number) && (first_b->number < last_b->number))
		{
			ft_reverse_rotate_b(&(*beta));
			ft_printf("rrb\n");
			ft_push_back_a(&(*beta), &(*alpha));
			ft_printf("pa\n");
		}

		/*else if  ((ft_list_size(*beta) >= 2))
		{
			algosort_small_b(&(*beta));
		}*/


		//для стека б
		if ((ft_list_size(*alpha) >= 2))
		{
			algosort_small_a(&(*alpha));
		}
		check = checksort(&(*alpha));
	}




}

void ft_algosrt_big(t_flist **alpha, t_flist **beta)//запускает большой алгоритм
{

	ft_balance_a(&(*alpha), &(*beta));
	ft_balance_twice(&(*alpha), &(*beta));
	//ft_balance(&(*alpha), &(*beta));
	ft_algos(&(*alpha), &(*beta));
	//ft_balance_a(&(*alpha), &(*beta));
	//ft_balance_a(&(*alpha), &(*beta));//балансировка ветвей
	//algosort_small(&(*alpha), &(*beta));
}
