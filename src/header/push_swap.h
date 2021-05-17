#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "error.h"

typedef struct	s_swap
{
	int			*veta;
	int			*vetb;
}				t_swap;

//utils
void	ft_putstr(char *text);

//push
void	ft_sa(t_swap *swap);
void	ft_sb(t_swap *swap);
void	ft_pa(t_swap *swap);
void	ft_pb(t_swap *swap);
void	ft_ss(t_swap *swap);
void	ft_rr(t_swap *swap);
void	ft_rrr(t_swap *swap);
void	ft_ra(t_swap *swap);
void	ft_rb(t_swap *swap);
void	ft_rra(t_swap *swap);
void	ft_rrb(t_swap *swap);

void	ft_error(char *text);

#endif