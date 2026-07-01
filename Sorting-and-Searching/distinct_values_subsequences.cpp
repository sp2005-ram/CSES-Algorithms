//Sri Rama Jayam

#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<map>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	vector<int>a(n);	
	map<int,int>element_frequency;
	long long e = 1e9+7;
	for (int i = 0; i < n; ++i){
		cin>>a[i];
		element_frequency[a[i]]++;
	}
	long long res = 1;
	for (auto &p : element_frequency){
		res*=(p.second+=1)%e;
		res%=e;
	}
	//long long e = 1e9+7;
	res = res%e;
	--res;
	cout<<res<<endl;
	return 0;
}
