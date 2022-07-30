//Striver video 13 (3D DP)

#include <bits/stdc++.h>

using namespace std;

int maxSum(int i, int j1, int j2, int m, int n, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
	if(j1<0 or j2<0 or j1>n-1 or j2>n-1) return -1e8;

	if(i==m-1)
	{
		if(j1==j2) return grid[i][j1];

		else return grid[i][j1] + grid[i][j2];
	}

	if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

	//Recursion

	int maxi = 0;

	for(int d1=-1; d1<=1; d1++)
	{
		for(int d2=-1; d2<=1; d2++)
		{
			int val = 0;

			if(j1==j2) val = grid[i][j1];

			if(j1!=j2) val = grid[i][j1]+grid[i][j2];

			val += maxSum(i+1, j1+d1, j2+d2, m, n, grid, dp);

			maxi = max(maxi, val);
		}
	}

	return dp[i][j1][j2] = maxi;
}

//Tabulation
int solve(vector<vector<int>> &grid)
{
	int m = grid.size();
	int n = grid[0].size();

	//vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, 0)));
	int dp[m][n][n];
	//Base case
	for(int j1=0; j1<n; j1++)
	{
		for(int j2=0; j2<n; j2++)
		{
			if(j1==j2) dp[m-1][j1][j2] = grid[m-1][j1];

			else dp[m-1][j1][j2] = grid[m-1][j1] + grid[m-1][j2];
		}
	}

	for(int i=m-2; i>=0; i--)
	{
		for(int j1=0; j1<n; j1++)
		{
			for(int j2=0; j2<n; j2++)
			{
				int maxi = -1e9;

				for(int d1=-1; d1<=1; d1++)
				{
					for(int d2=-1; d2<=1; d2++)
					{
						int val = 0;

						if(j1==j2) val = grid[i][j1];

						if(j1!=j2) val = grid[i][j1]+grid[i][j2];

						if(j1+d1>=0 and j1+d1<n and j2+d2>=0 and j2+d2<n)
							val += dp[i+1][j1+d1][j2+d2];

						else val += -1e8;

						maxi = max(maxi, val);
					}
				}
				dp[i][j1][j2] = maxi;
			}
		}
	}

	return dp[0][0][n-1];
}

// Space optimization
int solve2(vector<vector<int>> &grid)
{

	int m = grid.size();
	int n = grid[0].size();

	vector<vector<int>> front(n, vector<int>(n,0));
	vector<vector<int>> curr(n, vector<int>(n,0));

	//Base case
	for(int j1=0; j1<n; j1++)
	{
		for(int j2=0; j2<n; j2++)
		{
			if(j1==j2) front[j1][j2] = grid[m-1][j1];

			else front[j1][j2] = grid[m-1][j1] + grid[m-1][j2];
		}
	}

	for(int i=m-2; i>=0; i--)
	{
		for(int j1=0; j1<n; j1++)
		{
			for(int j2=0; j2<n; j2++)
			{
				int maxi = -1e9;

				for(int d1=-1; d1<=1; d1++)
				{
					for(int d2=-1; d2<=1; d2++)
					{
						int val = 0;

						if(j1==j2) val = grid[i][j1];

						if(j1!=j2) val = grid[i][j1]+grid[i][j2];

						if(j1+d1>=0 and j1+d1<n and j2+d2>=0 and j2+d2<n)
							val += front[j1+d1][j2+d2];

						else val += -1e8;

						maxi = max(maxi, val);
					}
				}
				curr[j1][j2] = maxi;
			}
		}
		front = curr;
	}

	return front[0][n-1];	
}

int main()
{
	int m,n;
	cin>>m>>n;

	vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));

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

	
	cout << maxSum(0, 0, n-1, m, n, grid, dp) << endl;

	cout << solve(grid) << endl;

	cout << solve2(grid) << endl;
}

// Input
// 3 4
// 2 3 1 2
// 3 4 2 2
// 5 6 3 5