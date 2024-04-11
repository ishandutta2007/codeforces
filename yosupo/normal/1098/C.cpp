#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

template <class T> ostream& operator<<(ostream& os, const V<T>& v) {
    os << "[";
    for (auto d : v) os << d << ", ";
    return os << "]";
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    return os << "P(" << p.first << ", " << p.second << ")";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, s;
    cin >> n >> s;

    if (s < n + n - 1) {
        cout << "No" << endl;
        return 0;
    }
    ll sm = 0;
    for (int i = 1; i <= n; i++) sm += i;
    if (sm < s) {
        cout << "No" << endl;
        return 0;
    }
    sm -= s;
    V<int> freq(n + 1), cnt(n + 1);

    auto check = [&](ll md) {
        if (md == 1) return sm == 0;
        fill(freq.begin(), freq.end(), 1);
        freq[0] = 0;
        cnt[1] = 1;
        for (int d = 2; d <= n; d++) {
            cnt[d] = min(n, cnt[d - 1] * md);
        }
        ll sm2 = sm;
        ll lower = 2;
        for (ll d = n; d >= 3; d--) {
            ll u = min<ll>(sm2, d - lower);
            // d - u >= lower -> d - lower >= u
            if (u <= 0) return false;
            freq[d]--;
            freq[d - u]++;
            sm2 -= u;
            if (!sm2) break;
            if (freq[lower] == cnt[lower]) lower++;
        }
        if (sm2) return false;
        return true;
    };
    ll lw = 0, up = n - 1;
    while (up - lw > 1) {
        ll md = (lw + up) / 2;
        if (!check(md)) {
            lw = md;
        } else {
            up = md;
        }
    }
    check(up);
    V<int> p(n - 1);
    int prev_l = 0, prev_r = 1;
    for (int d = 2; d <= n; d++) {
        int x = freq[d];
        if (!x) break;
        for (int i = 0; i < x; i++) {
            p[prev_r + i - 1] = prev_l + i % (prev_r - prev_l);
        }
        prev_l = prev_r;
        prev_r += x;
    }

    cout << "Yes" << endl;
    for (int d: p) {
        cout << d + 1 << " ";
    }
    cout << endl;
    return 0;
}