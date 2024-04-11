#include <bits/stdc++.h>
#define EB emplace_back
using std::cin;
using std::cout;

typedef std::pair <int, int> pr;
typedef std::vector <int> vector;
const int N = 4100, BL = 8, B = 1 << BL;

int C2[N];
inline int merge(int, int);

struct block {
	vector v, f;
	block () {}
	block (const vector &val) {
		const int n = val.size(); assert(n);
		if (n == 1) {v.EB(val.back()), f.EB(val.back()); return;}
		vector::const_iterator middle = val.begin() + n / 2;
		*this = block(vector(val.begin(), middle)) + block(vector(middle, val.end()));
	}
	inline int operator () (int L, int R) const {
		L = std::lower_bound(v.begin(), v.end(), L) - v.begin();
		R = std::upper_bound(v.begin(), v.end(), R) - v.begin() - 1;
		return L <= R ? f[L + C2[R]] : 0;
	}
	friend inline block operator + (const block &L, const block &R) {
		int i, j, Ln = L.v.size(), Rn = R.v.size(), n = Ln + Rn;
		block ret; ret.v.resize(n), ret.f.clear(), ret.f.reserve(C2[n + 1]);
		std::merge(L.v.begin(), L.v.end(), R.v.begin(), R.v.end(), ret.v.begin());
		for (j = 0; j < n; ++j)
			for (i = 0; i <= j; ++i)
				ret.f.EB(merge(L(ret.v[i], ret.v[j]), R(ret.v[i], ret.v[j])));
		return ret;
	}
};

int n, m, q, O;
int p[N], ans[66000];
block s[B];
pr op[2200000];

inline int min(const int x, const int y) {return x < y ? x : y;}
inline int merge(int A, int B) {return A && B ? (op[O] = pr(A, B), ++O) : A | B;}

int main() {
	int i, j, L, R, len; vector t, u;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	for (i = 1; i < N; ++i) C2[i] = C2[i - 1] + i;
	cin >> n >> q, O = n, m = ((n - 1) >> BL) + 1;
	for (i = 1; i <= n; ++i) cin >> j, p[--j] = i;
	for (i = 0; i < m; ++i) {
		L = i << BL, R = min((i + 1) << BL, n),
		t.clear(), t.reserve(len = R - L);
		for (j = L; j < R; ++j) t.EB(p[j]);
		s[i] = block(t);
	}
	for (i = 0; i < q; ++i) {
		cin >> L >> R;
		for (j = 0; j < m; ++j) ans[i] = merge(ans[i], s[j](L, R));
	}
	cout << O << '\n';
	for (i = n; i < O; ++i) cout << op[i].first << ' ' << op[i].second << '\n';
	for (i = 0; i < q; ++i) cout << ans[i] << (i == q - 1 ? '\n' : ' ');
	return 0;
}