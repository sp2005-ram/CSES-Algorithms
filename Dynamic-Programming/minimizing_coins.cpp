//Sri Rama Jayam

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

int min_coins(vector<int>coins, int n, int amount){
	vector<int>dp(amount+1, INT_MAX);
	dp[0] = 0;
	for (int i = 1; i <= amount; ++i){
		for (int coin : coins){
			if (i-coin>=0 && dp[i-coin] != INT_MAX){
				dp[i] = min(dp[i], dp[i-coin]+1);
			}
		}
	}
	return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main(){
	int n,amount;
	cin>>n>>amount;
	vector<int>coins(n);
	for (int i = 0; i < n; ++i){
		cin>>coins[i];
	}
	cout<<min_coins(coins,n,amount)<<endl;
	return 0;
}
