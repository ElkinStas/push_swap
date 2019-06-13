#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define BUFF_SIZE 15

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "../libft/libft/libft.h"

typedef struct      s_flist
{
    int             number;
    int             purpose;
    struct s_flist  *next;
}                  t_flist;

t_flist *get_list(char **av, int ac);
t_flist    *ft_swap_a(t_flist **first, t_flist *new, t_flist *start, int i);
t_flist    *ft_swap_b(t_flist **first, t_flist *new, t_flist *start, int i);
void    t_list_reverse(t_flist **begin_list);
void    ft_check_sort(int number, t_flist **mas);
void    ft_push_back_a(t_flist **first, t_flist **second);
void    ft_push_back_b(t_flist **first, t_flist **second);
void    ft_rotate_a(t_flist **first);
void    ft_rotate_b(t_flist **first);
void    ft_reverse_rotate_a(t_flist **first);
void    ft_reverse_rotate_b(t_flist **first);
void    ft_print_list(t_flist *first, t_flist *second);
int		ft_list_size(t_flist *begin_list);
void	sort_int_tab(int *tab, unsigned int size);
int    find_center(t_flist *first, int lenght);
void algoritm1(t_flist **first, t_flist **second);
void	algoritm3(t_flist **list, t_flist **list2);
void algosort_small(t_flist **alpha, t_flist **beta);
int checksort(t_flist **first);
int algosort_big_all(t_flist **alpha, t_flist **beta);
void ft_algosrt_big(t_flist **alpha, t_flist **beta);
void algosort_big_b(t_flist **alpha, t_flist **beta);
void	ft_balance(t_flist **alpha, t_flist **beta);
int find_center2(t_flist *first, int lenght);
int checksort2(t_flist **first);
#endif
