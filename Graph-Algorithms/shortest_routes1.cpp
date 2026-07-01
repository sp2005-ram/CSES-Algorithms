//Sri Rama Jayam

#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<utility>
#include<climits>

using namespace std;

vector<long long> dijkstra(const vector<vector<pair<int,long long>>>& adj, int src) {
    int n = adj.size();
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

    vector<long long> dist(n, LLONG_MAX);
    dist[src] = 0;
    pq.emplace(0, src);

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &[v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }

    return dist;
}


int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>edges(m);
	vector<vector<pair<int,long long>>>adj(n+1);
	for (int i = 0; i < m; ++i){
		int u, v, w;
		cin>>u>>v>>w;
		edges[i] = {u,v,w};
	}
	for (int i = 0; i < m; ++i){
		pair<int,int>a;
		a.first = edges[i][1];
		a.second = edges[i][2];
		adj[edges[i][0]].push_back(a);
	}
	int src = 1;
	vector<long long>distance = dijkstra(adj,src);
	for (int i = 1; i < distance.size(); ++i){
		cout<<distance[i]<<' ';
	}
	cout<<endl;
	return 0;
}
