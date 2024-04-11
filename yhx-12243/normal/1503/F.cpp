#include <bits/stdc++.h>
#define EF emplace_front
#define EB emplace_back
using std::cin;
using std::cout;

typedef std::pair <int, int> pr;
typedef std::list <int> list;
const int N = 400054;

struct curve {
	list li, lir;
	list::iterator out, outr;

	inline void base(int x) {
		li.clear(), lir.clear(), li.EB(x), lir.EB(x), 
		out = li.begin(), outr = lir.begin();
	}

	inline void reverse() {li.swap(lir), std::swap(out, outr);}

	inline curve & wrapPos(int l, int r) {
		reverse(),
		li.EF(r), li.EB(l), out = li.begin(), lir.EF(l), lir.EB(r), --(outr = lir.end());
		return *this;
	}

	inline curve & wrapNeg(int l, int r) {
		reverse(),
		li.EF(l), li.EB(r), --(out = li.end()), lir.EF(r), lir.EB(l), outr = lir.begin();
		return *this;
	}

	void join(curve &rhs) {
		li.splice(out, rhs.li), li.erase(out), out = rhs.out,
		lir.splice(outr, rhs.lir), lir.erase(outr), outr = rhs.outr;
	}
} c[N];

int n, m, A;
pr a[N];
int belU[N], belD[N];
int seq[N], stack[N], ans[N];
bool used[N], rev[N];

inline int tr(int x) {return x >= 0 ? 2 * (x - 1) : ~(2 * x);}
inline int Tr(int x) {return x & 1 ? ~x / 2 : x / 2 + 1;}

bool construct() {
	int i, s = 0, ss = 0;
	for (i = 0; i < m; ++i) s += (rev[i] ? -1 : 1);
	if (s != -2 && s != 2) return false;
	if (s == -2) {
		std::reverse(seq, seq + m), std::reverse(rev, rev + (m - 1));
		for (i = 0; i < m; ++i) rev[i] = !rev[i];
	}
	if (rev[0] || rev[m - 1]) {
		for (i = 2; i < m && (rev[i - 1] || rev[i]); i += 2);
		assert(i != m), std::rotate(seq, seq + i, seq + m), std::rotate(rev, rev + i, rev + m);
	}
	s = 0, c->base(1);
	for (i = 1; i < m - 1; ++i, s = ss) {
		ss = s + (rev[i] ? -1 : 1);
		if (abs(ss) > abs(s))
			stack[abs(ss)] = i, c[abs(ss)].base(i + 1);
		else if (s >= 0)
			c[ss].join(c[s].wrapPos(stack[s], i + 1));
		else
			c[-ss].join(c[-s].wrapNeg(stack[-s], i + 1));
	}
	ans[A++] = *seq;
	for (int idx : c->li) ans[A++] = seq[idx];
	return true;
}

int main() {
	int i, j, u, v, x;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n;
	for (i = 0; i < 2 * n; ++i)
		cin >> u >> v, a[i] = pr(u = tr(u), v = tr(v)), belU[u] = belD[v] = i;
	for (i = 0; i < n; ++i) if (!used[i]) {
		m = 0, j = i << 1, x = belU[j],
		u = belU[j], v = belU[j ^ 1], used[j >> 1] = true;
		for (; ; ) {
			seq[m] = u, rev[m++] = j & 1,
			j = a[v].second,
			u = v, v = belD[j ^ 1],
			seq[m] = u, rev[m++] = !(j & 1),
			j = a[v].first, used[j >> 1] = true,
			u = v, v = belU[j ^ 1];
			if (u == x) break;
		}
		if (!construct()) return cout << "NO\n", 0;
	}
	assert(A == 2 * n), cout << "YES\n";
	for (i = 0; i < A; ++i) cout << Tr(a[ans[i]].first) << ' ' << Tr(a[ans[i]].second) << '\n';
	return 0;
}