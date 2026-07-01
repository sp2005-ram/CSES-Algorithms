//Sri Rama Jayam

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

vector<int>possible_sums(vector<int>money, int n, int sum){
	vector<vector<bool>>dp (n+1, vector<bool>(sum+1,0));
	for (int i = 0; i <= n; ++i){
		dp[i][0] = 1;
	}
	for (int i = 1; i <= n; ++i){
		for (int amt = 1; amt <= sum; ++amt){
			dp[i][amt] = dp[i-1][amt];
			if (money[i-1] <= amt){
				dp[i][amt] = dp[i][amt] || dp[i-1][amt-money[i-1]];
			}
		}
	}
	set<int>res;
	for (int i = 1; i <= n; ++i){
		for (int amt = 1; amt <= sum; ++amt){
			if (dp[i][amt] == 1){
				res.insert(amt);
			}
		}
	}
	return vector<int>(res.begin(), res.end());	
}

int main(){
	int n;
	cin>>n;
	vector<int>money(n);
	int sum = 0;
	for (int i = 0; i < n; ++i){
		cin>>money[i];
		sum+=money[i];
	}
	vector<int>res = possible_sums(money,n,sum);
	cout<<res.size()<<endl;
	for (int amt : res){
		cout<<amt<<' ';
	}
	cout<<endl;
	return 0;
}
