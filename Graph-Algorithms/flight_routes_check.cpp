//Sri Rama Jayam

#include<bits/stdc++.h>

using namespace std;

vector<int> bfs(vector<vector<int>>&adj_list, int n, int src){
	vector<int>distance(n+1, INT_MAX);
	distance[src] = 0;
	queue<int>q;
	q.push(src);
	while (! q.empty()){
		int node = q.front();
		q.pop();
		for (int neighbor : adj_list[node]){
			if (distance[neighbor] != INT_MAX){
				continue;
			}
			distance[neighbor] = distance[node] + 1;
			q.push(neighbor);
		}
	}
	return distance;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	vector<vector<int>>adj_list(n+1);
	vector<vector<int>>rev_adj_list(n+1);
	for (int i = 0; i < m; ++i){
		int u,v;
		cin>>u>>v;
		adj_list[u].push_back(v);
		rev_adj_list[v].push_back(u);
	}
	vector<int>d1 = bfs(adj_list,n,1);
	vector<int>d2 = bfs(rev_adj_list,n,1);
	bool flag = true;
	for (int i = 2; i <= n; ++i){
		//cout<<d1[i]<<' '<<d2[i]<<endl;
		if (d1[i] == INT_MAX){
			cout<<"NO"<<endl;
			cout<<1<<' '<<i<<endl;
			flag = false;
			break;
		}
		if (d2[i] == INT_MAX){
			cout<<"NO"<<endl;
			cout<<i<<' '<<1<<endl;
			flag = false;
			break;
		}
	}
	if (flag){
		cout<<"YES"<<endl;
	}
	return 0;
}
