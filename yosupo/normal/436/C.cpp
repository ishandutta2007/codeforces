#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<ll, int> P;
typedef tuple<int, int, int> T;

char c[1000][10][10];
int main() {
    int n, m, k, w;
    cin >> n >> m >> k >> w;
    for (int i = 0; i < k; i++) {
        for (int x = 0; x < n; x++) {
            string s;
            cin >> s;
            for (int y = 0; y < m; y++) {
                c[i][x][y] = s[y];
            }
        }
    }
    int g[1000][1000];
    for (int i = 0; i < k; i++) {
        for (int j = i+1; j < k; j++) {
            int u = 0;
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < m; y++) {
                    if (c[i][x][y] != c[j][x][y]) {
                        u++;
                    }
                }
            }
            g[i][j] = g[j][i] = min(n*m, w*u);
        }
    }

    P mc[1000];
    bool us[1000] = {};
    fill_n(mc, 1000, P(1LL<<55, -1));
    mc[0] = P(0, -1);
    ll r = 0;
    vector<P> res;
    while (true) {
        int v = -1;
        for (int u = 0; u < k; u++) {
            if (!us[u] && (v == -1 || mc[u].first < mc[v].first)) v = u;
        }
        if (v == -1) break;
        us[v] = true;
        r += mc[v].first;
        if (mc[v].first == n*m) {
            res.push_back(P(v, -1));
        } else {
            res.push_back(P(v, mc[v].second));
        }
        for (int u = 0; u < k; u++) {
            if (g[v][u] < mc[u].first) {
                mc[u] = P(g[v][u], v);
            }
        }
    }
    cout << r+n*m << endl;
    for (P p: res) {
        cout << p.first+1 << ' ' << p.second+1 << endl;
    }
    return 0;
}