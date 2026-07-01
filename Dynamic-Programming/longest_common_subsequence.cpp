//Sri Rama Jayam

#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>

using namespace std;



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	vector<int>a(n);
	vector<int>b(m);
	for (int i = 0; i < n; ++i){
		cin>>a[i];
	}
	for (int j = 0; j < m; ++j){
		cin>>b[j];
	}
	return 0;
}
