#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
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

ll solve(int w, V<ll> a, string s) {
    reverse(s.begin(), s.end());
    int res = 0, x_tm = 0;
    for (int ph = 0; ph < w; ph++) {
        char c = toupper(s[ph]);
        if (islower(s[ph])) res |= (1 << ph);
        if (c == 'A') {
            for (int i = 0; i < (1<<w); i++) {
                if (i & (1 << ph)) continue;
                int j = i | (1 << ph);
                a[i] += a[j];
            }
        } else if (c == 'O') {
            for (int i = 0; i < (1<<w); i++) {
                if (i & (1 << ph)) continue;
                int j = i | (1 << ph);
                a[j] += a[i];
            }
        } else {
            x_tm++;
            for (int i = 0; i < (1<<w); i++) {
                if (i & (1 << ph)) continue;
                int j = i | (1 << ph);
                ll xi = a[i], xj = a[j];
                a[i] = xi + xj;
                a[j] = xi - xj;
            }
        }
    }

    for (int i = 0; i < (1<<w); i++) {
        a[i] *= a[i];
    }

    for (int ph = 0; ph < w; ph++) {
        char c = toupper(s[ph]);
        if (islower(s[ph])) res |= (1 << ph);
        if (c == 'A') {
            for (int i = 0; i < (1<<w); i++) {
                if (i & (1 << ph)) continue;
                int j = i | (1 << ph);
                a[i] -= a[j];
            }
        } else if (c == 'O') {
            for (int i = 0; i < (1<<w); i++) {
                if (i & (1 << ph)) continue;
                int j = i | (1 << ph);
                a[j] -= a[i];
            }
        } else {
            for (int i = 0; i < (1<<w); i++) {
                if (i & (1 << ph)) continue;
                int j = i | (1 << ph);
                ll xi = a[i], xj = a[j];
                a[i] = xi + xj;
                a[j] = xi - xj;
            }
        }
    }
    return a[res] / (1 << x_tm);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int w, n, m;
    cin >> w >> n >> m;
    V<ll> a(1 << w);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        cout << solve(w, a, s) << endl;
    }
    return 0;
}