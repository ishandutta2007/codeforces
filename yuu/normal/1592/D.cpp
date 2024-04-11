#include <bits/stdc++.h>
using namespace std;
vector<int> g[1001];
int n, target;
vector<int> remain;
bool dead[1001];
bool done[1001];
int f[1001];

int t[1001];
void dfs(int u) {
    done[u] = 1;
    f[u] = 1;
    for (int v : g[u])
        if ((!dead[v]) && (!done[v])) {
            dfs(v);
            f[u] += f[v];
        }
}

void get_tree(int u, vector<int>& q) {
    done[u] = 1;
    q.push_back(u);
    for (int v : g[u])
        if ((!dead[v]) && (!done[v])) {
            get_tree(v, q);
        }
}
void solve() {
    cin >> n;
    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cout << "? " << n << " ";
    for (int i = 1; i <= n; i++) cout << i << " \n"[i == n];
    cout.flush();
    cin >> target;
    for (int i = 1; i <= n; i++) remain.push_back(i);
    t[0] = -1;
    while (remain.size() > 2) {
        int best_config = 1e9;
        vector<int> best_array;
        for (int root : remain) {
            for (int x : remain) done[x] = 0;
            dfs(root);
            for (int i = 1; i <= remain.size()/2; i++) t[i] = 0;
            for (int x : g[root])
                if (!dead[x]) {
                    for (int w = remain.size()/2; w >= f[x]; w--) if(!t[w])
                        if (t[w - f[x]]) {
                            t[w] = x;
                        }
                }
            int best = 0;
            for (int i = 1; i <= remain.size()/2; i++)
                if (t[i]) {
                    if (max(i + 1, (int)remain.size() - i) < max(best + 1, (int)remain.size() - best)) best = i;
                }
            if (max(best + 1, (int)remain.size() - best) < best_config) {
                for (int x : remain) done[x] = 0;
                done[root] = 1;
                best_config = max(best + 1, (int)remain.size() - best);
                best_array.clear();
                best_array.push_back(root);
                while (best) {
                    get_tree(t[best], best_array);
                    best -= f[t[best]];
                }
            }
        }
        cout << "? " << best_array.size();
        for (auto&& x : best_array) cout << " " << x;
        cout << '\n';
        cout.flush();
        int current;
        cin >> current;
        if (target != current) {
            for (int x : best_array) dead[x] = 1;
            dead[best_array[0]] = 0;
        } else {
            for (int x : remain) dead[x] = 1;
            for (int x : best_array) dead[x] = 0;
        }
        best_array.clear();
        for (int x : remain)
            if (!dead[x]) best_array.push_back(x);
        remain = move(best_array);
    }
    cout << "! " << remain[0] << ' ' << remain[1] << '\n';
    cout.flush();
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}