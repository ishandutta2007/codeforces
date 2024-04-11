#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

template<class E>
struct MaxMatching {
    int n;
    const VV<E>& g;
    V<int> mt;
    MaxMatching(const VV<E>& _g) : n(int(_g.size())), g(_g), mt(n, -1) {}
    bool arg() {
        V<int> ty(n), rt(n, -1), gr(n, -1), nw(n, -1);
        using P = pair<int, int>;

        queue<int> q; // queue
        for (int i = 0; i < n; i++) {
            if (mt[i] == -1) {
                rt[i] = gr[i] = i; // , 
                ty[i] = -1;
                q.push(i);
            }
        }

        // u
        auto get_path = [&](int u) {
            V<int> v;
            while (rt[u] != u) {
                v.push_back(u);
                v.push_back(mt[u]);
                u = nw[mt[u]];
            }
            v.push_back(u);
            return v;
        };

        while (q.size()) {
            int a = q.front(); q.pop();
            for (auto e: g[a]) {
                int b = e.to;
                if (ty[b] == 1) continue; //  or 
                if (ty[b] == -1 and gr[a] == gr[b]) continue; // grop
                if (ty[b] == 0) {
                    // 
                    int c = mt[b];
                    nw[b] = a; nw[c] = -1;
                    rt[b] = rt[c] = rt[a];
                    gr[b] = b; gr[c] = c;
                    ty[b] = 1; ty[c] = -1;
                    q.push(c);
                    continue;
                }
                if (rt[a] != rt[b]) {
                    // 
                    for (int c: {a, b}) {
                        auto v = get_path(c);
                        int m = int(v.size());
                        assert(m % 2 == 1);
                        for (int i = 1; i < m; i += 2) {
                            mt[v[i]] = v[i+1];
                            mt[v[i+1]] = v[i];
                        }
                    }
                    mt[a] = b; mt[b] = a;
                    return true;
                }
                // 
                auto v1 = get_path(a);
                auto v2 = get_path(b);
                reverse(v1.begin(), v1.end());
                reverse(v2.begin(), v2.end());
                assert(v1[0] == v2[0]);
                int m = min(v1.size(), v2.size()), lca;
                for (int i = 1; i <= m; i++) {
                    if (i == m or v1[i] != v2[i]) {
                        lca = gr[v1[i-1]]; // LCA
                        break;
                    }
                }
                V<bool> used(n);
                for (int c: {a, b}) {
                    auto v = get_path(c);
                    int m = (int)v.size();
                    for (int i = 0; gr[v[i]] != lca; i += 2) {
                        used[gr[v[i]]] = used[gr[v[i+1]]] = true;
                        if (ty[v[i+1]] == 1) {
                            ty[v[i+1]] = -1;
                            q.push(v[i+1]);
                        }
                        if (i) nw[v[i]] = v[i-1];
                    }
                }
                if (gr[a] != lca) nw[a] = b;
                if (gr[b] != lca) nw[b] = a;
                for (int i = 0; i < n; i++) {
                    if (ty[i] and used[gr[i]]) {
                        gr[i] = lca;
                    }
                }
            }
        }
        return false;
    }
};

struct E { int to; };
void solve() {
    int n, m;
    cin >> n >> m;
    VV<E> g(2 * n + m);
    auto add_edge = [&](int a, int b) {
        g[a].push_back(E{b});
        g[b].push_back(E{a});
    };
    for (int i = 0; i < n; i++) {
        add_edge(i, i + n);
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '0') continue;
            add_edge(i, j + n + n);
            add_edge(i + n, j + n + n);
        }
    }
    auto mt = MaxMatching<E>(g);
    int ans = 0;
    while (mt.arg()) ans++;
    cout << ans - n << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    int t;
    cin >> t;
    for (int ph = 0; ph < t; ph++) solve();
    return 0;
}