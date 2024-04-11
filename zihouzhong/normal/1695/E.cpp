#include <bits/stdc++.h>
using namespace std;

const int maxn = 600010;
int n, tot, head[maxn];
bool vis[maxn], mark[maxn];
array<int, 2> a[maxn], res[maxn];
string A[maxn], B[maxn];
struct edge { int to, nxt; } e[maxn];

void add_edge(int u, int v) {
    e[++tot] = (edge){v, head[u]}, head[u] = tot;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1, x, y; i <= n; i++) {
        cin >> x >> y;
        a[2 * i - 1] = {x, y}, a[2 * i] = {y, x};
        add_edge(x, y), add_edge(y, x);
    }
    vector<int> st;
    auto dfs = [&](auto self, int u) -> void {
        mark[u] = 1;
        for (int &i = head[u]; i; i = e[i].nxt) if (!vis[i]) {
            int o = i;
            vis[i] = 1, self(self, e[i].to);
            st.push_back(o);
        }
    };
    int sz = 0;
    for (int i = 1; i <= 2 * n; i++) if (!mark[i]) {
        st.clear(), dfs(dfs, i);
        if (st.empty()) continue;
        if (st.size() == 2) cout << "-1\n", exit(0);
        reverse(st.begin(), st.end());
        vector<int> _st;
        for (int j = 0; j < st.size(); j += 2) _st.push_back(st[j]);
        st.clear();
        for (int j = 0; j < _st.size() / 2; j++) {
            st.push_back(_st[j]);
            st.push_back(_st[_st.size() - j - 1]);
        }
        if (_st.size() % 2) st.push_back(_st[_st.size() / 2]);
        for (int j = 0; j + 1 < st.size(); j += 2) {
            res[sz + j + 1] = {a[st[j]][0], a[st[j + 1]][1]};
            res[sz + j + 2] = {a[st[j]][1], a[st[j + 1]][0]};
            A[sz + j + 1] = "UU", A[sz + j + 2] = "DD";
        }
        B[sz + 1] = "LR";
        for (int j = 1; j + 1 < st.size(); j += 2) {
            B[sz + j + 1] = "UU", B[sz + j + 2] = "DD";
        }
        if (st.size() % 2) {
            res[sz + st.size()] = {a[st.back()][0], a[st.back()][1]};
            A[sz + st.size()] = "LR";
        } else {
            B[sz + st.size()] = "LR";
        }
        sz += st.size();
    }
    cout << n << " 2\n";
    for (int i = 1; i <= n; i++) {
        cout << res[i][0] << " " << res[i][1] << "\n";
    }
    for (int i = 1; i <= n; i++) {
        cout << A[i] << "\n";
    }
    for (int i = 1; i <= n; i++) {
        cout << B[i] << "\n";
    }
    return 0;
}