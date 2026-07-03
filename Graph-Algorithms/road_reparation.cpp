//Sri Rama Jayam

#include<bits/stdc++.h>

using namespace std;
//MST using Disjoint Set Union
class DSU{
	vector<int>parent,rank;
	public:
	DSU(int n){
		parent.resize(n);
		rank.resize(n);
		for (int i = 0; i < n; ++i){
			parent[i] = i;
			rank[i] = 1;
		}
	}

	int find(int x){
		if (x == parent[x]){
			return parent[x];
		}
		return parent[x] = find(parent[x]);
	}

	void unite(int x, int y){
		int s1 = find(x), s2 = find(y);
		if (s1 != s2){
			if (rank[s1] < rank[s2]) parent[s1] = parent[s2];
			else if (rank[s2] < rank[s1]) parent[s2] = parent[s1];
			else parent[s2] = s1, rank[s1]++;
		}
	}	
};

bool comp(const vector<int>&a, const vector<int>&b){
	return a[2] < b[2];
}

void solve(vector<vector<int>>edges, int n){
	//sort(edges.begin(), edges.end(), comp);
	DSU dsu(n);
	long long cost = 0;
	int count = 0;
	int edges_used = 0;
	for (vector<int>edge : edges){
		int u = edge[0], v = edge[1], w = edge[2];
		if (dsu.find(u) != dsu.find(v)){
			dsu.unite(u,v);
			cost+=w;
			edges_used++;
			if (++count == n-1){
				break;
			}
		}
	}
	if (edges_used != n-1){
		cout<<"IMPOSSIBLE"<<endl;
		return ;
	}
	cout<<cost<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	vector<vector<int>>edges(m);
	for (int i = 0; i < m; ++i){
		int u,v,w;
		cin>>u>>v>>w;
		edges[i] = {u-1,v-1,w};
	}
	sort(edges.begin(), edges.end(), comp);
	solve(edges,n);
	return 0;
}
