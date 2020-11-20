#ifndef UTILS_H
# define UTILS_H
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

int		ft_min(int a, int b);
void	ft_max_array(int *array, int size, int limit, int *p_max, int *p_argmax);
int		ft_sum_elements(int *array, int size);
int**	ft_calloc_2d_array(int rows, int cols);
void	ft_free_2d_array(int **array, int rows);
void	ft_display_array(int *array, int size);

#endif