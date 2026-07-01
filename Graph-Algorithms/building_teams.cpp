//Sri Rama Jayam

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void building_teams(vector<vector<int>>&graph, int n){
	vector<int>color(n+1, -1);
	queue<int>q;
	for (int i = 1; i <= n; ++i){
		if (color[i] == -1){
			color[i] = 1;
			q.push(i);
		}
		while (! q.empty()){
			int node = q.front();
			q.pop();
			for (int neighbor : graph[node]){
				if (color[neighbor] == -1){
					if (color[node] == 1){
						color[neighbor] = color[node] + 1;
					}
					else if (color[node] == 2){
						color[neighbor] = color[node] - 1;
					}
					q.push(neighbor);
				}
				else if (color[neighbor] == color[node]){
					cout<<"IMPOSSIBLE"<<endl;
					return;
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i){
		cout<<color[i]<<' ';
	}
	cout<<endl;
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>edges(m);
	for (int i = 0; i < m; ++i){
		int u, v;
		cin>>u>>v;
		edges[i] = {u,v};
	}
	vector<vector<int>>graph(n+1);
	for (int i = 0; i < m; ++i){
		graph[edges[i][0]].push_back(edges[i][1]);
		graph[edges[i][1]].push_back(edges[i][0]);
	}
	building_teams(graph,n);
	return 0;
}
