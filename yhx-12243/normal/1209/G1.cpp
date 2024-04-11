#include <bits/stdc++.h>

typedef std::pair <int, int> pr;
const int N = 200054;

int n, m, cnt = 0;
int a[N], L[N], R[N];
pr seg[N], Seg[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline void down(int &x, const int y) {x > y ? x = y : 0;}

namespace DC {
	int F[N]; pr D[N];

	int Discretize(int n) {
		int i, cnt = 0;
		std::sort(D, D + n);
		for (i = 0; i < n; ++i)
			F[D[i].second] = (i && D[i].first == D[i - 1].first ? cnt - 1 : (D[cnt] = D[i], cnt++));
		return cnt;
	}
}

int main() {
	int i, j, l, r, la, len, x, ans = 0;
	scanf("%d%*d", &n);
	for (i = 0; i < n; ++i) scanf("%d", &x), DC::D[i] = pr(x, i);
	m = DC::Discretize(n);
	memset(L, 127, sizeof L), memcpy(a, DC::F, sizeof a);
	for (i = 0; i < n; ++i) down(L[a[i]], i), up(R[a[i]], i);
	for (i = 0; i < m; ++i) assert(L[i] <= R[i]), seg[i] = pr(L[i], R[i]);
	std::sort(seg, seg + m), l = r = -1;
	for (i = 0; i < m; ++i) {
		if (seg[i].first <= r) up(r, seg[i].second);
		else Seg[cnt++] = pr(l, r), std::tie(l, r) = seg[i];
//		fprintf(stderr, "Adding %d %d (%d %d)\n", seg[i].first, seg[i].second, l, r);
	}
	Seg[cnt++] = pr(l, r);	
	for (i = 1; i < cnt; ++i) {
//		fprintf(stderr, "found %d %d\n", Seg[i].first, Seg[i].second);
		std::sort(a + Seg[i].first, a + (Seg[i].second + 1));
		la = Seg[i].first - 1, len = 0;
		for (j = la + 1; j <= Seg[i].second; ++j)
			if (j == Seg[i].second || a[j] != a[j + 1])
				up(len, j - la), la = j;
		ans += len;
	}
	printf("%d\n", n - ans);
	return 0;
}