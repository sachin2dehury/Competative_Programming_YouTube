#include <bits/stdc++.h> 

using namespace std;

void DFS(vector<vector<int>> &v,int k){
	vector<int> ans(v.size(),0);
	stack<int> s;
	s.push(k);
	ans[k]=1;
	while(s.size()){
		int x=s.top();
		s.pop();
		cout<<x<<' ';
		for(int i: v[x]){
			if(!ans[i]){
				s.push(i);
				ans[i]=1;
			}
		}
	}
}

void BFS(vector<vector<int>> &v,int k){
	vector<int> ans(v.size(),0);
	queue<int> q;
	q.push(k);
	ans[k]=1;
	while(q.size()){
		int x=q.front();
		q.pop();
		cout<<x<<' ';
		for(int i : v[x]){
			if(!ans[i]){
				q.push(i);
				ans[i]=1;
			}
		}
	}
}

void topologicalSortHelper(vector<vector<int>> &v,stack<int> &s,vector<int> &ans,int i){
	ans[i]=1;
	for(int j: v[i]){
		if(!ans[j]){
			topologicalSortHelper(v,s,ans,j);
		}
	}
	s.push(i);
}

void topologicalSort(vector<vector<int>> &v){
	vector<int> ans(v.size(),0);
	stack<int> s;
	for(int i=0;i<v.size();i++){
		if(!ans[i]){
			topologicalSortHelper(v,s,ans,i);
		}
	}
	while(s.size()){
		cout<<(char)(s.top()+65)<<' ';
		s.pop();
	}
}

void Dijkestra(vector<vector<pair<int,int>>> &v,int k){
	vector<int> ans(v.size(),INT_MAX);
	vector<int> p(v.size());
	vector<int> f(v.size());
	ans[k]=0;
	for(int i=0;i<p.size();i++){
		p[i]=i;
	}
	for(int i=0;i<v.size();i++){
		f[k]=1;
		for(auto j: v[k]){
			 if(ans[j.first]>ans[k]+j.second){
			 	ans[j.first]=ans[k]+j.second;
			 	p[i]=k;
			 }
		}
		int x=INT_MAX;
		for(int j=0;j<p.size();j++){
			if(!f[j] && ans[j]<x) {
				x=ans[j];
				k=j;
			}
		}
	}
	for(int j: ans){
		cout<<j<<' ';
	}
}

void prims(vector<vector<pair<int,int>>> &v) {
	vector<int> ans(v.size(),0);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	int k=0;
	ans[k]=1;
	int s=0;
	for(int i=1;i<v.size();i++){
		for(auto j : v[k]){
			if(!ans[j.first]){
				q.push({j.second,j.first});
			}
		}
		while(ans[q.top().second]){
			q.pop();
		}
		s+=q.top().first;
		cout<<q.top().first<<' ';
		k=q.top().second;
		q.pop();
		ans[k]=1;
	}
	cout<<endl;
	cout<<s;
}

int parent(vector<int> &p,int i){
	if(p[i]==i){
		return i;
	} else {
		return parent(p,p[i]);
	}
}

void kruskals(vector<vector<pair<int,int>>> &v){
	vector<int> p(v.size());
	for(int i=0;i<v.size();i++){
		p[i]=i;
	}

	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;

	for(int i=0;i<v.size();i++){
		for(auto j: v[i]){
			q.push({j.second,{i,j.first}});
		}
	}

	while(q.size()){
		auto x =q.top();
		int i=parent(p,x.second.first);
		int j=parent(p,x.second.second);
		if(i!=j){
			p[j]=i;
			cout<<x.first<<' '<<x.second.first<<"->"<<x.second.second<<'\n';
		}
		q.pop();
	}
}

int isCyclic(vector<vector<int>> &v){
	vector<int> ans(v.size(),0);
	stack<int> s;
	s.push(0);
	ans[0]=1;
	while(s.size()){
		int k= s.top();
		s.pop();
		for(int i : v[k]){
			if(!ans[i]){
				s.push(i);
			} else {
				return 1;
			}
		}
	}
	return 0;
}

void floydWarshal(vector<vector<int>> &v){
	vector<vector<int>> ans=v;
	vector<vector<int>> p=v;
	for(int i=0;i<p.size();i++){
		for(int j=0;j<p[0].size();j++){
			p[i][j]=i;
		}
	}
	for(int k=0;k<v.size();k++) {
		for(int i=0;i<v.size();i++){
			for(int j=0;j<v.size();j++){
				if(ans[i][k]!=INT_MAX && ans[k][j]!=INT_MAX &&
					ans[i][j]>ans[i][k]+ans[k][j]){
					ans[i][j]=ans[i][k]+ans[k][j];
					p[i][j]=p[k][j];
				}
			}
		}
	}
	for(int i=0;i<p.size();i++){
		for(int j=0;j<p[0].size();j++){
			cout<<ans[i][j]<<' ';
		}
		cout<<endl;
	}
}

class edge{
public:
	int start;
	int end;
	int cost;
};

void bellmanFord(vector<edge> &v,int n,int s){
	vector<int> ans(n,INT_MAX);
	vector<int> p(n);
	ans[s]=0;
	for(int i=0;i<n;i++){
		p[i]=1;
	}
	while(n){
		for(edge i : v){
			if(ans[i.start] != INT_MAX && ans[i.end]>ans[i.start]+i.cost){
				ans[i.end]=ans[i.start]+i.cost;
				p[i.end] = i.start;
			}
			if(n==1 && ans[i.start] != INT_MAX && ans[i.end]>ans[i.start]+i.cost) {
				cout<<"Negative";
				return;
			}
		}
		n--;
	}
	for(int i : ans){
		cout<<i<<' ';
	}
}

void hamiltonianCycleHelper(vector<vector<int>> &v,vector<int> &ans,vector<int> &p,int s,int n){
	if(n==1){
		if(v[s][0]){
			for(int i : p){
				cout<<i<<' ';
			}
			cout<<endl;
		}
		return;
	} else {
		for(int i=0;i<v.size();i++){
			if(!ans[i] && v[s][i]){
				ans[i]=1;
				p.push_back(i);
				hamiltonianCycleHelper(v,ans,p,i,n-1);
				p.pop_back();
				ans[i]=0;
			}
		}
	}
}

void hamiltonianCycle(vector<vector<int>> &v){
	vector<int> ans(v.size(),0);
	vector<int> p;
	p.push_back(0);
	ans[0]=1;
	hamiltonianCycleHelper(v,ans,p,0,v.size());
}

int main(int argc, char const *argv[]) {


	// vector<vector<int>> v ={
	// 	{1,2},
	// 	{2},
	// 	{0,3},
	// 	{3}
	// };

	// DFS(v,0);

	// BFS(v,0);

	// vector<vector<int>> v = {
	// 	{2},
	// 	{2,3},
	// 	{4},
	// 	{5},
	// 	{5},
	// 	{6},
	// 	{}
	// };

	// topologicalSort(v);

	// vector<vector<pair<int,int>>> v={
	// 	{{1,5},{3,9},{4,2}},
	// 	{{2,2},{0,5}},
	// 	{{3,3},{1,2}},
	// 	{{0,9},{5,2}},
	// 	{{0,2},{5,3}},
	// 	{{4,3},{3,2}},
	// };

	// Dijkestra(v,0);

	// vector<vector<pair<int,int>>> v={
	// 	{{1,3},{3,1}},
	// 	{{2,1},{3,3},{0,3}},
	// 	{{3,1},{4,5},{5,4},{1,1}},
	// 	{{0,1},{1,3},{2,1},{4,6}},
	// 	{{5,2},{3,6},{2,5}},
	// 	{{4,2},{2,4}},
	// };

	// prims(v);

	// kruskals(v);

	// cout<<isCyclic(v)

	// vector<vector<int>> v={
	// 	{0,   5,  INT_MAX, 10},
	// 	{INT_MAX,  0,  3,  INT_MAX},
	// 	{INT_MAX, INT_MAX, 0,   1},
	// 	{INT_MAX, INT_MAX, INT_MAX, 0}
	// };

	// floydWarshal(v);

	// vector<edge> v ={
	// 	{0,1,-1,},{0,2,4},{1,2,3},{1,3,2},{1,4,2},
	// 	{3,2,5},{3,1,1},{4,3,-3}
	// };

	// bellmanFord(v,5,0);

	// vector<vector<int>> v={
	// 	{ 0, 1, 1, 0, 0, 1 },
	// 	{ 1, 0, 1, 0, 1, 1 },
	// 	{ 1, 1, 0, 1, 0, 0 },
	// 	{ 0, 0, 1, 0, 1, 0 },
	// 	{ 0, 1, 0, 1, 0, 1 },
	// 	{ 1, 1, 0, 0, 1, 0 },
	// }; 

	// hamiltonianCycle(v);

	return 0;
}