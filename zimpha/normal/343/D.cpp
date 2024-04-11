#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)
using namespace std;
const int MAXN=500000+10;

vector<int> G[MAXN];
int f[MAXN];
int C[MAXN<<2], tag[MAXN<<2];
int st[MAXN], ed[MAXN];
int n, cnt;

void dfs(int u, int ff) {
	st[u]=++cnt; f[u]=ff;
	for (int i=0; i<(int)G[u].size(); i++) {
		if (G[u][i]!=ff) dfs(G[u][i], u);
	}
	ed[u]=cnt;
}

inline void pushdown(int rt) {
	tag[lson]=tag[rson]=tag[rt];
	C[lson]=C[rson]=tag[rt];
	tag[rt]=-1;
}

void modify1(int rt, int l, int r, int ll, int rr) {
	if (ll<=l && rr>=r) {
		tag[rt]=1; C[rt]=1;
		return;
	}
	if (tag[rt]!=-1) pushdown(rt);
	if (ll<=mid) modify1(lson, l, mid, ll, rr);
	if (rr>mid) modify1(rson, mid+1, r, ll, rr);
	C[rt]=C[lson] & C[rson];
}

void modify2(int rt, int l, int r, int p) {
	if (l==r) {C[rt]=0; return;}
	if (tag[rt]!=-1) pushdown(rt);
	if (p<=mid) modify2(lson, l, mid, p);
	else modify2(rson, mid+1, r, p);
	C[rt]=C[lson] & C[rson];
}

int query(int rt, int l, int r, int ll, int rr) {
	if (ll<=l && rr>=r) return C[rt];
	if (tag[rt]!=-1) pushdown(rt);
	int ret=1;
	if (ll<=mid) ret&=query(lson, l, mid, ll, rr);
	if (rr>mid) ret&=query(rson, mid+1, r, ll, rr);
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i=1; i<=n; i++) G[i].clear();
	for (int i=1, a, b; i<n; i++) {
		scanf("%d%d", &a, &b);
		G[a].push_back(b); G[b].push_back(a);
	}
	cnt=0; dfs(1, 0);
	memset(C, 0, sizeof(C));
	memset(tag, -1, sizeof(tag));
	int q; scanf("%d", &q);
	while (q--) {
		int c, v; scanf("%d%d", &c, &v);
		if (c==3) printf("%d\n", query(1, 1, cnt, st[v], ed[v]));
		else if (c==1) {
			if (!query(1, 1, cnt, st[v], ed[v])) {
				if (f[v]) modify2(1, 1, cnt, st[f[v]]);
			}
			modify1(1, 1, cnt, st[v], ed[v]);
		}
		else if (c==2) modify2(1, 1, cnt, st[v]);
	}
	return 0;
}