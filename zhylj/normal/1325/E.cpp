#include <bits/stdc++.h>

#define fi first
#define se second

typedef std::pair<int, int> pii;
typedef long long ll;

const int kN = 1e6 + 5;
const int kInf = 0x3f3f3f3f;

int n, sq_a, a[kN], p[kN], is_p[kN], sf[kN], max_a = 0, p_cnt = 0;
void Sieve() {
	memset(is_p, true, sizeof(is_p)); is_p[1] = true; sf[1] = 1;
	for(int i = 2; i <= max_a; ++i) {
		if(is_p[i]) { p[++p_cnt] = i; sf[i] = i; }
		for(int j = 1; j <= p_cnt && i * p[j] <= max_a; ++j) {
			is_p[i * p[j]] = false; sf[i * p[j]] = p[j];
			if(i % p[j] == 0) break;
		}
	}
}
struct Edge { int nxt, v; } E[kN];
int head[kN], d[kN], ans = kInf, cnt = 0; bool vis[kN];
void AddEdge(int u, int v) {
	E[cnt] = (Edge) {head[u], v}; head[u] = cnt++;
	E[cnt] = (Edge) {head[v], u}; head[v] = cnt++;
}
std::queue<pii> que;
void Bfs(int st) {
	memset(vis, false, sizeof(vis));
	que.push(std::make_pair(st, -1));
	vis[st] = true; d[st] = 0;
	while(!que.empty()) {
		int cur = que.front().fi, fa = que.front().se; que.pop();
		//printf("Cur : %d\n", cur);
		//if(d[cur] > ans) return;
		for(int i = head[cur]; ~i; i = E[i].nxt) if((i ^ 1) != fa) {
			int v = E[i].v;
			//printf("%d %d %d\n", i ^ 1, fa, v);
			if(vis[v]) ans = std::min(ans, d[cur] + d[v] + 1);
			else vis[v] = true, d[v] = d[cur] + 1, que.push(std::make_pair(v, i));
		}
	}
}

int main() {
	memset(head, 0xff, sizeof(head));
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", a + i), max_a = std::max(max_a, a[i]);
	sq_a = sqrt(max_a) + 5; Sieve();
	for(int i = 1; i <= n; ++i) {
		int x = a[i]; std::vector<int> ft;
		while(x != 1) {
			while(x != 1 && x % ((ll)sf[x] * sf[x]) == 0) x /= sf[x] * sf[x];
			if(x != 1) ft.push_back(sf[x]), x /= sf[x];
		}
		if(!ft.size()) { printf("1"); return 0; }
		else if(ft.size() == 1) AddEdge(1, ft[0]);
		else AddEdge(ft[0], ft[1]);
	}
	Bfs(1);
	for(int i = 1; p[i] <= sq_a && i <= p_cnt; ++i) Bfs(p[i]);
	printf("%d", ans == kInf ? -1 : ans);
	return 0;
}