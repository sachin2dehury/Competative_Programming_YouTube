#include <bits/stdc++.h>

using namespace std;

void swap(char &a,char &b){
	char c=a;
	a=b;
	b=c;
}

void stringPermutation(string &a,int i,int j) {
	if(i>=j) {
		cout<<a<<endl;
	} else {
		for(int k=i;k<j;k++){
			swap(a[i],a[k]);
			stringPermutation(a,i+1,j);
			swap(a[i],a[k]);
		}
	}
}

bool queenSafe(vector<vector<char>> &v,int i, int j) {
	for(int k=0;k<i;k++){
		if(v[k][j]=='q') {
			return 0;
		}
	}
	for(int a=i,b=j;a>=0 && b>=0;a--,b--){
		if(v[a][b]=='q') {
			return 0;
		}
	}
	for(int a=i,b=j;a>=0 && b<v.size();a--,b++){
		if(v[a][b]=='q') {
			return 0;
		}
	}
	return 1;
}

void Nqueen(vector<vector<char>> &v,int i, int j) {
	if(i>=j) {
		for(auto c: v) {
			for(char x: c){
				cout<<x<<' ';
			}
			cout<<'\n';
		}		
	} else {
		for(int k=i;k<j;k++){
			if(queenSafe(v,i,k)) {
				v[i][k]='q';
				Nqueen(v,i+1,j);
				v[i][k]='_';
			}
		}
	}
}

void allSubSet(string ip,string op=""){
	if(ip.length()==0){
		cout<<op<<endl;
	} else {
		string op1 = op;
		string op2 = op+ip[0];
		ip=ip.substr(1);
		allSubSet(ip,op1);
		allSubSet(ip,op2);
	}
}

int main(int argc, char const *argv[]) {

	string a="aabc";

	// stringPermutation(a,0,a.size());

	// allSubSet(a);

	vector<vector<char>> v(4,vector<char> (4,'_'));

	Nqueen(v,0,4);

	return 0;
}