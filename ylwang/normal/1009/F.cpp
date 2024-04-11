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
inline int ksm(int a, int b) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%MOD;a=1ll*a*a%MOD;}return ans;}
inline int inv(int a) {return ksm(a, MOD-2);}
inline int read() {
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag=-1;
    for(;c>='0'&&c<='9';num=num*10+c-48,c=getchar());
    return num*flag;
}
const int MAXN = 1000005; 
vector < int > e[MAXN];
int md[MAXN], dep[MAXN], lson[MAXN], n;

void dfs1(int u, int fa) {
	md[u] = dep[u] = dep[fa]+1;
	for(auto v : e[u]) {
		if(v == fa) continue;
		dfs1(v, u);
		if(md[v] > md[u])
			md[u] = md[v], lson[u] = v;
	}
}
int *f[MAXN], tmp[MAXN<<1], *id = tmp, ans[MAXN];
void dfs(int u, int fa) {
	f[u][0] = 1;
	if(lson[u]) {
		f[lson[u]] = f[u] + 1; // lson[u]fu 
		dfs(lson[u], u);
		ans[u] = ans[lson[u]]+1;
	}
	for(auto v : e[u]) {
		if(v == fa || v == lson[u]) continue;
		f[v] = id; id += md[v] - dep[v] + 1; //  
		dfs(v, u);
		For(j, 0, md[v] - dep[v]) { // O() 
			f[u][j+1] += f[v][j];
			if(f[u][j+1] > f[u][ans[u]] || f[u][j+1] == f[u][ans[u]] && ans[u] > j + 1) 
				ans[u] = j + 1;
		}
	}
	if(f[u][ans[u]] == 1) ans[u] =0 ;
}
signed main()
{
	cin >> n;
	For(i, 1, n-1) {
		int u = read(), v = read();
		e[u].pb(v); e[v].pb(u);
	}
	dfs1(1, 0);
	f[1] = id; id += md[1];
	dfs(1, 0);
	For(i, 1, n) printf("%d\n", ans[i]);
    return 0;
}