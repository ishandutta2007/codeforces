#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> g[100001];

int done[100001];
int done_cnt;
bool removed[100001];
int f[100001];
void dfs(int u) {
    done[u] = done_cnt;
    f[u] = 1;
    for (int v : g[u])
        if ((!removed[v]) && (done[v] != done_cnt)) {
            dfs(v);
            f[u] += f[v];
        }
}

char ans[100001];

void centroid(int u, char value) {
    done_cnt++;
    dfs(u);
    int region_size = f[u];
    bool found = false;
    while (!found) {
        found = true;
        for (int v : g[u])
            if ((done[v] == done_cnt) && (f[v] < f[u])) {
                if (f[v] * 2 > region_size) {
                    u = v;
                    found = false;
                    break;
                }
            }
    }
    ans[u] = value;
    removed[u] = 1;
    for (int v : g[u])
        if (!removed[v]) centroid(v, value + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    centroid(1, 'A');
    for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
}