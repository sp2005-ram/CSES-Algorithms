//Sri Rama Jayam

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long number_of_paths(vector<vector<char>>grid, int n){
	long long e = 1e9+7;
	vector<vector<long long>>dp(n,vector<long long>(n,0));
	for (int i = 0; i < n; ++i){
		if (grid[i][0] != '*'){
			dp[i][0] = 1;
		}
		else{
			break;
		}
	}
	for (int j = 0; j < n; ++j){
		if (grid[0][j] != '*'){
			dp[0][j] = 1;
		}
		else{
			break;
		}
	}
	for (int i = 1; i < n; ++i){
		for (int j = 1; j < n; ++j){
			if (grid[i][j] != '*'){
				dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % e;
			}
			else{
				dp[i][j] = 0;
			}	
		}
	}
	return (dp[n-1][n-1]+e)%e;
}

int main(){
	int n;
	cin>>n;
	vector<vector<char>>grid(n,vector<char>(n));
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			cin>>grid[i][j];
		}
	}
	cout<<number_of_paths(grid,n)<<endl;
	return 0;
}

