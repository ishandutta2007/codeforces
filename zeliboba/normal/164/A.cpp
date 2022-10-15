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
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

vvi gr, gr1;
vi was, was1;
vi f;

void dfs(int v, int in) {
    if (!in && f[v] == 1)
        return;
    if (was[v] == 0) {
        was[v] = 1;
        for (int i = 0; i < gr[v].size(); ++i)
            dfs(gr[v][i], 0);
    }
}

void dfs1(int v) {
    if (was1[v] == 0) {
        was1[v] = 1;
        if (f[v] == 1)
            return;
        for (int i = 0; i < gr1[v].size(); ++i)
            dfs1(gr1[v][i]);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    f.resize(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &f[i]);
    gr.resize(n);
    was.assign(n, 0);
    gr1.resize(n);
    was1.assign(n, 0);
    for (int i = 0; i < m; ++i) {
        int a,b;
        scanf("%d%d", &a, &b);
        gr[a - 1].push_back(b - 1);
        gr1[b - 1].push_back(a - 1);
    }
    for (int i = 0; i < n; ++i) if (f[i] == 1)
        dfs(i, 1);
    for (int i = 0; i < n; ++i) if (f[i] == 2)
        dfs1(i);
    for (int i = 0; i < n; ++i) {
//        cerr << was[i] << " " << was1[i] << endl;
        if (was[i] && was1[i])
            printf("1\n");
        else printf("0\n");
    }
    return 0;
}