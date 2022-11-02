#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1005, mod = 998244353;

int n, m, a[N], ans, d[N], rt, b[N];

vector <int> e[N];

bool vis[N];

void work_() {
    cin>>n>>m;

    for (int i = 1; i <= n; i++) {
        e[i].clear();
        d[i] = 0;
        cin>>a[i];
        b[i] = a[i];
    }

    for (int u, v, i = 1; i <= m; i++) {
        cin>>u>>v;
        e[u].push_back(v);
        d[v]++;
    }

    queue <int> q;

    for (int i = 1; i <= n; i++) {
        if (!e[i].size()) {
            rt = i;
        }

        if (!d[i]) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (int v : e[u]) {
            a[v] = (a[v] + a[u])%mod;

            if (!--d[v]) {
                q.push(v);
            }
        }
    }

    for (int i = 1; i <= n + 10; i++) {
        bool tag = 0;

        for (int j = 1; j <= n; j++) {
            vis[j] = b[j] > 0;
            tag |= vis[j];
        }

        if (!tag) {
            break;
        }

        if (!vis[rt]) {
            a[rt]++;
        }

        for (int j = 1; j <= n; j++) {
            if (vis[j]) {
                b[j]--;

                for (int k : e[j]) {
                    b[k]++;
                }
            }
        }
    }

    a[rt] %= mod;
    cout<<(a[rt]%mod + mod)%mod<<'\n';
}

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin>>T;

    while (T--) {
        work_();
    }
}