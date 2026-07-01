//Sri Rama Jayam

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Task{
	long long duration, deadline;
};

long long max_reward(vector<Task>tasks, int n){
	auto comp = [](Task a, Task b){
		return a.duration < b.duration;
	};
	sort(tasks.begin(), tasks.end(), comp);
	long long time = 0;
	long long reward = 0;
	for (long long i = 0; i < tasks.size(); ++i){
		reward+=(tasks[i].deadline - time-tasks[i].duration);
		time+=tasks[i].duration;
	}
	return reward;
}

int main(){
	long long n;
	cin>>n;
	vector<Task>tasks(n);
	for (long long i = 0; i < n; ++i){
		long long duration, deadline;
		cin>>duration>>deadline;
		tasks[i] = {duration, deadline};
	}
	cout<<max_reward(tasks,n)<<endl;
	return 0;
}
