#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <set>
using namespace std;
int n, k;
vector<int> q, s, rq;

vector<int> apply(vector<int> p, vector<int> q) {
	vector<int> ret(n);
	for (int i = 0; i < n; ++i) {
		ret[i] = p[q[i]];
	}
	return ret;
}

const int MAX_N = 100 + 10;

set<vector<int> > vis[MAX_N];

void dfs(vector<int> a, int t) {
	if (t < k && a == s)
		return;
	if (!vis[t].insert(a).second)
		return;
	if (t == k) {
		if (a == s)
			throw 1;
		return;
	}
	dfs(apply(a, q), t + 1);
	dfs(apply(a, rq), t + 1);
}

int main() {
	cin >> n >> k;
	q.resize(n), s.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> q[i];
		--q[i];
	}
	rq.resize(n);
	for (int i = 0; i < n; ++i) {
		rq[q[i]] = i;
	}
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		--s[i];
	}
	try {
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			a[i] = i;
		}
		dfs(a, 0);
	} catch (int e) {
		puts("YES");
		return 0;
	}
	puts("NO");
	return 0;
}