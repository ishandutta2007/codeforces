//pray for me
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

const int N = 3e3 + 5;
int n, m, k, ans, cnt, a[N];
char b[N]; 

inline void work(char ch, int step) {
	if(ans + step >= k) {
		if(step) a[++cnt] = k - ans, b[cnt] = ch;
		puts("YES");
		printf("%d\n", cnt);
		fu(i, 1, cnt) printf("%d %c\n", a[i], b[i]);
		exit(0);
	}
	if(step) a[++cnt] = step, b[cnt] = ch, ans += step;
}

int main() {
	rd(n), rd(m), rd(k);
	if(k > 4 * n * m - 2 * n - 2 * m) return puts("NO"), 0;
	work('R', m - 1), work('D', n - 1), work('L', m - 1), work('U', n - 1);
	fu(i, 1, n - 2) work('D', 1), work('R', m - 1), work('L', m - 1);
	work('D', 1);
	fu(i, 1, m - 2) work('R', 1), work('U', n - 1), work('D', n - 1);
	work('R', 1), work('U', n - 1), work('L', m - 1);
}