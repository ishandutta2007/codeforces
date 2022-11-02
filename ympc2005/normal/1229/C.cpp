#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

int n, m, q, d[N];

vector <int> e[N];

ll ans;

ll calc_(int u) {
    return 1ll*(d[u] - e[u].size())*e[u].size();
}

int main() {
    scanf("%d%d", &n, &m);

    for (int u, v, i = 1; i <= m; i++) {
        scanf("%d%d", &u, &v);

        if (u > v) {
            swap(u, v);
        }

        d[u]++, d[v]++;
        e[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        ans += calc_(i);
    }

    printf("%lld\n", ans);
    scanf("%d", &q);

    for (int u, i = 1; i <= q; i++) {
        scanf("%d", &u);
        ans -= calc_(u);
        
        for (int v : e[u]) {
            ans -= calc_(v);
            e[v].push_back(u);
            ans += calc_(v);
        }

        e[u].clear();
        ans += calc_(u);
        printf("%lld\n", ans);
    }
}