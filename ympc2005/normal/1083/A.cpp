#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int N = 3e5 + 10;

int n, w[N];

ll ans;

vector <pii> e[N];

ll dfs_(int u, int fa) {
    ll mx = 0, sx = 0;

    for (auto x : e[u]) {
        int v = x.first;

        if (v == fa) {
            continue;
        }

        sx = max(sx, dfs_(v, u) - x.second);
        
        if (sx > mx) {
            swap(mx, sx);
        }
    }

    ans = max(ans, mx + sx + w[u]);
    return w[u] + mx;
}

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    cin>>n;

    for (int i = 1; i <= n; i++) {
        cin>>w[i];
    }

    for (int u, v, w, i = 1; i < n; i++) {
        cin>>u>>v>>w;
        e[u].push_back(pii(v, w));
        e[v].push_back(pii(u, w));
    }

    dfs_(1, 0);
    cout<<ans<<'\n';
}