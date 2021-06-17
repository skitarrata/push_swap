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

void	ft_subsequence(int arr[], int n, int max)
{
	int i;
	int j;
	int count;
	int	vet[n];
	int m[max];

	i = -1;
	while (++i < n)
		vet[i] = 0;
	i = 0;
	vet[i] = 1;
	while (i < n)
	{
		j = 0;
		while (j < i)
		{
			if (arr[j] < arr[i])
			{
				if (vet[i] < vet[j] + 1)
					vet[i] = vet[j] + 1;
			}
			else if (arr[j] > arr[i] && !vet[i])
				vet[i] = 1;
			j++;
		}
		i++;
	}
	i = n - 1;
	count = max;
	while (count > 0)
	{
		if (vet[i] == count)
		{
			count--;
			m[count] = i;
		}
		i--;
	}
	i = -1;
	while (++i < max)
		printf("%d\n", arr[m[i]]);
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
    int arr[] = { 8, 0, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15, 55, 45, 76, 16};
    int n = sizeof(arr) / sizeof(arr[0]);
	//ft_subsequence(arr, n);
    printf("vet of lis is %d\n", ft_lis(arr, n));
    return 0;
}