// LUOGU_RID: 90971761
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline char getc() { //Don't to use it in interactive problems!!!
	return getchar();
	static char *p1, *p2, buf[1<<23]; // '\n' for function isspace in function readstr
	return p1==p2?(p2=(p1=buf)+fread(buf, 1, 1<<23, stdin), p1==p2?'\n':*p1++):*p1++;
}
inline void read(char *s) {
	char c; while (isspace(c=getc()));
	while (!isspace(c)) (*s++)=c, c=getc(); (*s++)='\0';
}
inline int read() {
	int f=1, r=0; char c=getc();
	while (!isdigit(c)) f^=c=='-', c=getc();
	while (isdigit(c)) r=r*10+c-48, c=getc();
	return f?r:-r;
}
#define fi first
#define se second
template<class T> inline void ckmin(T &x, T y) {if (y<x) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=50007, mod=1e9+7;
inline void inc(int &x, int y) {x+=y; if (x>=mod) x-=mod;}
inline void dec(int &x, int y) {x-=y; if (x<0) x+=mod;}
inline void mul(int &x, int y) {x=(ll)x*y%mod;}
inline int add(int x, int y) {return inc(x, y), x;}
inline int sub(int x, int y) {return dec(x, y), x;}
inline int qpow(int a, ll b) {
	int res=1;
	for (; b; b>>=1, mul(a, a)) if (b&1) mul(res, a);
	return res;
}
namespace Trie {
	const int N=1<<11|7;
	int tot, ch[N][2];
	inline void clear() {
		for (int i=0; i<=tot; i++) ch[i][0]=ch[i][1]=0;
		tot=0;
	}
	inline void insert(int x) {
		int u=0;
		for (int i=7; ~i; i--) {
			int c=x>>i&1;
			if (!ch[u][c]) ch[u][c]=++tot;
			u=ch[u][c];
		}
	}
	inline int query(int x) {
		int u=0, ans=0;
		for (int i=7; ~i; i--) {
			int c=x>>i&1;
			if (ch[u][c^1]) ans|=1<<i, u=ch[u][c^1];
			else u=ch[u][c];
		}
		return ans;
	}
}
int n, Q, a[N], fa[N], F[N], dep[N], f[N][257], mx[257];
vector<int>G[N];
void dfs(int x) {
	for (int y:G[x]) {
		if (y==fa[x]) continue;
		dep[y]=dep[x]+1, fa[y]=x, dfs(y);
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	n=read(), Q=read();
	for (int i=1; i<=n; i++) a[i]=read();
	for (int i=1, x, y; i<n; i++) x=read(), y=read(), G[x].push_back(y), G[y].push_back(x);
	dep[1]=1, dfs(1);
	for (int i=1; i<=n; i++) {
		int x=i; Trie::clear();
		for (int j=0; j<256; j++) mx[j]=-114514;
		for (int j=0; j<256 && x; j++) {
			int v=a[x]; Trie::insert(v>>8);
			ckmax(mx[v>>8], j^(v&255)), x=fa[x];
		}
		F[i]=x;
		for (int j=0; j<256; j++) {
			int y=Trie::query(j);
			f[i][j]=y*256+mx[y^j];
		}
	}
	while (Q--) {
		int x=read(), y=read(), ans=0, sum=0;
		while (dep[F[y]]>=dep[x]) ckmax(ans, f[y][sum]), sum++, y=F[y];
		sum<<=8;
		while (dep[y]>=dep[x]) ckmax(ans, a[y]^sum), sum++, y=fa[y];
		printf("%d\n", ans);
	}
	return 0;
}