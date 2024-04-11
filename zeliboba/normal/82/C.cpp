#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef vector<pii> vii;
vi order;
vector<int> next(5000);
vector<int> was(5000);
vector<int> cap(5000);
vi a(5000);
vector<vector<pii> > gr(5000);
int n;

void dfs (int v, int pr) {
    if (!was[v]) {
        next[v] = pr;
        was[v] = 1;
        for (int i = 0; i < gr[v].size(); ++i) {
            if (gr[v][i].first == pr)
                cap[v] = gr[v][i].second;
            dfs(gr[v][i].first, v);
        }
        order.push_back(v);
    }
}

vi rmerge (const vi & x, const vi & y) {
    int itx = 0, ity = (int)y.size() - 1;
    vi res;
    while (itx < x.size() && ity >= 0) {
        if (a[x[itx]] > a[y[ity]]) {
            res.push_back(x[itx]);
            ++itx;
        } else {
            res.push_back(y[ity]);
            --ity;
        }
    }
    for (;itx < x.size(); ++itx)
        res.push_back(x[itx]);
    for (;ity >= 0; --ity)
        res.push_back(y[ity]);
    return res;
}

void out (const vi & v) {
    for (int i = 0; i < v.size(); ++i)
        printf("%d-%d ", v[i], a[v[i]]);
    printf("\n");
}

int main() {
    cin >> n;
    map<int, int> inv;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        inv[a[i]] = i;
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        gr[a - 1].push_back(pii(b - 1, c));
        gr[b - 1].push_back(pii(a - 1, c));
    }
    dfs(0, 0);
    vi res(n, 0);
    vector<vi> q(n);
    for (int i = 1; i < n; ++i)
        q[i].push_back(-a[i]);
    int time = 0;
    while (true) {
//        vector<vi> toadd(n);
        bool go = false;
        for (int i1 = n - 2; i1 >= 0; --i1) {
            int i = order[i1];
            if (!q[i].empty()) {
                go = 1;
                int lim = min(cap[i], (int)q[i].size());
                for (int t = 0; t < lim; ++t) {
                    q[next[i]].push_back(q[i].back());
                    q[i].pop_back();
                }
            }
        }
        if (!go)
            break;
        for (int it = 0; it < q[0].size(); ++it) {
            res[inv[-q[0][it]]] = time + 1;
        }
        q[0].resize(0);
        for (int i = 1; i < n; ++i) {
//            if (!toadd[i].empty()) {
//            for (int it = toadd[i].size() - 1; it >= 0; --it) {
//                q[i].push_back(toadd[i][it]);
//            }
            sort(q[i].begin(), q[i].end());
        }
        ++time;
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", res[i]);
    }
    printf("\n");
    return 0;
}