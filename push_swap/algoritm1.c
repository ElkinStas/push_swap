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
    sort_int_tab(tab, i);
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

void	algoritm2(t_flist **list)//обучаем алгоритм
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
	while(check!= 1)
	{
		if ((first->number > second->number) && (last->number < first->number))
		{
			ft_swap_a(&(*list), (*list)->next, *list, 0);
			ft_printf("sa\n");
		}
		if (first->number > last->number)
		{
			ft_rotate_a(&(*list));
			ft_printf("ra\n");
		}


		check = checksort(&(*list));
	}

}
void algoritm1(t_flist **first, t_flist **second)//пока научим его примитиву: пусть перебрасывает все в стек б пока не останется три элемента в стеке а
{
	int search;
	int center;
	center = ft_list_size(*first);
	search = find_center(*first);
	while(center > 3)
	{
		ft_push_back_b(&(*first), &(*second));
		ft_printf("pb\n");
		center--;
	}
	//ft_printf("%d\n", checksort(&(*first)));
	algoritm2(&(*first));

}
