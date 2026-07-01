//Sri Rama Jayam

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void bfs(vector<vector<int>>&graphs, vector<int>&parent, vector<int>&distance){
	queue<int>q;
	int source = 1;
	distance[source] = 1;
	q.push(source);
	while (! q.empty()){
		int node = q.front();
		q.pop();
		for (int neighbor : graphs[node]){
			if (distance[neighbor] == 1e9){
				parent[neighbor] = node;
				distance[neighbor] = distance[node] + 1;
				q.push(neighbor);
			}
		}	
	}
}

void printShortestDistance(vector<vector<int>>&graph, int n){
	vector<int>parent(n+1, -1);
	vector<int>distance(n+1, 1e9);
	bfs(graph, parent, distance);
	if (distance[n] == 1e9){
		cout<<"IMPOSSIBLE"<<endl;
	}
	else{
		cout<<distance[n]<<endl;
		vector<int>path;
		int current_node = n;
		path.push_back(n);
		while (parent[current_node] != -1){
			path.push_back(parent[current_node]);
			current_node = parent[current_node];
		}
		for (int i = path.size()-1; i >= 0; i--){
			cout<<path[i]<<' ';
		}
		cout<<endl;
	}
}

int main(){
	int n, m;
	cin>>n>>m;
	vector<vector<int>>edges(m);
	for (int i = 0; i < m; ++i){
		int u, v;
		cin>>u>>v;
		edges[i] = {u,v};
	}
	vector<vector<int>>adj_list(n+1);
	for (int i = 0; i < m; ++i){
		adj_list[edges[i][0]].push_back(edges[i][1]);
		adj_list[edges[i][1]].push_back(edges[i][0]);
	}
	printShortestDistance(adj_list, n);
	return 0;
}
