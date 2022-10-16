#include <bits/stdc++.h>
using namespace std;
constexpr int64_t base = 998244353;
int n, k;
int64_t a, x, y, M;
int64_t p[20];
class Result {
  public:
    int64_t a, b;  // a*x + b

    int64_t Get(const int64_t& val) const { return (a * val + b) % base; }

    Result& operator+=(const Result& rhs) {
        a += rhs.a;
        b += rhs.b;
        if (a >= base) a -= base;
        if (b >= base) b -= base;
        return *this;
    }

    template <typename T>
    Result operator*(const T& rhs) const {
        return Result{(a * rhs) % base, (b * rhs) % base};
    }
};

Result r[18][720720];

void solve() {
    cin >> n >> a >> x >> y >> k >> M;
    p[0] = 1;
    for (int i = 1; i <= k; i++) p[i] = (p[i - 1] * n) % base;

    int L = 1;
    for (int i = 1; i < k; i++) L = lcm(L, i);
    for (int mod = 0; mod < L; mod++) {
        r[k][mod].a = 1;
        r[k][mod].b = mod;
    }
    for (int i = k - 1; i >= 1; i--) {
        for (int mod = 0; mod < L; mod++) {
            r[i][mod] += r[i + 1][mod] * (n - 1);    // not chosen
            r[i][mod] += r[i + 1][mod - mod % i];    // chosen
            r[i][mod] += Result(1, mod) * p[k - i];  // chosen
        }
    }
    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
        int64_t p = a % L;
        ans += r[1][p].Get(a - p);
        a = (a * x + y) % M;
    }
    ans %= base;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}