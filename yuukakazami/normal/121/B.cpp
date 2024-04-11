#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <map>
using namespace std;

vector<int> make(int a, int b, int c) {
	vector<int> v;
	v.push_back(a), v.push_back(b), v.push_back(c);
	return v;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	string s;
	cin >> s;
	for (int i = 0; i < n; ++i) {
		a[i] = s[i] - '0';
	}
	a.push_back(1);
	++n;
	for (int i = 0; i + 2 < n; i += 2) {
		int &x = a[i], &y = a[i + 1], &z = a[i + 2];
		map<vector<int>, int> last;
		int cur = 0;
		while (k > 0) {
			vector<int> v = make(x, y, z);
			if (last.count(v)) {
				int cyc = cur - last[v];
				k %= cyc;
			}
			if (!k)
				break;
			last[v] = cur++;
			if (x == 4 && y == 7) {
				y = 4;
				--k;
			} else if (y == 4 && z == 7) {
				y = 7;
				--k;
			} else {
				break;
			}
		}
	}

	for (int i = 0; i < n - 1; ++i) {
		cout << a[i];
	}
	cout << endl;
	return 0;
}