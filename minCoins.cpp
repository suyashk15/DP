// Striver video 20
// Find the min no. of coins required to sum up to target
// TC: O(nxtarget) (Good question)

#include <bits/stdc++.h>

using namespace std;

int minCoins(int index, vector<int> &val, int target, vector<vector<int>> &dp)
{
	//if(target==0) return 1;

	if(index == 0)
	{
		if(target%val[0]==0) return target/val[0];

		else return 1e9;
	}

	if(dp[index][target] != -1) return dp[index][target];

	int pick = 1e9;

	if(target>=val[index]) pick = 1 + minCoins(index, val, target-val[index], dp);

	int notPick = minCoins(index-1, val, target, dp);

	return dp[index][target] = min(pick, notPick);
}

int solve(vector<int> &val, int target)
{
	int n = val.size();

	vector<vector<int>> dp(n, vector<int>(target+1, 0));

	//Base case
	for(int t=0; t<=target; t++)
	{
		if(t%val[0]==0) dp[0][t] = t/val[0];

		else dp[0][t] = 1e9;
	}

	for(int i=1; i<n; i++)
	{
		for(int t=0; t<=target; t++)
		{
			int p=1e9;

			if(val[i]<=t) p = 1 + dp[i][t-val[i]];

			int n = dp[i-1][t];

			dp[i][t] = min(p, n);
		}
	}
	return dp[n-1][target];
}

//Space optimization
int solve2(vector<int> &val, int target)
{
	int n = val.size();

	vector<int> prev(target+1, 0), curr(target+1, 0);

	//Base case
	for(int t=0; t<=target; t++)
	{
		if(t%val[0]==0) prev[t] = t/val[0];

		else prev[t] = 1e9;
	}

	for(int i=1; i<n; i++)
	{
		for(int t=0; t<=target; t++)
		{
			int p=1e9;

			if(val[i]<=t) p = 1 + curr[t-val[i]];

			int n = prev[t];

			curr[t] = min(p, n);
		}
		prev = curr;
	}
	return prev[target];
}


int main()
{
	int n,target;
	cin>>n>>target;

	vector<int> val;

	vector<vector<int>> dp(n, vector<int>(target+1, -1));

	for(int i=0; i<n; i++)
	{
		int t;
		cin>>t;
		val.push_back(t);
	}

	cout << minCoins(n-1, val, target, dp) << endl;

	cout << solve(val, target) << endl;

	cout << solve2(val, target) << endl;
}