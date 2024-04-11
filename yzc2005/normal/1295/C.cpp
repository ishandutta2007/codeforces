#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, N = 1e5 + 10;
const int inf = 0x3f3f3f3f;
#define rg register
#define fu(i, a, b) for(rg int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(rg int i = a, I = (b) - 1; i > I; --i)
#define go(G, u) for(rg int o = G.head[u], v = G.to[o]; o; o = G.nxt[o], v = G.to[o])
#define reset(a) memset(a, 0, sizeof(a))
#define finish(a) return a, 0;
typedef pair<int, int> P;
typedef long long ll;
template <class T> inline void read(T &x) {
    x = 0; T f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    x *= f;
} 
template <class T> inline void ckmax(T &a, T b) {a = max(a, b);}
template <class T> inline void ckmin(T &a, T b) {a = min(a, b);}
template <class T> inline void addmod(T &a, T b) {a = (a + b) % mod;}

int T, n, m, nxt[N][30], lst[30];
char s[N], t[N];
bool a[30], b[30];

inline int find(int pos) {
	int p = 0, i;
	for(i = pos + 1; i <= m; ++i) {
		p = nxt[p][t[i] - 'a'];
		if(p == -1) break;
	}
	return i - 1;
}

int main() {
	read(T);
	while(T--) {
		scanf("%s", s + 1); n = strlen(s + 1);
		scanf("%s", t + 1); m = strlen(t + 1);
		fu(i, 0, n) fu(k, 0, 25) nxt[i][k] = -1;
		memset(lst, 0, sizeof lst);
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		fu(i, 1, n) {
			int k = s[i] - 'a';
			fu(j, lst[k], i - 1) nxt[j][k] = i;
			lst[k] = i;
			a[k] = 1;
		}
		fu(i, 1, m) b[t[i] - 'a'] = 1;
		bool flg = 1;
		fu(k, 0, 25) if(!a[k] && b[k]) flg = 0;
		if(!flg) {
			puts("-1");
			continue;
		} 
		int cur = 0, ans = 0;
		while(cur != m) ++ans, cur = find(cur);
		printf("%d\n", ans);
	}
	return 0;
}