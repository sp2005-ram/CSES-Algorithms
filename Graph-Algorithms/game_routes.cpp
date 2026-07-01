//Sri Rama Jayam

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stdio.h>

using namespace std;

void game_routes(vector<vector<int>>&adj_list, vector<int>&in_degree, int n, int m){
	queue<int>q;
	for (int i = 1; i <= n; ++i){
		if (in_degree[i] == 0){
			q.push(i);
		}
	}
	vector<int>list;
	while (! q.empty()){
		int node = q.front();
		list.push_back(node);
		q.pop();
		for (int neighbor : adj_list[node]){
			in_degree[neighbor]--;
			if (in_degree[neighbor] == 0){
				q.push(neighbor);
			}	
		}
	}
	vector<long long>dp(n+1,0);
	long long e = 1e9+7;
	dp[1] = 1;
	for (int u : list){
		if (dp[u] == 0){
			continue;
		}
		for (int v : adj_list[u]){
			dp[v] = (dp[v]%e + dp[u]%e)%e;
			dp[v]%=e;
		}	
	}
	cout<<dp[n]<<endl;
}	

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	vector<vector<int>>adj_list(n+1);
	vector<int>in_degree(n+1,0);
	for (int i = 0; i < m; ++i){
		int u,v;
		cin>>u>>v;
		adj_list[u].push_back(v);
		in_degree[v]++;
	}
	game_routes(adj_list, in_degree, n, m);
	return 0;
}
