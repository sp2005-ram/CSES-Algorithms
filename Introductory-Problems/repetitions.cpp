//Sri Rama Jayam

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.size();
    vector<int>dp(n,1);
    for (int i = 1; i < n; ++i){
        if (s[i] == s[i-1]){
            dp[i] = dp[i-1]+1;
        }
    }
    cout<<*max_element(dp.begin(), dp.end())<<endl;
    return 0;
}
