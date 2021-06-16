#include <stdio.h>
#include <stdlib.h>

int		ft_subvet(int arr[], int n, int *max)
{
	int i;
	int	res;
	int	max_end;

	i = 0;
	res = 1;
	max_end = 1;

	if (n == 1)
		return (max_end);
	while (++i < n)
	{
		res = ft_subvet(arr, i, max);
		if (arr[i - 1] < arr[n - 1] && res + 1 > max_end)
			max_end = res + 1;
	}
	if (*max < max_end)
		*max = max_end;
	return (max_end);
}

/* void	ft_subsequence(int arr[], int n, int max)
{
	int i;
	int j;
	int z;
	int count;
	int vet[max];

	i = 0;
	j = 0;
	z = 0;
	count = 0;
	vet[i] = arr[i];
	while (j < max - 1 && i < n - 1)
	{
		if (vet[j] < arr[i + 1])
		{
			vet[j + 1] = arr[i + 1];
			j++;
		}
		i++;
		if (i == n - 1 && j != max - 1)
		{
			j = 0;
			count++;
			i = count;
			vet[j] = arr[i];
		}
		if (vet[0] == vet[1])
			{
				z++;
				i = z;
				j = 0;
				vet[0] = arr[i];
			}
	}
	i = -1;
	while (++i < max)
		printf("%d\n", vet[i]);
} */

void		ft_subsequence(int arr[], int n, int max)
{
	int i;
	int j;
	int z;
	int tmp;
	int count;
	int rip;
	int vet[max];

	i = 0;
	z = 0;
	rip = 0;
	vet[i] = i;
	while (i < n - 1)
	{
		count = 0;
		if (arr[vet[z]] < arr[i + 1])
		{
			vet[z + 1] = i + 1;
			z++;
		}
		else
		{
			j = 0;
			while (j <= i)
				if (arr[j++] < arr[i + 1])
					count++;
			if (count == i)
				vet[z] = i + 1;
			else if (count == 1)
				tmp = i + 1;
		}
		//printf("%d\n", vet[z]);
		i++;
		if (i == n - 1 && z != max - 1)
		{
			rip++;
			z = 0;
			vet[z + rip] = tmp;
			i = tmp + 1;
		}
	}
	i = -1;
	while (++i < max)
		printf("%d\n", arr[vet[i]]);
}

int		ft_lis(int arr[], int n)
{
	int max;

	max = 1;
	ft_subvet(arr, n, &max);
	ft_subsequence(arr, n, max);
	return (max);
}

int main()
{
    int arr[] = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
    int n = sizeof(arr) / sizeof(arr[0]);
	//ft_subsequence(arr, n);
    printf("vet of lis is %d\n", ft_lis(arr, n));
    return 0;
}