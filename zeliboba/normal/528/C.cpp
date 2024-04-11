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
#include <stack>
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

vi euler(const vii & edges, int n) {
	vector < vector<int> > gr (n);
	vector < vector<int> > gre (n);
    vi t(4);
    for (int i = 0; i < edges.size(); ++i) {
        int a = edges[i].first, b = edges[i].second;
        gr[a].push_back(b);
        gr[b].push_back(a);
        gre[a].push_back(i);
        gre[b].push_back(i);
    }
	int first = 0;
	stack<int> st;
	st.push (first);
	vi res;
    vi used(edges.size());
    vi it(n);
	while (!st.empty())
	{
		int v = st.top();
		for (; it[v] < gr[v].size(); ++it[v])
			if (used[gre[v][it[v]]] == 0)
				break;
		if (it[v] == gr[v].size())
		{
			res.push_back (v);
			st.pop();
		}
		else
		{
            used[gre[v][it[v]]] = 1;
			st.push (gr[v][it[v]]);
		}
	}
    return res;
}

int main() {
	int n, m;
    scanf("%d%d", &n, &m);
    vii edges(m);
    vi deg(n);
    for (int i = 0; i < m; ++i) {
        int a,b;
        scanf("%d%d", &a, &b);
        --a; --b;
        edges[i] = pii(a, b);
        ++deg[a]; ++deg[b];
    }
    int prev = -1;
    for (int i = 0; i < n; ++i) if (deg[i] % 2) {
        if (prev == -1) prev = i;
        else {
            ++deg[i];
            ++deg[prev];
            edges.push_back(pii(i, prev));
            prev = -1;
            ++m;
        }
    }
    if (m % 2) {
        edges.push_back(pii(0,0));
        ++m;
    }
    vi res = euler(edges, n);
    printf ("%d\n", (int)res.size() - 1);
    for (size_t i=0; i+1<res.size(); ++i) {
        if (i % 2) printf ("%d %d\n", res[i]+1, res[i+1] + 1);
        else printf ("%d %d\n", res[i+1]+1, res[i] + 1);
    }
    return 0;
}