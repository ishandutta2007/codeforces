#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long llong;
typedef long double ld;
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()

int mathdiv(int a, int b) {
    assert(b >= 2);
    if (a >= 0) {
        return a / b;
    } else if (a % b == 0) {
        return a / b;
    } else {
        return a / b - 1;
    }
}

int main() {
#ifdef LOCAL
    assert(freopen(".in", "r", stdin));
#endif
    int n, k;
    scanf("%d %d", &n, &k);
    int a = n - k;
    int t = mathdiv(a - 2, k);
    bool half = (a - 2) % k == 0;
    int ans = half ? 2 * t + 3 : 2 * t + 4;
    printf("%d\n", ans);
    vector<int> top(k);
    int ver = 0;
    for (int i = 0; i < k; i++) {
        top[i] = ver++;
    }
    vector<pair<int, int>> edges;
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < k; j++) {
            int v = ver++;
            edges.emplace_back(top[j], v);
            top[j] = v;
        }
    }
    if (a == 1) {
        int v = ver++;
        for (int i = 0; i < k; i++) {
            edges.emplace_back(top[i], v);
        }
    } else if ((a - 2) % k == 0) {
        int v = ver++;
        int u = ver++;
        edges.emplace_back(v, u);
        edges.emplace_back(top[0], v);
        for (int i = 1; i < k; i++) {
            edges.emplace_back(top[i], u);
        }
    } else {
        int root = ver++;
        int own = (a - 1) % k;
        if (own == 0)
            own = k;
        for (int i = 0; i < own; i++) {
            int v = ver++;
            edges.emplace_back(top[i], v);
            edges.emplace_back(v, root);
        }
        for (int i = own; i < k; i++) {
            edges.emplace_back(top[i], root);
        }
    }
    assert(ver == n);
    for (auto edge : edges) {
        printf("%d %d\n", edge.first + 1, edge.second + 1);
    }
}