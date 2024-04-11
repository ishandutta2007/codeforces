#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=r*10+(c&15), c=getchar();
	return f?r:-r;
}
#define pii pair<int, int>
#define fi first
#define se second
template<class T> inline void ckmin(T &x, T y) {if (x>y) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=1e6+7;
namespace seg {
	const int N=5e6+7;
	int tot, ls[N], rs[N]; pii t[N];
	inline void upd(int p) {t[p]=max(t[ls[p]], t[rs[p]]);}
	void modify(int &p, int l, int r, int x) {
		if (!p) p=++tot; if (l==r) {t[p].fi++, t[p].se=-l; return;}
		int mid=(l+r)>>1; x<=mid?modify(ls[p], l, mid, x):modify(rs[p], mid+1, r, x); upd(p);
	}
	int merge(int p, int q, int l, int r) {
		if (!p || !q) return p|q; if (l==r) {t[p].fi+=t[q].fi; return p;}
		int mid=(l+r)>>1; ls[p]=merge(ls[p], ls[q], l, mid), rs[p]=merge(rs[p], rs[q], mid+1, r); return upd(p), p;
	}
	pii query(int p, int l, int r, int x, int y) {
		if (!p) return {0, -x}; if (x<=l && r<=y) return t[p]; int mid=(l+r)>>1; if (y<=mid) return query(ls[p], l, mid, x, y);
		if (x>mid) return query(rs[p], mid+1, r, x, y); return max(query(ls[p], l, mid, x, y), query(rs[p], mid+1, r, x, y));
	}
}
int n, m, ed[N];
pii ans[N];
char str[N], s[N];
namespace sam {
	const int N=1e6+1e5+7;
	int tot=1, link[N], nxt[N][26], len[N], rt[N];
	inline int insert(int c, int lst) {
		if (len[lst]+1==len[nxt[lst][c]]) return nxt[lst][c];
		int cur=++tot, p=lst; len[cur]=len[lst]+1;
		while (p && !nxt[p][c]) nxt[p][c]=cur, p=link[p];
		if (!p) link[cur]=1;
		else {
			int q=nxt[p][c];
			if (p==lst) {
				link[cur]=link[q], link[q]=cur, memcpy(nxt[cur], nxt[q], 26<<2);
				while (p && nxt[p][c]==q) nxt[p][c]=cur, p=link[p];
			} else if (len[q]==len[p]+1) link[cur]=q;
			else {
				int u=++tot; link[u]=link[q], memcpy(nxt[u], nxt[q], 26<<2);
				len[u]=len[p]+1, link[q]=link[cur]=u;
				while (p && nxt[p][c]==q) nxt[p][c]=u, p=link[p];
			}
		}
		return cur;
	}
	inline void insert(char *str, int id) {
		for (int i=1, lst=1; str[i]; i++) {
			lst=insert(str[i]-'a', lst);
			if (id) seg::modify(rt[lst], 1, m, id);
			else ed[i]=lst;
		}
	}
	int f[N][21];
	vector<int>G[N];
	struct node {int id, l, r;};
	vector<node>q[N];
	void dfs1(int x) {
		for (int i=1; i<=20; i++) f[x][i]=f[f[x][i-1]][i-1];
		for (int y:G[x]) dfs1(y);
	}
	void dfs2(int x) {
		for (int y:G[x]) dfs2(y), rt[x]=seg::merge(rt[x], rt[y], 1, m);
		for (auto y:q[x]) ans[y.id]=seg::query(rt[x], 1, m, y.l, y.r);
	}
	inline void init() {
		for (int i=2; i<=tot; i++) G[f[i][0]=link[i]].push_back(i);
		dfs1(1);
	}
	inline void query(int l, int r, int pl, int pr, int id) {
		int x=ed[pr];
		for (int i=20; ~i; i--) if (len[f[x][i]]>=pr-pl+1) x=f[x][i];
		q[x].push_back({id, l, r});
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%s", str+1), n=strlen(str+1), m=read();
	for (int i=1; i<=m; i++) scanf("%s", s+1), sam::insert(s, i);
	sam::insert(str, 0), sam::init(); int Q=read();
	for (int i=1; i<=Q; i++) {
		int l=read(), r=read(), pl=read(), pr=read();
		sam::query(l, r, pl, pr, i);
	}
	sam::dfs2(1);
	for (int i=1; i<=Q; i++) printf("%d %d\n", -ans[i].se, ans[i].fi);
	return 0;
}