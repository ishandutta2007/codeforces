#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;

typedef long long int64;
vector<int64> ls;

void rec(int64 cur, int n) {
	ls.push_back(cur);
	if (n > 0) {
		rec(cur * 10 + 4, n - 1);
		rec(cur * 10 + 7, n - 1);
	}
}

int main() {
	rec(0, 11);
	sort(ls.begin(), ls.end());
	int64 l, r, ret = 0;
	cin >> l >> r;
	for (int i = 0; i + 1 < ls.size(); ++i) {
		int64 L = ls[i] + 1, R = ls[i + 1];
		L = max(L, l);
		R = min(R, r);
		if (L <= R) {
			ret += (R - L + 1) * ls[i + 1];
		}
	}
	cout << ret << endl;
	return 0;
}