//Sri Rama Jayam

#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<stdio.h>

using namespace std;

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
	
	int find(int i){
		if (i == parent[i]){
			return parent[i];
		}
		return parent[i] = find(parent[i]);
	}

	void unite(int x, int y){
		int s1 = parent[x], s2 = parent[y];
		if (s1 != s2){
			if (rank[s1] < rank[s2]) parent[s1] = s2;
			else if (rank[s1] > rank[s2]) parent[s2] = s1;
			else parent[s1] = s2, rank[s1]++;
		}
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	DSU dsu(n);
	for (int i = 0; i < m; ++i){
		int u,v;
		cin>>u>>v;
		if (dsu.find(u-1) != dsu.find(v-1)){
			dsu.unite(u-1,v-1);
		}
	}
	int root = 0;
	int count = 0;
	vector<pair<int,int>>res;
	for (int i = 1; i < n; ++i){
		if (dsu.find(root) != dsu.find(i)){
			count++;
			//cout<<count<<endl;
			res.push_back({root+1,i+1});
			dsu.unite(root,i);
		}
	}
	cout<<count<<endl;
	for (pair<int,int>r : res){
		cout<<r.first<<' '<<r.second<<endl;
	}
	return 0;
}
