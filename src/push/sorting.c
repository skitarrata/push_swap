#include "../header/push_swap.h"

/* static void  ft_copyvet(t_swap *swap)
{
   int   i;

   i = -1;
   swap->sort = (long *)ft_calloc(swap->lena, sizeof(long));
   if (!swap->sort)
      ft_error(swap, MALLOC_FAIL);
   while (++i < swap->lena)
      swap->sort[i] = swap->veta[i];
}

static void  ft_swap(long *xp, long *yp)
{
    long  tmp;
    
    tmp = *xp;
    *xp = *yp;
    *yp = tmp;
}

void  ft_bubbleSort(t_swap *swap)
{
   int   i;
   int   j;

   i = -1;
   swap->lso = swap->lena;
   ft_copyvet(swap);
   while (++i < swap->lso - 1)
   {
      j = -1;
      while (++j < swap->lso - i - 1)
         if (swap->sort[j] > swap->sort[j + 1])
            ft_swap(&swap->sort[j], &swap->sort[j + 1]);
   }
}

void ft_printvet(t_swap *swap)
{
	int i;

	i = -1;
	while (++i < swap->lena)
		printf("%ld ", swap->sort[i]);
} */

void	ft_sort_three(t_swap *swap)
{
	int		first;
	int		second;
	int		third;

	first = swap->veta[0];
	second = swap->veta[1];
	third = swap->veta[2];
	if ((first > second) && (second > third) && (third < first))
	{
		ft_sa(swap, 0);
		ft_rra(swap, 0);
	}
	else if ((first > second) && (second < third) && (third < first))
		ft_ra(swap, 0);
	else if ((first > second) && (second < third) && (third > first))
		ft_sa(swap, 0);
	else if ((first < second) && (second > third) && (third < first))
		ft_rra(swap, 0);
	else if ((first < second) && (second > third) && (third > first))
	{
		ft_rra(swap, 0);
		ft_sa(swap, 0);
	}
}