//Sri Rama Jayam

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<stdio.h>

// Bellman Ford

using namespace std;

void bellman_ford(vector<vector<int>>edges, int n, int m){
	vector<long long>distance(n+1, LLONG_MIN);
	distance[1] = 0;
	for (int node = 1; node <= n-1; ++node){
		for (auto e : edges){
			int a = e[0];
			int b = e[1];
			int x = e[2];
			if (distance[a]!=LLONG_MIN){
				distance[b] = max(distance[b], distance[a]+x);
			}
		}
	}
	vector<bool> affected_by_cycle(n+1,false);
	for (int i = 1; i <= n; ++i){
		for (auto e : edges){
			int a = e[0];
			int b = e[1];
			int x = e[2];
			if (distance[a] != LLONG_MIN){
				if (distance[b] < distance[a] + x){
					distance[b] = distance[a] + x;
					affected_by_cycle[b] = true;
				}
				if (affected_by_cycle[a]){
					affected_by_cycle[b] = true;
				}
			}
		}
	}
	if (distance[n] == LLONG_MIN){
		cout<<-1<<endl;
	}
	else if (affected_by_cycle[n]){
		cout<<-1<<endl;
	}
	else{
		cout<<distance[n]<<endl;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin>>n>>m;
	vector<vector<int>>edges;
	for (int i = 0; i < m; ++i){
		int a,b,x;
		cin>>a>>b>>x;
		edges.push_back({a,b,x});
		//bellman_ford(edges,n,m);
	}
	bellman_ford(edges,n,m);
	return 0;
}
