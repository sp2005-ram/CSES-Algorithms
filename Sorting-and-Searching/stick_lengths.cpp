//Sri Rama Jayam

#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

long long stick_length(vector<int>lengths, int n){
	sort(lengths.begin(), lengths.end());
	int med = 0;
	if (n%2 != 0){
		med = lengths[n/2];
	}
	else{
		med = (lengths[n/2] + lengths[n/2-1])/2;
	}
	long long cost = 0;
	for (int i = 0; i < n; ++i){
		cost+=abs(lengths[i] - med);
	}
	return cost;
}

int main(){
	int n;
	cin>>n;
	vector<int>lengths(n);
	for (int i = 0; i < n; ++i){
		cin>>lengths[i];
	}
	cout<<stick_length(lengths,n)<<endl;
	return 0;
}
