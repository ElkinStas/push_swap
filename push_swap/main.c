#include "push_swap.h"

int main(int ac, char **av)
{
    t_flist *first_a;
    t_flist *first_b;

    first_a = get_list(av, ac);
    //first_b = (t_flist*)malloc(sizeof(t_flist));
    //first_b->next = NULL;
    //first_b = get_list(av, ac, b);

    //ft_swap(&first_a, first_a->next, first_a, 0); /* Function swap */
    //ft_push_back(&first_a, &first_b); /* Push b /Push a  в Данном случае из стека a в стек b*/

    //ft_check_sort(ac - 1, &first_a); /* Сортировка пузырьком стандартная */
    //ft_push_back(&first_a, &first_b); /* Push b /Push a  в Данном случае из стека a в стек b*/
   // ft_push_back_b(&first_a, &first_b); /* Push b /Push a  в Данном случае из стека a в стек b*/
    //ft_push_back_b(&first_a, &first_b);
    //ft_push_back_a(&first_b, &first_a);
    //ft_push_back(&first_a, &first_b);
    //ft_reverse_rotate(&first_a);
    //ft_list_reverse(&first_a); /* Реверс лист Reverse rotate */
    //ft_rotate(&first_a); /* Function rotate */
    //ft_rotate_a(&first_a);
    //ft_swap(&first_a, first_a->next, first_b, 0);c
    //ft_push_back(&first_a, &first_b);
    algoritm1(&first_a, &first_b);
    ft_print_list(first_a, first_b); /* распечатка обоих листов*/
    ft_printf("\n%d", checksort(&first_a));
    //find_center(first_a);
    //ft_print_list(first_a);
    return (0);
}
