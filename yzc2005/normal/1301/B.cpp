#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;
const long long INF = 1e18;
#define fu(i, a, b) for(int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(int i = a, I = (b) - 1; i > I; --i)
#define go(G, u) for(int o = G.head[u], v = G.to[o]; o; o = G.nxt[o], v = G.to[o])
#define reset(a) memset(a, 0, sizeof(a))
#define finish(a) a, exit(0)
#define fail puts("NO"), exit(0)
typedef pair<int, int> P;
typedef long long ll;
template <class T> inline void rd(T &x) {
    x = 0; T f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    x *= f;
} 
template <class T> inline void ckmax(T &a, T b) {if(a < b) a = b;}
template <class T> inline void ckmin(T &a, T b) {if(a > b) a = b;}
 
const int N = 1e5 + 5;
int t, n, a[N];
 
int main() {
	for(rd(t); t; --t) {
		rd(n);
		int mx = 0, maxv = 0, minv = inf; 
		fu(i, 1, n) rd(a[i]);
		fu(i, 1, n) {
			if(a[i] == -1) {
				if(i != n && a[i + 1] != -1) ckmax(maxv, a[i + 1]), ckmin(minv, a[i + 1]);
				if(i != 1 && a[i - 1] != -1) ckmax(maxv, a[i - 1]), ckmin(minv, a[i - 1]);  
			} else {
				if(i != 1 && a[i - 1] != -1) ckmax(mx, abs(a[i] - a[i - 1]));
			}
		}
		printf("%d %d\n", max(mx, (maxv - minv + 1) / 2), (maxv + minv) / 2);
	}
	return 0;
}