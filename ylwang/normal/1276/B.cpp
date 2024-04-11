#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define reaD() read()
#define pb push_back
#define mkp make_pair
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(register int i = (k); i >= (j); i--)
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define DEBUG fprintf(stderr, "***IAKIOI***\n")
#define CDEBUG cerr << "***IAKIOI***" << endl;
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
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
const int MAXN = 200005;
vector < int > e[MAXN];
int n, m, s, t, v[MAXN][2];
void dfs(int u, int op, int gl) {
	v[u][op] = 1;
	if(u == gl) return;
	for(auto vv : e[u]) {
		if(v[vv][op]) continue;
		dfs(vv, op, gl);
	}
}
signed main()
{
	int T = read();
	while(T--) {
		cin >> n >> m >> s >> t;
		For(i, 1, n) e[i].clear(), v[i][0] = v[i][1] = 0;
		For(i, 1, m) {
			int u = read(), v = read();
			e[u].pb(v); e[v].pb(u);
		}
		dfs(s, 0, t); dfs(t, 1, s);
		int c0 = 0, c1 = 0;
		For(i, 1, n) {
			if(v[i][0] && !v[i][1] && i != s && i != t) c0++;
			if(v[i][1] && !v[i][0] && i != s && i != t) c1++;
		}
//		cout << c0 << ' ' << c1 << endl;
		printf("%lld\n", 1ll * c0 * c1);
	}
    return 0;
}