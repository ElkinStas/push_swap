#include "push_swap.h"
/*
void	ft_balance(t_flist **alpha, t_flist **beta)//балансировка ветвей по середине
{
	int lists_lenght;
	int search;
	int *searcher;
	t_flist *searcher2;
	int list;
	list = 0;
	searcher2= *alpha;
	search =  find_center(*alpha);
	lists_lenght = ft_list_size(*alpha);
	searcher = (int*)malloc(sizeof(int) * lists_lenght);
	while(searcher2)
	{
		searcher[list] = searcher2->number;
		list++;
		searcher2 = searcher2->next;
	}




	while (ft_list_size(*alpha) > 10)
	{

		search =  find_center(*alpha);
		list = 0;
		while(list < ft_list_size(*alpha))
		{
			//search =  find_center(*alpha);
			if(searcher[list] <= search)
			{
				ft_push_back_b(&(*alpha), &(*beta));
				ft_printf("pb\n");
				//if(ft_list_size(*beta) >= 2)
					//algosort_big_b(&(*alpha), &(*beta));
			}
			else
			{
				 ft_rotate_a(&(*alpha));//вот тут исчезает сеарч - нужно фиксить
				ft_printf("ra\n");
			}

			list++;
		}
	}

}



int ft_algosort_a(t_flist **alpha, t_flist **beta)//это будет сортировка массива до 10 элементов ключительно
{
	int check;
	int i;
 	t_flist *first_a;
	t_flist *second_a;
	t_flist *last_a;
	check = checksort(&(*alpha));
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
			return(1);
		}
		else if ((first_a->number < second_a->number) && (first_a->number > last_a->number))
		{
			ft_reverse_rotate_a(&(*alpha));
			return(3);
		}
		else if ((first_a->number < second_a->number) && (first_a->number < last_a->number) && (checksort(&(*alpha)) != 1))
		{
			ft_push_back_b(&(*alpha), &(*beta));
			ft_printf("pb\n");
		}
		else if ((first_a->number > second_a->number) && (first_a->number > last_a->number)&& (ft_list_size(*alpha) <= 3))
		{
			ft_rotate_a(&(*alpha));
			return(2);
		}
		return(4);
}

int ft_algosort_b(t_flist **alpha, t_flist **beta, int pusher)
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
			return(1);
		}
		else if (((first_b->number > second_b->number) && (first_b->number < last_b->number)) || ((first_b->number > second_b->number) && (second_b->number < last_b->number)))
		{
			ft_reverse_rotate_b(&(*beta));
			return(3);
		}
		else if ((first_b->number < second_b->number) && (first_b->number < last_b->number)&& (ft_list_size(*beta) <= 3))
		{
			ft_rotate_a(&(*beta));
			return(2);
		}
		else if ((first_b->number > second_b->number) && (first_b->number > last_b->number) && pusher != 4)
		{
			ft_push_back_a(&(*beta), &(*alpha));
			ft_printf("pa\n");
			return(4);
		}
	return(5);
}

void ft_algosrt_big(t_flist **alpha, t_flist **beta)//запускает большой алгоритм
{
	int i = 3;//это 3 - хер знает почему это 3, возможно стоит вообще свести до 0
	int j = 0;
	ft_balance(&(*alpha), &(*beta));
	ft_balance(&(*alpha), &(*beta));
	ft_balance(&(*alpha), &(*beta));
	ft_balance(&(*alpha), &(*beta));//балансировка ветвей - здесь закидываем в правый стек необходимые(?) данные

	while(ft_list_size(*beta)>0)//пока стек б не пуст
	{
		int meaning_a;
		int meaning_b;
		meaning_a = ft_algosort_a(&(*alpha), &(*beta));
		if (ft_list_size(*beta)>3)
		meaning_b = ft_algosort_b(&(*alpha), &(*beta), meaning_a);
		if(meaning_a == 1 && meaning_b == 1)
		{
			ft_printf("ss\n");
		}
		else if(meaning_a == 2 && meaning_b == 2)
		{
			ft_printf("rr\n");
		}
		else if(meaning_a == 3 && meaning_b == 3)
		{
			ft_printf("rrr\n");
		}
		else if(meaning_a == 1)
		{
			ft_printf("sa\n");
		}
		else if(meaning_a == 2)
		{
			ft_printf("ra\n");
		}
		else if(meaning_a == 3)
		{
			ft_printf("rra\n");
		}
		if (meaning_a != 1 && meaning_b == 1)
		{
			ft_printf("sb\n");
		}
		else if(meaning_a != 2 && meaning_b == 2)
		{
			ft_printf("rb\n");
		}
		else if(meaning_a != 3 && meaning_b == 3)
		{
			ft_printf("rrb\n");
		}
		if(checksort(&(*alpha)) == 1 && meaning_b == 5)
		{
			int i = 5;
			if (i > ft_list_size(*beta))
				i = ft_list_size(*beta);
			while(i > 0)
			{
				ft_push_back_a(&(*beta), &(*alpha));
				ft_printf("pa\n");
				i--;
			}
		}
	}
}


