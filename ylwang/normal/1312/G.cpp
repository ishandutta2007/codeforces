#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define reaD() read()
#define pb push_back
#define Pair pair < int, int >
#define mkp make_pair
#define rint register int
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(register int i = (k); i >= (j); i--)
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define DEBUG fprintf(stderr, "***IAKIOI***\n")
#define CDEBUG cerr << "***IAKIOI***" << endl;
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define file(s) freopen(s".in", "r", stdin);freopen(s".out", "w", stdout)
#define INF ((1 << 30) - 1)
#define dprintf(x) fprintf(stderr, "%d ", x)
#define dprintfln(x) fprintf(stderr, "%d\n", x)
#define dln fprintf(stderr, "\n")
const int P = 998244353; //
using namespace std;
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(int &a, int b) {a = min(a, b);}
inline void mulmod(int &a, int b) {a = 1ll * a * b % P;}
inline void addmod(int &a, int b) {int t = a + b; a = (t >= P ? t - P : t); }
inline int ksm(int a, int b) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%P;a=1ll*a*a%P;}return ans;}
inline int inv(int a) {return ksm(a, P-2);}
inline int read() {
    int num=0,flag=1;char c=' ';
    for(;!isdigit(c);c=getchar()) if(c=='-') flag=-1;
    for(;isdigit(c);num=num*10+c-48,c=getchar());
    return num*flag;
}
const int MAXN = 1e6 + 5;
int a[MAXN][26], n, m, tot, fa[MAXN], f[MAXN], o[MAXN], dfn[MAXN], mdfn[MAXN], mn[MAXN], ind, S[MAXN];
void dfs1(int u) {
//	cout <<u << endl;
	if(o[u]) mdfn[u] = dfn[u] = ++ind;
	For(i, 0, 25) {
		int v = a[u][i];
		if(v) {
			dfs1(v);
			ckmin(mdfn[u], mdfn[v]);
		}
			
	}
}

void dfs2(int u) {
	if(u != 0) {
		if(o[u]) f[u] = min(f[fa[u]] + 1, mn[fa[u]] + dfn[u]);
		else f[u] = f[fa[u]] + 1;
	}
		
	if(mdfn[u] == INF) return;
	else {
		mn[u] = min(mn[fa[u]], f[u] - mdfn[u] + 1);
	}
	For(i, 0, 25) {
		int v = a[u][i];
		if(v) dfs2(v);
	}
}
signed main()
{
	n = read();
	For(i, 1, n) {
		int lst = read();
		char t[55]; scanf("%s", t);
		a[lst][t[0]-'a'] = i, fa[i] = lst;
	}
	m = read();
	For(i, 1, m)
		o[S[i] = read()] = 1;
	For(i, 0, n)
		mdfn[i] = INF, mn[i] = INF;
	dfs1(0);
//	For(i, 1, n) {
//		fprintf(stderr, "mdfn[%d] = %d\n", i, mdfn[i]); 
//	}
	dfs2(0);
//	For(i, 1, n) {
//		fprintf(stderr, "mn[%d] = %d\n", i, mn[i]); 
//	}
//	For(i, 1, n) {
//		fprintf(stderr, "f[%d] = %d\n", i, f[i]); 
//	}
//	For(i, 1, m) {
//		printf("%d ", id[S[i]]);
//	}
	For(i, 1, m) {
		printf("%d ", f[S[i]]); 
	}
    return 0;
}
/*

*/