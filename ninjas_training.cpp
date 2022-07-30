#include <bits/stdc++.h>

using namespace std;

// Problem: Striver DP video 7

int solve(int index, vector<vector<int>> &points, int lastTask, vector<vector<int>> &dp)
{
	if(index == 0){
		int maxi = 0;
		for(int i=0; i<3; i++)
		{
			if(i != lastTask) 
				maxi = max(maxi, points[index][i]);
		}

		return maxi;
	}

	if (dp[index][lastTask] != -1) return dp[index][lastTask];

	int maxi = 0;

	for(int i=0; i<3; i++)
	{
		if(i != lastTask)
		{ 
			int pt = points[index][i] + solve(index-1, points, i, dp);
			maxi = max(maxi, pt);
		}
	}

	return dp[index][lastTask] = maxi;
}

// Tabulation
int solve2(vector<vector<int>> &points, int n)
{
	vector<vector<int>> dp(n, vector<int>(4, 0));

	//Base cases:
	dp[0][0] = std::max({points[0][1], points[0][2]});
	dp[0][1] = std::max({points[0][0], points[0][2]});
	dp[0][2] = std::max({points[0][0], points[0][1]});
	dp[0][3] = std::max({points[0][1], points[0][2], points[0][0]});

	for(int day=1; day<n; day++)
	{
		for(int last=0; last<4; last++)
		{
			dp[day][last] = 0; //maxi

			for(int task=0; task<3; task++)
			{
				if(task != last)
				{
					int pt = points[day][task] + dp[day-1][task];
					dp[day][last] = std::max({dp[day][last], pt});
				}
			}	
		}
	}
	return dp[n-1][3];
}

int main()
{
	int n;
	cin>>n;

	vector<vector<int>> points;

	vector<int> temp;

	vector<vector<int>> dp(n, vector<int>(4, -1));

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<3; j++)
		{
			int t;
			cin>>t;
			temp.push_back(t);
		}
		points.push_back(temp);
		temp.clear();
	}

	cout << solve(n-1, points, 3, dp) << endl; 

	cout << solve2(points, 3);
}

//Input:
// 3
// 1 2 5 
// 3 1 1
// 3 3 3
//output: 11
