//Sri Rama Jayam

#include<iostream>
#include<vector>

using namespace std;

long long dice_combinations(int n){
	vector<long long>dp(n+1,0);
	long long e = 1e9+7;
	if (n>=1) dp[1] = 1;
	if (n>=2) dp[2] = 2;
	if (n>=3) dp[3] = 4;
	if (n>=4) dp[4] = 8;
	if (n>=5) dp[5] = 16;
	if (n>=6) dp[6] = 32;
	for (int i = 7; i <= n; ++i){
		dp[i] = (dp[i-1]%e + dp[i-2]%e + dp[i-3]%e + dp[i-4]%e + dp[i-5]%e + dp[i-6]%e)%e;
	}
	return dp[n];
}

int main(){
	int n;
	cin>>n;
	cout<<dice_combinations(n)<<endl;
	return 0;
}
