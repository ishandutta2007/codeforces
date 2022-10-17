#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, m, dgr[N], dis[N];
vector<int> e[N];
priority_queue<pair<int, int>> pq;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        ++dgr[u];
        e[v].push_back(u);
    }
    memset(dis, 0x3f, sizeof dis);
    dis[n] = 0;
    pq.emplace(-dis[n], n);
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        int u = cur.second;
        if (cur.first + dis[u]) {
            continue;
        }
        for (auto v : e[u]) {
            int val = dis[u] + (--dgr[v]) + 1;
            if (dis[v] > val) {
                dis[v] = val;
                pq.emplace(-dis[v], v);
            }
        }
    }
    cout << dis[1] << "\n";
    return 0;
}