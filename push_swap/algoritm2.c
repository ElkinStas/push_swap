#include "push_swap.h"


void	ft_balance(t_flist **alpha, t_flist **beta)//балансировка ветвей по середине
{
	int lists_lenght;
	int search;
	t_flist *searcher;
	searcher = *alpha;
	search =  find_center(*alpha);
	lists_lenght = ft_list_size(*alpha);
	while (ft_list_size(*alpha) > 3)
	{
		searcher = *alpha;
		search =  find_center(*alpha);
		while(searcher)
		{
			//search =  find_center(*alpha);
			if(searcher->number < search)
			{
				ft_push_back_b(&(*alpha), &(*beta));
				ft_printf("pb\n");

			}
			else
			{
				ft_rotate_a(&(*alpha));
				ft_printf("ra\n");
			}

			searcher= searcher->next;
		}
	}

}




void ft_algosrt_big(t_flist **alpha, t_flist **beta)//запускает большой алгоритм
{
	int i = 3;
	int j = 0;
	ft_balance(&(*alpha), &(*beta));//балансировка ветвей

	while(ft_list_size(*beta)>0)
	{
		if(algosort_big_all(&(*alpha), &(*beta)) == 1)
		{
				j  = i;
				if (j >= ft_list_size(*beta))
					j = ft_list_size(*beta);
				while(j > 0)
				{
					ft_push_back_a(&(*beta), &(*alpha));
					algosort_big_b(&(*alpha), &(*beta));
					ft_printf("pa\n");
					j--;
				}
				i = i * i;
		}
	}
}
void algosort_big_b(t_flist **alpha, t_flist **beta)
{
	t_flist *first_b;
	t_flist *second_b;
	t_flist *last_b;
	int i;
	first_b = *beta;
	second_b = *beta;
	last_b = *beta;
	i = ft_list_size(*beta);
	second_b = second_b->next;
	while(i> 1)
	{
		last_b = last_b->next;
		i--;
	}


		if ((first_b->number < second_b->number) && (first_b->number > last_b->number))
		{
			ft_swap_a(&(*beta), (*beta)->next, *beta, 0);
			ft_printf("sb\n");
		}
		else if ((first_b->number < second_b->number) && (first_b->number < last_b->number))
		{
			ft_reverse_rotate_b(&(*beta));
			ft_printf("rrb\n");
		}
		else if ((first_b->number < second_b->number) && (first_b->number < last_b->number)&& (ft_list_size(*beta) <= 3))
		{
			ft_rotate_a(&(*beta));
			ft_printf("rb\n");
		}
		/*else if ((first_b->number > second_b->number) && (first_b->number > last_b->number))
		{
			ft_push_back_a(&(*beta), &(*alpha));
			ft_printf("pa\n");
		}*/

}
int algosort_big_all(t_flist **alpha, t_flist **beta)//это будет сортировка массива до 10 элементов ключительно
{
	int check;
	int i;
 	t_flist *first_a;
	t_flist *second_a;
	t_flist *last_a;
	check = checksort(&(*alpha));

	  while((check != 1) || (ft_list_size(*beta) != 0))
	{
		first_a = *alpha;
		second_a = *alpha;
		last_a= *alpha;
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
		else if ((first_a->number < second_a->number) && (first_a->number < last_a->number) && (checksort(&(*alpha)) != 1))
		{
			ft_push_back_b(&(*alpha), &(*beta));
			ft_printf("pb\n");
		}
		else if ((first_a->number > second_a->number) && (first_a->number > last_a->number)&& (ft_list_size(*alpha) <= 3))
		{
			ft_rotate_a(&(*alpha));
			ft_printf("ra\n");
		}

		else if ((check = checksort(&(*alpha)) == 1) && (ft_list_size(*beta) != 0))
		{
			ft_push_back_a(&(*beta), &(*alpha));
			ft_printf("pa\n");
		}

		//для стека б
			if ((ft_list_size(*beta) >= 2))
		{
			algosort_big_b(&(*alpha), &(*beta));
		}
		check = checksort(&(*alpha));
	}
	return(1);
}
