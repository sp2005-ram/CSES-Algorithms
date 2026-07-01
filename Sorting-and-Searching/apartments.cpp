//Sri Rama Jayam

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int apartment_count(vector<int>applicants, int n, vector<int>apartments, int m, int k){
	sort(applicants.begin(), applicants.end());
	sort(apartments.begin(), apartments.end());
	int i = 0, j = 0;
	int count = 0;
	while (i < n && j < m){
		if (applicants[i] >= apartments[j]-k && applicants[i] <= apartments[j]+k){
			count++;
			//cout<<applicants[i]<<' '<<apartments[j]<<endl;
			i++;
			j++;
		}
		else if (applicants[i] < apartments[j]-k){
			i++;
		}
		else if (applicants[i] > apartments[j]+k){
			j++;
		}
	}
	return count;
}

int main(){
	int n,m,k;
	cin>>n>>m>>k;
	vector<int>applicants(n);
	vector<int>apartments(m);
	for (int i = 0; i < n; ++i){
		cin>>applicants[i];
	}
	for (int j = 0; j < m; ++j){
		cin>>apartments[j];
	}
	cout<<apartment_count(applicants,n,apartments,m,k)<<endl;
	return 0;
}
