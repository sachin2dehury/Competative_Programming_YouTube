#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];

class node {
public:
	int value;
	node* left=nullptr;
	node* right=nullptr;
	node(int value){
		this->value=value;
	}
};

int knapsack(vector<int> &wt,vector<int> &val,int w,int n){
	if(dp[w][n]!=-1){
		return dp[w][n];
	} else if(n==0 || w==0){
		return 0;
	} else if(w<wt[n-1]) {
		dp[w][n]= knapsack(wt,val,w,n-1);
		return dp[w][n];
	} else {
		dp[w][n]=max(knapsack(wt,val,w,n-1),
			val[n-1]+knapsack(wt,val,w-wt[n-1],n-1));
		return dp[w][n];
	}
}

bool subSetSum(vector<int> &v,int s,int n){
	if(dp[s][n]!=-1){
		return dp[s][n];
	} else if (s==0) {
		return 1;
	} else if(n==0) {
		return 0;
	} else if(s<v[n-1]) {
		dp[s][n]=subSetSum(v,s,n-1);
		return dp[s][n];
	} else {
		dp[s][n]= subSetSum(v,s,n-1) || subSetSum(v,s-v[n-1],n-1);
		return dp[s][n];
	}
}

bool equalSumPartition(vector<int> &v) {
	int s=0;
	for(int i : v){
		s+=i;
	}
	if(s%2) {
		return 0;
	} else {
		return subSetSum(v,s/2,v.size());
	}
}

int countOfSubSetSum(vector<int> &v,int s,int n) {
	if(dp[s][n]!=-1) {
		return dp[s][n];
	} else if(s==0) {
		return 1;
	} else if(n==0) {
		return 0;
	} else if(s<v[n-1]) {
		dp[s][n]=countOfSubSetSum(v,s,n-1);
		return dp[s][n];
	} else {
		dp[s][n]=countOfSubSetSum(v,s,n-1)
			+ countOfSubSetSum(v,s-v[n-1],n-1);
		return dp[s][n];
	}
}

// int minimumSubSetDifference(vector<int> &v) {
// 	int s=0;
// 	for(int i: v){
// 		s+=i;
// 	}
// 	subSetSum(v,s/2,v.size());
// 	int maximum =0;
// 	for(int i=0;i<=s/2;i++){
// 		for(int j=0;j<=v.size();j++){
// 			cout<<dp[i][j]<<' ';
// 		}
// 		cout<<'\n';
// 	}
// 	return s-2*maximum;
// }

int countOfSubSetWithDifference(vector<int> &v,int d){
	int s=0;
	for(int i : v){
		s+=i;
	}
	return countOfSubSetSum(v,(s-d)/2,v.size());
}

int targetSum(vector<int> &v,int d) {
	//add + or - sign to int , hence reduced to above problem;
	return countOfSubSetWithDifference(v,d);
}

int rodCuttingProblem(vector<int> &v,int l,int n) {
	if(dp[l][n]!=-1) {
		return dp[l][n];
	} else if(l==0 || n==0) {
		return 0;
	} else if(l<n) {
		dp[l][n] = rodCuttingProblem(v,l,n-1);
		return dp[l][n];
	} else {
		dp[l][n] = max(rodCuttingProblem(v,l,n-1),
			v[n-1]+rodCuttingProblem(v,l-n,n));
		return dp[l][n];
	}
}

int countCoinChangeWays(vector<int> &v,int s,int n) {
	if(dp[s][n]!=-1) {
		return dp[s][n];
	} else if(s==0) {
		return 1;
	} else if(n==0) {
		return 0;
	} else if(s<v[n-1]) {
		dp[s][n] = countCoinChangeWays(v,s,n-1);
		return dp[s][n];
	} else {
		dp[s][n] = countCoinChangeWays(v,s,n-1) + 
		countCoinChangeWays(v,s-v[n-1],n);
		return dp[s][n];
	}
}

int minimumCoins(vector<int> &v,int s,int n) {
	if(dp[s][n]!=-1) {
		return dp[s][n];
	} else if(n==0) {
		return INT_MAX;
	} else if(s==0) {
		return 0;
	} else if(s<v[n-1]) {
		dp[s][n] = minimumCoins(v,s,n-1);
		return dp[s][n];
	} else {
		dp[s][n] = min(minimumCoins(v,s,n-1),
			1+minimumCoins(v,s-v[n-1],n));
		return dp[s][n];
	}
}

int longestCommomSubSequence(string &a,string &b,int m,int n) {
	if(dp[m][n]!=-1) {
		return dp[m][n];
	} else if(m==0 || n==0) {
		return 0;
	} else if(a[m-1]==b[n-1]) {
		dp[m][n]= longestCommomSubSequence(a,b,m-1,n-1)+1;
		return dp[m][n];
	} else {
		dp[m][n]= max(longestCommomSubSequence(a,b,m-1,n),
			longestCommomSubSequence(a,b,m,n-1));
		return dp[m][n];
	}
}

// int longestCommomSubString(string &a,string &b,int m,int n,int c=0) {
// 	if(dp[m][n]!=-1) {
// 		return dp[m][n];
// 	} else if(m==0 || n==0) {
// 		return c;
// 	} else if(a[m-1]==b[n-1]) {
// 		dp[m][n] = longestCommomSubString(a,b,m-1,n-1,c+1)+1;
// 		return dp[m][n];
// 	} else {
// 		dp[m][n]=max(c,max(longestCommomSubString(a,b,m-1,n),
// 			longestCommomSubString(a,b,m,n-1)));
// 		return dp[m][n];
// 	}
// }

string printLCS(string &a,string &b,int m,int n) {
	longestCommomSubSequence(a,b,m,n);
	string v="";
	while(m>0 && n>0){
		if(a[m-1]==b[n-1]) {
			v+=a[m-1];
			m--,n--;
		} else if(dp[m][n-1] > dp[m-1][n]) {
			n--;
		} else {
			m--;
		}
	}
	return v;
}

int shortestCommonSuperSequence(string &a,string &b){
	int m=a.size();
	int n = b.size();
	int lcs= longestCommomSubSequence(a,b,m,n);
	return m+n-lcs;
}

void minimumInsertAndDelete(string &a,string &b) {
	//make a->b
	int m=a.size();
	int n = b.size();
	int lcs= longestCommomSubSequence(a,b,m,n);
	cout<<m-lcs<<"Delete\n";
	cout<<n-lcs<<"Insert\n";
}

int longestPallendromicSubSequence(string &a,int m,int n=0) {
	if(dp[m][n]!=-1){
		return dp[m][n];
	} else if(m==0 || n==a.size()) {
		return 0;
	} else if(a[m-1]==a[n]) {
		dp[m][n]=1+longestPallendromicSubSequence(a,m-1,n+1);
		return dp[m][n];
	} else {
		dp[m][n] = max(longestPallendromicSubSequence(a,m-1,n),
			longestPallendromicSubSequence(a,m,n+1));
		return dp[m][n];
	}
}

int minimumDeletionForPallendrome(string &a){
	int m=a.size();
	int lps=longestPallendromicSubSequence(a,m);
	return m-lps;
}

void printSCS(string &a,string &b,int m,int n) {
	shortestCommonSuperSequence(a,b);
	string v="";
	while(m>0 && n>0){
		if(a[m-1]==b[n-1]){
			v+=a[m-1];
			m--,n--;
		} else if(dp[m][n-1]>dp[m-1][n]) {
			v+=b[n-1];
			n--;
		} else {
			v+=a[m-1];
			m--;
		}
	}
	while(n>0){
		v+=b[n-1];
		n--;
	}
	while(m>0){
		v+=a[m-1];
		m--;
	}
	reverse(v.begin(),v.end());
	cout<<v;
}

int longestRepeatingSubSequence(string &s,int m,int n){
	if(dp[m][n]!=-1) {
		return dp[m][n];
	} else if(m==0 || n==0) {
		return 0;
	} else if(s[m-1]==s[n-1] && m!=n) {
		dp[m][n]=longestRepeatingSubSequence(s,m-1,n-1)+1;
		return dp[m][n];
	} else {
		dp[m][n]=max(longestRepeatingSubSequence(s,m-1,n),
			longestRepeatingSubSequence(s,m,n-1));
		return dp[m][n];
	}
}

int sequencePatternMatching(string &a,string &b,int m,int n) {
	int lcs= longestCommomSubSequence(a,b,m,n);
	if(lcs==n) {
		return 1;
	} else {
		return 0;
	}
}

int minimumInsertionForPallendrome(string &s) {
	int lps=longestPallendromicSubSequence(s,s.size());
	return s.size()-lps;
}

int matrixChainMultiplication(vector<int> &v,int i,int j){
	if(dp[i][j]!=-1){
		return dp[i][j];
	} else if(i>=j) {
		return 0;
	} else {
		dp[i][j] =INT_MAX;
		for(int k=i;k<j;k++){
			dp[i][k]=matrixChainMultiplication(v,i,k);
			dp[k+1][j]=matrixChainMultiplication(v,k+1,j);
			int temp= dp[i][k]+ dp[k+1][j] +v[i]*v[k]*v[j-1];
			dp[i][j]= min(dp[i][j],temp);
		}
	}
	return dp[i][j];
}

bool isPallendrome(string &s,int i,int j){
	while(i<=j){
		if(s[i]!=s[j]){
			return 0;
		}
		i++,j--;
	}
	return 1;
}

int pallendromePartition(string &v,int i,int j){
	if(dp[i][j]!=-1){
		return dp[i][j];
	} else if(i>=j){
		return 0;
	} else if(isPallendrome(v,i,j)){
		dp[i][j]=0;
		return dp[i][j];
	} else{
		dp[i][j]=INT_MAX;
		for(int k=i;k<j;k++){
			dp[i][k]= pallendromePartition(v,i,k);
			dp[k+1][j]= pallendromePartition(v,k+1,j);
			int temp= dp[i][k]+dp[k+1][j] +1;
			dp[i][j]=min(dp[i][j],temp);
		}
	}
	return dp[i][j];
}

int eggDroping(int e,int f){
	if(dp[e][f]!=-1){
		return dp[e][f];
	} else if(e==0) {
		dp[e][f]=0;
	} else if(e==1) {
		dp[e][f]=f;
	} else if(f<=1) {
		dp[e][f]=f;
	} else {
		dp[e][f] = INT_MAX;
		for(int k=0;k<f;k++){
			dp[e-1][k]=eggDroping(e-1,k);
			dp[e][f-k-1]=eggDroping(e,f-k-1);
			int temp = 1+max(dp[e-1][k],dp[e][f-k-1]);
			dp[e][f]= min(dp[e][f],temp);
		}
	}
	return dp[e][f];
}

// int scrambleString(string &a,string &b,int i,int j){
// 	if(a==b){
// 		return 1;
// 	} else if(i>=j) {
// 		return 0;
// 	} else if()
// }

int diameterOfTree(node* root,int &res) {
	if(root==nullptr) {
		return 0;
	}
	int l = diameterOfTree(root->left,res);
	int r = diameterOfTree(root->right,res);

	int temp = 1+max(l,r);
	int ans = max(1+l+r,temp);
	res = max(res,ans);

	return temp;
}

int maximumPathSum(node* root,int &res){
	if(root==nullptr){
		return 0;
	}
	int l= maximumPathSum(root->left,res);
	int r= maximumPathSum(root->right,res);

	int temp = max(root->value,l+r+root->value);
	int ans = max(temp,l+r+root->value);
	res = max(ans,res);

	return temp;
}

int maximumPathSumFromLeaf(node* root,int &res) {
	if(root==nullptr){
		return 0;
	}
	int l = maximumPathSumFromLeaf(root->left,res);
	int r = maximumPathSumFromLeaf(root->right,res);

	int temp = max(l,r)+root->value;
	int ans = max(temp,l+r+root->value);
	res =max(res,ans);

	return temp;
}

int main(int argc, char const *argv[]) {
	
	memset(dp,-1,sizeof(dp));
	
	// vector<int> wt={1,3,4,5};
	// vector<int> val={1,4,5,7};
	// int w=7;

	// memset(dp,-1,sizeof(dp));

	// cout<<knapsack(wt,val,w,val.size());

	// vector<int> v ={2,3,7,8,10};
	// int s =11;

	// memset(dp,-1,sizeof(dp));

	// cout<<subSetSum(v,s,v.size());

	// vector<int> v={1,5,11,5};

	// memset(dp,-1,sizeof(dp));

	// cout<<equalSumPartition(v);

	// vector<int> v ={2,3,5,6,8,10};
	// int s=10;

	// memset(dp,-1,sizeof(dp));

	// cout<<countOfSubSetSum(v,s,v.size());

	// vector<int> v={1,6,11,5};

	// vector<int> v={1,1,2,3};

	// cout<<countOfSubSetWithDifference(v,1);

	// vector<int> v={1,1,2,3};

	// cout<<targetSum(v,1);

	// vector<int> v={1,5,8,9,10,17,17,20};
	// int l=8;

	// cout<<rodCuttingProblem(v,l,v.size());

	// vector<int> v={1,2,3};
	// int s=5;

	// cout<<countCoinChangeWays(v,5,v.size());

	// vector<int> v={1,2,3};
	// int s=5;

	// cout<<minimumCoins(v,5,v.size());

	// string a="abcdgh";
	// string b= "abedfhr";

	// cout<<longestCommomSubSequence(a,b,a.size(),b.size());

	// cout<<printLCS(a,b,a.size(),b.size());

	// string a="geek";
	// string b="eke";

	// cout<<shortestCommonSuperSequence(a,b);

	// minimumInsertAndDelete(a,b);

	// string v="agbcba";

	// cout<<longestPallendromicSubSequence(v,v.size());

	// cout<<minimumDeletionForPallendrome(v);

	// string a= "acbcf";
	// string b="abcdaf";

	// printSCS(a,b,a.size(),b.size());

	// string a= "aabebcdd";
	// cout<<longestRepeatingSubSequence(a,a.size(),a.size());

	// string a="adxcpy";
	// string b="axy";

	// cout<<sequencePatternMatching(a,b,a.size(),b.size());

	// string s= "acbcbda";
	// cout<<minimumInsertionForPallendrome(s);

	// vector<int> v={40,20,30,10,30};

	// cout<<matrixChainMultiplication(v,0,v.size()-1);

	// string s="nitik";

	// cout<<pallendromePartition(s,0,s.size()-1);

	// cout<<eggDroping(3,5);

	// string a= "great";
	// string b="rgeat";

	// int res = INT_MIN;
	// diameterOfTree(null,res);

	return 0;
}