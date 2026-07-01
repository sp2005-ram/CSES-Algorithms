//Sri Rama Jayam

#include<iostream>
#include<vector>
#include<algorithm> 

using namespace std;

long long accumulate(vector<int>num){
	long long sum = 0;
	for (int n : num){
		sum+=n;
	}
	return sum;
}

long long min_max_subarray_sum(vector<int>num, int n, int k){
	long long left = *max_element(num.begin(), num.end());
	long long right = accumulate(num);
	long long ans;
	while (left <= right){
		long long mid = left + (right-left)/2;
		long long sum = 0;
		long long count = 1;
		for (long long i = 0; i < n; ){
			if (sum+num[i] <= mid){
				sum+=num[i];
				i++;
			}
			else{
				sum = 0;
				count++;
			}
		}
		if (count > k){
			left = mid+1; // Too many divisions implies mid is too small
		}
		else{
			ans = mid;
			right = mid-1;	
		}
	}
	return ans;
}

int main(){
	int n,k;
	cin>>n>>k;
	vector<int>num(n);
	for (int i = 0; i < n; ++i){
		cin>>num[i];
	}
	cout<<min_max_subarray_sum(num,n,k)<<endl;
	return 0;
}
