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
const int K = 40;

int n, q;
ll a[N], b[K];
ll t[N][K];
unordered_map<ll, ll> mt;

ll get(ll x) {
    unsigned long long y = x;
    y += 0x9e3779b97f4a7c15;
    y = (y ^ (y >> 30)) * 0xbf58476d1ce4e5b9;
    y = (y ^ (y >> 27)) * 0x94d049bb133111eb;
    y = y ^ (y >> 31);
    y %= mod;
    return y;
}

const ll MOD = mod;

void upd(int p, ll x, int k) {
    for (int j = 0; j < K; j++) {
        ll y = get(x + b[j]);
        for (int i = p; i < N; i = (i | (i + 1)))
            t[i][j] += (ll)y * k;
    }
}

bool check(int l, int r, int k) {
    for (int j = 0; j < K; j++) {
        ll res = 0;
        for (int i = r; i >= 0; i = (i & (i + 1)) - 1)
            res += t[i][j];
        for (int i = l - 1; i >= 0; i = (i & (i + 1)) - 1)
            res -= t[i][j];
        if (res % k)
            return 0;
    }
    return 1;
}

void solve() {
    for(int i = 0; i < K; i++){
        ll res = 0;
        for (int j = 0; j < 40; j++)
            if (rand() & 1)
                res ^= (1ll << j);
        b[i] = res;
    }
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = get(a[i]);
        upd(i, a[i], 1);
    }

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, x;
            cin >> i >> x;
            upd(i, a[i], -1);
            a[i] = x;
            a[i] = get(a[i]);
            upd(i, a[i], 1);
        } else {
            int l, r, k;
            cin >> l >> r >> k;
            if (check(l, r, k))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}

int main() {
//#ifdef DEBUG
//    freopen("input.txt", "r", stdin);
//#endif
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    for (int i = 1; i <= t; i++) {
//        cout << "Case #" << i << endl;
        solve();
    }
}