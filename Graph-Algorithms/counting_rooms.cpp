//Sri Rama Jayam

#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;


void dfs(int x, int y, const vector<vector<char>>&grid, vector<vector<bool>>&visited, int n, int m){	
	static const vector<vector<int>>directions = {{-1,0},{0,-1},{1,0},{0,1}};
	//const vector<vector<int>>directions = {{-1,0},{0,-1},{1,0},{0,1}};
	visited[x][y] = true;
	for (vector<int> direction : directions){
		int dx = direction[0];
		int dy = direction[1];
		int nx = x + dx;
		int ny = y + dy;
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '.' && !visited[nx][ny]) {
			dfs(nx,ny,grid,visited,n,m);
		}
	}
}

int count_rooms(const vector<vector<char>>&grid, int n, int m){
	vector<vector<bool>>visited(n,vector<bool>(m,false));
	int count = 0;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			if (!visited[i][j] && grid[i][j] == '.'){
				dfs(i,j,grid,visited,n,m);
				count++;
			}
		}
	}
	return count;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin>>n>>m;
	vector<vector<char>>grid(n,vector<char>(m));
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			cin>>grid[i][j];
		}
	}
	//vector<vector<bool>>visited(n,vector<bool>(m,false));
	cout<<count_rooms(grid,n,m)<<endl;
	return 0;
}
