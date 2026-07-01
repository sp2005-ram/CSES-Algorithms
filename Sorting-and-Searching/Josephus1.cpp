//Sri Rama Jayam

#include<iostream>
#include<vector>
#include<stdio.h>
#include<climits>

using namespace std;

struct Node{
	int val;
	Node* next;
	Node (int v){
		val = v;
		next = nullptr;
	}
};

void solve(int n){
	if (n == 1){
		cout<<1<<endl;
		return ;
	}
	Node* starter = new Node(1);
	Node* current = starter;
	for (int i = 2; i <= n; ++i){
		Node* n = new Node(i);
		current -> next = n;
		current = current -> next;
	}
	current -> next = starter;
	current = starter;
	while (current != current -> next -> next){
		cout<<current->next->val<<' ';
		current -> next = current -> next -> next;
		current = current -> next;
	}
	cout<<current->next->val<<' '<<current->val<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	solve(n);
	return 0;
}
