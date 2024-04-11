#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int m = 1;; ++m) {
		if ((1 << m) < n)
			continue;
		cout << m << endl;
		for (int i = 0; i < m; ++i) {
			vector<int> a, b;
			for (int j = 0; j < n; ++j) {
				if (j >> i & 1)
					a.push_back(j);
			}
			cout << a.size() << " ";
			for (int j = 0; j < a.size(); ++j) {
				cout << a[j] + 1;
				if (j + 1 < a.size())
					cout << " ";
			}
			cout << endl;
		}
		break;
	}
	return 0;
}