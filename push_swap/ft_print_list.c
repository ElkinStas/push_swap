#include "push_swap.h"

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
int find_center(t_flist *first)//это заполнит массив цифрами наобум
{
    t_flist *search;
    int i;
    int j = 0;
    i = 0;
    int *tab;
    int center;
    i = ft_list_size(first);
    tab = (int*)malloc(sizeof(int) * i);
    search = first;
    while(search != NULL)
    {
        tab[j] = (search)->number;
        search= search->next;
        j++;
    }
    sort_int_tab(tab, i);
    free(tab);
    center = tab[i/2];
    return (center);
}
