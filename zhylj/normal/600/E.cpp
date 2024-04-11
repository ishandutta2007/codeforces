#include <bits/stdc++.h>

typedef long long ll;

const int kMaxN = 2e5 + 5;

struct Edge {
	int to, nxt;
} edges[kMaxN];
int head[kMaxN], siz[kMaxN], hvy[kMaxN], tot[kMaxN], fa[kMaxN], n, cnt = 0;
ll ans[kMaxN], c[kMaxN];
void AddEdge(int u, int v) { edges[cnt] = (Edge) {v, head[u]}; head[u] = cnt++; }
void GetHvy(int cur) {
	siz[cur] = 1;
	for(int i = head[cur]; ~i; i = edges[i].nxt)
		if(edges[i].to != fa[cur]) {
			fa[edges[i].to] = cur; GetHvy(edges[i].to); siz[cur] += siz[edges[i].to];
			if(siz[edges[i].to] > siz[hvy[cur]]) hvy[cur] = edges[i].to;
		}
}
void Clear(int cur) {
	tot[c[cur]] = 0;
	for(int i = head[cur]; ~i; i = edges[i].nxt)
		if(edges[i].to != fa[cur]) Clear(edges[i].to);
}
void Cal(int cur, int& maxn, ll& tmp_ans) {
	int v = ++tot[c[cur]];
	if(v > maxn) tmp_ans = c[cur], maxn = tot[c[cur]];
	else if(v == maxn) tmp_ans += c[cur];
	for(int i = head[cur]; ~i; i = edges[i].nxt)
		if(edges[i].to != fa[cur]) Cal(edges[i].to, maxn, tmp_ans);
}
int GetAns(int cur) {
	for(int i = head[cur]; ~i; i = edges[i].nxt)
		if(edges[i].to != fa[cur] && edges[i].to != hvy[cur])
			{ GetAns(edges[i].to); Clear(edges[i].to); }
	int maxn = 0;
	if(hvy[cur]) { maxn = GetAns(hvy[cur]); ans[cur] = ans[hvy[cur]]; }
	for(int i = head[cur]; ~i; i = edges[i].nxt)
		if(edges[i].to != fa[cur] && edges[i].to != hvy[cur])
			Cal(edges[i].to, maxn, ans[cur]);
	int v = ++tot[c[cur]];
	if(v > maxn) ans[cur] = c[cur], maxn = tot[c[cur]];
	else if(v == maxn) ans[cur] += c[cur];
	return maxn;
}

int main() {
	memset(head, 0xff, sizeof(head));
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%lld", c + i);
	for(int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		AddEdge(u, v); AddEdge(v, u);
	}
	GetHvy(1); GetAns(1);
	for(int i = 1; i <= n; ++i)
		printf("%lld ", ans[i]);
	return 0;
}