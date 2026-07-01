//Sri Rama Jayam

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int max_pages(const vector<int>& pages, const vector<int>& costs, int n, int max_cost){
	vector<int> dp(max_cost+1, 0);
	for (int i = 0; i < n; ++i){
		for (int cost = max_cost; cost >= costs[i]; --cost){
			dp[cost] = max(dp[cost], dp[cost-costs[i]] + pages[i]);
		}
	}
	return dp[max_cost];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, max_cost;
	cin>>n>>max_cost;
	vector<int>costs(n);
	vector<int>pages(n);
	for (int i = 0; i < n; ++i){
		cin>>costs[i];
	}
	for (int i = 0; i < n; ++i){
		cin>>pages[i];
	}
	cout<<max_pages(pages,costs,n,max_cost)<<endl;
	return 0;
}
