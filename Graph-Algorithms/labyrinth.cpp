//Sri Rama Jayam

#include<iostream>
#include<vector>

using namespace std;

void dfs(vector<vector<char>>&grid, int n, int m, vector<vector<bool>>&visited, int index_x, int index_y){
	visited[index_x][index_y] = true;
	// Left traverse
	int left = index_x-1;
	while (left >= 0 && grid[left][index_y] != '#' && !visited[left][index_y]){
		dfs(grid,n,m,visited,left,index_y);
		left--;
	}

	// Right traverse
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<char>>grid;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			cin>>grid[i][j];
		}
	}
	int start_x = -1;
	int start_y = -1;
	int end_x = -1;
	int end_y = -1;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			if (grid[i][j] == 'A'){
				start_x = i;
				start_y = j;
			}
			if (grid[i][j] == 'B'){
				end_x = i;
				end_y = j;
			}
		}
	}
	return 0;
}
