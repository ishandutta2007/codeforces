#include <cstdio>
#include <cstdlib>
#include <cassert>
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
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

vvi gr;
vi col;
vi p(2);

void dfs (int v, int t) {
    if (col[v] == -1) {
        col[v] = t;
        p[t]++;
        for (int i = 0; i < gr[v].size(); ++i)
            dfs(gr[v][i], 1 - t);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    gr.resize(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a; --b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    col.assign(n, -1);
    for (int i = 0; i < n; ++i)
        dfs(i, 0);
    vi res(n);
    int curk = 1;
    if (p[0] % 3) {
        if (p[0] % 3 != 1) {
            swap(p[0], p[1]);
            for (int i = 0; i < n; ++i)
                col[i] = 1 - col[i];
        }
        int ok = 0, good = 0;
        for (int i = 0; i < n; ++i) if (col[i] == 0 && gr[i].size() + 2 <= p[1]) {
            ok = 1;
            good = i;
            break;
        }
        if (!ok) {
            vi g(2);
            int cg = 0;
            for (int i = 0; i < n; ++i) if (col[i] == 1 && gr[i].size() + 2 <= p[0]) {
                g[cg] = i;
                ++cg;
                if (cg == 2)
                    break;
            }
            if (cg < 2) {
                cout << "NO\n";
                return 0;
            }
//            cerr << g[0] << " " << g[1] << endl;
            res[g[0]] = 1;
            res[g[1]] = 2;
            int cnt = 0;
            vi bad(n);
            for (int i = 0; i < gr[g[0]].size(); ++i)
                bad[gr[g[0]][i]] = 1;
            for (int i = 0; i < n; ++i) if (col[i] == 0 && !bad[i]) {
                res[i] = 1;
                ++cnt;
                if (cnt >= 2)
                    break;
            }
            cnt = 0;
            bad.assign(n, 0);
            for (int i = 0; i < gr[g[1]].size(); ++i)
                bad[gr[g[1]][i]] = 1;
            for (int i = 0; i < n; ++i) if (col[i] == 0 && !bad[i]) {
                res[i] = 2;
                ++cnt;
                if (cnt >= 2)
                    break;
            }
            curk = 3;
        } else {
            res[good] = 1;
            int cnt = 0;
            vi bad(n);
            for (int i = 0; i < gr[good].size(); ++i)
                bad[gr[good][i]] = 1;
            for (int i = 0; i < n; ++i) if (col[i] && !bad[i]) {
                res[i] = 1;
                ++cnt;
                if (cnt >= 2)
                    break;
            }
            curk = 2;
        }
    }
//    cerr << curk << endl;
    int cnt = 0;
    for (int i = 0; i < n; ++i) if (col[i] == 0 && res[i] == 0) {
        res[i] = curk;
        ++cnt;
        if (cnt == 3) {
            ++curk;
            cnt = 0;
        }
    }
    for (int i = 0; i < n; ++i) if (col[i] == 1 && res[i] == 0) {
        res[i] = curk;
        ++cnt;
        if (cnt == 3) {
            ++curk;
            cnt = 0;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i)
        printf("%d ", res[i]);
    return 0;
}