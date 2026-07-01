//Sri Rama Jayam

#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>

using namespace std;

const long long e = 1e9+7;

long long coin_combinations(vector<int>coins, int amount, int n){
	vector<int>dp(amount+1, 0);
	dp[0] = 1;
	for (int i = 0; i < n; ++i){
		for (int j = coins[i]; j <= amount; ++j){
			dp[j] = (dp[j] + dp[j - coins[i]])%e;
		}
	}
	/*
	for (int i = 0; i < n; ++i){
		for (int amt = 0; amt <= amount; ++amt){
			cout<<dp[i][amt]<<' ';
		}
		cout<<endl;	
	}
	*/
	
	return dp[amount];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, amount;
	cin>>n>>amount;
	vector<int>coins(n);
	for (int i = 0; i < n; ++i){
		cin>>coins[i];
	}
	cout<<coin_combinations(coins, amount, n)<<endl;
	return 0;
}
