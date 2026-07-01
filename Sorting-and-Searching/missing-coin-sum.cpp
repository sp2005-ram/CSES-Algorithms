//Sri Rama Jayam

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long int missing_sum(vector<int>coins, int n){
	sort(coins.begin(), coins.end());
	long long reachable = 1;
	for (int i = 0; i < n; ++i){
		if (coins[i]<=reachable){
			reachable+=coins[i];
		}
		else{
			return reachable;
		}
	}
	return reachable;
}

int main(){
	int n;
	cin>>n;
	vector<int>coins(n);
	for (int i = 0; i < n; ++i){
		cin>>coins[i];
	}
	cout<<missing_sum(coins,n)<<endl;	
	return 0;
}

