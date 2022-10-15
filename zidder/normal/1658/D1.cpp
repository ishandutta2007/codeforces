#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

struct Node {
	int d;
	Node *zero, *one;
	Node(int dd=17): d(dd){zero=nullptr; one=nullptr;}
	void insert(int x){
		if (x & (1<<d)){
			if (one == nullptr) one = new Node(d-1);
			if (d > 0) one->insert(x);
		} else {
			if (zero == nullptr) zero = new Node(d-1);
			if (d > 0) zero->insert(x);
		}
	}

	int min(int x){
		if (d == -1) return 0;
		if (x&(1<<d)){
			if (one != nullptr) return one->min(x);
			else return (1<<d) + zero->min(x);
		} else {
			if (zero != nullptr) return zero->min(x);
			else return (1<<d) + one->min(x);
		}
	}

	int max(int x){
		if (d == -1) return 0;
		if (x&(1<<d)){
			// cout << zero << " " << one << " " << (1<<d) << " " << x << endl;
			if (zero!=nullptr) return (1<<d) + zero->max(x);
			else return one->max(x);
		} else {
			// cout << zero << " " << one << " " << (1<<d) << " " << x << endl;
			if (one != nullptr) return (1<<d) + one -> max(x);
			else return zero->max(x);
		}
	}

	~Node(){
		if (zero!=nullptr) delete zero;
		if (one !=nullptr)  delete one;
	}
};

void solve(int test_ind){
	int l, r;
	cin >> l >> r;
	vector<int> a(r-l+1);
	Node root;
	for (int i=0;i<(r-l+1);++i){
		cin >> a[i];
		root.insert(a[i]);
	}
	for (int i=0;i<r-l+1;++i){
		if (root.min(a[i]^l) == l && root.max(a[i]^l) == r){
			// cout << root.min(1) << " " << root.max(1) << endl;
			cout << (a[i] ^ l) << endl;
			return;
		}
	}
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}