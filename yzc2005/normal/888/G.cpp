#include <bits/stdc++.h> 
using namespace std;
#define fu(i, a, b) for(int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(int i = a, I = (b) - 1; i > I; --i)
template <class T> inline void rd(T &x) {
    x = 0; char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
} 
template <class T> inline void ckmin(T &a, T b) {if(a > b) a = b;}

const int N = 2e5 + 5, M = N * 31;
int n, w[N], son[M][2], tot;
long long ans;

inline void insert(int x) {
	for(int k = 30, p = 0; ~k; --k) {
		int y = x >> k & 1;
		if(!son[p][y]) son[p][y] = ++tot;
		p = son[p][y];
	}
}

inline int ask(int x) {
	int res = 0;
	for(int k = 30, p = 0; ~k; --k) {
		int y = x >> k & 1;
		if(!son[p][y]) y ^= 1, res += 1 << k;
		p = son[p][y];
	}
	return res;
}

void solve(int l, int r, int k) {
	if(k == -1) return;
	int pos = l;
	while(pos <= r && !(w[pos] >> k & 1)) ++pos;
	if(pos == l || pos == r + 1) return solve(l, r, k - 1);
	solve(l, pos - 1, k - 1), solve(pos, r, k - 1);
	fu(i, l, pos - 1) insert(w[i]);
	int res = INT_MAX; fu(i, pos, r) ckmin(res, ask(w[i])); ans += res; 
	fu(i, 0, tot) fu(j, 0, 1) son[i][j] = 0; tot = 0;
}

int main() {
	rd(n);
	fu(i, 1, n) rd(w[i]);
	sort(w + 1, w + n + 1);
	solve(1, n, 30);
	printf("%lld\n", ans);
	return 0; 
}