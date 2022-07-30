#include <bits/stdc++.h>

using namespace std;

// Problem: striver DP video 6

int solve(int index, vector<int> &nums, vector<int> &dp)
{
	if (index==0) return nums[index];

	if (index<0) return 0;

	if (dp[index] != -1) return dp[index];

	int pick = nums[index] + solve(index-2, nums, dp);

	int notPick = 0 + solve(index-1, nums, dp);

	return dp[index] = max(pick, notPick);
}

// Space optimized approach

int solve2(vector<int> &nums)
{
	int n = nums.size();

	int prev = nums[0]; // Base case 1

	int prev2 = 0; // Base case 2

	for(int i=0; i<n ; i++)
	{
		int pick = nums[i];

		if(i>1) pick += prev2;

		int notPick = 0 + prev;

		int curr = max(pick, notPick);

		prev2 = prev;

		prev = curr;
	}

	return prev;
}

int main()
{
	int n;
	cin >> n;
	vector<int> nums;

	vector<int> dp(n, -1);

	for(int i=0; i<n; ++i)
	{
		int p;
		cin>>p;
		nums.push_back(p);
	}

	vector<int> t1;
	vector<int> t2;

	for(int i=0; i<n; ++i)
	{
		if (i==0) 
		{
			t1.push_back(nums[i]);
			continue;
		}

		if (i==n-1)
		{
			t2.push_back(nums[i]);
			continue;
		}

		t1.push_back(nums[i]);

		t2.push_back(nums[i]);
	}

	int s1 = solve(n-2, t1, dp);

	vector<int> dp2(n, -1);

	int s2 = solve(n-2, t2, dp2);

	cout << max(s1, s2) << endl;

	cout << max(solve2(t1), solve2(t2));
}