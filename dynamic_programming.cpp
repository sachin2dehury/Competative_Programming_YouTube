#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];

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

	return 0;
}