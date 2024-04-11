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

vvi gr;
vvi gri;
vi cnt;
ll sum = 0;
vl c;
vvi e;
int n, q;

void dfs(int v, int pr) {
    for (int i = 0; i < gr[v].size(); ++i) if (gr[v][i] != pr) {
        dfs(gr[v][i], v);
        cnt[v] += cnt[gr[v][i]];
        c[gri[v][i]] = (ll)cnt[gr[v][i]] * (n - cnt[gr[v][i]]);
        sum += e[gri[v][i]][2] * c[gri[v][i]];
//        sum[v] += sum[gr[v][i]];
//        sum0[v] += sum0[gr[v][i]] + e[gri[v][i]][2];
    }
//    sum[v] += sum0[v];
}

int main() {
    scanf("%d", &n);
    ll mul = 3;// * (n - 2);
    ll div = n*(ll)(n-1) / 2;
    cnt.assign(n, 1);
    c.assign(n-1, 0);
//    sum.assign(n, 0);
//    sum0.assign(n, 0);
    gr.resize(n);
    gri.resize(n);
    e.assign(n-1, vi(3));
    for (int i = 0; i < n-1; ++i) {
        int a,b,l;
        scanf("%d%d%d", &a, &b, &l);
        --a; --b;
        e[i][0] = a; e[i][1] = b; e[i][2] = l;
        gr[a].push_back(b);
        gr[b].push_back(a);
        gri[a].push_back(i);
        gri[b].push_back(i);
    }
    scanf("%d", &q);
    vi r(q), w(q);
    for (int i = 0; i < q; ++i) {
        scanf("%d%d", &r[i], &w[i]);
        --r[i];
//        swap(w[i], e[r[i]][2]);
    }
    dfs(0, -1);
//    vl res(q + 1);
//    res.back() = sum;
    for (int i = 0; i < q; ++i) {
        sum += (w[i] - e[r[i]][2]) * c[r[i]];
        e[r[i]][2] = w[i];
        printf("%.10lf\n", (double)(sum * mul) / div);
    }
    return 0;
}