#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];

void longestIncreasingSubSequence(vector<int> &v) {
	vector<int> ans(v.size());
	stack<int> s;
	int res=INT_MIN;
	for(int i=0;i<v.size();i++) {
		if(s.size()==0){
			ans[i]=i;
		} else if(v[s.top()]<v[i]) {
			ans[i]=s.top();
		} else {
			while(s.size()>0 && v[s.top()]>v[i]){
				s.pop();
			}
			if(s.size()==0){
				ans[i]=i;
			} else {
				ans[i]=s.top();
			}
		}
		s.push(i);
	}
	for(int i=0;i<v.size();i++){
		if(ans[i]==i){
			ans[i]=1;
		} else {
			ans[i]= ans[ans[i]]+1;
		}
		res=max(res,ans[i]);
	}
	cout<<res;
}

// void optimalBinarySearchTree(vector<int> &v,vector<int> &f){
// 	priority_queue<pair<int,int>> q;
// 	for(int i=0;i<v.size();i++){
// 		q.push({f[i],i});
// 	}
// }

void maximumSumRectangle(vector<vector<int>> &v) {
	vector<int> ans(v[0].size(),0);
	int res =INT_MIN;
	for(int i=0;i<v.size();i++) {
		for(int j=0,s=0;j<v[0].size();j++) {
			ans[j]+=v[i][j];
		}
	}
	for(int j=0,s=0;j<v[0].size();j++) {
		if(ans[j]>=0){
			s+=ans[j];
		} else {
			s=0;
		}
		res=max(res,s);
	}
	for(int i=0;i<v.size();i++) {
		for(int j=0,s=0;j<v[0].size();j++) {
			ans[j]-=v[i][j];
			if(ans[j]>=0){
				s+=ans[j];
			} else {
				s=0;
			}
			res=max(res,s);
			// cout<<res<<endl;
		}
	}
	cout<<res;
}

void weightedJobSheduling(vector<pair<pair<int,int>,int>> j) {
	vector<int> ans(j.size());
	int v=0;
	for(int i =0;i<j.size();i++) {
		if(i==0) {
			ans[i]=j[i].second;
		} else {
			int res=0;
			for(int k=0;k<i;k++){
				if(j[k].first.second <= j[i].first.first) {
					res=max(res,ans[k]);
				}
			}
			ans[i]=j[i].second+res;
		}
		v=max(v,ans[i]);
	}
	cout<<v;
}

int maximumAreaHistogram(vector<int> &v){
	stack<int> s;
	vector<int> ans(v.size());
	int res=0;
	for(int i=v.size()-1;i>=0;i--){
		if(s.size()==0){
			ans[i]=v.size();
		} else if(v[s.top()]<v[i]) {
			ans[i]=s.top();
		} else {
			while(s.size()>0 && v[s.top()]>=v[i]){
				s.pop();
			}
			if(s.size()==0){
				ans[i]=v.size();
			} else {
				ans[i]=s.top();
			}
		}
		s.push(i);
	}
	while(s.size()>0){
		s.pop();
	}
	for(int i=0;i<v.size();i++){
		if(s.size()==0){
			ans[i]+=1;
		} else if(v[s.top()]<v[i]) {
			ans[i]-=s.top();
		} else {
			while(s.size()>0 && v[s.top()]>=v[i]){
				s.pop();
			}
			if(s.size()==0){
				ans[i]+=1;
			} else {
				ans[i]-=s.top();
			}
		}
		res =max(res, (ans[i]-1)*v[i]);
		s.push(i);
	}
	return res;
}

void maximumAreaRectangle(vector<vector<int>> &v){
	vector<vector<int>> ans=v;
	int res= maximumAreaHistogram(ans[0]);
	for(int i=1;i<v.size();i++){
		for(int j=0;j<v[0].size();j++){
			if(ans[i][j]){
				ans[i][j]=ans[i-1][j]+1;
			} else {
				ans[i][j] =0;
			}
		}
		res=max(res,maximumAreaHistogram(ans[i]));
	}
	cout<<res;
}


int wordBreakProblem(string &a,unordered_set<string> &s,int i,int j) {
	if(dp[i][j]!=-1){
		return dp[i][j];
	} else if(i>=j){
		dp[i][j]= 0;
	} else if(s.find(a.substr(i,j-i))!=s.end()){
		dp[i][j]= 1;
	} else {
		dp[i][j]=0;
		for(int k=i;k<j;k++){
			dp[i][k]= wordBreakProblem(a,s,i,k);
			dp[k+1][j]= wordBreakProblem(a,s,k+1,j);
			dp[i][j] = dp[i][j] || (dp[i][k] && dp[k+1][j]);
		}
	}
	return dp[i][j];
}

void buySellStockMultiple(vector<int> &v,int k){
	stack<int> s;
	vector<int> ans(v.size());
	priority_queue<int> q;
	int res=0;
	int temp=0;
	for(int i=0;i<v.size();i++){
		if(s.size()==0){
			ans[i]=0;
		} else if(v[s.top()]<v[i]){
			ans[i]=ans[s.top()]+(v[i]-v[s.top()]);
		} else {
			while(s.size()>0 && v[s.top()]>=v[i]) {
				s.pop();
			}
			if(s.size()==0){
				ans[i]=0;
			} else {
				ans[i]=ans[s.top()]+(v[i]-v[s.top()]);
			}
		}
		s.push(i);
	}
	for(int i=0;i<ans.size();i++){
		temp=max(ans[i],temp);
		if(ans[i]==0){
			q.push(temp);
			temp=0;
		}
	}
	q.push(temp);
	while(k && q.size()) {
		res+=q.top();
		q.pop();
		k--;
	}
	cout<<res;
}

void minimumJumpsToEnd(vector<int> &v) {
	vector<int> ans(v.size());
	ans[0]=0;
	for(int i=1;i<v.size();){
		if(v[i]==0){
			i--;
		} else {
			for(int j=0;j<v[i];j++){
				ans[i+j+1]=ans[i]+1;
			}
			i+=v[i];
		}
	}
	cout<<ans[v.size()-1];
}

int minimumCostPath(vector<vector<int>> &v,int i,int j) {
	if(i<1 || j<1){
		return INT_MAX;
	} else if(i==1 && j==1) {
		return v[i-1][j-1];
	} else {
		return min(minimumCostPath(v,i-1,j),minimumCostPath(v,i,j-1))
			+v[i-1][j-1];
	}
}

// void textJustificationProblem(){

// }

// void optimalGamePattern() {

// }

void maximumSubSquareMatrix() {
	
}

int main(int argc, char const *argv[]) {

	// vector<int> v={3,4,-1,0,6,2,3};

	// longestIncreasingSubSequence(v);

	// vector<int> v = {10,12,16,21};
	// vector<int> f = {4,2,6,3};

	// optimalBinarySearchTree(v,f);

	// vector<vector<int>> v= {
	// 	{2,1,-3,-4,5},
	// 	{0,6,3,4,1},
	// 	{2,-2,-1,4,-5},
	// 	{-3,3,1,0,3},
	// };

	// maximumSumRectangle(v);

	// vector<pair<pair<int,int>,int>> j = {
	// 	{{1,3},5},
	// 	{{2,5},6},
	// 	{{4,6},5},
	// 	{{6,7},4},
	// 	{{5,8},11},
	// 	{{7,9},2},
	// };

	// weightedJobSheduling(j);

	// vector<int> v={0,1,2,3,1,3};

	// cout<<maximumAreaHistogram(v);

	// vector<vector<int>> v = {
	// 	{1,0,0,1,1,1},
	// 	{1,0,1,1,0,1},
	// 	{0,1,1,1,1,1},
	// 	{0,0,1,1,1,1},
	// };

	// maximumAreaRectangle(v);

	// memset(dp,-1,sizeof(dp));

	// unordered_set<string> s={"a","i","am","ace"};
	// string a="iamac";

	// cout<<wordBreakProblem(a,s,1,a.size());

	// vector<int> stock={100, 30, 15, 10, 8, 25, 80};
	// buySellStockMultiple(stock,3);

	// vector<int> v={2,3,1,1,2,4,2,0,1,1};

	// minimumJumpsToEnd(v);

	// vector<vector<int>> v= {
	// 	{1,3,5,8},
	// 	{4,2,1,7},
	// 	{4,3,2,3}
	// };

	// cout<<minimumCostPath(v,v.size(),v[0].size());

	return 0;
}