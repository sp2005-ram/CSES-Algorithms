//Sri Rama Jayam

#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<algorithm>

using namespace std;

void solve(string s){
	vector<int>alpha_count(26,0);
	for (int i = 0; i < s.size(); ++i){
		alpha_count[s[i] - 'A']++;
	}
	int odd_count = 0;
	int odd_idx = -1;
	for (int i = 0; i < 26; ++i){
		if (alpha_count[i]%2){
			odd_count+=1;
			odd_idx = i;
		}
	}
	if (odd_count > 1){
		cout<<"NO SOLUTION"<<endl;
		return ;
	}
	string res = "";
	for (int i = 0; i < 26; ++i){
		if (alpha_count[i]%2 == 0){
			string r = string(alpha_count[i]/2,i+'A');
			res+=r;
		}
	}
	string e = res;
	if (odd_idx != -1){
		string t = string(alpha_count[odd_idx],odd_idx + 'A');
		res+=t;
	}
	int n = res.size();
	reverse(e.begin(), e.end());
	res+=e;
	cout<<res<<endl;	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin>>s;
	solve(s);
	return 0;
}
