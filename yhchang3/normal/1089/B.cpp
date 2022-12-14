#include <iostream>
#include <cstring>
#include <utility>
#include <vector>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <complex>
#include <array>
#include <ctime>
#include <cassert>
#include <set>
#include <iomanip>
#include <random>
#include <cstdlib>
#include <chrono>

using namespace std;

const int maxn = 500;
vector<int> e[maxn];
int p[maxn], mat[maxn], rt[maxn], vis[maxn], stp[maxn], n, t;
int lca(int u, int v) {
    for (t++;;swap(u, v)) {
        if (u == 0) continue; if(stp[u] == t) return u;
        stp[u] = t, u = rt[p[mat[u]]];
    }
}
#define qpush(u) q.push(u), vis[u] = 0
void fl(int u, int v, int l, queue<int>& q) {
    while (rt[u] != l) {
        p[u] = v;
        if (vis[v = mat[u]] == 1) qpush(v);
        rt[u] = rt[v] = l;
        u = p[v];
    }
}
bool bfs(int u) {
    for (int i = 1; i <= n; i++) rt[i] = i;
    memset(vis, -1, sizeof vis);
    queue<int> q;
    qpush(u);
    while (!q.empty()) {
        u = q.front(); q.pop();
        for (int v: e[u]) {
            if (vis[v] == -1) {
                p[v] = u;
                vis[v] = 1;
                if (!mat[v]) {
                    for (int tmp; u; v = tmp, u = p[v]) {
                        tmp = mat[u];
                        mat[mat[u] = v] = u;
                    }
                    return true;
                }
                qpush(mat[v]);
            } else if (vis[v] == 0 && rt[u] != rt[v]) {
                int l = lca(rt[v], rt[u]);
                fl(v, u, l, q);
                fl(u, v, l, q);
            }
        }
    }
    return false;
}
#undef qpush
int blossom() {
    memset(p, 0, sizeof p);
    memset(mat, 0, sizeof mat);
    memset(rt, 0, sizeof rt);
    memset(vis, 0, sizeof vis);
    memset(stp, 0, sizeof stp);
    t = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!mat[i] && bfs(i)) ans++;
    }
    return ans;
}

void con(int a, int b) {
//    cout << a << " " << b << "\n";
    e[a].push_back(b);
    e[b].push_back(a);
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while (T--) {
        for (int i = 0; i < maxn; i++) e[i].clear();
        int qn, qm; cin >> qn >> qm;
        string s;
        n = qn + qn + qm;
        for (int i = 1; i <= qn; i++) {
            cin >> s;
            for (int j = 1; j <= qm; j++) {
                if (s[j - 1] == '1') {
                    con(i << 1, qn + qn + j);
                    con((i << 1) - 1, qn + qn + j);
                }
            }
            con (i << 1, (i << 1) - 1);
        }
        cout << blossom() - qn << "\n";
    }

}