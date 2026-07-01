//Sri Rama Jayam

#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;

vector<long long> build_prefix(vector<int>a, int n){
	vector<long long>prefix(n+1,0);
	for (int i = 1; i <= n; ++i){
		prefix[i] = prefix[i-1] + a[i-1];
	}
	return prefix;
}

long long subarray_divisibility(vector<int>a, int n){
	vector<long long>prefix = build_prefix(a,n);
	long long count = 0;
	vector<int>rem(n,0);
	for (int i = 1; i <= n; ++i){
		if (prefix[i] >= 0){
			rem[prefix[i]%n]++;
		}
		else{
			rem[((prefix[i]%n) + n) % n]++;
		}
	}
	count = rem[0] + 1LL*rem[0]*(rem[0]-1)/2;
	for (int i = 1; i < n; ++i){
		if (rem[i] >= 1){
			count+=(1LL*rem[i]*(rem[i]-1))/2;
		}
	}
	return count;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	vector<int>a(n);
	for (int i = 0; i < n; ++i){
		cin>>a[i];
	}
	cout<<subarray_divisibility(a,n)<<endl;
	return 0;
}
