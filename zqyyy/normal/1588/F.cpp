#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
const int N=2e5+7, B=sqrt(2e5);
int n, Q, p[N];
struct Block {
	ll v1[N], v2[N/B+7];
	inline void add(int i, ll x) {v1[i]+=x, v2[(i-1)/B+1]+=x;}
	inline ll ask(int p) {
		if (!p) return 0;
		ll res=0; int b=(p-1)/B+1;
		for (int i=1; i<b; i++) res+=v2[i];
		for (int i=(b-1)*B+1; i<=p; i++) res+=v1[i];
		return res;
	}
	inline ll query(int l, int r) {return ask(r)-ask(l-1);}
}ds;
struct Query {
	int opt, x, y;
} q[B+7];
int pa[N], sz[N]; bool fl[N];
int find(int x) {return pa[x]^x?pa[x]=find(pa[x]):x;}
inline void unin(int x, int y) {x=find(x), y=find(y); if (x!=y) pa[x]=y; else fl[x]=true;}
ll w[N];
vector<int> vec[N];
int tot, id[B+N/B+7], num[N], cnt[B+N/B+7][B+7], e[N];
bool vis[N];
struct node {
	int opt, l, id;
	bool operator <(const node &q) const {return l<q.l;}
} eve[B+B+7];
int tl;
inline void work(int Q) {
	for (int i=1; i<=n; i++) pa[i]=i, fl[i]=false, sz[i]=0, vec[i].clear();
	tl=0;
	for (int i=1; i<=Q; i++)
		if (q[i].opt==3) vis[q[i].x]=vis[q[i].y]=true;
		else if (q[i].opt==1) eve[++tl]={-1, q[i].x-1, i}, eve[++tl]={1, q[i].y, i};
	for (int i=1; i<=n; i++) if (!vis[i]) unin(i, p[i]);
	for (int i=1; i<=n; i++) sz[find(i)]++, vec[pa[i]].push_back(i);
	for (int i=1; i<=Q; i++)
		if (q[i].opt==3) e[pa[q[i].x]]=q[i].x, e[pa[q[i].y]]=q[i].y;
	tot=0;
	for (int i=1; i<=n; i++)
		if (pa[i]==i && (!fl[i] || sz[i]>B)) id[++tot]=i;
	for (int i=1; i<=tot; i++)
		for (int j=1; j<=Q; j++) cnt[i][j]=0;
	sort (eve+1, eve+tl+1);
	for (int i=1; i<=tot; i++) {
		int j=0, Num=0;
		for (int x:vec[id[i]]) {
			while (j<tl && eve[j+1].l<x) j++, cnt[i][eve[j].id]+=eve[j].opt*Num;
			Num++;
		}
		while (j<tl) j++, cnt[i][eve[j].id]+=eve[j].opt*Num;
	}
	for (int i=1; i<=Q; i++) {
		if (q[i].opt==1) {
			ll res=ds.query(q[i].x, q[i].y);
			for (int j=1; j<=tot; j++) res+=w[id[j]]*cnt[j][i];
			printf("%lld\n", res);
		} else if (q[i].opt==2) {
			int x=find(q[i].x), v=q[i].y;
			if (fl[x]) {
				if (sz[x]<=B) for (int y:vec[x]) ds.add(y, v);
				else w[x]+=v;
				continue;
			}
			w[x]+=v; int y=pa[p[e[x]]];
			while (x^y) w[y]+=v, y=pa[p[e[y]]];
		} else swap(p[q[i].x], p[q[i].y]);	
	}
	for (int i=1; i<=tot; i++) {
		int p=id[i];
		for (int x:vec[p]) ds.add(x, w[p]);
		w[p]=0;
	}
	for (int i=1; i<=Q; i++)
		if (q[i].opt==3) vis[q[i].x]=vis[q[i].y]=false;
}
int main() {
#ifdef LOCAL
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	n=read();
	for (int i=1; i<=n; i++) ds.add(i, read());
	for (int i=1; i<=n; i++) p[i]=read();
	Q=read(); int m=0;
	while (Q) {
		m++, q[m].opt=read(), q[m].x=read(), q[m].y=read();
		if (m==min(Q, B)) Q-=m, work(m), m=0;
	}
	return 0;
}