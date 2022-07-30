// Striver video 19
#include <bits/stdc++.h>

using namespace std;

int knapsack(int index, vector<int> &wt, vector<int> &val, int w, vector<vector<int>> &dp)
{
	if(index==0)
	{
		if(wt[index] <= w) return val[index];

		else return 0;
	}

	if(dp[index][w] != -1) return dp[index][w];

	int pick = 0;

	if(wt[index] <= w) pick = val[index] + knapsack(index-1, wt, val, w-wt[index], dp);

	int notPick = knapsack(index-1, wt, val, w, dp);

	return dp[index][w] = max(pick, notPick);
}

//Tabulation
int solve(vector<int> &val, vector<int> &wt, int w)
{
	int n = val.size();

	vector<vector<int>> dp(n, vector<int>(w+1, 0));

	//Base case
	for(int i=0; i<=w; i++)
		if(wt[0] <= i) dp[0][i] = val[0];

	for(int i=1; i<n; i++)
	{
		for(int j=0; j<=w; j++)
		{
			int p=0;

			if(wt[i] <= j and j>=wt[i]) p = val[i] + dp[i-1][j-wt[i]];

			int n = dp[i-1][j];

			dp[i][j] = max(p, n);
		}
	}

	return dp[n-1][w];
}

int main()
{
	int n,w;
	cin>>n>>w;

	vector<int> wt, val;

	vector<vector<int>> dp(n, vector<int>(w+1, -1));

	for(int i=0; i<n; i++)
	{
		int t;
		cin>>t;
		wt.push_back(t);
	}

	for(int i=0; i<n; i++)
	{
		int t;
		cin>>t;
		val.push_back(t);
	}

	cout << knapsack(n-1, wt, val, w, dp) << endl;

	cout << solve(val, wt, w) << endl;
}

// Input
// 4 5
// 1 2 4 5
// 5 4 8 6