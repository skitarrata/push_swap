#include "../header/push_swap.h"

void	ft_putstr(char *text)
{
	int i;

	i = -1;
	if (!text)
		exit(0);
	while (text[++i])
		write(1, &text[i], 1);
}