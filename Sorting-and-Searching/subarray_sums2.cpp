//SriRamajayam

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<stdio.h>

using namespace std;

long long subarray_sums(vector<int>&num, int &n, int &x){
	long long prefix_sum = 0;
	map<long long, int>sum_count;
	long long count = 0;
	sum_count[0] = 1;
	for (int i = 1; i <= n; ++i){
		prefix_sum = prefix_sum + num[i-1];
		long long bal = prefix_sum - x;
		if (sum_count.find(bal) != sum_count.end()){
			count+=sum_count[bal];
		}
		sum_count[prefix_sum]++;	
	}
	return count;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, x;
	cin>>n>>x;
	vector<int>num(n);
	for (int i = 0; i < n; ++i){
		cin>>num[i];
	}
	cout<<subarray_sums(num,n,x)<<endl;
	return 0;
}
