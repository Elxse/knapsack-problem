# Knapsack problem

Given a set of n items, each with a cost c<sub>i</sub> and an utility u<sub>i</sub>, and a budget b, the objective is to determine a subset of items so that the total cost is less than or equal to the budget and the total utility is as large as possible. 

## Solver using dynamic programming

Let u<sub>max</sub> = max(u<sub>i</sub>) for i in {1, ..., n} and c<sub>max</sub> = max(c<sub>i</sub>) for i in {1, ..., n}.

- Time complexity : O(n² u<sub>max</sub> log(c<sub>max</sub>))
- Spatial complexity : O(n² u<sub>max</sub>)