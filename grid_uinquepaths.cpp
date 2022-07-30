// In a mxn matrix, find unique ways from (0,0) to (m-1,n-1)
// Diagonal movement not allowed 
// Stiver DP video 8

#include <bits/stdc++.h>

using namespace std;

int uniqueWays(int i, int j, vector<vector<int>> &dp)
{
	//Base case:
	if(i==0 and j==0) return 1; //count as one possible way

	if(i<0 or j<0) return 0; //edge case

	if(dp[i][j] != -1) return dp[i][j];

	int up = uniqueWays(i-1, j, dp);

	int left = uniqueWays(i, j-1, dp);

	return dp[i][j] = up+left;
}

// Tabulation

int solve(int m, int n)
{
	vector<vector<int>> dp(m, vector<int>(n, 0));

	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(i==0 and j==0) {dp[0][0] = 1;}
			else
			{	
				int up = 0;
				if(i>0) up += dp[i-1][j];
				int left = 0;
				if(j>0) left += dp[i][j-1];
				dp[i][j] = up+left;
			}
		}
	}
	return dp[m-1][n-1];
}

// Space optimized

int solve2(int m, int n)
{
	vector<int> prev(n,0);

	vector<int> curr(n,0);

	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(i==0 and j==0) {curr[0] = 1;}
			else
			{	
				int up = 0;
				if(i>0) up += prev[j];
				int left = 0;
				if(j>0) left += curr[j-1];
				curr[j] = up+left;
			}

			prev = curr;
		}
	}
	return prev[n-1];
}

int main()
{
	int m,n;
	cin>>m>>n;

	vector<vector<int>> dp(m, vector<int>(n, -1));

	cout << uniqueWays(m-1, n-1, dp) << endl;

	cout << solve(m,n) << endl;

	cout << solve2(m,n); 
}