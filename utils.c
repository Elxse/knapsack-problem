#include "utils.h"

int		ft_min(int a, int b)
{
	return (a < b ? a : b);
}

void	ft_max_array(int *array, int size, int limit, int *p_max, int *p_argmax)
{
	int i;
	int max;
	int argmax;

	max = array[0];
	argmax = 0;
	for (i = 1; i < size; i++)
	{
		if (max < array[i] && array[i] <= limit)
		{
			max = array[i];
			argmax = i;
		}
	}
	*p_max = max;
	*p_argmax = argmax;
}

int		ft_sum_elements(int *array, int size)
{
	int sum;
	int i;

	sum = 0;
	for (i = 0; i < size; i++)
		sum += array[i];
	return (sum);
}

int**	ft_calloc_2d_array(int rows, int cols)
{
	int **matrix = NULL;
	int i;
	
	if (!(matrix = (int **)calloc(rows, sizeof(int *))))
		return (0);
	for (i = 0; i < rows; i++)
		if (!(matrix[i] = (int *)calloc(cols, sizeof(int))))
			return (0);
	return (matrix);
}

void	ft_free_2d_array(int **array, int rows)
{
	int i;

	for (i = 0; i < rows; i++)
		free(array[i]);
	free(array);
}

void	ft_display_array(int *array, int size)
{
	int i;

	for (i = 0; i < size; i++)
		printf("%d, ", array[i]);
	printf("\n");
}