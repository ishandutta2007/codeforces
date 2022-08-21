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

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n, k; ll a, b;
    cin >> n >> k >> a >> b;
    a = min(a, 5 * b);
    V<ll> cont(n);
    for (int i = 0; i < n; i++) {
        cin >> cont[i];
        cont[i] += TEN(9) + TEN(6);
    }
    sort(cont.begin(), cont.end());
    ll ans = TEN(18) * 5;
    for (int md = 0; md < 5; md++) {
        priority_queue<ll> que;
        ll sm = 0;
        auto inc = [&](ll d) {
            ll nd = d / 5 * 5 + md;
            if (nd < d) nd += 5;
            ll cost = (nd - d) * b;
            nd /= 5;
            cost -= nd * a;
            que.push(cost);
            sm += cost;
            if (que.size() > k) {
                sm -= que.top(); que.pop();
            }
        };
        for (auto d: cont) {
            ll nd = d / 5 * 5 + md;
            if (nd < d) nd += 5;
            nd /= 5;

            inc(d);
            if (que.size() == k) {
                ans = min(ans, nd * k * a + sm);
            }
        }
    }
    cout << ans << endl;
    return 0;
}