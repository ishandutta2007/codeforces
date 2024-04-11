#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
#include <memory.h>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <list>
#include <complex>

using namespace std;

#define INF 1000000001
#define INFL 1000000000000000001ll
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef long double ld;
typedef complex <ld> point;

#define NAME "b"

#define left lsfgn
#define right lsfgnejogn

int a[1001][1001];
int left[1001][1001];
int right[1001][1001];
int up[1001][1001];
int down[1001][1001];
int n, m;

inline void calc_hor(int x) {
	int q = -1;
	for (int i = 0; i < m; ++i) {
		if (!a[x][i])
			q = i;
		left[x][i] = i - q;
	}
	q = m;
	for (int i = m - 1; i >= 0; --i) {
		if (!a[x][i])
			q = i;
		right[x][i] = q - i;
	}
}

inline void calc_ver(int y) {
	int q = -1;
	for (int i = 0; i < n; ++i) {
		if (!a[i][y])
			q = i;
		up[i][y] = i - q;
	}
	q = n;
	for (int i = n - 1; i >= 0; --i) {
		if (!a[i][y])
			q = i;
		down[i][y] = q - i;
	}
}

vector <int> s;
int nx[1001];
int pr[1001];
int h[1001];

inline int ans_stack(int y, int m) {
	s.clear();
	for (int i = 0; i < m; ++i) {
		while (!s.empty() && h[s.back()] > h[i]) {
			nx[s.back()] = i;
			s.pop_back();
		}
		s.pb(i);
	}
	while (!s.empty()) {
		nx[s.back()] = m;
		s.pop_back();
	}
	
	for (int i = m - 1; i >= 0; --i) {
		while (!s.empty() && h[s.back()] > h[i]) {
			pr[s.back()] = i + 1;
			s.pop_back();
		}
		s.pb(i);
	}
	while (!s.empty()) {
		pr[s.back()] = 0;
		s.pop_back();
	}
	int ans = 0;
	for (int i = 0; i < m; ++i)
		if (pr[i] <= y && y < nx[i])
			ans = max(ans, (nx[i] - pr[i]) * h[i]);
	return ans;
}

inline int answer(int x, int y) {
	int ans = 0;
	for (int i = 0; i < m; ++i)
		h[i] = up[x][i];
	ans = max(ans, ans_stack(y, m));
	
	for (int i = 0; i < m; ++i)
		h[i] = down[x][i];
	ans = max(ans, ans_stack(y, m));
	
	for (int i = 0; i < n; ++i)
		h[i] = left[i][y];
	ans = max(ans, ans_stack(x, n));
	
	for (int i = 0; i < n; ++i)
		h[i] = right[i][y];
	ans = max(ans, ans_stack(x, n));
	
	return ans;
}

int main() {
	srand(time(0));
	cout.setf(ios::fixed);
	cout.precision(10);
	#ifdef _GEANY
	assert(freopen(NAME ".in", "r", stdin));
	#endif
	int q;
	cin >> n >> m >> q;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%d", a[i] + j);
	for (int i = 0; i < n; ++i)
		calc_hor(i);
	for (int i = 0; i < m; ++i)
		calc_ver(i);
	for (int ii = 0; ii < q; ++ii) {
		int op, x, y;
		cin >> op >> x >> y;
		--x, --y;
		if (op == 1) {
			a[x][y] ^= 1;
			calc_hor(x);
			calc_ver(y);
		} else
			cout << answer(x, y) << '\n';
	}
}