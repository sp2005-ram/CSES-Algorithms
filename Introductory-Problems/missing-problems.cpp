//Sri Rama Jayam

#include<iostream>
#include<vector>

using namespace std;

int get_missing_number(vector<int>num, int n){
	long long ex_sum = 1LL*n*(n+1)/2;
	long long sum = 0;
	for (int x : num){
		sum+=x;
	}
	//cout<<ex_sum<<' '<<sum<<endl;
	return ex_sum-sum;
}

int main(){
	int n;
	cin>>n;
	vector<int>num(n-1);
	for (int i = 0; i < n-1; ++i){
		cin>>num[i];
	}
	cout<<get_missing_number(num,n)<<endl;
	return 0;
}
