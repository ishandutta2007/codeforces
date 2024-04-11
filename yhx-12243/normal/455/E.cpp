#include <bits/stdc++.h>
#define EB emplace_back
using std::cin;
using std::cout;

typedef long long ll;
typedef std::vector <int> vector;
const int N = 100054;

int n, q;
int x[N], y[N], s[N];
int left[N], ans[N];
int hull[N];
bool key[N];
vector qs[N];

inline void down(int &x, const int y) {x > y ? x = y : 0;}
inline int value(int i, int v) {return y[i] - v * x[i];}
inline ll cross(int i, int j, int k) {return ll(x[j] - x[i]) * (y[k] - y[i]) - ll(y[j] - y[i]) * (x[k] - x[i]);}

void solve(int L, int R) {
	if (L + 1 == R) return;
	int i, M = (L + R) / 2, cur = INT_MAX, beg = 0, top = 0, bL, bR, bM;
	for (i = M - 1; i >= L; --i) if ((key[i] = x[i] < cur)) cur = x[i];
	for (i = L; i < M; ++i) if (key[i]) {
		for (; top > 1 && cross(hull[top - 2], hull[top - 1], i) <= 0; --top);
		hull[top++] = i;
	}
	for (; beg + 1 < top && y[ hull[beg] ] >= y[ hull[beg + 1] ]; ++beg);
	assert(beg < top);
	for (i = M; i < R; ++i)
		for (int id : qs[i]) {
			bL = std::lower_bound(hull + beg, hull + top, left[id]) - hull;
			if (bL == top) continue;
			for (bR = top - 1; bL < bR; bM = (bL + bR) / 2, value(hull[bM], left[id]) <= value(hull[bM + 1], left[id]) ? bR = bM : bL = bM + 1);
			down(ans[id], value(hull[bL], left[id]) + s[i]);
		}
	solve(L, M), solve(M, R);
}

int main() {
	int i, l, r;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n;
	for (i = 1; i <= n; ++i) cin >> x[i], s[i] = s[i - 1] + x[i], y[i] = i * x[i] - s[i];
	cin >> q;
	for (i = 0; i < q; ++i) cin >> l >> r, left[i] = r - l, qs[r].EB(i), ans[i] = l * x[r];
	solve(1, n + 1);
	for (i = 0; i < q; ++i) cout << ans[i] << '\n';
	return 0;
}