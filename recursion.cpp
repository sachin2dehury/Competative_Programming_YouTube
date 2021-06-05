#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

class node {
public:
	int value;
	node* left=nullptr;
	node* right=nullptr;
};

int treeHeight(node* root);

void sortArray(vector<int> &v);
void insertToSortArray(vector<int> &v, int ele);

void sortStack(stack<int> &s);
void insertToSortStack(stack<int> &s,int ele);

void deleteMidStack(stack<int> &s,int k);

void reverseStack(stack<int> &s);
void insertToReverseStack(stack<int> &s,int ele);

int kThSymbol(int n,int k);

void towerOfHanoi(int n,int s,int d,int h);


int treeHeight(node* root) {
	if(root == nullptr) {
		return 0;
	}
	int leftHeight = treeHeight(root->left);
	int rightHeight = treeHeight(root->right);
	return 1+ max(leftHeight,rightHeight);
}


void sortArray(vector<int> &v) {
	if(v.size()==1) {
		return;
	}
	int temp = v[v.size()-1];
	v.pop_back();
	sortArray(v);
	insertToSortArray(v,temp);
}

void insertToSortArray(vector<int> &v, int ele) {
	if(v.size()==0 || v[v.size()-1] < ele) {
		v.push_back(ele);
		return;
	}
	int temp = v[v.size()-1];
	v.pop_back();
	insertToSortArray(v,ele);
	v.push_back(temp);
}

void sortStack(stack<int> &s) {
	if(s.size()==1) {
		return;
	}
	int temp = s.top();
	s.pop();
	sortStack(s);
	insertToSortStack(s,temp);
}

void insertToSortStack(stack<int> &s,int ele) {
	if(s.size()==0 || s.top()<ele) {
		s.push(ele);
		return;
	}
	int temp = s.top();
	s.pop();
	insertToSortStack(s,ele);
	s.push(temp);
}

void deleteMidStack(stack<int> &s,int k) {
	if(k==0) {
		s.pop();
		return;
	}
	int temp = s.top();
	s.pop();
	deleteMidStack(s,k-1);
	s.push(temp);
}

void reverseStack(stack<int> &s) {
	if(s.size()==1){
		return ;
	}
	int temp = s.top();
	s.pop();
	reverseStack(s);
	insertToReverseStack(s,temp);
}

void insertToReverseStack(stack<int> &s,int ele) {
	if(s.size()==0) {
		s.push(ele);
		return;
	}
	int temp = s.top();
	s.pop();
	insertToReverseStack(s,ele);
	s.push(temp);
}


int kThSymbol(int n,int k) {
	if(n==1 && k==1) {
		return 0;
	}
	int mid = pow(2,n-2);
	if(k <= mid) {
		return kThSymbol(n-1,k);
	}
	else {
		return !kThSymbol(n-1,k-mid);
	}
}

void towerOfHanoi(int n,int s=1,int d=3,int h=2) {
	if(n==1) {
		cout<<"from "<<s<<"to"<<d<<'\n';
		return;
	}
	towerOfHanoi(n-1,s,h,d);
	cout<<"from "<<s<<"to"<<d<<'\n';
	towerOfHanoi(n-1,h,d,s);
}

int main() {
	
	vector<int> v = {4,3,2,1};
	// sortArray(v);
	// for(int i : v){
	// 	cout<<i<<" ";
	// }

	cout<<endl;

	stack<int> s;
	s.push(5);
	s.push(4);
	s.push(1);
	s.push(3);
	s.push(2);
	
	// sortStack(s);

	// while(s.size()>0) {
	// 	cout<<s.top()<<' ';
	// 	s.pop();
	// }

	// deleteMidStack(s,s.size()/2);

	// while(s.size()>0) {
	// 	cout<<s.top()<<' ';
	// 	s.pop();
	// }

	// reverseStack(s);

	// while(s.size()>0) {
	// 	cout<<s.top()<<' ';
	// 	s.pop();
	// }

	// cout<<kThSymbol(4,3);

	// towerOfHanoi(4);



}