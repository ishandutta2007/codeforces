#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 300500, inf = 1e9, mod = 998244353;

int sum(int a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0)
        a += mod;
    return a;
}

int mult(int a, int b) {
    return 1ll * a * b % mod;
}

int bp(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = mult(res, a);
        a = mult(a, a);
        b >>= 1;
    }
    return res;
}

int inv(int x) {
    return bp(x, mod - 2);
}

int n, k, a[N];
vector< int > g[N];
map<int, ll> dp[N];

ll get(int v, int k, ll s){
    s += a[v];
    if(g[v].size() == 0)
        return k * s;
    if(dp[v].find(k) != dp[v].end())
        return dp[v][k];
    ll res = 0;
    if(k % g[v].size() == 0){
        for(auto to : g[v])
            res += get(to, k / g[v].size(), s);
    }else {
        vector<ll> kek;
        for (auto to: g[v]) {
            ll x = get(to, k / g[v].size(), s);
            ll y = get(to, k / g[v].size() + 1, s);
            res += x;
            kek.push_back(y - x);
        }
        sort(kek.begin(), kek.end());
        reverse(kek.begin(), kek.end());
        for(int i = 0; i < k % g[v].size(); i++)
            res += kek[i];
    }
    return dp[v][k] = res;
}
void solve() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        dp[i].clear();
        g[i].clear();
    }
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        g[p].pb(i);
    }
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    cout << get(1, k, 0) << endl;
}
int main() {
//#ifdef DEBUG
//    freopen("input.txt", "r", stdin);
//#endif
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
//        cout << "Case #" << i << endl;
        solve();
    }
}