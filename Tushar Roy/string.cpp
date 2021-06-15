#include <bits/stdc++.h> 

using namespace std;

int dp[1001][1001];

int wildcardPatternMatch(string &a,string &b,int m,int n){
	if(dp[m][n]!=-1) {
		return dp[m][n];
	} else if(m==0 && n==0) {
		dp[m][n] = 1;
	} else if(m==0 || n==0) {
		dp[m][n] = 0;
	} else if(b[n-1] =='?' || a[m-1]==b[n-1]) {
		dp[m][n] = wildcardPatternMatch(a,b,m-1,n-1);
	} else if(b[n-1]=='*') {
		dp[m-1][n] = wildcardPatternMatch(a,b,m-1,n);
		dp[m][n-1] = wildcardPatternMatch(a,b,m,n-1);
		dp[m][n] = dp[m][n-1] || dp[m-1][n];
	} else {
		dp[m][n] = 0;
	}
	return dp[m][n];
}

void robinKarpSubStringSearch(string &a,string &b){
	int m=a.size();
	int n=b.size();

	int prime = 9;
	int hash = 0;

	int res = 0;

	for(int i=0;i<n;i++){
		hash += (b[i]*pow(prime,i));
		res += (a[i]*pow(prime,i));
	}

	for(int i=n;i<m;i++){
		if(hash == res && b.compare(a.substr(i-n,n))) {
			cout<<i-n;
		} else {
			res -= a[i-n];
			res /= prime;
			res += a[i]*pow(prime,n-1);
		}
	}
	if(hash == res && b.compare(a.substr(m-n-1,n))) {
		cout<<m-n;
	}
}


void zAlgorithm(string &a,string &b){
	string s=b+'$'+a;
	cout<<s<<endl;
	for(int i=1,k=0;i<s.size();i++){
		if(s[k]==s[i]){
			k++;
		} else {
			i-=k;
			if(k+1==b.length()) {
				cout<<i-1<<s.substr(i,b.length());
			}
			k=0;
		}
	}
}



int main(int argc, char const *argv[]) {

	memset(dp,-1,sizeof(dp));

	// string a="avcxbny";
	// string b="a*xb?y";

	// cout<<wildcardPatternMatch(a,b,a.size(),b.size());

	string a = "abdabc";
	string b = "abc";

	// robinKarpSubStringSearch(a,b);

	zAlgorithm(a,b);

	// cout<<endl;

	// for(int i=0;i<8;i++){
	// 	for(int j=0;j<=8;j++){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	return 0;
}