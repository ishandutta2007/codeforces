//    
#include <bits/stdc++.h>
using namespace std;
#define mem(a, x) memset(a, x, sizeof(a))
#define fu(i, a, b) for(int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(int i = a, I = (b) - 1; i > I; --i)
#define go(G, u) for(int o = G.head[u], v = G.to[o]; o; o = G.nxt[o], v = G.to[o])
template <class T> inline void rd(T &x) {
    x = 0; T f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    x *= f;
} 
template <class T> inline void ckmax(T &a, T b) {if(a < b) a = b;}
template <class T> inline void ckmin(T &a, T b) {if(a > b) a = b;}
 
const int N = 5005;
int n, m, a[N], cnt[N << 1];

int main() {
	rd(n), rd(m);
	int p = 1;
	for(; p <= n; ++p) {
		if(m <= cnt[p]) break;
		m -= cnt[p], a[p] = p;
		fu(j, 1, p - 1) ++cnt[p + j];
	}
	if(p > n) puts("-1"), exit(0);
	int pos = p;
	while(cnt[p] != m) ++p;
	a[pos] = p;
	for(int cur = 1e8 + 1; pos < n; cur += 1e4) a[++pos] = cur;
	fu(i, 1, n) printf("%d ", a[i]);
	return 0;
}