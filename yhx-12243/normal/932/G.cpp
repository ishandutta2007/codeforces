#include <bits/stdc++.h>

typedef long long ll;
const int N = 1000054, mod = 1000000007;

int n;
int f[N], F[N];
char s[N], t[N], *ptr;

inline void add(int &x, const int y) {x += y - mod, x += x >> 31 & mod;}

namespace PAM {
	int p, cnt;
	int d[N][26], fail[N], val[N];
	int per[N], fst[N];

	void init() {val[1] = -1, p = 0, *fail = cnt = 1;}

	int get_fail(int x) {for (; ptr[~val[x]] != *ptr; x = fail[x]); return x;}

	int extend(int x) {
		int &q = d[p = get_fail(p)][x];
		if (!q)
			fail[++cnt] = d[get_fail(fail[p])][x], val[q = cnt] = val[p] + 2,
			per[cnt] = val[cnt] - val[fail[cnt]],
			fst[cnt] = (per[cnt] == per[fail[cnt]] ? fst[fail[cnt]] : fail[cnt]);
		return p = q;
	}
}

int main() {
	int i, j, p = 0, l;
	scanf("%s", t), n = strlen(t);
	if (n & 1) return putchar(48), putchar(10), 0;
	for (i = 0, j = n - 1; i < j; s[p++] = t[i++], s[p++] = t[j--]);
	PAM::init();
	for (*f = i = 1, ptr = s; i <= n; ++i, ++ptr)
		for (p = PAM::extend(*ptr - 97); p; p = j) {
			j = PAM::fst[p], l = PAM::val[j] + PAM::per[p], F[p] = f[i - l];
			if (PAM::val[p] != l) add(F[p], F[PAM::fail[p]]);
			if (!(i & 1)) add(f[i], F[p]);
		}
	printf("%d\n", f[n]);
	return 0;
}