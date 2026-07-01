//Sri Rama Jayam

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long max_subarray_sum(vector<int>nums, int n){
	long long int max_sum = nums[0];
	long long int curr_sum = nums[0];
	for (int i = 1; i < n; ++i){
		curr_sum+=nums[i];
		if (curr_sum < nums[i]){
			curr_sum = nums[i];
		}
		max_sum = max(max_sum, curr_sum);
		//cout<<curr_sum<<' '<<max_sum<<endl;
	}
	return max_sum;
}

int main(){
	int n;
	cin>>n;
	vector<int>nums(n);
	for (int i = 0; i < n; ++i){
		cin>>nums[i];
	}
	cout<<max_subarray_sum(nums,n)<<endl;
	return 0;
}
