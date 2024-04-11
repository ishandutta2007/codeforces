#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
const int inf = 0x3f3f3f3f;
#define rg register
#define fu(i, a, b) for(rg int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(rg int i = a, I = (b) - 1; i > I; --i)
#define go(G, u) for(rg int o = G.head[u], v = G.to[o]; o; o = G.nxt[o], v = G.to[o])
#define reset(a) memset(a, 0, sizeof(a))
#define finish(a) return a, 0
#define fail puts("NO"), exit(0)
typedef long long ll;
inline void ckmax(int &a, int b) {if(a < b) a = b;}
template <class T> inline void read(T &x) {
    x = 0; 
    char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
} 

int n, m, fa[N << 1], f[N << 1], bel[N << 1], d[N << 1], cnt, tot;
char s[N][N];

struct Graph {
	int to[N * N], nxt[N * N], head[N << 1], cnt;
	inline void add(int u, int v) {
		to[++cnt] = v;
		nxt[cnt] = head[u];
		head[u] = cnt;
		++d[v];
	}
} G;

int get(int x) {
	return x == fa[x] ? x : fa[x] = get(fa[x]);
} 

int main() {
	read(n), read(m); 
	fu(i, 1, n + m) fa[i] = i; 
	fu(i, 1, n) {
		scanf("%s", s[i] + 1);
		fu(j, 1, m) if(s[i][j] == '=') fa[get(i)] = get(j + n);
	}
	fu(i, 1, n)
		fu(j, 1, m) 
			if(s[i][j] != '=' && get(i) == get(j + n)) fail;
	fu(i, 1, n + m) if(fa[i] == i) bel[i] = ++cnt;
	fu(i, 1, n + m) bel[i] = bel[get(i)];
	fu(i, 1, n)
		fu(j, 1, m) if(s[i][j] != '='){
			if(s[i][j] == '<') G.add(bel[i], bel[j + n]);
			else G.add(bel[j + n], bel[i]);
		}
	queue<int> q;
	fu(i, 1, cnt) if(!d[i]) f[i] = 1, q.push(i); 
	while(!q.empty()) {
		int u = q.front(); q.pop();
		++tot;
		go(G, u) {
			--d[v];
			ckmax(f[v], f[u] + 1);
			if(!d[v]) q.push(v);
		}
	}
	if(tot < cnt) fail;
	puts("YES"); 
	fu(i, 1, n) printf("%d ", f[bel[i]]); puts("");
	fu(i, 1, m) printf("%d ", f[bel[i + n]]);
	return puts(""), 0;
}