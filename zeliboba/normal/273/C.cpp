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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

vi col;
vvi gr;

void dfs(int v) {
//    cerr << v << ' ' << gr.size() << endl;
    int cnt = 0;
    for (int i = 0; i < gr[v].size(); ++i)
        if (col[gr[v][i]] == col[v])
            ++cnt;
    if (cnt > 1) {
        col[v] = 1 - col[v];
        for (int i = 0; i < gr[v].size(); ++i)
            dfs(gr[v][i]);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    gr.resize(n);
    col.assign(n, 0);
    for (int i = 0; i < m; ++i) {
        int a,b;
        scanf("%d%d", &a, &b);
        --a; --b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
//    cerr << gr.size() << endl;
    for (int i = 0; i < gr.size(); ++i) {
//        cerr << i << endl;
        dfs(i);
    }
    for (int i = 0; i < n; ++i)
        printf("%d", col[i]);
    return 0;
}