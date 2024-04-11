#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
template <class T> using VVV = V<VV<T>>;

struct SCC {
    V<int> id;
    VV<int> groups;
};

template<class E>
struct SCCExec : SCC {
    int n;
    const VV<E>& g;
    int tm = 0;
    V<bool> flag;
    V<int> low, ord, st;
    void dfs(int v) {
        low[v] = ord[v] = tm++;
        st.push_back(v);
        flag[v] = true;
        for (auto e: g[v]) {
            if (ord[e.to] == -1) {
                dfs(e.to);
                low[v] = min(low[v], low[e.to]);
            } else if (flag[e.to]) {
                low[v] = min(low[v], ord[e.to]);
            }
        }
        if (low[v] == ord[v]) {
            V<int> gr;
            while (true) {
                int u = st.back(); st.pop_back();
                gr.push_back(u);
                if (u == v) break;
            }
            for (int x: gr) flag[x] = false;
            groups.push_back(gr);
        }
    }
    SCCExec(const VV<E>& _g) : n(int(_g.size())), g(_g),
                               flag(n), low(n), ord(n, -1) {
        id = V<int>(n);
        for (int i = 0; i < n; i++) {
            if (ord[i] == -1) dfs(i);
        }
        reverse(groups.begin(), groups.end());
        for (int i = 0; i < int(groups.size()); i++) {
            for (int x: groups[i]) {
                id[x] = i;
            }
        }
    }
};

template<class E> SCC get_scc(const VV<E>& g) { return SCCExec<E>(g); }

bool solve() {
    int n, m;
    cin >> n >> m;
    struct E { int to; };
    VV<E> g(2 * n);
    auto add_cond = [&](int a, bool a_exp, int b, bool b_exp) {
        g[2 * a + (a_exp ? 0 : 1)].push_back(E{2 * b + (b_exp ? 1 : 0)});
        g[2 * b + (b_exp ? 0 : 1)].push_back(E{2 * a + (a_exp ? 1 : 0)});
    };
    string s;
    cin >> s;
    for (int ph = 0; ph < m; ph++) {
        int a, b;
        cin >> a >> b;
        bool fa = true, fb = true;
        if (a < 0) {
            fa = false;
            a = -a;
        }
        if (b < 0) {
            fb = false;
            b = -b;
        }
        a--; b--;
        add_cond(a, fa, b, fb);
    }
    auto sc = get_scc(g);
    for (int i = 0; i < n; i++) {
        if (sc.id[2 * i] == sc.id[2 * i + 1]) return false;
    }
    int k = int(sc.groups.size());
    V<bool> all(k);
    for (int gr = k-1; gr >= 0; gr--) {
/*        cerr << gr << ":";
        for (int i: sc.groups[gr]) cerr << i << ", ";
        cerr << endl;*/
        int my = -1;
        for (int i: sc.groups[gr]) {
            if (s[i/2] == 'A') {
                if (my != -1) return false;
                my = i;
            }
            for (auto e: g[i]) {
                int j = e.to;
                if (sc.id[j] != gr && all[sc.id[j]]) all[gr] = true;
            }
        }
        if (my != -1) {
            if (all[gr]) return false;
            all[gr] = true;
            for (int i: sc.groups[gr]) {
                if (i < my) return false;
            }
        }
    }
/*    for (auto f: all) cerr << f << ", ";
    cerr << endl;*/
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20) << fixed;

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        if (solve()) cout << "TRUE\n";
        else cout << "FALSE\n";
    }
    return 0;
}