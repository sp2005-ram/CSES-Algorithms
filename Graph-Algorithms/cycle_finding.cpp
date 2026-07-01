//Sri Rama Jayam
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<stdio.h>

using namespace std;

void bellman_ford_cycle_finding(long long n, long long m,vector<vector<long long>>edges){
	if (n == 1 && edges[0][0] == edges[0][1]){
		cout<<"YES"<<endl;
		cout<<edges[0][0]<<' '<<edges[0][1]<<endl;
		return ;
	}
	vector<long long>distance(n+1,INT_MAX);
	vector<long long>parent(n+1,-1);
	long long virtual_src = 0;
	for (long long i = 1; i <= n; ++i){
		edges.push_back({virtual_src,i,0});
	}
	distance[virtual_src] = 0;
	for (long long i = 1; i <= n; ++i){
		for (auto e : edges){
			long long u = e[0];
			long long v = e[1];
			long long w = e[2];
			if (distance[u] != INT_MAX && distance[v] > distance[u] + w){
				distance[v] = distance[u] + w;
				parent[v] = u;
			}
		}
		/*
		cout<<"Distances after "<<i<<"th iteration : "<<endl;
		for (long long j = 1; j <= n; ++j){
			cout<<distance[j]<<' ';
		}
		cout<<endl;
		*/
	}
	long long cycle_vertex = -1;
	for (auto e : edges){
		long long u = e[0];
		long long v = e[1];
		long long w = e[2];
		if (distance[v] != INT_MAX && distance[v] > distance[u] + w){
			cycle_vertex = v;
			cout<<"YES"<<endl;
			break;
		}
	}
	if (cycle_vertex == -1){
		cout<<"NO"<<endl;
		return ;
	}
	long long x = cycle_vertex;
	vector<long long> cycle;
	for (long long i = 0; i <= n; ++i){
		x = parent[x];
		//cout<<"Value of x is "<<x<<endl;
	}
	long long curr = x;
	do{
		cycle.push_back(curr);
		curr = parent[curr];
	} while (curr != x);
	cycle.push_back(x); 
	reverse(cycle.begin(), cycle.end());
	for (long long v : cycle){
		cout<<v<<' ';
	}
	cout<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n,m;
	cin>>n>>m;
	vector<vector<long long>>edges(m);
	for (long long i = 0; i < m; ++i){
		long long u,v,w;
		cin>>u>>v>>w;
		edges[i] = {u,v,w};
	}
	bellman_ford_cycle_finding(n,m,edges);
	return 0;
}
