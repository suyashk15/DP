// Striver video 16

// Logic: Just use the code of subset sum to find all possible
// target sums. Corresponding s2 = totSum - s1.
// Minimize this |s1-s2|

#include<bits/stdc++.h>

using namespace std;

int minSumDiff(vector<int> &arr, int n)
{
	int sum = 0;
	for(int i=0; i<n; i++)
		sum += arr[i];

	vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));

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

	int s2=0;
	int ans = 1e8;

	for(int i=0; i<=sum; i++)
	{
		if(dp[n-1][i] == 1)
		{
			s2 = sum - i;

			ans = min(ans, abs(i-s2));
		}
	}

	return ans;
}

int main()
{
	int n;
	cin>>n;

	vector<int> arr;

	for(int i=0; i<n; i++)
	{
		int t;
		cin>>t;
		arr.push_back(t);
	}

	cout << minSumDiff(arr, n) << endl;
}

//Input
// 3
// 8 6 5