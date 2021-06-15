#include <bits/stdc++.h>

using namespace std;

void swap(int &a,int &b){
	a=a+b;
	b=a-b;
	a=a-b;
}

void missingAndDuplicate(vector<int> &v){
	for(int i=0;i<v.size();i++){
		if(v[i]!=i+1){
			swap(v[i],v[v[i]-1]);
		}
	}

	for(int i=0;i<v.size();i++){
		if(v[i]!=i+1){
			cout<<"Missing "<<i+1<<endl;
			if(v[v[i]-1]==v[i]) {
				cout<<"Duplicate "<<v[i]<<endl;
			}
		}
	}
}

int main(int argc, char const *argv[]) {
	
	vector<int> v ={2,3,1,5,4,4,7};

	missingAndDuplicate(v);

	return 0;
}