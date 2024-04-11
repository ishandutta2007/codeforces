#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
const int N = 100006;

ll w[N];
ll ans[N];

vector<int> G[N];
int u[N], v[N];

void solve() {
    int n; scanf("%d", &n);
    for (int i = 0; i <= n + 1; ++i) {
        G[i].clear();
    }
    ll tot = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &w[i]);
        tot += w[i];
    }
    for (int i = 1; i < n; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        G[x].push_back(y); G[y].push_back(x);
        u[i] = x, v[i] = y;
    }
    priority_queue<ll> pq;
    for (int i = 1; i <= n; ++i) {
        for (int j = 2; j <= G[i].size(); ++j) pq.push(w[i]);
    }
    int ptr = 1;
    ans[ptr] = tot;
    ++ptr;
    while (!pq.empty()) {
        ll p = pq.top(); pq.pop();
        tot += p;
        ans[ptr] = tot;
        ++ptr;
    }
    for (int i = 1; i <= n - 1; ++i) {
        printf("%lld%c", ans[i], " \n"[i == n - 1]);
    }
}

int main () {
    int T; scanf("%d", &T);
    while (T--) {
        solve();
    }
}