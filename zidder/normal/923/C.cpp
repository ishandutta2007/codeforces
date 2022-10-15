#include <iostream>
#include <stack>

#define SS ;

typedef long long ll;
using namespace std;
const int max_size = 30;
struct BTree {
	BTree* zero;
	BTree* one;
	int count;

	int _find(stack<int>& a) {
		count--;
		if (a.size() == 0)
			return 0;
		if (a.top()) {
			int n;
			a.pop();
			if (one && one->count)
				n = (1 << (a.size())) + one->_find(a);
			else
				n = zero->_find(a);
			return n;
		}
		else {
			int n;
			a.pop();
			if (zero && zero->count)
				n = zero->_find(a);
			else
				n = (1 << (a.size())) + one->_find(a);
			return n;
		}
	}
	int find(int n) {
		stack<int> a;
		for (size_t i = 0; i < max_size; i++) {
			a.push(n % 2);
			n /= 2;
		}
		return _find(a);
	}
	void _insert(stack<int>& a) {
		count++;
		if (a.size() == 0)
			return;
		if (a.top()) {
			a.pop();
			if (!one) {
				one = new BTree();
			}
			one->_insert(a);
		}
		else {
			a.pop();
			if (!zero) {
				zero = new BTree();
			}
			zero->_insert(a);
		}
	}
	void insert(int n) {
		stack<int> a;
		for (size_t i = 0; i < max_size; i++) {
			a.push(n % 2);
			n /= 2;
		}
		_insert(a);
	}
};
BTree t;
int num;
const int N = 300000;
int A[N + 1];
int main() {
	cin >> num;
	for (size_t i = 0; i < num; i++)
	{
		cin >> A[i];
	}

	for (size_t i = 0; i < num; i++)
	{
		int p;
		cin >> p;
		t.insert(p);
	}

	for (size_t i = 0; i < num; i++)
	{
		cout << (A[i] ^ (t.find(A[i]))) << " ";
	}
	SS;
	return 0;
}