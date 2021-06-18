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


int optimalBinarySearchTree(vector<int> &f,int i,int j,int h=1){
	if(i>=j){
		return 0;
	} else {
		int ans=INT_MAX;
		for(int k=i;k<j;k++){
			int temp = optimalBinarySearchTree(f,i,k,h+1)+
				optimalBinarySearchTree(f,k+1,j,h+1)+ h*f[k];
			ans=min(ans,temp);
		}
		return ans;
	}
}

void maximumSubSquareMatrix(vector<vector<int>> &v) {
	vector<vector<int>> ans = v;
	int res=0;
	for(int i=1;i<v.size();i++){
		for(int j=1;j<v[0].size();j++){
			ans[i][j]+=min(ans[i-1][j-1],
				min(ans[i-1][j],ans[i][j-1]));
			res = max(ans[i][j],res);
		}
	}
	cout<<res;
}

int stairCase(int n) {
	if(n<2){
		return 1;
	} else {
		return stairCase(n-1)+stairCase(n-2);
	}
}
 
void maximumSumIncreasingSubSequece(vector<int> &v) {
	stack<int> s;
	vector<int> ans(v.size());
	vector<int> res(v.size(),1);
	int c=0;
	int k=0;
	for(int i=v.size()-1;i>=0;i--){
		if(s.size()==0){
			ans[i]=v[i];
		} else if(v[s.top()]>v[i]){
			ans[i]=v[i]+ans[s.top()];
			res[i]=res[s.top()]+1;
		} else {
			while(s.size()>0 && v[s.top()]<v[i]){
				s.pop();
			}
			if(s.size()==0){
				ans[i]=v[i];
			} else {
				ans[i]=v[i]+ans[s.top()];
				res[i]=res[s.top()]+1;
			}
		}
		s.push(i);
		if(c<ans[i]){
			c=ans[i];
			k=res[i];
		}
	}
	cout<<c<<' '<<k;
}

int interleavingString(string &a,string &b,string &c,int i,int j,int k) {
	if(i==0 && j==0 && k==0) {
		return 1;
	} else if(c[k-1]==a[i-1] && c[k-1]==b[j-1]) {
		return interleavingString(a,b,c,i-1,j,k-1) || 
			interleavingString(a,b,c,i,j-1,k-1);
	} else if(c[k-1]==a[i-1]){
		return interleavingString(a,b,c,i-1,j,k-1);
	} else if(c[k-1]==b[j-1]){
		return interleavingString(a,b,c,i,j-1,k-1);
	} else {
		return 0;
	}
}

int numberOfBST(int n) {
	if(n<=1){
		return 1;
	} else {
		int ans=0;
		for(int k=0;k<n;k++){
			ans+=numberOfBST(k)*numberOfBST(n-k-1);
		}
		return ans;
	}
}

int totalWayInMatrix(int i,int j) {
	if(i==1 || j==1){
		return 1;
	} else {
		return totalWayInMatrix(i-1,j)+totalWayInMatrix(i,j-1);
	}
}

void longestBitonicSubSequence(vector<int> &v) {
	vector<int> inc(v.size(),1);
	vector<int> dec(v.size(),1);
	int ans=0;
	for(int i=1;i<v.size();i++){
		int res=0;
		for(int j=0;j<i;j++){
			if(v[j]<v[i]){
				res=max(res,inc[j]);
			}
		}
		inc[i]+=res;
	}
	for(int i=v.size()-2;i>=0;i--){
		int res=0;
		for(int j=i+1;j<v.size();j++){
			if(v[j]<v[i]){
				res=max(res,dec[j]);
			}
		}
		dec[i]+=res;
	}
	for(int i=0;i<v.size();i++){
		inc[i]+=(dec[i]-1);
		ans=max(inc[i],ans);
	}
	cout<<ans;
}

void subRectangleSum(vector<vector<int>> &v,int x,int y,int a,int b) {
	vector<vector<int>> ans(v.size()+1,vector<int>(v[0].size()+1));
	for(int i=0;i<=v.size();i++){
		for(int j=0;j<=v[0].size();j++){
			if(i==0 || j==0){
				ans[i][j]=0;
			} else {
				ans[i][j]=ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1]+v[i-1][j-1];
			}
			cout<<ans[i][j]<<' ';
		}
		cout<<endl;
	}
	cout<<ans[a][b]+ans[x][y]-ans[x][b]-ans[a][y];
}

int numberWithOutConsecutiveOnes(int n) {
	if(n==1){
		return 2;
	} else if(n==2) {
		return 3;
	} else {
		return numberWithOutConsecutiveOnes(n-1)+
			numberWithOutConsecutiveOnes(n-2);
	}
}

vector<pair<pair<int,int>,int>> boxGenerator(vector<pair<pair<int,int>,int>> &a){
	vector<pair<pair<int,int>,int>> v;
	for(auto b: a){
		if(b.first.first>b.first.second){
			v.push_back(b);
		}
		if(b.first.first<b.first.second){
			v.push_back({{b.first.second,b.first.first},b.second});
		}
		if(b.first.first > b.second) {
			v.push_back({{b.first.first,b.second},b.first.second});
		}
		if(b.first.first < b.second) {
			v.push_back({{b.second,b.first.first},b.first.second});
		}
		if(b.first.second > b.second) {
			v.push_back({{b.first.second,b.second},b.first.first});
		}
		if(b.first.second < b.second) {
			v.push_back({{b.second,b.first.second},b.first.first});
		}
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	return v;
}

void boxStacking(vector<pair<pair<int,int>,int>> &v){
	vector<pair<pair<int,int>,int>> b=boxGenerator(v);
	vector<int> a(b.size());
	a[0]=b[0].second;
	int ans =0;
	for(int i=1;i<a.size();i++){
		if(b[i].first.first<b[i-1].first.first 
			&& b[i].first.second<b[i-1].first.second){
			a[i]=a[i-1]+b[i].second;
		} else {
			a[i]=b[i].second;
			for(int j=i-2;j>=0;j--) {
				if(b[i].first.first<b[j].first.first 
			&& b[i].first.second<b[j].first.second) {
					a[i]=max(a[i],b[i].second+b[j].second);
				}
			}
		}
		ans =max(ans,a[i]);
	}
	cout<<ans;
}

// void ballonBurst() {

// }

// void maximumSubSquareMatrixWithX() {

// }

// int textJustificationProblem(vector<int> &v,int w,int i,int op=0){
// 	if(i==0){
// 		return op;
// 	} else {
// 		int op1=op+pow(w-v[i-1],2);
// 		if()
// 		if()
// 	}
// }

// void optimalGamePattern() {

// }


int maximumSumNonAdjacent(vector<int> &v,int i,int op=0,int f=0) {
	if(i==0){
		return op;
	} else if(f==0){
		return max(maximumSumNonAdjacent(v,i-1,op+v[i-1],1),
			maximumSumNonAdjacent(v,i-1,op,0));
	} else {
		return maximumSumNonAdjacent(v,i-1,op,0);
	}
}


int main(int argc, char const *argv[]) {

	// vector<int> v={3,4,-1,0,6,2,3};

	// longestIncreasingSubSequence(v);

	// vector<int> v = {10,12,16,21};
	// vector<int> f = {4,2,6,3};

	// cout<<optimalBinarySearchTree(f,0,f.size());

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

	// vector<vector<int>> v= {
	// 	{0,0,1,1,1},
	// 	{1,0,1,1,1},
	// 	{0,1,1,1,1},
	// 	{1,0,1,1,1},
	// };

	// maximumSubSquareMatrix(v);

	// cout<<stairCase(5);

	// vector<int> v={4,6,1,3,8,4,6};

	// maximumSumIncreasingSubSequece(v);

	// string a="aab";
	// string b="axy";
	// string c="aaxaby";

	// cout<<interleavingString(a,b,c,a.size(),b.size(),c.size());

	// cout<<numberOfBST(5);

	// cout<<totalWayInMatrix(4,5);

	// vector<vector<int>> v= {
	// 	{2,0,-3,4},
	// 	{6,3,2,-1},
	// 	{5,4,7,3},
	// 	{2,-6,8,1}
	// };

	// subRectangleSum(v,1,2,3,3);

	// cout<<numberWithOutConsecutiveOnes(5);

	// vector<int> v={2,-1,4,3,5,-1,3,2};

	// longestBitonicSubSequence(v);

	// vector<int> v = {4,1,1,4,2,1};

	// cout<<maximumSumNonAdjacent(v,v.size());

	vector<pair<pair<int,int>,int>> v={
		{{1,2},4},
		{{3,2},5}
	};

	boxStacking(v);

	return 0;
}