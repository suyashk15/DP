// Count no. of subsets with sum = k
// Striver video 17

#include <bits/stdc++.h>

using namespace std;

int countSubsets(int index, vector<int> &arr, int k, vector<vector<int>> &dp)
{
	if(index==0)
	{
		if(arr[index]==0 and k==0) return 2;

		if(k==0 or arr[index]==k) return 1;

		return 0;
	} 

	if(dp[index][k] != -1) return dp[index][k];

	int pick = 0;

	if(arr[index] <= k) pick = countSubsets(index-1, arr, k-arr[index], dp);

	int notPick = countSubsets(index-1, arr, k, dp);

	return dp[index][k] = pick + notPick;
}

//Tabulation
int solve(vector<int> &arr, int k)
{
	int n = arr.size();

	vector<vector<int>> dp(n+1, vector<int>(k+1, 0));

	if(arr[0]==0) dp[0][0] = 2; //To handle zeros

	else dp[0][0] = 1;

	if(arr[0]!=0 and arr[0]<=k) dp[0][arr[0]] = 1;

	for(int i=1; i<n; i++)
	{
		for(int j=0; j<=k; j++)
		{
			int p=0;

			if(j>=arr[i]) p = dp[i-1][j-arr[i]];

			int n = dp[i-1][j];

			dp[i][j] = p+n;
		}
	}

	return dp[n-1][k];
}

//Space optimization
int solve2(vector<int> &arr, int k)
{
	int n = arr.size();

	vector<int> prev(k+1,0), curr(k+1, 0);

	prev[0] = 1;

	if(arr[0]<=k) prev[arr[0]] = 1;

	for(int i=1; i<n; i++)
	{
		for(int j=0; j<=k; j++)
		{
			int p=0;

			if(j>=arr[i]) p = prev[j-arr[i]];

			int n = prev[j];

			curr[j] = p+n;
		}

		prev = curr;
	}

	return prev[k];
}


int main()
{
	int n, k;
	cin>>n>>k;

	vector<int> arr;

	vector<vector<int>> dp(n+1, vector<int>(k+1, -1));

	for(int i=0; i<n; i++)
	{
		int t;
		cin>>t;
		arr.push_back(t);
	}

	cout << countSubsets(n-1, arr, k, dp) << endl;

	cout << solve(arr, k) << endl;

	cout << solve2(arr, k) << endl;
}

// Input
// 4 3
// 1 2 2 3