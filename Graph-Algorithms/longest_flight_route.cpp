//Sri Rama Jayam

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<stdio.h>

using namespace std;

void bfs(){
	//Kahn's algorithm
	ios_base::sync_with_stdio(false);
        cin.tie(NULL);
	int n,m;
	cin>>n>>m;	
	vector<int>in_degree(n+1,0);
        vector<vector<int>>adj_list(n+1);
        for (int i = 0; i < m; ++i){
                int u,v;
                cin>>u>>v;
                adj_list[u].push_back(v);
		in_degree[v]++;
        }
	queue<int>q;
	for (int i = 1; i <= n; ++i){
		if (in_degree[i] == 0){
			q.push(i);
		}
	}
	vector<int>list;
	while (! q.empty()){
		int x = q.front();
		list.push_back(x);
		q.pop();
		for (int neighbor : adj_list[x]){
			in_degree[neighbor]--;
			if (in_degree[neighbor] == 0){
				q.push(neighbor);
			}
		}
	}
	vector<int> dp(n+1,-1);
	vector<int> parent(n+1,-1);
	dp[1] = 1;
	for (int x : list){
		if (dp[x] == -1){
			continue ;
		}
		for (int v : adj_list[x]){
			if (dp[x] + 1 > dp[v]){
				dp[v] = dp[x] + 1;
				parent[v] = x;
			}
		}
	}
	if (dp[n] == -1){
		cout<<"IMPOSSIBLE"<<endl;
	}
	else{
		cout<<dp[n]<<endl;
		int x = n;
		vector<int>res;
		while (parent[x] != -1){
			res.push_back(x);
			x = parent[x];
		}
		reverse(res.begin(), res.end());
		cout<<1<<' ';
		for (int i = 0; i < res.size(); ++i){
			cout<<res[i]<<' ';
		}
		cout<<endl;
	}	
}

int main(){
	bfs();
	return 0;
}
