#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 8e5 + 7;
int n, m;
ll dis[N];
int head[N], edge_id;
struct edge {
	int to, next, val;
} e[N << 3];
void add_edge(int u, int v, int val) {
	++edge_id, e[edge_id].to = v, e[edge_id].val = val, e[edge_id].next = head[u], head[u] = edge_id;
} 
void ad(int u, int v, int w) {
	add_edge(u, v + n, 0), add_edge(u + n * 2, v + n * 3, 0); //  max		 
	add_edge(u, v + n * 2, w * 2), add_edge(u + n, v + n * 3, w * 2); //  min	
	add_edge(u, v + n * 3, w); //  min, max
	add_edge(u, v, w), add_edge(u + n, v + n, w), add_edge(u + n * 2, v + n * 2, w), add_edge(u + n * 3, v + n * 3, w);
}
priority_queue< pair<ll, int> > q;
int flag[N]; 
void dijkstra() {
	memset(dis, 0x3f, sizeof(dis));
	dis[1] = 0;
	q.push(mkp(0, 1));
	while(!q.empty()) {
		int u = q.top().second;
		q.pop();
		if(flag[u]) continue;
		flag[u] = 1;
		for(int i = head[u]; i; i = e[i].next) {
			int v = e[i].to;
			if(dis[v] > dis[u] + e[i].val) {
				dis[v] = dis[u] + e[i].val;
				q.push(mkp(-dis[v], v));
			}
		}
	}
}
// n : max; 2 * n : min; 3 * n : max, min 
void Main() {
	cin >> n >> m;
	L(i, 1, m) {
		int u, v, w; cin >> u >> v >> w;
		ad(u, v, w), ad(v, u, w);
	}
	dijkstra();
	L(i, 2, n) cout << dis[i + n * 3] << " ";
	cout << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	Main();
	return 0;
}