#include <bits/stdc++.h>

using namespace std;

int numberOfReaders(vector<int> &v,int k,int m) ;

void binarySearch(vector<int> &v, int k) {
	int l=0;
	int h=v.size()-1;
	while(l<=h) {
		int m= l+(h-l)/2;
		if(k==v[m]) {
			cout<<m<<endl;
			return;
		}
		else if(v[m]<k) {
			l=m+1;
		}
		else {
			h=m-1;
		}
	}
	cout<<"Not Found !";
}

void reverseBinarySearch(vector<int> &v,int k) {
	int l=0;
	int h=v.size()-1;
	while(l<=h) {
		int m = l+ (h-l)/2;
		if(v[m]==k){
			cout<<m<<endl;
			return;
		}
		else if(k>v[m]) {
			h=m-1;
		}
		else {
			l=m+1;
		}
	}
	cout<<"Not Found !";
}

void unknownOrderSearch(vector<int> &v, int k) {
	if(v[0]>v[1]) {
		reverseBinarySearch(v,k);
	}
	else {
		binarySearch(v,k);
	}
}

int firstOccurance(vector<int> &v,int k) {
	int l=0;
	int h=v.size()-1;
	int ans = -1;
	while(l<=h) {
		int m= l+(h-l)/2;
		if(v[m]==k){
			ans=m;
			h=m-1;
		}
		else if(k>v[m]) {
			l=m+1;
		}
		else {
			h=m-1;
		}
	}
	cout<<ans<<endl;
	return ans;
}

int lastOccurance(vector<int> &v,int k) {
	int l=0;
	int h= v.size()-1;
	int ans=-1;
	while(l<=h){
		int m= l+ (h-l)/2;
		if(v[m]==k){
			ans=m;
			l=m+1;
		}
		else if(k<v[m]) {
			h=m-1;
		}
		else {
			l=m+1;
		}
	}
	cout<<ans<<endl;
	return ans;
}

void countOfElement(vector<int> &v,int k) {
	int l= firstOccurance(v,k);
	int h= lastOccurance(v,k);
	if(l>-1){
		cout<<h-l+1;
	}
	else {
		cout<<-1;
	}
}

int numberOfRotation(vector<int> &v) {
	int l=0;
	int h=v.size()-1;
	while(l<=h){
		int m=l+(h-l)/2;
		int n=(m+1)%v.size();
		int p=(m+v.size()-1)%v.size();
		if(v[m]<v[n] && v[m]<v[p]){
			cout<<m<<endl;
			return m;
		}
		else if(v[m]>v[p] && v[m]>v[n]) {
			l=m+1;
		}
		else {
			h=m-1;
		}
	}
	return -1;
}

void findInRotated(vector<int> &v,int k){
	int r = numberOfRotation(v);
	int l=r;
	int h=v.size()-1;
	while(l<=h) {
		int m=l+(h-l)/2;
		if(v[m]==k) {
			cout<<m<<endl;
			return;
		}
		else if(k<v[m]) {
			h=m-1;
		}
		else {
			l=m+1;
		}
	}
	l=0;
	h=r-1;
	while(l<=h) {
		int m=l+(h-l)/2;
		if(v[m]==k) {
			cout<<m<<endl;
			return;
		}
		else if(k<v[m]) {
			h=m-1;
		}
		else {
			l=m+1;
		}
	}
}

void nearlySortedSearch(vector<int> &v,int k) {
	int l=0;
	int h=v.size()-1;
	while(l<=h) {
		int m= l+(h-l)/2;
		if(v[m]==k){
			cout<<m<<endl;
			return;
		}
		else if(m<v.size()-1 && v[m+1]==k){
			cout<<m+1<<endl;
			return;
		}
		else if(m>0 && v[m-1]==k) {
			cout<<m<<endl;
			return;
		}
		else if(k<v[m]){
			h=m-2;
		}
		else {
			l=m+2;
		}
	}
}

int floorOfElement(vector<int> &v,int k){
	int l=0;
	int h = v.size()-1;
	int ans = -1;
	while(l<=h) {
		int m= l+(h-l)/2;
		if(v[m]==k) {
			cout<<k<<endl;
			return k;
		}
		else if(k>v[m]){
			ans=v[m];
			l=m+1;
		}
		else {
			h=m-1;
		}
	}
	cout<<ans<<endl;
	return ans;
}

int ceilOfElement(vector<int> &v,int k) {
	int l=0;
	int h=v.size()-1;
	int ans =-1;
	while(l<=h) {
		int m = l+(h-l)/2;
		if(v[m]==k){
			cout<<k<<endl;
			return k;
		}
		else if(k<v[m]){
			ans=v[m];
			h=m-1;
		}
		else {
			l=m+1;
		}
	}
	cout<<ans<<endl;
	return ans;
}

void nextAlphabet(string &v,char c) {
	int l=0;
	int h=v.size()-1;
	char ans=' ';
	while(l<=h){
		int m = l+ (h-l)/2;
		if(c<v[m]) {
			ans=v[m];
			h=m-1;
		}
		else {
			l=m+1;
		}
	}
	cout<<ans<<endl;
}

void infiniteArray(vector<int> &v,int k){
	int l=0;
	int h=1;
	while(k>v[h]){
		l=h;
		h=2*h;
	}
	while(l<=h){
		int m=l+(h-l)/2;
		if(v[m]==k){
			cout<<m<<endl;
			return ;
		}
		else if(k<v[m]) {
			h=m-1;
		}
		else {
			l=m+1;
		}
	}
}

void indexOfOne(vector<int> &v) {
	int l=0;
	int h=1;
	int ans = -1;
	while(!v[h]) {
		l=h;
		h=2*h;
	}
	while(l<=h) {
		int m = l+(h-l)/2;
		if(v[m]){
			ans = m;
			h=m-1;
		}
		else {
			l=m+1;
		}
	}
	cout<<ans<<endl;
}

void minimumDifference(vector<int> &v,int k) {
	int l=floorOfElement(v,k);
	int h = ceilOfElement(v,k);
	if(l!=-1){
		cout<<min(k-l,h-k);
	}
}

void peakElement(vector<int> &v){
	int l=0;
	int h=v.size()-1;
	while(l<=h){
		int m= l+(h-l)/2;
		int n= (m+1)%v.size();
		int p = (m+v.size()-1)%v.size();
		if(v[m]> v[p] && v[m]>v[n]){
			cout<<v[m]<<endl;
			return;
		}
		else if(v[m]<v[n] && v[m]>v[p]) {
			l=m+1;
		}
		else {
			h=m-1;
		}
	}
}

int maximumInBitonic(vector<int> &v) {
	int l=0;
	int h=v.size()-1;
	while(l<=h){
		int m= l+ (h-l)/2;
		int n=(m+1)%v.size();
		int p = (m+v.size()-1)%v.size();
		if(v[m]>v[p] && v[m]>v[n]) {
			cout<<v[m]<<endl;
			return m;
		}
		else if(v[m]<v[n] && v[m]>v[p]){
			l=m+1;
		}
		else {
			h=m-1;
		}
	}
	return -1;
}

void searchInBitonic(vector<int> &v,int k) {
	int n=maximumInBitonic(v);
	int l=0;
	int h=n-1;
	while(l<=h){
		int m= l+(h-l)/2;
		if(v[m]==k){
			cout<<m;
			return;
		}
		else if(k>v[m]){
			l=m+1;
		}
		else {
			h=m-1;
		}
	}

	l=n;
	h=v.size()-1;

	while(l<=h){
		int m= l+(h-l)/2;
		if(v[m]==k){
			cout<<m;
			return;
		}
		else if(k>v[m]){
			h=m-1;
		}
		else {
			l=m+1;
		}
	}
}

void searchInMatrix(vector<vector<int>> &v,int k) {
	int r=0;
	int c=v.size();
	int n=c;
	while(r<=n && 0<=c){
		if(k==v[r][c]){
			cout<<r<<","<<c<<endl;
			return;
		}
		else if(k>v[r][c]){
			r++;
		}
		else {
			c--;
		}
	}
}

void allocateMinimumPages(vector<int> &v,int k){
	if(k>v.size() || k==0) {
		return;
	}
	int l=0;
	int h=0;
	// int minimum= INT_MAX;
	// int maximum = INT_MIN;
	for(int i: v){
		h+=i;
		// minimum=min(i,minimum);
		// maximum=max(i,maximum);
	}
	while(1){
		int m=l+(h-l)/2;
		int r=numberOfReaders(v,k,m);
		if(r==k){
			// cout<<m<<endl;
			int sum=0;
			for(int i : v){
				sum+=i;
				if(sum>m) {
					sum-=i;
					cout<<sum<<endl;
					sum=i;
				}
			}
			cout<<sum<<endl;
			break;
		}
		else if (r>k) {
			l=m+1;
		}
		else {
			h=m-1;
		}
	}
}

int numberOfReaders(vector<int> &v,int k,int m) {
	int sum=0;
	int r=1;
	for(int i : v){
		sum+=i;
		if(sum>m) {
			sum-=i;
			r++;
			sum=i;
		}
	}
	return r;
}

int main(int argc, char const *argv[]) {
	
	// vector<int> v = {1,3,5,5,5,5,6};

	// binarySearch(v,6);

	// reverse(v.begin(),v.end());

	// reverseBinarySearch(v,1);

	// unknownOrderSearch(v,2);

	// firstOccurance(v,1);

	// lastOccurance(v,1);

	// countOfElement(v,5);

	// vector<int> v= {11,12,15,18,20,2,5,6,8};

	// numberOfRotation(v);

	// findInRotated(v,6);

	// vector<int> v ={5,10,30,20,40};

	// nearlySortedSearch(v,5);

	// vector<int> v= {1,2,3,4,8,10,10,12,19};

	// ceilOfElement(v,1);

	// floorOfElement(v,1);

	// string v = "acfh";

	// nextAlphabet(v,'h');

	// infiniteArray(v,1);

	// vector<int> v = {0,0,0,0,0,0,0,0,1,1,1,1};

	// indexOfOne(v);

	// minimumDifference(v,7);

	// vector<int> v= {5,10,20,15};

	// peakElement(v);

	// vector<int> v={1,3,8,12,4,2};

	// maximumInBitonic(v);

	// searchInBitonic(v,2);

	// vector<vector<int>> v= {
	// 	{10,20,30,40},
	// 	{15,25,35,45},
	// 	{27,29,37,48},
	// 	{32,33,39,50}
	// };

	// searchInMatrix(v,10);

	vector<int> v= {10,20,30,40};

	allocateMinimumPages(v,2);

	return 0;
}