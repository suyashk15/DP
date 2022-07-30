// Striver video 10
#include <bits/stdc++.h>

using namespace std;

int minPathSum(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp)
{
	int n = grid.size();

	if(i==n-1) return grid[i][j];

	if(dp[i][j] != -1) return dp[i][j];

	int down = grid[i][j] + minPathSum(grid, i+1, j, dp);

	int right = grid[i][j] + minPathSum(grid, i+1, j+1, dp);

	return dp[i][j] = min(down, right);
}

//Tabulation

int solve(vector<vector<int>> &grid, int n)
{
	vector<vector<int>> dp(n, vector<int>(n));

	//Base case
	for(int i=0; i<n; i++)
		dp[n-1][i] = grid[n-1][i];

	for(int i=n-2; i>=0; i--)
	{
		for(int j=i; j>=0; j--)
		{
			int d = grid[i][j] + dp[i+1][j];

			int r = grid[i][j] + dp[i+1][j+1];

			dp[i][j] = min(d,r);
		}
	}

	return dp[0][0];
}