#include "push_swap.h"

int checksort(t_flist **first)//проверяет, отсортирован ли массив в листах
{
	t_flist *search;
    t_flist *search2;
	int i;
    int j = 0;
    i = 0;
    int *tab;
    int match;
	match = 0;
    i = ft_list_size(*first);
    tab = (int*)malloc(sizeof(int) * i);
    search = *first;
	search2 = *first;

    while (search != NULL)
    {

		tab[j] = search->number;

		search= search->next;
        j++;
    }
    //sort_int_tab(tab, i);
   	ft_qsort(tab, 0, --i);
	i = 0;
	while(search2 != NULL)
	{

		if(search2->number != tab[i])
			return(0);
		i++;
		search2 = search2->next;
	}

		free(tab);
		return(1);

}

void algosort_small_b(t_flist **beta)
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
			ft_rotate_a(&(*beta));
			ft_printf("rb\n");
		}
}
void algosort_small(t_flist **alpha, t_flist **beta)//это будет сортировка массива до 10 элементов ключительно
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

		/*else if  ((ft_list_size(*beta) >= 2))
		{
			algosort_small_b(&(*beta));
		}*/
		else if ((check = checksort(&(*alpha)) == 1) && (ft_list_size(*beta) != 0))
		{
			ft_push_back_a(&(*beta), &(*alpha));
			ft_printf("pa\n");
		}

		//для стека б
		if ((ft_list_size(*beta) >= 2))
		{
			algosort_small_b(&(*beta));
		}
		check = checksort(&(*alpha));
	}
}




void algoritm1(t_flist **first, t_flist **second)//пока научим его примитиву: пусть перебрасывает все в стек б пока не останется три элемента в стеке а
{
	int search;
	int center;
	int size;
	center = ft_list_size(*first);
	search = find_center(*first);
	size = ft_list_size(*first);
	if (size <= 10)
		algosort_small(&(*first), &(*second));
	else
	{
		ft_algosrt_big(&(*first), &(*second));
	}


}
