//Sri Rama Jayam

#include<iostream>
#include<vector>

using namespace std;

long long subarray_sums(vector<int>&arr, int n, int target){
	int start = 0, end = -1;
	long long sum = 0;
	long long count = 0;
	while (end < n){
		while (sum < target && end < n){
			end++;
			sum+=arr[end];
		}
		while (end < n && sum > target){
			sum-=arr[start];
			start++;
		}
		if (sum == target){
			count++;
			sum-=arr[start];
			start++;
		}
	}
	return count;
}

int main(){
	int n, target;
	cin>>n>>target;
	vector<int>arr(n);
	for (int i = 0; i < n; ++i){
		cin>>arr[i];
	}
	cout<<subarray_sums(arr,n,target)<<endl;
	return 0;
}
