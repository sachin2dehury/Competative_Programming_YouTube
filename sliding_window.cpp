#include <bits/stdc++.h>

using namespace std;

void maximumSubArraySumOfSizeK(vector<int> &v,int k){
	int i=0;
	int sum=0;
	int ans=INT_MIN;
	for(;i<k;i++){
		sum+=v[i];
	}
	ans = max(ans,sum);
	for(;i<v.size();i++){
		sum -= v[i-k];
		sum+=v[i];
		ans = max(ans,sum);
	}
	cout<<ans;
}

void firstNegativeNumber(vector<int> &v,int k){
	vector<int> temp;
	
	for(int i : v){
		if(i<0){
			temp.push_back(i);
		}
	}
	for(int i=k-1, j=0;i<v.size();i++){
		if(j<temp.size()){
			cout<<temp[j]<<" ";
		} else {
			cout<<"0 ";
		}
		if(v[i-k+1]==temp[j]){
			j++;
		}
	}
}

void countOfAnagrams(string &s,string &v){
	unordered_map<char,int> m;
	int n= v.length();
	bool c=0;
	int ans=0;
	for(int i=0;i<n;i++){
		m[s[i]]++;
		m[v[i]]--;
	}
	
	for(auto i: m){
		if(i.second){
			c=1;
		}
	}

	if(!c){
		ans++;
	} else {
		c=0;
	}
		

	for(int i=n;i<s.length();i++){
		m[s[i-n]]--;
		m[s[i]]++;

		for(auto i: m){
			if(i.second){
				c=1;
			}
		}

		if(!c){
			ans++;
		} else {
			c=0;
		}
	}

	cout<<ans<<endl;
}

void maximumOfSubArray(vector<int> &v,int k){
	vector<int> s;
	s.push_back(INT_MIN);
	for(int i=0;i<k;i++){
		if(v[i]>s[0]){
			s.clear();
		}
		s.push_back(v[i]);
	}
	cout<<s[0]<<" ";
	for(int i=k;i<v.size();i++){
		if(v[i]>s[0]){
			s.clear();
		}
		s.push_back(v[i]);
		cout<<s[0]<<" ";
	}
}

void largestSubArraySumK(vector<int> &v,int k){
	int s=0;
	int c=0;
	int ans=0;
	for(int i:v){
		if(k-s>=i){
			s+=i;
			c++;
		} else if(k<i) {
			s=0;
			c=0;
		} else {
			s=i;
			c=1;
		}
		if(s==k){
			ans=max(c,ans);
		}
	}
	cout<<ans;
}

void longestSubstringWithKUniqueChar(string &v,int k){
	unordered_map<char,int> s;
	int c=0;
	int ans =0;
	for(int i=0;i<v.size();i++){
		s[v[i]]++;
		if(s.size()>k){
			c-=s[v[i-c]];
			s.erase(v[i-c]);
		} else {
			c++;
			ans=max(ans,c);
		}
	}
	cout<<ans;
}

void longestSubstringWithoutRepeatChar(string &v){
	unordered_set<char> s;
	int ans=0;
	for(int i=0;i<v.size();i++){
		if(s.find(v[i])!=s.end()){
			int c=s.size();
			ans=max(ans,c);
			s.clear();
		}
		s.insert(v[i]);
	}
	cout<<ans;
}

int main(int argc, char const *argv[]) {
	
	// vector<int> v={2,5,1,8,2,9,1};

	// maximumSubArraySumOfSizeK(v,3);

	// vector<int> v ={12,-1,-7,8,-15,20,13,28};

	// firstNegativeNumber(v,3);

	// string s="aabaabaa";
	// string v="aaba";

	// countOfAnagrams(s,v);

	// vector<int> v={1,3,-1,-3,5,3,6,7};

	// maximumOfSubArray(v,3);

	// vector<int> v= {4,1,7,1,2,3,5};

	// largestSubArraySumK(v,6);

	// string v="aabacbebebe";

	// longestSubstringWithKUniqueChar(v,3);

	string v= "pwwkew";

	longestSubstringWithoutRepeatChar(v);

	return 0;
}