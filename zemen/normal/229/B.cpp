#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define INF __INT_MAX__

vector <pair <int, int> > g[100001];
vector <pair <int, int> > bad[100001];
int d[100001];

int main() {
	int n, m, u, v, w;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &u, &v, &w);
		--u;
		--v;
		g[u].pb(mp(v, w));
		g[v].pb(mp(u, w));
	}
	for (int i = 0; i < n; ++i) {
		int k;
		scanf("%d", &k);
		int prev = -2, last = -2;
		for (int j = 0; j < k; ++j) {
			scanf("%d", &w);
			if (w - 1 == last) {
				last = w;
				continue;
			}
			bad[i].pb(mp(prev, last + 1));
			prev = last = w;
		}
		bad[i].pb(mp(prev, last + 1));
	}
	d[0] = 0;
	if (bad[0].size() > 1 && bad[0][1].first == 0)
		d[0] = bad[0][1].second;
	for (int i = 1; i < n; ++i)
		d[i] = INF;
	set <pair <int, int> > o;
	for (int i = 0; i < n; ++i)
		o.insert(mp(d[i], i));
	while (o.size()) {
		u = o.begin()->second;
		//printf("%d\n", u);
		o.erase(mp(d[u], u));
		if (d[u] == INF) {
			printf("-1");
			return 0;
		}
		for (int i = 0; i < (int) g[u].size(); ++i) {
			v = g[u][i].first;
			w = g[u][i].second;
			if (d[v] > d[u] + w) {
				o.erase(mp(d[v], v));
				d[v] = d[u] + w;
				int cur = upper_bound(bad[v].begin(), bad[v].end(), mp(d[v], d[v])) - bad[v].begin();
				if (v != n - 1 && cur != (int) bad[v].size() && bad[v][cur].first <= d[v] && bad[v][cur].second > d[v])
					d[v] = bad[v][cur].second;
				else if (v != n - 1 && cur != 0 && bad[v][cur - 1].first <= d[v] && bad[v][cur - 1].second > d[v])
					d[v] = bad[v][cur - 1].second;
				o.insert(mp(d[v], v));
			}
		}
		if (u == n - 1)
			break;
	}
	printf("%d", d[n - 1]);
}