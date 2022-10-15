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
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

vi pr, r;

int getp(int v) {
    if (v == pr[v])
        return v;
    return pr[v] = getp(pr[v]);
}

bool join(int a, int b) {
    a = getp(a);
    b = getp(b);
    if (a == b) return 0;
    if (r[a] > r[b]) swap(a, b);
    pr[a] = b;
    if (r[a] == r[b]) ++r[b];
    return 1;
}

vvi gr;
vvi dr;
vl was;

void dfs(int v, ll sum) {
    if (was[v] == -1) was[v] = sum;
    else return;
    for (int i = 0; i < gr[v].size(); ++i) {
        dfs(gr[v][i], sum+dr[v][i]);
    }
}

int main() {
    int n;
    cin >> n;
    pr.resize(n);
    gr.resize(n);
    dr.resize(n);
    for (int i = 0; i < n; ++i) pr[i] = i;
    r.assign(n, 0);
    vvi v(n, vi(n));
    vii ts;
    ts.reserve(n*n/2);
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
        scanf("%d", &v[i][j]);
        if (i == j && v[i][j]) {
            printf("NO\n");
            return 0;
        }
    }
    for (int i = 0; i < n; ++i) for (int j = i+1; j < n; ++j) {
        if (v[i][j] != v[j][i] || v[i][j] == 0) {
            printf("NO\n");
            return 0;
        }
        ts.push_back(pii(v[i][j], i*n+j));
    }
    sort(ts.begin(), ts.end());
    for (int it = 0; it < ts.size(); ++it) {
        int i = ts[it].second/n;
        int j = ts[it].second%n;
        if (join(i, j)) {
            gr[i].push_back(j);
            gr[j].push_back(i);
            dr[i].push_back(ts[it].first);
            dr[j].push_back(ts[it].first);
        }
    }
    for (int i = 0; i < n; ++i) {
        was.assign(n, -1);
        dfs(i, 0);
        for (int j = 0; j < n; ++j) if (v[i][j] != was[j]) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}