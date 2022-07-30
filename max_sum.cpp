// Find the max sum of subsequence of a given array 
// which contains no adjacent elements

#include <bits/stdc++.h>

using namespace std;

int solve(int index, vector<int> arr, vector<int> &dp)
{
	if(index == 0) return arr[index];

	if(index < 0) return 0;

	if(dp[index] != -1) return dp[index];

	int pick = arr[index] + solve(index-2, arr, dp);

	int not_pick = 0 + solve(index-1, arr, dp);

	return dp[index] = max(pick, not_pick);
}

//Tabulation (Bottom up)
int solve2(vector<int> arr)
{
	int n = arr.size();
	int dp[n];
	dp[0] = arr[0];

	for(int i=1; i<n; i++)
	{
		int pick = arr[i];

		if(i>1) pick += dp[i-2];

		int notPick = arr[i-1];

		dp[i] = max(pick, notPick);
	}

	return dp[n-1];
}

int main()
{
	int n;

	cin >> n;

	vector<int> arr;

	for(int i=0; i<n; i++)
	{
		int t;
		cin >> t;
		arr.push_back(t);
	}

	vector<int> dp(n,-1);

	cout << solve(n-1, arr, dp) << '\n';
	cout << solve2(arr);
}