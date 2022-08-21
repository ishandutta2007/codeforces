#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

struct QuickFind {
    V<int> id, cnt;
    VV<int> groups;
    int gc;  // group count
    QuickFind(int n = 0) {
        id = V<int>(n);
        cnt = V<int>(n);
        groups = VV<int>(n);
        for (int i = 0; i < n; i++) {
            id[i] = i;
            groups[i] = {i};
        }
        gc = n;
    }
    void merge(int a, int b) {
        if (same(a, b)) return;
        gc--;
        int x = id[a], y = id[b];
        if (groups[x].size() < groups[y].size()) swap(x, y);
        for (int j : groups[y]) {
            id[j] = x;
            groups[x].push_back(j);
        }
        groups[y].clear();
        cnt[x] += cnt[y];
        cnt[y] = 0;
    }
    bool same(int a, int b) { return id[a] == id[b]; }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    QuickFind qf(n);
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x; x--;
        qf.cnt[x] = 1;
    }
    struct E {
        int from, to, cost;
    };
    V<E> edges;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c; a--; b--;
        edges.push_back(E{a, b, c});
    }
    sort(edges.begin(), edges.end(), [&](E a, E b) {
        return a.cost < b.cost;
    });
    for (auto e: edges) {
        if (qf.same(e.from, e.to)) continue;
        qf.merge(e.from, e.to);
        if (qf.cnt[qf.id[e.from]] != k) continue;
        for (int i = 0; i < k; i++) {
            cout << e.cost << " ";
        }
        cout << endl;
        return 0;
    }
    assert(false);

    return 0;
}