#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;

typedef long long int64;

struct Point {
	int x, y;
	Point() {
	}
	Point(int _x, int _y) :
			x(_x), y(_y) {
	}
	Point operator+(const Point&p) const {
		return Point(x + p.x, y + p.y);
	}
	Point operator-(const Point&p) const {
		return Point(x - p.x, y - p.y);
	}
	int64 det(const Point&p) const {
		return 1LL * x * p.y - 1LL * y * p.x;
	}
	void read() {
		scanf("%d%d", &x, &y);
	}
	bool operator<(const Point&p) const {
		int t = part() - p.part();
		if (t != 0)
			return t == -1;
		return det(p) > 0;
	}
	int part() const { //lower->0,upper->1
		if (x < 0 || (x == 0 && y < 0))
			return 0;
		else
			return 1;
	}
};

#define cross(p1,p2,p3) ((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y))

const int MAX_N = 100000 + 10;
Point ps[MAX_N];
int n, m;

struct Edge {
	Edge*nxt, *rev;
	int flow, t;
	Edge(int t, Edge*nxt) :
			t(t), nxt(nxt) {
		flow = 0;
	}
};
Edge*first[MAX_N] = { };
void addEdge(int u, int v) {
	Edge*uv = first[u] = new Edge(v, first[u]);
	Edge*vu = first[v] = new Edge(u, first[v]);
	uv->rev = vu, vu->rev = uv;
}

bool vis[MAX_N];
int dfs(int u) {
	vis[u] = true;
	int cnt = 0;
	for (Edge*e = first[u]; e; e = e->nxt)
		if (!vis[e->t]) {
			int me = dfs(e->t) + 1;
			e->flow = me;
			e->rev->flow = -me;
			cnt += me;
		}
	return cnt;
}

vector<int> sum[MAX_N];
vector<Point> lst[MAX_N];
int deg[MAX_N];

int get(int me, int o) {
	vector<Point>&p = lst[me];
	Point q = ps[o] - ps[me];
	return lower_bound(p.begin(), p.end(), q) - p.begin();
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u, --v;
		addEdge(u, v);
	}
	for (int i = 0; i < n; ++i) {
		ps[i].read();
	}

	int sink = 0;
	for (int i = 0; i < n; ++i) {
		if (ps[i].x < ps[sink].x)
			sink = i;
	}

	dfs(sink);

	for (int i = 0; i < n; ++i) {
		static pair<Point, int> buf[MAX_N];
		int cnt = 0;
		for (Edge*e = first[i]; e; e = e->nxt)
			buf[cnt++] = make_pair(ps[e->t] - ps[i], e->flow);
		deg[i] = cnt;
		sort(buf, buf + cnt);
		sum[i].assign(cnt + 1, 0);
		lst[i].resize(cnt, Point());
		for (int j = 0; j < cnt; ++j) {
			sum[i][j + 1] = sum[i][j] + buf[j].second;
			lst[i][j] = buf[j].first;
		}
	}

	int nQ;
	cin >> nQ;
	for (int i = 0; i < nQ; ++i) {
		int k;
		scanf("%d", &k);
		static int a[MAX_N];
		for (int j = 1; j <= k; ++j) {
			scanf("%d", a + j);
			--a[j];
		}
		a[k + 1] = a[1];
		a[0] = a[k];
		int64 area = 0;
		for (int j = 1; j <= k; ++j) {
			area += ps[a[j]].det(ps[a[j + 1]]);
		}
		if (area < 0) {
			reverse(a, a + k + 2);
		}
		int ans = k;
		for (int j = 1; j <= k; ++j) {
			int me = a[j];
			int x = get(me, a[j - 1]);
			int y = get(me, a[j + 1]);
			if (x >= y)
				ans += sum[me][x] - sum[me][y + 1];
			else
				ans += sum[me][deg[me]] - sum[me][y + 1] + sum[me][x];

		}
		cout << ans << endl;
	}
	return 0;
}