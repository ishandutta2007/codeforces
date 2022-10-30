#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, int> pli;

const int N = 1e5 + 10, mod = 1e9 + 7;

int n, fa[N], ans;

ll a[N];

vector <int> e[N];
vector <pli> b[N], tmp;

ll gcd_(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }

    return a;
}

void dfs_(int u) {
    tmp = b[fa[u]];

    for (int i = 0; i < (int) tmp.size(); i++) {
        tmp[i].first = gcd_(tmp[i].first, a[u]);
    }

    tmp.push_back(pli(a[u], 1));
    sort(tmp.begin(), tmp.end());

    for (int l = 0, r; l < (int) tmp.size(); l = r + 1) {
        r = l;
        int sum = tmp[l].second;

        while (r + 1 < (int) tmp.size() && tmp[r + 1].first == tmp[l].first) {
            sum += tmp[++r].second;
        }

        b[u].push_back(pli(tmp[l].first, sum));
        ans = (ans + tmp[l].first%mod*sum)%mod;
    }

    for (int v : e[u]) {
        if (v != fa[u]) {
            fa[v] = u;
            dfs_(v);
        }
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }

    for (int u, v, i = 1; i < n; i++) {
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }

    dfs_(1);
    printf("%d\n", (ans%mod + mod)%mod);
}