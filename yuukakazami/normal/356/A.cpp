#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <vector>
using namespace std;
const int MAX_N = 300000 + 10;
int ans[MAX_N], n, m;
set<int> st;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		st.insert(i);
	}
	for (int i = 0; i < m; ++i) {
		int l, r, x;
		scanf("%d%d%d", &l, &r, &x);
		vector<int> every(st.lower_bound(l), st.upper_bound(r));
		for (vector<int>::iterator e = every.begin(); e != every.end(); ++e) {
			if (*e != x) {
				ans[*e] = x;
				st.erase(*e);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d ", ans[i]);
	}
	puts("");
}