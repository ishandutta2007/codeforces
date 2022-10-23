#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int > 
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long
#define ld __float128
using namespace std;
const int N = 3e5 + 7, M = 1.2e7 + 7, mod = 998244353;
int n, m, p, q;
string s[N];
inline int P(int x, int y) {
	return (x - 1) * m + y;
}
int ehd[M], ev[M], ew[M], enx[M], eid;
void eadd(int u, int v, int w) {
	++eid, ev[eid] = v, ew[eid] = w, enx[eid] = ehd[u], ehd[u] = eid;
}
ll dis[N]; 
void bfs() {
	priority_queue < pair < ll, int > > q;
	me(dis, 0x3f);
	L(i, 1, n) L(j, 1, m) if(s[i][j] == '.') 
		dis[P(i, j)] = 0, q.push({0, P(i, j)});
	while(!q.empty()) {
		int u = q.top().second;
		q.pop();
		for(int i = ehd[u]; i; i = enx[i]) {
			int v = ev[i];
			if(dis[v] > dis[u] + ew[i]) dis[v] = dis[u] + ew[i], q.push({-dis[v], v});
		}
	}
}

ll ns = 1e18;
void calc(int x, int y) {
	ns = min(ns, dis[x] + dis[y]);
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	cin >> p >> q;
	L(i, 1, n) {
		cin >> s[i];
		s[i] = " " + s[i];
	}
	
	L(i, 1, n) {
		L(j, 1, m - 1) {
			if(s[i][j] == 'L' && s[i][j + 1] == 'R') {
				if(i > 1) eadd(P(i - 1, j), P(i, j + 1), p);
				if(i < n) eadd(P(i + 1, j), P(i, j + 1), p);
				if(i > 1) eadd(P(i - 1, j + 1), P(i, j), p);
				if(i < n) eadd(P(i + 1, j + 1), P(i, j), p);
				if(j < m - 1) eadd(P(i, j + 2), P(i, j), q);
				if(j > 1) eadd(P(i, j - 1), P(i, j + 1), q); 
			}
		}
	}
	
	L(i, 1, n - 1) {
		L(j, 1, m) {
			if(s[i][j] == 'U' && s[i + 1][j] == 'D') {
				if(j > 1) eadd(P(i, j - 1), P(i + 1, j), p);
				if(j < m) eadd(P(i, j + 1), P(i + 1, j), p);
				if(j > 1) eadd(P(i + 1, j - 1), P(i, j), p);
				if(j < m) eadd(P(i + 1, j + 1), P(i, j), p);
				if(i < n - 1) eadd(P(i + 2, j), P(i, j), q);
				if(i > 1) eadd(P(i - 1, j), P(i + 1, j), q); 
			}
		}
	}
	
	bfs();
	
	L(i, 1, n) {
		L(j, 1, m - 1) {
			calc(P(i, j), P(i, j + 1));
		}
	}
	L(i, 1, n - 1) {
		L(j, 1, m) {
			calc(P(i, j), P(i + 1, j));
		}
	}
	
	if(ns > 1e17) cout << -1 << '\n';
	else cout << ns << '\n';
	return 0;
}