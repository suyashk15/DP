// Striver video 10
#include <bits/stdc++.h>

using namespace std;

int minPathSum(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp)
{
	if(i==0 and j==0) return grid[i][j];

	if(i<0 or j<0) return 100000;

	if(dp[i][j] != -1) return dp[i][j];

	int left = grid[i][j] + minPathSum(grid, i, j-1, dp);

	int up = grid[i][j] + minPathSum(grid, i-1, j, dp);

	return dp[i][j] = std::min({up, left});
}

int main()
{
	int m,n;
	cin>>m>>n;

	vector<vector<int>> dp(m, vector<int>(n, -1));

	vector<vector<int>> grid;

	vector<int> temp;

	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			int t;
			cin>>t;
			temp.push_back(t);
		}
		grid.push_back(temp);
		temp.clear();
	}

	cout << minPathSum(grid, m-1, n-1, dp);

}