#include <bits/stdc++.h>
#define EB emplace_back
using std::vector;

typedef long long ll;
typedef std::pair <int, int> pr;

struct rational {
	ll n, d;
	rational (ll _n = 0, ll _d = 0) : n(_n), d(_d) {}
	inline bool operator < (const rational &B) const {return n * B.d < d * B.n;}
};

typedef std::pair <rational, int> pra;
const int N = 100054;

int n, m, lim;
int a[N], ty[N], assign[N], assign_id[N];
vector <pr> add[N];
vector <pra> multiplies;

inline void down(int &x, const int y) {x > y ? x = y : 0;}

int main() {
	int i, id, arg; ll sum;
	scanf("%d%d%d", &n, &m, &lim);
	for (i = 1; i <= n; ++i) scanf("%d", a + i), assign[i] = a[i], assign_id[i] = -1;
	for (i = 0; i < m; ++i)
		switch (scanf("%d%d%d", ty + i, &id, &arg), ty[i]) {
			case 1: if (arg > assign[id]) assign[id] = arg, assign_id[id] = i; break;
			case 2: add[id].EB(arg, i); break;
			case 3: multiplies.EB(rational(arg - 1, 1), i); break;
		}
	for (i = 1; i <= n; ++i) {
		if (~assign_id[i]) add[i].EB(assign[i] - a[i], assign_id[i]);
		std::sort(add[i].begin(), add[i].end(), std::greater <pr> ()), sum = a[i];
		for (const pr &op : add[i]) multiplies.EB(rational(op.first, sum), op.second), sum += op.first;
	}
	std::sort(multiplies.begin(), multiplies.end(), std::greater <pra> ());
	down(lim, multiplies.size()), printf("%d\n", lim);
	std::sort(multiplies.begin(), multiplies.begin() + lim, [] (const pra &A, const pra &B) {return ty[A.second] < ty[B.second];});
	for (i = 0; i < lim; ++i) printf("%d%c", multiplies[i].second + 1, i == lim - 1 ? 10 : 32);
	return 0;
}