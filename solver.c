#include "utils.h"

void	ft_solver(int n, int *utility, int *cost, int budget)
{
	int i, j;
	int rows, cols;
	int **B = NULL;
	int **C = NULL;
	int sol_cost, sol_utility;

	rows = n;
	cols = ft_sum_elements(utility, n);

	// Safe calloc
	if (!(B = ft_calloc_2d_array(rows, cols)))
		return ;
	if (!(C = ft_calloc_2d_array(rows, cols)))
		return ;

	// Matrix B initialisation
	for (j = 0; j < cols; j++)
	{
		if (j == 0 || j == utility[0])
			B[0][j] = 1;
		else
			B[0][j] = 0;
	}
	for (i = 1; i < rows; i++)
		for (j = 0; j < cols; j++)
		{
			if (B[i - 1][j] == 1)
				B[i][j] = 1;
			else if (j >= utility[i])
				B[i][j] = B[i - 1][j - utility[i]];
			else
				B[i][j] = 0;
		}

	// Matrix C initialisation
	for (j = 0; j < cols; j++)
	{
		if (j == 0)
			C[0][j] = 0;
		else if (j == utility[0])
			C[0][j] = cost[0];
		else
			C[0][j] = INT_MIN;
	}
	for (i = 1; i < rows; i++)
	{
		for (j = 1; j < cols; j++)
		{
			if (B[i - 1][j] == 1 && B[i - 1][j - utility[i]] == 0)
				C[i][j] = C[i - 1][j];
			else if (B[i - 1][j] == 0 && B[i - 1][j - utility[i]] == 1)
				C[i][j] = C[i - 1][j - utility[i]] + cost[i];
			else
				C[i][j] = ft_min(C[i - 1][j - utility[i]] + cost[i], C[i - 1][j]);
		}
	}

	// Compute and display solution
	sol_cost = 0;
	sol_utility = 0;
	ft_max_array(C[n - 1], cols, budget, &sol_cost, &sol_utility);
	printf("The optimal solution contains items ");
	for (i = n - 2; i >= 0; i--)
		if (B[i][sol_utility] == 0 || C[i + 1][sol_utility] != C[i][sol_utility])
			printf("%d, ", i + 2);
	printf("with a total utility of %d\n", sol_utility);

	// Free arrays
	ft_free_2d_array(B, rows);
	ft_free_2d_array(C, rows);
}

int main(void){
	int n = 3;
	int utility[3] = {10, 8, 5};
	int cost[3] = {6, 5, 4};
	int budget = 9;

	ft_solver(n, utility, cost, budget);
	return (0);
}