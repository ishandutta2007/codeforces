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
#define show(x) true
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

const int MN = 52;
int n;
int g[MN][MN];
int sm[MN][MN];

int get_sm(int l, int r, int d, int u) {
    return sm[r][u] - sm[l][u] - sm[r][d] + sm[l][d];
}

bool vis[MN][MN][MN][MN];
int memo[MN][MN][MN][MN];

int solve(int l, int r, int d, int u) {
    if (get_sm(l, r, d, u) == 0) return 0;

    if (vis[l][r][d][u]) return memo[l][r][d][u];
    vis[l][r][d][u] = true;

    int ans = max(r - l, u - d);

    if (r - l < u - d) {
        for (int m = d + 1; m < u; m++) {
            ans = min(ans, solve(l, r, d, m) + solve(l, r, m, u));
        }
    } else {
        for (int m = l + 1; m < r; m++) {
            ans = min(ans, solve(l, m, d, u) + solve(m, r, d, u));
        }
    }

    return memo[l][r][d][u] = ans;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            g[i][j] = (s[j] == '#' ? 1 : 0);
        }
    }
    

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sm[i][j] = g[i - 1][j - 1];
            sm[i][j] += sm[i - 1][j];
            sm[i][j] += sm[i][j - 1];
            sm[i][j] -= sm[i - 1][j - 1];
        }
    }

    cout << solve(0, n, 0, n) << endl;
    return 0;
}