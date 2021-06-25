#include <bits/stdc++.h>

using namespace std;

class node {
public:
	int value;
	node* left=nullptr;
	node* right=nullptr;
	node(int value){
		this->value = value;
	}
};

void preorder(node* root) {
	if(root==nullptr){
		return;
	} else {
		cout<<root->value<<' ';
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(node* root){
	if(root==nullptr){
		return;
	} else {
		inorder(root->left);
		cout<<root->value<<' ';
		inorder(root->right);
	}
}

void postorder(node* root){
	if(root==nullptr){
		return;
	} else {
		postorder(root->left);
		postorder(root->right);
		cout<<root->value<<' ';
	}
}

void insert(node* root, int value){
	if(root==nullptr){
		return;
	} else {
		if(value<root->value && root->left) {
			insert(root->left,value);
		} else if(value<root->value){
			root->left = new node(value);
		} else if(value>root->value && root->right) {
			insert(root->right,value);
		} else {
			root->right = new node(value);
		}
	}
}

int sameBinaryTree(node* a,node* b){
	if(a==nullptr && b==nullptr) {
		return 1;
	} else if(a==nullptr || b==nullptr) {
		return 0;
	} else if(a->value == b->value) {
		return sameBinaryTree(a->left,b->left) &&
			sameBinaryTree(a->right,b->right);
	} else {
		return 0;
	}
}

int sizeOfBinaryTree(node* root){
	if(root == nullptr){
		return 0;
	} else {
		return sizeOfBinaryTree(root->left)+sizeOfBinaryTree(root->right)+1;
	}
}

int heightOfBinaryTree(node* root){
	if(root==nullptr){
		return 0;
	} else {
		return 1+max(heightOfBinaryTree(root->left),
			heightOfBinaryTree(root->right));
	}
}

int rootToLeafMaximumSum(node* root){
	if(root==nullptr){
		return 0;
	} else {
		return root->value+max(rootToLeafMaximumSum(root->left),
			rootToLeafMaximumSum(root->right));
	}
}

int isBST(node* root,int l=INT_MIN,int r=INT_MAX){
	if(root==nullptr){
		return 1;
	} else if(root->value < r && root->value >l){
		return isBST(root->left,l,root->value) &&
			isBST(root->right,root->value,r);
	} else {
		return 0;
	}
}

void levelOrder(node* root){
	if(root==nullptr){
		return ;
	}
	queue<node*> q;
	q.push(root);
	while(q.size()>0){
		node* a=q.front();
		q.pop();
		if(a->left){
			q.push(a->left);
		}
		if(a->right){
			q.push(a->right);
		}
		cout<<a->value<<' ';
	}
}

void postorderIterative(node* root){
	if(root==nullptr){
		return;
	}
	stack<node*> s;
	s.push(root);
	stack<node*> r;
	while(s.size()){
		node* a=s.top();
		s.pop();
		r.push(a);
		if(a->left){
			s.push(a->left);
		}
		if(a->right){
			s.push(a->right);
		}
	}
	while(r.size()>0){
		cout<<r.top()->value<<' ';
		r.pop();
	}
}

void preorderIterative(node* root){
	if(root==nullptr){
		return;
	}
	stack<node*> s;
	s.push(root);
	while(s.size()){
		node* a=s.top();
		s.pop();
		if(a->right){
			s.push(a->right);
		}
		if(a->left){
			s.push(a->left);
		}
		cout<<a->value<<' ';
	}
}

void inorderIterative(node* root){
	if(root==nullptr){
		return;
	}
	stack<node*> s;
	while(1){
		if(root){
			s.push(root);
			root=root->left;
		} else if(s.size()==0){
				break;
		} else {
			root=s.top();
			cout<<root->value<<' ';
			s.pop();
			root=root->right;
		}
	}
}

void levelWise(node* root){
	if(root==nullptr){
		return;
	}
	queue<node*> q;
	q.push(root);
	q.push(nullptr);
	while(q.size()){
		node* a=q.front();
		q.pop();
		if(a==nullptr){
			if(q.size()){
				q.push(nullptr);
			}
			cout<<endl;
		} else {
			if(a->left){
				q.push(a->left);
			}
			if(a->right){
				q.push(a->right);
			}
			cout<<a->value<<' ';
		}
	}
}

void reverseLevelWise(node* root){
	if(root==nullptr){
		return;
	}
	queue<node*> q;
	stack<int> s;
	q.push(root);
	vector<int> v;
	while(q.size()){
		node* a=q.front();
		q.pop();
		if(a->left){
			q.push(a->left);
		}
		if(a->right){
			q.push(a->right);
		}
		s.push(a->value);
	}
	while(s.size()){
		cout<<s.top()<<' ';
		s.pop();
	}
}

void spiralTraversal(node * root){
	if(root==nullptr){
		return ;
	}
	deque<node*> q;
	q.push_back(nullptr);
	q.push_back(root);
	while(q.size()>1){
		if(q.back()==nullptr){
			while(q.front()){
				node* a=q.front();
				q.pop_front();
				if(a->right){
					q.push_back(a->right);
				}
				if(a->left){
					q.push_back(a->left);
				}
				cout<<a->value<<' ';
			}
		} else {
			while(q.back()){
				node* a=q.back();
				q.pop_back();
				if(a->left){
					q.push_front(a->left);
				}
				if(a->right){
					q.push_front(a->right);
				}
				cout<<a->value<<' ';
			}
		}
	}
}

void lowestCommonAncestorBST(node* root,int a,int b){
	if(root==nullptr){
		return;
	} else if(root->value < a && root->value < b){
		return lowestCommonAncestorBST(root->right,a,b);
	} else if(root->value > a && root->value > b) {
		return lowestCommonAncestorBST(root->left,a,b);
	} else {
		cout<<root->value;
	}
}

node* lowestCommonAncestor(node* root,int a,int b){
	if(root==nullptr){
		return nullptr;
	} else if(root->value==a || root->value==b){
		return root;
	} else {
		node* l=lowestCommonAncestor(root->left,a,b);
		node* r=lowestCommonAncestor(root->right,a,b);
		if(l && r){
			return root;
		} else if(l) {
			return l;
		} else {
			return r;
		}
	}
}


// void postorderInterative2(node* root){
// 	if(root==nullptr){
// 		return;
// 	}
// 	stack<node*> s;
// 	node* a = root;
// 	while(a || s.size()) {
// 		if(a==nullptr){
// 			node* b=s.top()->right;
// 			if(temp==nullptr){
// 				temp=s.top();
// 				cout<<temp->value<<' ';
// 			}
// 			while(s.size() && temp)
			
// 			s.push(a->right);
// 		} else {
// 			s.push(a);
// 			a=a->left;
// 		}
// 	}
// }

// int largestBST(node* root){
// 	if(root==nullptr){
// 		return 0;
// 	} else {
// 		int l= largestBST(root->left);
// 		int r= largestBST(root->right);
// 		if(r==0 && l==0){
// 			return 1;
// 		} else if(l>0 && r>0){
// 			return 1+l+r;
// 		} else if(l && root->value > root->left->value){
// 			return l;
// 		} else if(r && root->value < root->right->value) {
// 			return r;
// 		} else {
// 			return max(l,r);
// 		}
// 	}
// }


int main(int argc, char const *argv[]) {

	// node * root = new node(3);
	// root->left = new node(1);
	// root->right = new node(5);
	// root->left->right = new node(2);
	// root->right->left = new node(4);

	// preorder(root);
	// cout<<endl;
	// inorder(root);
	// cout<<endl;
	// postorder(root);

	// node * a = root;

	// node * b = new node(3);
	// b->left = new node(1);
	// b->right = new node(5);
	// b->left->right = new node(2);
	// b->right->left = new node(4);

	// cout<<sameBinaryTree(a,b);

	// cout<<sizeOfBinaryTree(root);

	// cout<<heightOfBinaryTree(root);

	node * root = new node(10);
	root->left = new node(16);
	root->right = new node(5);
	root->left->right = new node(-3);
	root->right->left = new node(6);
	root->right->right = new node(11);

	// cout<<rootToLeafMaximumSum(root);

	// levelOrder(root);

	// postorderIterative(root);

	// preorderIterative(root);

	// inorderIterative(root);

	// levelWise(root);

	// reverseLevelWise(root);

	// spiralTraversal(root);

	// lowestCommonAncestorBST(root,1,2);

	// cout<<isBST(root);

	// cout<<lowestCommonAncestor(root,6,11)->value;

	cout<<largestBST(root);

	return 0;
}