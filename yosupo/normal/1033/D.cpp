//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
//#undef LOCAL
#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

#ifdef LOCAL
#define show(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define show(x)
#endif

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    return os << "P(" << p.first << ", " << p.second << ")";
}

template <class T> ostream& operator<<(ostream& os, const V<T>& v) {
    os << "[";
    for (auto d : v) os << d << ", ";
    return os << "]";
}

const int MAD = 2 * TEN(6);
V<ll> pred;
void first() {
    V<bool> is_pr(MAD, true);
    is_pr[0] = is_pr[1] = false;
    for (int i = 2; i < MAD; i++) {
        if (!is_pr[i]) continue;
        pred.push_back(i);
        for (int j = 2 * i; j < MAD; j += i) {
            is_pr[j] = false;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    first();
    int n;
    cin >> n;
    V<ll> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        for (int e = 2; e <= 4; e++) {
            ll lw = 1, up = 2 * TEN(9);
            while (up - lw > 1) {
                ll md = (lw + up) / 2;
                double mdd = 1;
                for (int k = 0; k < e; k++) mdd *= md;
                if (mdd > 3 * 1e18) {
                    up = md;
                    continue;
                }
                ll mdi = 1;
                for (int k = 0; k < e; k++) mdi *= md;
                if (mdi > p[i]) up = md;
                else lw = md;
            }
            if (lw > 1 && lw < p[i] && p[i] % lw == 0) pred.push_back(lw);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ll x = __gcd(p[i], p[j]);
            if (x > 1 && x != p[i] && x != p[j]) pred.push_back(x);
        }
    }
    sort(pred.begin(), pred.end());

    map<ll, int> mp;
    set<ll> ab;
    for (int i = 0; i < n; i++) {
        ll v = p[i];
        int cnt = 0;
        for (ll d: pred) {
            if (v <= d) break;
            while (v % d == 0) {
                cnt++;
                mp[d]++;
                v /= d;
            }
        }
        if (v > 1) {
            mp[v]++;
            if (cnt == 0) ab.insert(v);
        }
    }

    const ll MD = 998244353;
    ll ans = 1;
    for (auto p: mp) {
        if (ab.count(p.first)) {
            ans *= p.second + 1;
            ans *= p.second + 1;
        } else {
            ans *= p.second + 1;
        }
        ans %= MD;
    }
    cout << ans << endl;
    return 0;
}