#include <bits/stdc++.h>
using namespace std;

int current_count[1000001];
set<int> indices[1000001];
int ft[1000001];
int n, q, tree_size;

int get(int u) {
    int res = 0;
    for (; u > 0; u -= (u & -u)) res += ft[u];
    return res;
}

void update(int u, int diff) {
    for (; u <= tree_size; u += u & -u) {
        ft[u] += diff;
    }
}

int cnt[1000001];
int a[1000001];
vector<int> g[1000001];
vector<tuple<int, int, int>> query[1000001];
int* ans;

void PopType(int u) {
    if (current_count[u] == 0) return;
    indices[current_count[u]].erase(u);
    update(current_count[u], -1);
}

void PushType(int u) {
    if (current_count[u] == 0) return;
    indices[current_count[u]].insert(u);
    update(current_count[u], 1);
}

void dfs(int u) {
    PopType(a[u]);
    current_count[a[u]]++;
    PushType(a[u]);
    for (auto&& [l, k, id] : query[u]) {
        if (l > tree_size) {
            ans[id] = -1;
            continue;
        }
        k += get(l - 1);
        int low = 1, high = tree_size, mid = 1;
        ans[id] = -1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (get(mid) >= k) {
                ans[id] = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (ans[id] != -1) ans[id] = *indices[ans[id]].begin();
    }
    query[u].clear();
    for (auto&& v : g[u]) dfs(v);

    PopType(a[u]);
    current_count[a[u]]--;
    PushType(a[u]);
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cnt[i] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int u = 2, p; u <= n; u++) {
        cin >> p;
        g[p].push_back(u);
    }
    for (int i = 1, v, k, l; i <= q; i++) {
        cin >> v >> l >> k;
        query[v].emplace_back(l, k, i);
    }
    tree_size = *max_element(cnt + 1, cnt + n + 1);
    for (int i = 1; i <= tree_size; i++) ft[i] = 0;
    ans = cnt;
    dfs(1);
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 1; i <= n; i++) query[i].clear();
    for (int i = 1; i <= q; i++) cout << ans[i] << " \n"[i == q];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}