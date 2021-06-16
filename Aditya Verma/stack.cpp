#include <bits/stdc++.h>

using namespace std;

vector<int> nearestGreaterToRight(vector<int> &v) {
	stack<int> s;
	vector<int> ans(v.size());
	for(int i = v.size()-1;i>=0;i--) {
		if(s.size()==0) {
			ans[i]=-1;
		}
		else if(s.top()>v[i]) {
			ans[i]=s.top();
		}
		else {
			while(s.size()>0 && s.top()<v[i]) {
				s.pop();
			}
			if(s.size()==0) {
				ans[i]=(-1);
			}
			else {
				ans[i]=s.top();
			}
		}
		s.push(v[i]);
	}
	return ans;
}

vector<int> nearestGreaterToLeft(vector<int> &v) {
	stack<int> s;
	vector<int> ans(v.size());
	for(int i=0;i<v.size();i++)	{
		if(s.size()==0) {
			ans[i]=-1;
		}
		else if(s.top()>v[i]) {
			ans[i]=s.top();
		}
		else {
			while(s.size()>0 && s.top()<v[i]) {
				s.pop();
			}
			if(s.size()==0) {
				ans[i]=-1;
			}
			else {
				ans[i]=s.top();
			}
		}
		s.push(v[i]);
	}
	return ans;
}

vector<int> nearestSmallerToLeft(vector<int> &v) {
	stack<int> s;
	vector<int> ans(v.size());
	for(int i =0;i<v.size();i++) {
		if(s.size()==0) {
			ans[i]=-1;
		}
		else if(s.top()<v[i]){
			ans[i]=s.top();
		}
		else {
			while(s.size()>0 && s.top()>v[i]){
				s.pop();
			}
			if(s.size()==0){
				ans[i]=-1;
			}
			else {
				ans[i]=s.top();
			}
		}
		s.push(v[i]);
	}
	return ans;
}

vector<int> nearestSmallerToRight(vector<int> &v) {
	stack<int> s;
	vector<int> ans(v.size());
	for(int i = v.size()-1;i>=0;i--) {
		if(s.size()==0){
			ans[i]=-1;
		}
		else if(s.top()<v[i]){
			ans[i]=s.top();
		}
		else {
			while(s.size()>0 && s.top()>v[i]){
				s.pop();
			}
			if(s.size()==0){
				ans[i]=-1;
			}
			else{
				ans[i]=s.top();
			}
		}
		s.push(v[i]);
	}
	return ans;
}

vector<int> stockSpan(vector<int> v){
	vector<int> ans(v.size());
	stack<int> s;
	for(int i=0;i<v.size();i++){
		if(s.size()==0){
			ans[i]=i+1;
		}
		else if(v[s.top()]>v[i]){
			ans[i]=i-s.top();
		}
		else {
			while(s.size()>0 && v[s.top()]<v[i]){
				s.pop();
			}
			if(s.size()==0){
				ans[i]=i+1;
			}
			else {
				ans[i]=i-s.top();
			}
		}
		s.push(i);
	}
	return ans;
}

int maximumAreaHistogram(vector<int> &v) {
	vector<int> ans(v.size());
	int res = INT_MIN;
	stack<int> s;

	for(int i=v.size()-1;i>=0;i--) {
		if(s.size()==0){
			ans[i]=v.size();
		}
		else if(v[s.top()]<v[i]){
			ans[i]= s.top();
		}
		else {
			while(s.size()>0 && v[s.top()]>=v[i]){
				s.pop();
			}
			if(s.size()==0){
				ans[i]=v.size();
			}
			else {
				ans[i]= s.top();
			}
		}
		s.push(i);
	}

	while(s.size()>0){
		s.pop();
	}

	for(int i =0;i<v.size();i++) {
		if(s.size()==0){
			ans[i]+=1;
		}
		else if(v[s.top()]<v[i]){
			ans[i]-= s.top();
		}
		else {
			while(s.size()>0 && v[s.top()]>=v[i]){
				s.pop();
			}
			if(s.size()==0){
				ans[i]+=1;
			}
			else {
				ans[i]-= s.top();
			}
		}
		ans[i]= (ans[i]-1)*v[i];
		res=max(res,ans[i]);
		s.push(i);
	}
	return res;
}

int rainWaterTrap(vector<int> &v) {
	vector<int> r(v.size());
	vector<int> l(v.size());
	stack<int> s;

	for(int i=v.size()-1;i>=0;i--){
		if(s.size()==0){
			r[i]=v[i];
		}
		else if(s.top()>v[i]) {
			r[i]=max(s.top(),r[i+1]);
		}
		else {
			while(s.size()>0 && s.top()<v[i]) {
				s.pop();
			}
			if(s.size()==0){
				r[i]=max(v[i],r[i+1]);
			}
			else {
				r[i]=max(s.top(),r[i+1]);
			}
		}
		s.push(v[i]);
	}

	while(s.size()>0) {
		s.pop();
	}

	for(int i =0;i<v.size();i++) {
		if(s.size()==0) {
			l[i]= v[i];
		}
		else if(s.top()>v[i]){
			l[i]= max(l[i-1],s.top());
		}
		else {
			while(s.size()>0 && s.top()<v[i]) {
				s.pop();
			}
			if(s.size()==0) {
				l[i]= max(v[i],l[i-1]);
			}
			else{
				l[i]= max(l[i-1],s.top());
			}
		}
		s.push(v[i]);
	}

	int sum=0;

	for(int i=0;i<v.size();i++){
		l[i]= min(l[i],r[i]);
		l[i]-=v[i];
		sum+=l[i];
	}

	return sum;
}

class MinStack {
private:
	stack<int> s;
	stack<int> m;
public:
	void push(int value) {
		if(s.size()==0) {
			m.push(value);
		}
		else if(m.top()>value) {
			m.push(value);
		}
		s.push(value);
	}

	void pop() {
		if(s.size() > 0 && s.top()==m.top()) {
			m.pop();
		}
		s.pop();
	}

	int top() {
		return s.top();
	}

	int min() {
		return m.top();
	}

	int size() {
		return s.size();
	}
};

class OptimizedMinStack {
private:
	stack<int> s;
	int k=INT_MAX;
public:
	void push(int value){
		if(s.size()==0){
			s.push(value);
			k=value;
		}
		else if(value<k) {
			s.push(2*value-k);
			k=value;
		}
		else {
			s.push(value);
		}
		cout<<s.top()<<endl;
	}
	void pop() {
		if(s.size()>0 && k>s.top()) {
			k= 2*k - s.top();
		}
		s.pop();
	}

	int top() {
		if(s.size()>0 && k>s.top()) {
			return k;
		}
		return s.top();
	}

	int min() {
		return k;
	}

	int size() {
		return s.size();
	}
};


int main(int argc, char const *argv[])
{

	// vector<int> v= {1,3,2,4};

	// vector<int> ans = nearestGreaterToRight(v);

	// vector<int> ans = nearestGreaterToLeft(v);

	// vector<int> ans = nearestSmallerToLeft(v);

	// vector<int> ans = nearestSmallerToRight(v);

	// vector<int> stock = {100,80,60,70,60,75,85};

	// vector<int> ans = stockSpan(stock);

	// for(int i : ans) {
	// 	cout<<i<<' ';
	// }

	// vector<int> v= {6,2,5,4,5,1,6};

	// cout<<maximumAreaHistogram(v);

	vector<int> v={0,1,2,3,1,3};

	cout<<maximumAreaHistogram(v);

	// vector<int> v= {3,0,0,2,0,4};

	// cout<<rainWaterTrap(v);

	// MinStack s;

	// s.push(4);
	// s.push(2);
	// s.push(1);
	// s.push(3);

	// while(s.size()>0) {
	// 	cout<<s.top()<<" "<<s.min()<<"\n";
	// 	s.pop();
	// }

	// OptimizedMinStack s;

	// s.push(4);
	// s.push(2);
	// s.push(1);
	// s.push(3);

	// while(s.size()>0) {
	// 	cout<<s.top()<<" "<<s.min()<<"\n";
	// 	s.pop();
	// }


	return 0;
}

