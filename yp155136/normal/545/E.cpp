#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
ll dis[300005], wei[300005], res = 0;
bool in[300005];
int parent[300005];
priority_queue<pli, vector<pli>, greater<pli> > pq;
struct edge
{
	int to, index;
	ll cost;
	edge(int _to, int _index, ll _cost):
		to(_to), index(_index), cost(_cost) {};
};
vector<edge> adj[300005];
void dijkstra(int source)
{
	memset(parent, -1, sizeof(parent));
	fill(dis, dis + 300005, LONG_LONG_MAX);
	dis[source] = 0;
	pq.push(pli(0, source));
	while (!pq.empty()) {
		int ver = pq.top().second;
		ll d = pq.top().first;
		pq.pop();
		if (d != dis[ver])
			continue;
		for (int i = 0; i < adj[ver].size(); ++i) {
			int next = adj[ver][i].to, ind = adj[ver][i].index;
			ll nd = adj[ver][i].cost;
			if (d + nd <= dis[next]) {
				if (parent[next] != -1) {
					in[parent[next]] = false;
					res -= wei[parent[next]];
				}
				if (d + nd < dis[next]) {
					dis[next] = d + nd;
					pq.push(pli(dis[next], next));
				}
				parent[next] = ind;
				res += wei[ind];
				in[ind] = true;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int a, b; ll c;
	for (int i = 1; i <= m; ++i) {
		cin >> a >> b >> c;
		if (a > b)
			swap(a, b);
		adj[a].push_back(edge(b, i, c));
		adj[b].push_back(edge(a, i, c));
		wei[i] = c;
	}
	int source;
	cin >> source;
	dijkstra(source);
	cout << res << '\n';
	for (int i = 1; i <= m; ++i)
		if (in[i])
			cout << i << ' ';
	cout << '\n';
	return 0;
}