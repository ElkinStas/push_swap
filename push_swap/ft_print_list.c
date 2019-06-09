#include "push_swap.h"
/* это все для малого алгоритма до 10 цифр включительно*/
void    ft_print_list(t_flist *first, t_flist *second)
{
    while (first || second)
    {
        if(first)
            ft_putnbr(first->number);
        else
            {
                ft_putchar(' ');
                ft_putchar(' ');
            }
        ft_putchar(' ');
        if(second)
            ft_putnbr(second->number);
        ft_putchar('\n');
        if (first)
            first = first->next;
        if (second)
            second = second->next;
    }
}

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i;
	int tmp;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
}
int find_center(t_flist *first, int lenght)//это заполнит массив цифрами наобум и расставляет в нужном порядке
{
    t_flist *search;
    t_flist *search2;
    int i;
    int j = 0;
    int lenght2;
    lenght2 = lenght;
    i = 0;
    int *tab;
    int center;
    int q;
    q = 0;
    i = lenght;
    tab = (int*)malloc(sizeof(int) * i);
    search = first;
    search2 = first;
    while(lenght > 0)
    {
        tab[j] = (search)->number;
        search= search->next;
        j++;
        lenght --;
    }
    //sort_int_tab(tab, i);
    ft_qsort(tab, 0, --i);
    while(lenght2 > 0)
    {
      j= 0;
         while(tab[j] != (first)->number)
        j++;
        first->purpose = j;
        first = first->next;
        lenght2--;
    }
    center = tab[i/2];
    free(tab);
    return (center);
}
/*void	ft_int_max(t_flist *first, int *max, int *min)
{
	unsigned int	cmp;
	int				cpy;
    int i;

    ft_check_sort(ac - 1, &first_a);
    i = ft_list_size(first);
	*min = first->number;
	while (i > 1)
	{
		first = first->next;
        i--;
	}
	*max = first->number;
}*/
