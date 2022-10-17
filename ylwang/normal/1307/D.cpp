#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL mod = 1e9 + 7;
const int N = 200005;

vector<int> a;
vector<int> G[N];
int d[N], f[N];  //d1fn
int b[N];
bool cmp(int p1, int p2) {
    return d[p1] < d[p2];
}
int main() {
    int n, m, g;
    scanf("%d%d%d", &n, &m, &g);
    while (g--) {
        int x;
        scanf("%d", &x);
        a.push_back(x);
    }
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    queue<int> q;
    memset(d, -1, sizeof d);
    memset(f, -1, sizeof f);
    q.push(1);
    d[1] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : G[u]) {
            if (d[v] == -1) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    q.push(n);
    f[n] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : G[u]) {
            if (f[v] == -1) {
                f[v] = f[u] + 1;
                q.push(v);
            }
        }
    }
    sort(a.begin(), a.end(), cmp);
    int ans = 0;
    for (int i = 0; i < a.size() - 1; i++) {
        ans = max(ans, d[a[i]] + f[a[i + 1]] + 1);
    }
    ans = min(d[n], ans);
    cout << ans << endl;
    return 0;
}