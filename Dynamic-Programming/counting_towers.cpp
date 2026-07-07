//Sri Rama Jayam

#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>

using namespace std;

const long long r = 1e9+7;

vector<vector<long long>> solve(){
	int mx = 1000000;
	// dp[i][0] - represents the possibilities of tiling with a tile of width 2 for the ith row
	// dp[i][1] - represents the possibilities of tiling with two tiles of width 1 for the ith row 
	vector<vector<long long>>dp(mx+1, vector<long long>(2,0));
	//const long long r = 1e9+7;
	dp[1][0] = 1;
	dp[1][1] = 1;
	for (int i = 2; i <= mx; ++i){
		dp[i][0] = (2*dp[i-1][0]%r + dp[i-1][1]%r)%r;
		dp[i][1] = (4*dp[i-1][1]%r + dp[i-1][0]%r)%r;
	}
	return dp;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	vector<vector<long long>>dp = solve();
	while (t--){
		int n;
		cin>>n;
		long long res = (dp[n][0]%r + dp[n][1]%r)%r;
		cout<<res<<endl;
	}
	return 0;
}
