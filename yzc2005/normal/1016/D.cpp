#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rg register
#define fu(i, a, b) for(rg int i = (a), I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(rg int i = (a), I = (b) - 1; i > I; --i)
#define go(u) for(rg int o = head[u], v = to[o], w = val[o]; o; o = nxt[o], v = to[o], w = val[o])
template <class T> inline void read(T &x) {
	x = 0; char ch = getchar();
	while(ch < 48 || ch > 57) ch = getchar();
	while(ch >= 48 && ch <= 57) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
}
template <class T> inline void ckmax(T &a, T b) {a = max(a, b);}
template <class T> inline void ckmin(T &a, T b) {a = min(a, b);}

const int N = 105;
int n, m, r[N], c[N], ans[N][N];

inline bool check(int k) {
	bool cntr = 0, cntc = 0;
	fu(j, 1, m - 1) if(c[j] >> k & 1) ans[1][j] |= 1 << k, cntr ^= 1;
	if(cntr ^ (r[1] >> k & 1)) ans[1][m] |= 1 << k, cntc = 1;
	fu(i, 2, n) if(r[i] >> k & 1) ans[i][m] |= 1 << k, cntc ^= 1;
	return cntc == (c[m] >> k & 1);  
}

int main() {
	read(n), read(m);
	fu(i, 1, n) read(r[i]);
	fu(i, 1, m) read(c[i]);
	fd(k, 31, 0) if(!check(k)) return puts("NO"), 0;
	puts("YES");
	fu(i, 1, n) {
		fu(j, 1, m) printf("%d ", ans[i][j]);
		puts("");
	}
	return 0;
}