//Sri Rama Jayam

#include<iostream>
#include<vector>
#include<queue>
#include<stdio.h>

using namespace std;

vector<int> topoSort(vector<vector<int>>&adj_list){
	int n = adj_list.size() - 1;
	vector<int> indegree(n+1,0);
	queue<int>q;
	vector<int> list;

	for (int i = 1; i <= n; ++i){
		for (int next : adj_list[i]){
			indegree[next]++;
		}
	}

	for (int i = 1; i <= n; ++i){
		if (indegree[i] == 0){
			q.push(i);
		}
	}
	while (! q.empty()){
		int top = q.front();
		q.pop();
		list.push_back(top);
		for (int next : adj_list[top]){
			indegree[next]--;
			if (indegree[next] == 0){
				q.push(next);
			}
		}
	}
	return list;	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	vector<vector<int>>edges(m);
	vector<vector<int>>adj_list(n+1);
	for (int i = 0; i < edges.size(); ++i){
		int u,v;
		cin>>u>>v;
		adj_list[u].push_back(v);
	}
	vector<int>list = topoSort(adj_list);
	if (list.size() < n){
		cout<<"IMPOSSIBLE"<<endl;
	}
	else{
		for (int i = 0; i < list.size(); ++i){
			cout<<list[i]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
