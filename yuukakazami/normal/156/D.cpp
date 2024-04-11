/*
 * d.cpp
 *
 *  Created on: 2012-3-1
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

typedef long long ll;

const int MAX_N = 100000 + 10;
int mod;

int n, m;

vector<int> E[MAX_N];

bool v[MAX_N];
int cnt;

void dfs(int u) {
	if (v[u])
		return;
	v[u] = true;
	++cnt;
	for (vector<int>::iterator e = E[u].begin(); e != E[u].end(); ++e) {
		dfs(*e);
	}
}

int main() {
	cin >> n >> m >> mod;

	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		E[a].push_back(b), E[b].push_back(a);
	}

	memset(v, 0, sizeof v);

	vector<int> comp;
	for (int i = 0; i < n; ++i) {
		if (!v[i]) {
			cnt = 0;
			dfs(i);
			comp.push_back(cnt);
		}
	}

	if (comp.size() == 1) {
		cout << 1 % mod << endl;
		return 0;
	}

	ll ans = 1, sum = 0;

	for (vector<int>::iterator e = comp.begin(); e != comp.end(); ++e) {
		ans = ans * (*e) % mod;
		sum += *e;
		sum %= mod;
	}

	for (int i = 0; i < comp.size() - 2; ++i) {
		ans = ans * sum % mod;
	}

	cout << ans << endl;
	return 0;
}