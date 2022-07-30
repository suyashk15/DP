// Striver video - 9
#include <bits/stdc++.h>

using namespace std;

int uniqueWays(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp)
{
	if(i==0 and j==0) return 1;

	if(i<0 or j<0) return 0;

	if(dp[i][j] != -1) return dp[i][j];

	if(grid[i][j] != -1)
	{
		int left = uniqueWays(grid, i, j-1, dp);

		int up = uniqueWays(grid, i-1, j, dp);

		return dp[i][j] = left + up;
	}
	else return 0;
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

	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}


	cout << uniqueWays(grid, m-1, n-1, dp) << endl;

}