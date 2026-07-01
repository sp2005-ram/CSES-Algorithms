//Sri Rama Jayam

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int coin_combinations(int n, int amount, vector<int>&coins){
	long long e = 1e9+7;
	vector<int>dp(amount+1,0);
	dp[0] = 1;
	for (int i = 1; i <= amount; ++i){
		for (int coin : coins){
			if (i-coin >= 0){
				dp[i]+=(dp[i-coin]%e);
				dp[i]%=e;
			}
		}
	}
	return dp[amount]%e;	
}

int main(){
	int n, amount;
	cin>>n>>amount;
	vector<int>coins(n);
	for (int i = 0; i < n; ++i){
		cin>>coins[i];
	}
	cout<<coin_combinations(n,amount,coins)<<endl;
	return 0;
}

