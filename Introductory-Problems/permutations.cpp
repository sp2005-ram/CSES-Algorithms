//Sri Rama Jayam

#include<iostream>
#include<vector>

using namespace std;


int main(){
	int n;
	cin>>n;
	if (n == 1){
		cout<<n<<endl;
	}
	if (n == 2 || n == 3){
		cout<<"NO SOLUTION"<<endl;
	}
	if (n == 4){
		cout<<"2 4 1 3"<<endl;
	}
	if (n > 4){
		for (int i = n; i > 0; --i){
			if (i%2 == 0){
				cout<<i<<' ';
			}
		}
		for (int i = n; i > 0; --i){
			if (i%2){
				cout<<i<<' ';
			}
		}
		cout<<endl;
	}
	return 0;
}
