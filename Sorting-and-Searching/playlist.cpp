//SriRamajayam

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<stdio.h>

using namespace std;

int longest_unique_subarray(vector<int>num, int n){
	int l = 0;
	int r = 1;
	int res = 1;
	map<int,int>seen;
	seen[num[0]] = 0;
	while (r < n){
		if (seen.find(num[r]) != seen.end()) {
			if (l <= seen[num[r]]){
				l = seen[num[r]]+1;
			}
			seen[num[r]] = r;
		}
		else {
			seen[num[r]] = r;
		}
		res = max(res, r - l + 1);
		//cout<<r<<' '<<l<<' '<<res<<endl;
		r++;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	vector<int>num(n);
	for (int i = 0; i < n; ++i) {
		cin>>num[i];
	}
	cout<<longest_unique_subarray(num,n)<<endl;
	return 0;
}
