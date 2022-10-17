#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define reaD() read()
#define pb push_back
#define mkp make_pair
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(register int i = (k); i >= (j); i--)
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define DEBUG fprintf(stderr, "***IAKIOI***\n")
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int MOD = 998244353; //
using namespace std;
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(int &a, int b) {a = min(a, b);}
inline void addmod(int &a, int b) {int t = a + b; a = (t >= MOD ? t - MOD : t); }
inline int read() {
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag=-1;
    for(;c>='0'&&c<='9';num=num*10+c-48,c=getchar());
    return num*flag;
}
const int MAXN = 1200005;
struct Edge {
	int v, w, nxt;
}e[MAXN];
int n, lst[MAXN], tot;
void addedge(int u, int v, int w) {
	e[++tot] = (Edge) {v, w, lst[u]};
	lst[u] = tot;
}
int a1 = 0, a2 = 0, siz[MAXN];
void dfs(int u, int fa) {
	siz[u] = 1;
	for(int i = lst[u]; i; i = e[i].nxt) {
		int v = e[i].v;
		if(v == fa) continue;
		dfs(v, u);
		a1 += (siz[v] % 2) * e[i].w;
		siz[u] += siz[v];
		a2 += min(n - siz[v], siz[v]) * e[i].w;
	}
}
signed main()
{
	int T = read();
	while(T--) {
		n = read() * 2, tot = a1 = a2 = 0 ;
		For(i, 1, n) lst[i] = 0, siz[i] = 0;
		For(i, 1, n-1) {
			int u = read(), v = read(), w = read();
			addedge(u, v, w); addedge(v, u, w);
		}
		dfs(1, 0);
		cout << a1 << ' ' << a2 << endl;
	}
    return 0;
}