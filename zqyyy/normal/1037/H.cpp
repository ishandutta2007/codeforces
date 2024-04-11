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
const int N=2e5+7;
int n, m, Q;
char str[N];
namespace seg {
	const int N=5e6+7;
	int tot, ls[N], rs[N]; bool t[N];
	void modify(int &p, int l, int r, int x) {
		p=++tot, t[p]=true; if (l==r) return; int mid=(l+r)>>1;
		x<=mid?modify(ls[p], l, mid, x):modify(rs[p], mid+1, r, x);
	}
	int merge(int p, int q, int l, int r) {
		if (!p || !q) return p|q; int x=++tot; t[x]=t[p]|t[q]; if (l==r) return x;
		int mid=(l+r)>>1; ls[x]=merge(ls[p], ls[q], l, mid), rs[x]=merge(rs[p], rs[q], mid+1, r); return x;
	}
	bool query(int p, int l, int r, int x, int y) {
		if (x<=l && r<=y) return t[p]; int mid=(l+r)>>1;
		if (x<=mid && query(ls[p], l, mid, x, y)) return true;
		if (y>mid && query(rs[p], mid+1, r, x, y)) return true;
		return false;
	}
}
namespace sam {
	int lst=1, tot=1, link[N], nxt[N][26], len[N], rt[N];
	inline void insert(int c, int id) {
		int cur=++tot, p=lst; len[cur]=len[lst]+1, lst=cur, seg::modify(rt[cur], 1, n, id);
		while (p && !nxt[p][c]) nxt[p][c]=cur, p=link[p];
		if (!p) link[cur]=1;
		else {
			int q=nxt[p][c];
			if (len[q]==len[p]+1) link[cur]=q;
			else {
				int u=++tot; link[u]=link[q], memcpy(nxt[u], nxt[q], 26<<2);
				len[u]=len[p]+1, link[q]=link[cur]=u;
				while (p && nxt[p][c]==q) nxt[p][c]=u, p=link[p];
			}
		}
	}
	inline void init() {
		static int deg[N]; for (int i=2; i<=tot; i++) deg[link[i]]++;
		queue<int>q; for (int i=1; i<=tot; i++) if (!deg[i]) q.push(i);
		while (!q.empty()) {
			int x=q.front(), f=link[x]; q.pop();
			if (!f) continue;
			rt[f]=seg::merge(rt[f], rt[x], 1, n);
			if (!--deg[f]) q.push(f);
		}
	}
	int a[N];
	inline void work() {
		int l=read(), r=read(), m, p=1, i=1;
		scanf("%s", str+1), m=strlen(str+1);
		while (true) {
			int c=max(0, str[i]-'a'+1); a[i]=-1;
			for (int j=c; j<26; j++) {
				int x=nxt[p][j];
				if (x && seg::query(rt[x], 1, n, l+i-1, r)) {a[i]=j; break;}
			}
			if (i==min(r-l+1, m+1) || !nxt[p][str[i]-'a']) break;
			p=nxt[p][str[i]-'a'], i++;
		}
		while (i && !~a[i]) i--;
		if (!i) {puts("-1"); return;}
		for (int j=1; j<i; j++) putchar(str[j]); putchar(a[i]+97), putchar(10);
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%s", str+1), n=strlen(str+1);
	for (int i=1; i<=n; i++) sam::insert(str[i]-'a', i);
	sam::init(), Q=read(); while (Q--) sam::work();
	return 0;
}