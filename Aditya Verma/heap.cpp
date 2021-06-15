#include <bits/stdc++.h>

using namespace std;

int kThSmallest(vector<int> &v,int k) {
	priority_queue<int> q;
	for(int i : v){
		q.push(i);
		if(q.size()>k) {
			q.pop();
		}
	}
	return q.top();
}

void kLargestElement(vector<int> &v,int k) {
	priority_queue<int, vector<int>, greater<int>> q;
	for(int  i : v){
		q.push(i);
		if(q.size()>k){
			q.pop();
		}
	}
	while(q.size()>0){
		cout<<q.top()<<endl;
		q.pop();
	}
}

void sortKSortedArray(vector<int> &v,int k) {
	priority_queue<int,vector<int>,greater<int>> q;
	for(int i: v){
		q.push(i);
		if(q.size()>k){
			cout<<q.top()<<endl;
			q.pop();
		}
	}
	while(q.size()>0){
		cout<<q.top()<<endl;
		q.pop();
	}
}

void kClosestNumber(vector<int> &v,int k,int x) {
	priority_queue<pair<int,int>> q;
	for(int i : v) {
		q.push({abs(x-i),i});
		if(q.size()>k){
			q.pop();
		}
	}
	while(q.size()>0){
	cout<<q.top().second<<endl;
	q.pop();
	}
}

void topKFrequentNumber(vector<int> &v,int k) {
	priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> q;
	unordered_map<int,int> m;
	for(int i : v) {
		m[i]++;
	}
	for(auto i: m) {
		q.push({i.second,i.first});
		if(q.size()>k) {
			q.pop();
		}
	}
	while(q.size()>0){
	cout<<q.top().second<<endl;
	q.pop();
	}
}

void frequencySort(vector<int> &v){
	priority_queue<pair<int,int>> q;
	unordered_map<int,int> m;
	for(int i : v){
		m[i]++;
	}
	for(auto i: m){
		q.push({i.second,i.first});
	}
	while(q.size()>0){
		cout<<q.top().second<<endl;
		q.pop();
	}
}

void kClosestPointToOrigin(vector<pair<int,int>> &v,int k) {
	priority_queue<pair<int,pair<int,int>>> q;
	for(auto i : v){
		q.push({i.first*i.first + i.second*i.second,i});
		if(q.size()>k){
			q.pop();
		}
	}
	while(q.size()>0){
	cout<<q.top().second.first<<" "<<q.top().second.second<<endl;
	q.pop();
	}
}

void connectRope(vector<int> &v) {
	priority_queue<int,vector<int>,greater<int>> q;
	int cost=0;
	for(int i : v){
		q.push(i);
	}
	while(q.size()>1){
		int a=q.top();
		q.pop();
		int b=q.top();
		q.pop();
		cost += (a+b);
		q.push(a+b);
	}
	cout<<cost<<endl;
}

void sumOfElemenents(vector<int> &v,int a,int b) {
	int x= kThSmallest(v,a);
	int y= kThSmallest(v,b);

	int c,d;

	int sum=0;

	for(int i=0;i<v.size();i++){
		if(x==v[i]){
			c=i;
		}
		else if(y==v[i]){
			d=i;
		}
	}
	for(int i =min(c,d)+1;i<max(c,d);i++){
		sum+=v[i];
	}
	cout<<sum<<endl;
}

int main(int argc, char const *argv[])
{
	
	// vector<int> v = {7,10,4,3,20,15};

	// cout<<kThSmallest(v,3);

	// kLargestElement(v,3);

	// vector<int> v = {6,5,3,2,8,10,9};

	// sortKSortedArray(v,3);

	// vector<int> v= {5,6,7,8,9};

	// kClosestNumber(v,3,7);

	// vector<int> v= {1,1,1,3,2,2,4};

	// topKFrequentNumber(v,2);

	// frequencySort(v);

	// vector<pair<int,int>> v = {{1,3},{-2,2},{5,8},{0,1}};

	// kClosestPointToOrigin(v,2);

	// vector<int> v= {1,2,3,4,5};

	// connectRope(v);

	// vector<int> v = {1,3,5,12,11,15};

	// sumOfElemenents(v,3,6);

	return 0;
}