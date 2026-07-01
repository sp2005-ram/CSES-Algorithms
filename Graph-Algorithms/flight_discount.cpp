//Sri Rama Jayam

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
#include<climits>
#include<stdio.h>

using namespace std;

vector<long long>dijkstra(vector<vector<pair<int,int>>>adj_list, int n, int src){
	priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>>pq;
	vector<long long>distance(n+1,LLONG_MAX);
	distance[src] = 0;
	pq.push({0,src});
	while (! pq.empty()){
		pair<long long, long long>x = pq.top();
		pq.pop();
		long long d = x.first;
		long long u = x.second;
		if (d > distance[u]){
			continue;
		}
		for (pair<int,int>p : adj_list[u]){
			long long v = p.first;
			long long w = p.second;
			if (distance[v] > distance[u] + w){
				distance[v] = distance[u] + w;
				pq.push({distance[v],v});
			}
		}
	}
	return distance;
}

void flight_discount(vector<vector<pair<int,int>>>adj_list, vector<vector<pair<int,int>>>rev_adj_list,int n, int m){
	vector<long long>d1 = dijkstra(adj_list,n,1);
	vector<long long>d2 = dijkstra(rev_adj_list,n,n);
	long long min_cost = LLONG_MAX;
	for (long long c = 1; c <= n; ++c){
		for (pair<long long,long long> p : adj_list[c]){
			long long nc = p.first;
			long long w = p.second;
			if (d1[c] != LLONG_MAX && d2[nc] != LLONG_MAX){
				min_cost = min(min_cost, d1[c] + w/2 + d2[nc]);
			}
		}
	}
	cout<<min_cost<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	vector<vector<pair<int,int>>>adj_list(n+1);
	vector<vector<pair<int,int>>>rev_adj_list(n+1);
	for (int i = 0; i < m; ++i){
		long long u, v, w;
		cin>>u>>v>>w;
		adj_list[u].push_back({v,w});
		rev_adj_list[v].push_back({u,w});
	}
	flight_discount(adj_list,rev_adj_list,n,m);
	return 0;
}
