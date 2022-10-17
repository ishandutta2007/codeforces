#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int t;
void yes() {
	cout << "Yes" << endl;
	if (t == 1)
		exit(0);
}

void no() {
	cout << "No" << endl;
	if (t == 1)
		exit(0);
}

const long long MOD = 998244353;
vector<int> v;
inline int f(int x, int w, int m) {
	return x * m + w;
}
bool slv(int a, int b, int  c, int d, int w = 0, int m = 1) {
	v.clear();
	if (d == 0) {
		if (b == a + c + 1) {
			b--;
			v.push_back(f(1, w, m));
		}
		while (c) {
			c--;
			v.push_back(f(2, w, m));
			if (b == 0)
				return a == 0 && b == 0 && c == 0;
			b--;
			v.push_back(f(1, w, m));
		}
		while (a) {
			a--;
			v.push_back(f(0, w, m));
			if (b == 0)
				break;
			b--;
			v.push_back(f(1, w, m));
		}
	}
	else {
		while (a) {
			a--;
			v.push_back(f(0, w, m));
			if (b == 0)
				return false;
			b--;
			v.push_back(f(1, w, m));
		}
		if (c == 0)
			return false;
		c--;
		v.push_back(f(2, w, m));
		while (b) {
			b--;
			v.push_back(f(1, w, m));
			if (c == 0)
				return false;
			c--;
			v.push_back(f(2, w, m));
		}
		while (d) {
			d--;
			v.push_back(f(3, w, m));
			if (c == 0)
				break;
			c--;
			v.push_back(f(2, w, m));
		}
	}
	if (a || b || c || d)
		return false;
	return true;
}
void solve(int test_id) {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (slv(a, b, c, d) || slv(d, c, b, a, 3, -1)) {
		cout << "YES" << endl;
		for (size_t i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
	}
	else {
		cout << "NO";
	}
}

int main() {
	t = 1;
	//cin >> t;
	for (size_t i = 0; i < t; i++)
	{
		solve(i + 1);
	}
	return 0;
}
/*
1
10 5
()((()()))
*/