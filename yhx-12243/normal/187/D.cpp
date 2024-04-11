#include <bits/stdc++.h>
#define N 100010

typedef long long ll;
typedef std::map <int, int> map;

int n, q, G, T;
ll l[N], suf[N];
map f;

inline ll reduce(ll x) {return x %= T, x + (x >> 63 & T);}

void insert(int i, int l, int r) {
	map::iterator beg = f.lower_bound(l), end = f.upper_bound(r);
	int tmp = (--end)->second;
	f.erase(beg, ++end);
	f[l] = i; f[r] = tmp;
}

ll drive(int i, ll x) {
	int j = (--f.upper_bound(reduce(x)))->second;
	return l[j] - l[i] + (j == n ? 0 : T - reduce(x + l[j]) + suf[j]);
}

int main() {
	int i; ll L, R, t, ans = 0;
	scanf("%d%d%d", &n, &G, &T);
	++n; T += G;
	for (i = 1; i <= n; ++i) scanf("%lld", l + i), l[i] += l[i - 1];
	f[0] = n;
	for (i = n - 1; i; --i) {
		L = reduce(G - l[i]), R = reduce(-l[i]); suf[i] = drive(i, -l[i]); // offset
		L < R ? insert(i, L, R) : (insert(i, L, T), insert(i, 0, R));
	}
	for (scanf("%d", &q); q; --q)
		scanf("%lld", &t), printf("%lld\n", ans = t + drive(0, t));
	return 0;
}