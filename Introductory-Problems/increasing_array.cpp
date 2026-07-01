//Sri Rama Jayam

#include<iostream>
#include<vector>

using namespace std;

long long increasing_array(vector<int>&num, int n){
	long long count = 0;
	for (int i = 0; i < n - 1; ++i){
		if (num[i] > num[i+1]){
			count+=(num[i] - num[i+1]);
			num[i+1] = num[i]; //change the value of the next element
		}
	}
	return count;
}

int main(){
	int n;
	cin>>n;
	vector<int>num(n);
	for (int i = 0; i < n; ++i){
		cin>>num[i];
	}
	cout<<increasing_array(num,n)<<endl;
	return 0;
}
