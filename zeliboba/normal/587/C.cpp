#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

const int N = 17;
vvi gr;
vi lc[N][100001];

vector<int> tin, tout;
int timer;
vector < vector<int> > up;

void dfs (int v, int p = 0) {
	tin[v] = ++timer;
	up[v][0] = p;
	for (int i=1; i < N; ++i)
		up[v][i] = up[up[v][i-1]][i-1];
	for (size_t i=0; i<gr[v].size(); ++i) {
		int to = gr[v][i];
		if (to != p)
			dfs (to, v);
	}
	tout[v] = ++timer;
}

bool upper (int a, int b) {
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}

vi f(const vi & a, const vi & b) {
    vi v;
    int it = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (it >= b.size() || a[i] <= b[it]) {
            v.push_back(a[i]);
        } else {
            v.push_back(b[it]);
            ++it;
            --i;
        }
    }
    for (; it < b.size(); ++it) v.push_back(b[it]);
    v.resize(unique(v.begin(), v.end()) - v.begin());
    v.resize(min(10, (int)v.size()));
    return v;
}

int lca (int a, int b) {
	if (upper (a, b))  return a;
	if (upper (b, a))  return b;
	for (int i = N-1; i>=0; --i)
		if (! upper (up[a][i], b))
			a = up[a][i];
	return up[a][0];
}

vi g(int a, int b) {
    vi v;
    for (int i = N - 1; i >= 0; --i) {
        if (! upper (up[a][i], b)) {
            v = f(v, lc[i][a]);
//            cerr << i << ' ' << a << ' ' << v.size() << endl;
			a = up[a][i];
        }
    }
    v = f(v, lc[0][b]);
    v = f(v, lc[0][a]);
//    cerr << b << ' ' << lc[0][b].size() << ' ' << v.size() << endl;
    return v;
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    gr.resize(n);
    tin.resize(n);
    tout.resize(n);
    up.resize(n);
    for (int i=0; i<n; ++i)  up[i].resize (N);
    for (int i = 0; i < n-1; ++i) {
        int u,v;
        scanf("%d%d", &u, &v);
        --u; --v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    vi c(m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &c[i]);
        --c[i];
        lc[0][c[i]].push_back(i+1);
    }
    dfs(0);
    for (int i = 0; i < n; ++i) {
        sort(lc[0][i].begin(), lc[0][i].end());
        lc[0][i].resize(min(10, (int)lc[0][i].size()));
//        cerr << lc[0][i].size() << endl;
    }
    for (int i = 1; i < N; ++i) for (int v = 0; v < n; ++v) {
        lc[i][v] = f(lc[i-1][v], lc[i-1][up[v][i-1]]);
//        cerr << i << ' ' << v << ' ' << lc[i][v].size() << endl;
    }
    for (int qq = 0; qq < q; ++qq) {
        int a,b,l;
        scanf("%d%d%d", &a, &b, &l);
        --a; --b;
        int c = lca(a, b);
//        cerr << a << ' ' << b << ' ' << c << endl;
        vi res = f(g(a, c), g(b, c));
//        cerr << res.size() << ' ' << g(a, c).size() << ' ' << g(b, c).size() << endl;
        res.resize(min(l, (int)res.size()));
        printf("%d ", (int)res.size());
        for (int i = 0; i < res.size(); ++i) printf("%d ", res[i]);
        printf("\n");
    }
    return 0;
}