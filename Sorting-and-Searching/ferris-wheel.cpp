//Sri Rama Jayam

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int min_gondolas_needed(vector<int>weights, int n, int x){
	sort(weights.begin(), weights.end());
	int count = 0;
	int left = 0;
	int right = n-1;
	while (left <= right){
		if (weights[left] + weights[right] <= x){
			count++;
			left++;
			right--;
		}
		else{
			count++;
			right--;
		}
	}
	return count;
}

int main(){
	int n, x;
	cin>>n>>x;
	vector<int>weights(n);
	for (int i = 0; i < n; ++i){
		cin>>weights[i];
	}
	cout<<min_gondolas_needed(weights,n,x)<<endl;
	return 0;
}
