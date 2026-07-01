//Sri Rama Jayam

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

string lex_min(vector<vector<char>>&grid, int n){
	vector<vector<string>>dp(n, vector<string>(n,""));
	dp[0][0]+=grid[0][0];
	for (int i = 1; i < n; ++i){
		dp[i][0] = dp[i-1][0] + grid[i][0];
	}
	for (int j = 1; j < n; ++j){
		dp[0][j] = dp[0][j-1] + grid[0][j];
	}
	for (int i = 1; i < n; ++i){
		for (int j = 1; j < n; ++j){
			dp[i][j] = min(dp[i-1][j] + grid[i][j], dp[i][j-1] + grid[i][j]);
		}
	}

	return dp[n-1][n-1];
}

int main(){
	int n;
	cin>>n;
	vector<vector<char>>grid(n, vector<char>(n));
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			cin>>grid[i][j];
		}
	}
	cout<<lex_min(grid,n)<<endl;
	return 0;
}
