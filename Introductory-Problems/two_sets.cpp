//Sri Rama Jayam

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void two_sets(int n){
	if (n <= 2){
		cout<<"NO"<<endl;
	}
	else if (n == 3){
		cout<<"YES"<<endl;
		cout<<2<<endl;
		cout<<1<<' '<<2<<endl;
		cout<<1<<endl;
		cout<<3<<endl;
	}
	else{
		if (n%4 != 0 && n%4 != 3){
			cout<<"NO"<<endl;
		}
		else if (n%4 == 0){
			cout<<"YES"<<endl;
			vector<int>a;
			vector<int>b;
			int count = 0;
			for (int i = 1; i <= n/2; ++i){
				if (count%2 == 0){
					a.push_back(i);
					a.push_back(n+1-i);
				}
				else{
					b.push_back(i);
					b.push_back(n+1-i);
				}
				count++;
			}
			sort(a.begin(), a.end());
			sort(b.begin(), b.end());
			cout<<n/2<<endl;
			for (int i = 0; i < n/2; ++i){
				cout<<a[i]<<' ';
			}
			cout<<endl;
			cout<<n/2<<endl;
			for (int i = 0; i < n/2; ++i){
				cout<<b[i]<<' ';
			}
			cout<<endl;
		}
		else{
			cout<<"YES"<<endl;
			vector<int>a;
			vector<int>b;
			int count = 0;
			for (int i = 1; i <= n/2; ++i){
				if (count%2 == 0){
					a.push_back(i);
					a.push_back(n-i);
				}
				else{
					b.push_back(i);
					b.push_back(n-i);
				}
				count++;
			}
			b.push_back(n);
			sort(a.begin(), a.end());
			sort(b.begin(), b.end());
			cout<<a.size()<<endl;
			for (int i = 0; i < a.size(); ++i){
				cout<<a[i]<<' ';
			}
			cout<<endl;
			cout<<b.size()<<endl;
			for (int i = 0; i < b.size(); ++i){
				cout<<b[i]<<' ';
			}
			cout<<endl;
		}
	}
}

int main(){
	int n;
	cin>>n;
	two_sets(n);
	return 0;
}
