//Sri Rama Jayam

#include<bits/stdc++.h>

using namespace std;

// Digit DP

string num_str;
//dp[ith digit from left][previous digit][leading_zeroes][tight]
long long dp[20][11][2][2];

long long counting_numbers_solve(int idx, int prev_digit, bool leading_zeroes, bool tight){
	if (idx == num_str.size()){
		return 1;
	}

	if (prev_digit != -1 && dp[idx][prev_digit][leading_zeroes][tight] != -1){
		return dp[idx][prev_digit][leading_zeroes][tight];
	}

	int lb = 0;
	int ub = (tight == 1) ? (num_str[idx] - '0') : 9;
	long long ans = 0;
	for (int digit = lb; digit <= ub; ++digit){
		if (digit != 0 && digit == prev_digit){
			continue;
		}
		if (digit == 0 && digit == prev_digit && leading_zeroes == false){
			// Numbers like 700, where the leading prefix does not have zeroes (leading_zeroes = false)
			continue;
		}
		bool nxt_leading_zeroes = (leading_zeroes) & (digit == 0);
		bool nxt_tight = tight && (digit == num_str[idx] - '0');
		ans+=counting_numbers_solve(idx+1, digit, nxt_leading_zeroes, nxt_tight);
	}
	return dp[idx][prev_digit][leading_zeroes][tight] = ans;
}
	
long long solve(long long x){
	if (x < 0) return 0;
	memset(dp, -1, sizeof(dp));
	num_str = to_string(x);
	return counting_numbers_solve(0,-1,true,true);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long l, r;
	cin>>l>>r;
	cout<<solve(r) - solve(l-1)<<endl;
	return 0;
}	
