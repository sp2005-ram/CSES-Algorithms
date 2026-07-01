//Sri Rama Jayam

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int get_distinct_number_count(vector<int>num, int n){
	sort(num.begin(), num.end());
	int count = 0;
	int fast = 0, slow = 0;
	for (int fast = 0; fast < n; ++fast){
		if (num[fast] != num[slow]){
			slow = fast;
			count++;
		}
	}
	return ++count;
}

int main(){
	int n;
	cin>>n;
	vector<int>num(n);
	for (int i = 0; i < n; ++i){
		cin>>num[i];
	}
	cout<<get_distinct_number_count(num,n)<<endl;
	return 0;
}
