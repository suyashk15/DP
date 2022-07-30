// Striver video 14
#include <bits/stdc++.h>

using namespace std;

bool targetSum(int index, vector<int>& arr, int sum, vector<vector<int>> &dp)
{
	if(sum==0) return true;

	if(index==0) return (arr[0]==sum);

	if(dp[index][sum] != -1) return dp[index][sum];

	bool pick = targetSum(index-1, arr, sum-arr[index], dp);

	bool notPick = targetSum(index-1, arr, sum, dp);

	return dp[index][sum] = (pick or notPick);
}

//Tabulation
int solve(vector<int> &arr, int sum)
{
	int n = arr.size();

	vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));

	//Base cases
	for(int i=0; i<n; i++)
		dp[i][0] = 1;

	if(arr[0] <= sum) dp[0][arr[0]] = 1;

	for(int i=1; i<n; i++)
	{
		for(int s=1; s<=sum; s++)
		{
			int p = 0;

			if(s>=arr[i]) p += dp[i-1][s-arr[i]];

			int n = dp[i-1][s];

			dp[i][s] = p or n;
		}
	}

	return dp[n-1][sum];
}

//Space optimisation
int solve2(vector<int> &arr, int sum)
{
	int n = arr.size();

	vector<int> prev(sum+1, 0), curr(sum+1, 0);

	//Base cases
	prev[0] = 1;
	curr[0] = 1;
	prev[arr[0]] = 1;

	for(int i=1; i<n; i++)
	{
		for(int s=1; s<=sum; s++)
		{
			int p = 0;

			if(s>=arr[i]) p += prev[s-arr[i]];

			int n = prev[s];

			curr[s] = p or n;
		}
		prev = curr;
	}

	return prev[sum];
}


int main()
{
	int n, sum;

	cin>>n>>sum;

	vector<int> arr;

	vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));

	for(int i=0; i<n; i++)
	{
		int t;
		cin>>t;
		arr.push_back(t);
	}

	cout << targetSum(n-1, arr, sum, dp) << endl;

	cout << solve(arr, sum) << endl;

	cout << solve2(arr, sum) << endl;
}

// Input
// 5 6
// 1 7 2 9 10