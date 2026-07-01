//Sri Rama Jayam

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void two_sum(vector<int>num, int n, int k){
	vector<int>temp = num;
	sort(num.begin(), num.end());
	int left = 0;
	int right = n-1;
	int a = -1; 
	int b = -1;
	while (left <= right){
		if (num[left] + num[right] == k){
			a = num[left];
			b = num[right];
			break;
		}
		else if (num[left] + num[right] < k){
			left++;
		}
		else{
			right--;
		}
	}
	if (a == -1 || b == -1 || left == right){
		// Take care of distinct values
		cout<<"IMPOSSIBLE"<<endl;
		return; 
	}
	int idx1, idx2;
	for (int i = 0; i < n; ++i){
		if (temp[i] == a){
			idx1 = i+1;
			break;
		}
	}
	for (int i = n-1; i >= 0; i--){
		if (temp[i] == b){
			idx2 = i+1;
			break;
		}
	}
	cout<<min(idx1,idx2)<<' '<<max(idx1, idx2)<<endl;
}

int main(){
	int n, k;
	cin>>n>>k;
	vector<int>num(n);
	for (int i = 0; i < n; ++i){
		cin>>num[i];
	}
	two_sum(num,n,k);
	return 0;
}
