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

vi pr,r,path,d,ans;
vvi gr;

int getp(int v) {
    if (pr[v] == v) return v;
    return pr[v] = getp(pr[v]);
}

void join(int a0, int b0) {
    int a = getp(a0);
    int b = getp(b0);
    if (a == b) return;
    if (r[a] > r[b]) swap(a, b);
    pr[a] = b;
    if (r[a] == r[b]) ++r[b];
}

int bfs(int v0) {
    vi q(1, v0);
    d[v0] = 0;
    path[v0] = -1;
    for (int it = 0; it < q.size(); ++it) {
        int v = q[it];
        for (int i = 0; i < gr[v].size(); ++i) if (gr[v][i] != path[v]) {
            q.push_back(gr[v][i]);
            path[gr[v][i]] = v;
            d[gr[v][i]] = d[v] + 1;
        }
    }
    return q.back();
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    pr.resize(n);
    d.resize(n);
    ans.assign(n, 0);
    path.resize(n);
    gr.resize(n);
    r.assign(n, 0);
    for (int i = 0; i < n; ++i) pr[i] = i;
    for (int i = 0; i < m; ++i) {
        int a,b;
        scanf("%d%d",&a,&b);
        --a; --b;
        gr[a].push_back(b);
        gr[b].push_back(a);
        join(a, b);
    }
    //vi mid(n);
    for (int i = 0; i < n; ++i) if (pr[i] == i) {
        int t = bfs(i);
        int t1 = bfs(t);
        ans[i] = d[t1];
        //mid[i] = t1;
        //for (int j = 0; j < d[t1]/2; ++j) mid[i] = path[mid[i]];
    }
    for (int t = 0; t < q; ++t) {
        int type,x,y;
        scanf("%d%d",&type, &x);
        --x;
        if (type == 2) {
            scanf("%d", &y);
            --y;
            x = getp(x);
            y = getp(y);
            if (x == y) continue;
            join(x, y);
            if (pr[x] != x) swap(x, y);
            //if (ans[y] > ans[x]) mid[x] = mid[y];
            ans[x] = max(max(ans[y], ans[x]), 1 + (ans[x] + 1) / 2 + (ans[y] + 1) / 2);
        } else {
            printf("%d\n", ans[getp(x)]);
        }
    }
    return 0;
}