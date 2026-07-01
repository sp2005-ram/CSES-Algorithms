//SriRamajayam

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

const long long INF = LLONG_MAX/4;

vector<vector<long long>> shortest_route2(vector<vector<int>>&adj_matrix, int n){
	vector<vector<long long>>dp(n, vector<long long>(n, INF));
	for (int i = 0; i < n; ++i){
		dp[i][i] = 0;
	}
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			if (adj_matrix[i][j]) dp[i][j] = adj_matrix[i][j];
		}
	}
	for (int k = 0; k < n; ++k){
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j){
				if (dp[i][k] < INF && dp[k][j] < INF){
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
				}
			}
		}
	}
	for (int i = 0; i < n; ++i){
                dp[i][i] = 0;
        }
	return dp;
}

int main(){
	int n, m, q;
	cin>>n>>m>>q;
	vector<vector<int>>adj_matrix(n, vector<int>(n, 0));
	for (int i = 0; i < m; ++i){
		int u, v, w;
		cin>>u>>v>>w;
		int a = u - 1;
		int b = v - 1;
		if (adj_matrix[a][b] == 0){
    			adj_matrix[a][b] = adj_matrix[b][a] = w;
		}
		else {
    			adj_matrix[a][b] = adj_matrix[b][a] = min(adj_matrix[a][b], w);
		}
	}
	vector<vector<long long>>dp = shortest_route2(adj_matrix, n);
	for (int i = 0; i < q; ++i){
		int u, v;
		cin>>u>>v;
		int a = u - 1;
		int b = v - 1;
		if (dp[a][b] != INF){
			cout<<dp[a][b]<<endl;
		}
		else{
			cout<<-1<<endl;
		}
	}
	return 0;
}
