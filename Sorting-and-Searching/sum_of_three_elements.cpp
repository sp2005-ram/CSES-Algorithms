//Sri Rama Jayam

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> sum_of_three_elements(vector<int>& num, int n, int target) {
	vector<pair<int, int>> valWithIdx;
    	for (int i = 0; i < n; i++) {
        	valWithIdx.push_back({num[i], i + 1});
    	}	

    	sort(valWithIdx.begin(), valWithIdx.end());

    
   	for (int i = 0; i <= n - 3; ++i) {
        	int left = i + 1;
        	int right = n - 1;
        	int remainingTarget = target - valWithIdx[i].first;

        	while (left < right) {
            	int currentSum = valWithIdx[left].first + valWithIdx[right].first;

            	if (currentSum == remainingTarget) {
                
                	return {valWithIdx[i].second, valWithIdx[left].second, valWithIdx[right].second};
            	} 
            	else if (currentSum < remainingTarget) {
                	left++;
            	} 
            	else {
                	right--;
            	}
        	}
    	}
    	return {}; 
}

int main(){
	int n, target;
	cin>>n>>target;
	vector<int>num(n);
	for (int i = 0; i < n; ++i){
		cin>>num[i];
	}
	vector<int> res = sum_of_three_elements(num,n,target);
	if (res.empty()){
		cout<<"IMPOSSIBLE"<<endl;
	}
	else{
		sort(res.begin(), res.end());
		for (int i = 0; i < 3; ++i){
			cout<<res[i]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
