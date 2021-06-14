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

/* void	ft_subvet(int arr[], int n, int max)
{
	int i;
	int j;
	int count;
	int vet[max];

	i = 0;
	j = 0;
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
	}
	i = -1;
	while (++i < max)
		printf("%d\n", vet[i]);
} */

int		ft_lis(int arr[], int n)
{
	int max;

	max = 1;
	ft_subvet(arr, n, &max);
	return (max);
}

void		ft_subsequence(int x[], int n)
{
	int	p[n];
	int	m[n + 1];
	int l;
	int i;
	int newl;
	int lo;
	int hi;
	int mid;

	l = 0;
	i = -1;
	while (++i < n)
		p[i] = 0;
	i = -1;
	while (++i < n + 1)
		m[i] = 0;
	i = 0;
	while (i < n - 1)
	{
		lo = 1;
		hi = l;
		while (lo <= hi)
		{
			if ((lo + hi) % 2)
				mid = (int)((lo + hi) / 2) + 1;
			else
				mid = ((lo + hi) / 2);
			printf("%d\n",mid);
			if (x[m[mid]] < x[i])
				lo = mid + 1;
			else
				hi = mid - 1;
		}
		newl = lo;
		p[i] = m[newl - 1];
		m[newl] = i;
		if (newl > l)
			l = newl;
		i++;
	}
/* 	i = -1;
	while (++i < n)
		printf("%d\n",p[i]); */
	int s[l];
	int k;

	i = l - 1;
	k = m[l];
	while (i > 0)
	{
		s[i] = x[k];
		k = p[k];
		i--;
	}
	i = -1;
	while (++i < l)
		printf("\n%d\n",s[i]);
}

int main()
{
    int arr[] = { 0, 8, 11, 10, 2, 14 };
    int n = sizeof(arr) / sizeof(arr[0]);
	ft_subsequence(arr, n);
    printf("vet of lis is %d\n", ft_lis(arr, n));
    return 0;
}