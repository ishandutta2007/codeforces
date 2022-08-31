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
struct PrettyOS {
    ostream& os;
    bool first;
    template <class T> auto operator<<(T&& x) {
        if (!first) os << ", ";
        first = false;
        os << x;
        return *this;
    }
};
template <class... T> void dbg0(T&&... t) {
    (PrettyOS{cerr, true} << ... << t);
}
#define dbg(...)                                            \
    do {                                                    \
        cerr << __LINE__ << " : " << #__VA_ARGS__ << " = "; \
        dbg0(__VA_ARGS__);                                  \
        cerr << endl;                                       \
    } while (false);
#else
#define dbg(...)
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

using D = long double;
using P = pair<int, int>;
int la[10][10];

P nx(int r, int c) {
    if (r == -1) return P(r, c);
    if (r % 2 == 0 && c == 0) return P(r - 1, 0);
    if (r % 2 == 1 && c == 9) return P(r - 1, 9);

    if (r % 2 == 0) return P(r, c - 1);
    else return P(r, c + 1);
}

P nx(int r, int c, int k) {
    P nw = P(r, c);
    for (int i = 0; i < k; i++) {
        nw = nx(nw.first, nw.second);
    }
    return nw;
}

D dp[10][10];
bool memo[10][10] = {};

D solve(int r, int c) {
    if (r == 0 && c == 0) return 0;

    if (memo[r][c]) return dp[r][c];
    memo[r][c] = true;

    // x = 1 + (sum + self * x)
    // (1 - self) * x = 1 + sum
    // x = (1 + sum) / (1 - self)

    D sum = 0;
    D self = 0;
    for (int i = 1; i <= 6; i++) {
        int nr, nc;
        tie(nr, nc) = nx(r, c, i);
        if (nr == -1) self += 1.0 / 6;
        else {
            sum += 1.0 / 6 * min(solve(nr, nc), solve(nr - la[nr][nc], nc));
        }
    }
    return dp[r][c] = (1 + sum) / (1 - self);
}


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> la[i][j];
        }
    }

    cout << solve(9, 0) << endl;

    return 0;
}