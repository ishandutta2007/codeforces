#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cassert>
#include <ctime>
#include <memory.h>

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <complex>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex <ld> point;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF 1000000001
#define INFL 2000000000000000001ll

#define NAME "c"

int a[30];

void solve(vector <pair <int, int> > &v, int k);

void dfs(vector <pair <int, int> > &v, int sum, int k, int cnt = 0, int step = 0) {
	if (sum < 0)
		return;
	if (step == (int) v.size()) {
		if (sum)
			return;
		if (cnt < 2)
			return;
		if (v.back().fi == a[k - 1])
			v.back().se++;
		else
			v.pb(mp(a[k - 1], 1));
		solve(v, k - 1);
		v.back().se--;
		if (!v.back().se)
			v.pop_back();
		return;
	}
	for (int i = 0; i <= v[step].se; ++i) {
		v[step].se -= i;
		dfs(v, sum - i * v[step].fi, k, cnt + i, step + 1);
		v[step].se += i;
	}
}

void solve(vector <pair <int, int> > &v, int k) {
	//~ cerr << "solve " << k << '\n';
	//~ for (int i = 0; i < (int) v.size(); ++i)
		//~ cerr << v[i].fi << ' ' << v[i].se << '\n';
	if (!k) {
		int cnt = 0;
		for (int i = 0; i < (int) v.size(); ++i)
			cnt += (v[i].se != 0);
		if (cnt != 1)
			return;
		cout << "YES\n";
		exit(0);
	}
	dfs(v, a[k - 1] - 1, k);
}

int main() {
	#ifdef _GEANY
	assert(freopen(NAME ".in", "r", stdin));
	#endif
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	sort(a, a + n);
	reverse(a, a + n);
	int k = n;
	vector <pair <int, int> > v(0);
	while (k && a[k - 1] == 1)
		--k;
	v.pb(mp(1, n - k));
	solve(v, k);
	cout << "NO\n";
}