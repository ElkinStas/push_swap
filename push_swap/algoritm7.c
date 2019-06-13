#include "push_swap.h"



int recurs_swap(t_flist **alpha, t_flist **beta)
{
		t_flist *polly;
		int search;
		int i;
		i = ft_list_size(*alpha)- checksort2(&(*alpha));
		if (i < 3)
		i = 2;
		polly = *alpha;
		if (checksort(&(*alpha)))
			return(1);
		while (0 < i)
		{
			search = find_center(*alpha, ft_list_size(*alpha) - checksort2(&(*alpha)));
				if((*alpha)->number > search)
			{
				ft_rotate_a(&(*alpha));
				ft_printf("ra\n");
			}
			else
			{
				ft_push_back_a(&(*alpha), &(*beta));
				ft_printf("pb\n");
			}
			i--;
		}

		return(recurs_swap(alpha, beta));

}





void algosortus(t_flist **alpha, t_flist **beta)//это будет сортировка массива до 10 элементов ключительно
{
	int check;
	int i;
 	t_flist *first_a;
	t_flist *second_a;
	t_flist *last_a;
	check = checksort(&(*alpha));
	  while((check != 1) || (ft_list_size(*beta) != 0))
	{
		if (recurs_swap(&(*alpha), &(*beta)) == 1)
		{
			ft_push_back_a(&(*beta), &(*alpha));
			ft_printf("pa\n");
		}
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

			//recurs_swap(&(*alpha), &(*beta));

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

		/*else if  ((ft_list_size(*beta) >= 2))
		{
			algosort_small_b(&(*beta));
		}*/
		/*else if ((check = checksort(&(*alpha)) == 1) && (ft_list_size(*beta) != 0))
		{
			ft_push_back_a(&(*beta), &(*alpha));
			ft_printf("pa\n");
		}*/

		//для стека б
		if ((ft_list_size(*beta) >= 2))
		{
			//algosort_small_b(&(*beta));
		}
		check = checksort(&(*alpha));
		if (check != 1)
		recurs_swap(&(*alpha), &(*beta));
	}
}





void ft_algosrt_big(t_flist **alpha, t_flist **beta)//запускает большой алгоритм
{
	int i = 4;
	//recurs_swap(&(*alpha), &(*beta));
	i = 4;

	//ft_balance(&(*alpha), &(*beta));
	//ft_algos(&(*alpha), &(*beta));
	//ft_balance_a(&(*alpha), &(*beta));
	//ft_balance_a(&(*alpha), &(*beta));//балансировка ветвей
	algosortus(&(*alpha), &(*beta));
}
