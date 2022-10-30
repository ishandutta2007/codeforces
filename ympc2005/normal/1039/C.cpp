#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e5 + 10, mod = 1e9 + 7;

int n, m, k, b[N], u[N], v[N], fa[N];

ll a[N];

map <ll, vector <int> > mp;

int find_(int x) {
    return fa[x] == x ? x : fa[x] = find_(fa[x]);
}

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m>>k;

    for (int i = 1; i <= n; i++) {
        cin>>a[i];
        fa[i] = i;
    }

    for (int i = 1; i <= m; i++) {
        cin>>u[i]>>v[i];
        mp[a[u[i]]^a[v[i]]].push_back(i);
    }

    b[0] = 1;

    for (int i = 1; i <= max(n, k); i++) {
        b[i] = 2ll*b[i - 1]%mod;
    }

    int ans = 1ll*b[n]*b[k]%mod;

    for (auto x : mp) {
        ans = (ans - b[n])%mod;
        int cnt = n;

        for (int i : x.second) {
            if (find_(u[i]) != find_(v[i])) {
                fa[find_(u[i])] = find_(v[i]);
                cnt--;
            }
        }

        ans = (ans + b[cnt])%mod;

        for (int i : x.second) {
            fa[u[i]] = u[i];
            fa[v[i]] = v[i];
        }
    }

    cout<<(ans%mod + mod)%mod<<'\n';
}