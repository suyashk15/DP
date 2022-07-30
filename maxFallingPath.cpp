//Striver video 12
#include <bits/stdc++.h>

using namespace std;

int maxPath(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp)
{
	int n = grid[0].size();

	if(j<0 or j>n) return -1e9;
	
	if(i==0) return grid[i][j];

	if(dp[i][j] != -1) return dp[i][j];

	int up = grid[i][j] + maxPath(grid, i-1, j, dp);

	int ld = grid[i][j] + maxPath(grid, i-1, j-1, dp);

	int rd = grid[i][j] + maxPath(grid, i-1, j+1, dp);

	return dp[i][j] = max(up,max(ld, rd));
}

//Tabulation
int solve(vector<vector<int>> &grid)
{
	int n = grid[0].size();
	int m = grid.size();

	vector<vector<int>> dp(m, vector<int>(n, 0));

	//Base case:
	for(int j=0; j<n; j++) 
		dp[0][j] = grid[0][j];

	for(int i=1; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			int up = grid[i][j] + dp[i-1][j];

			int ld = -1e8;
			if(j>0) ld = grid[i][j] + dp[i-1][j-1];

			int rd = -1e8;
			if(j<n-1) rd = grid[i][j] + dp[i-1][j+1];

			dp[i][j] = max(up, max(ld,rd));
		}
	}

	//To find max
	int ans = 0;

	for(int j=0; j<n; j++)
		ans = max(ans, dp[m-1][j]);
	
	return ans;
}

// Space optimization
int solve2(vector<vector<int>> &grid)
{
	int n = grid[0].size();
	int m = grid.size();

	vector<int> prev(n, 0);
	vector<int> curr(n, 0);

	//Base case:
	for(int j=0; j<n; j++) 
		prev[j] = grid[0][j];

	for(int i=1; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			int up = grid[i][j] + prev[j];

			int ld = -1e8;
			if(j>0) ld = grid[i][j] + prev[j-1];

			int rd = -1e8;
			if(j<n-1) rd = grid[i][j] + prev[j+1];

			curr[j] = max(up, max(ld,rd));
		}
		prev = curr;
	}

	//To find max
	int ans = 0;

	for(int j=0; j<n; j++)
		ans = max(ans, prev[j]);
	
	return ans;
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

	int ans = 0;

	for(int j=n-1; j>=0; j--)
	{
		int sol = maxPath(grid, m-1, j, dp);
		//fill(dp.begin(), dp.begin()+m, vector<int>(n,-1));
		ans = max(ans, sol);
	}

	cout << ans << endl;

	cout << solve(grid) << endl;

	cout << solve2(grid) << endl;
}

//Input:
// 4 4
// 1 2 10 4
// 100 3 2 1
// 1 1 20 2
// 1 2 2 1