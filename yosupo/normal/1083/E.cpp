#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

template<class T>
struct ConvexHull {
    using L = array<T, 2>;

    bool que_incr;
    ConvexHull(bool _que_incr) : que_incr(_que_incr) {}

    deque<L> lines;
    // can remove mid?
    static bool is_need(L mid, L left, L right) {
        assert(left[0] <= mid[0] && mid[0] <= right[0]);
        ll a = (right[0]-mid[0]), b = (left[1]-mid[1]), c = (mid[0]-left[0]), d = (mid[1]-right[1]);
        long double x = (long double)(a) * b - (long double)(c) * d;
        if (abs(x) > (1LL << 60)) return x < 0;
        int fl = b < 0, fr = d < 0;
        if (fl != fr) return fl == 1;
        ull z = ull(a) * ull(abs(b)) - ull(c) * ull(abs(d));
        if (fl == 0) return (1ULL << 63) < z;
        return z < (1ULL << 63);
    }
    /*static bool is_need(L mid, L left, L right) {
        assert(left[0] <= mid[0] && mid[0] <= right[0]);
        return (right[0]-mid[0])*(left[1]-mid[1]) < (mid[0]-left[0])*(mid[1]-right[1]);
    }*/

    void insert_front(L l) {
        if (lines.empty()) {
            lines.push_front(l);
            return;
        }
        assert(l[0] <= lines[0][0]);
        if (l[0] == lines[0][0]) {
            if (l[1] <= lines[0][1]) return;
            lines.pop_front();
        }
        while (lines.size() >= 2 && !is_need(lines.front(), l, lines[1])) {
            lines.pop_front();
        }
        lines.push_front(l);
    }
    void insert_back(L l) {
        if (lines.empty()) {
            lines.push_back(l);
            return;
        }
        assert(lines.back()[0] <= l[0]);
        if (lines.back()[0] == l[0]) {
            if (l[1] <= lines.back()[1]) return;
            lines.pop_back();
        }
        while (lines.size() >= 2 && !is_need(lines.back(), lines[lines.size()-2], l)) {
            lines.pop_back();
        }
        lines.push_back(l);
    }
    /**
    Insert line
    line's degree must be minimum or maximum
     */
    void insert_line(L line) {
        if (lines.empty()) {
            lines.push_back(line);
            return;
        }
        if (line[0] <= lines[0][0]) insert_front(line);
        else if (lines.back()[0] <= line[0]) insert_back(line);
        else assert(false); //line's degree must be minimum or maximum
    }
    /// get maximum y
    T max_y(T x) {
        assert(lines.size());
        auto value = [&](L l) { return l[0] * x + l[1]; };
        if (que_incr) {
            while (lines.size() >= 2 &&
                   value(lines[0]) <= value(lines[1])) {
                lines.pop_front();
            }
            return value(lines.front());
        } else {
            while (lines.size() >= 2 &&
                   value(lines[lines.size()-2]) >= value(lines.back())) {
                lines.pop_back();
            }
            return value(lines.back());
        }
    }
};

using P = pair<ll, ll>;

V<ll> a, dp;
V<P> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    //n = 100000;
    a = V<ll>(n); dp = V<ll>(n); v = V<P>(n);
    struct E { ll x, y, a; };
    V<E> buf(n);
    for (int i = 0; i < n; i++) {
        /*buf[i].x = i + 1;
        buf[i].y = n - i;
        buf[i].a = 0;*/
        cin >> buf[i].x >> buf[i].y >> buf[i].a;
    }
    sort(buf.begin(), buf.end(), [&](E l, E r){
        return l.x < r.x;
    });
    ConvexHull<ll> cht(false);
    for (int i = 0; i < n; i++) {
        v[i] = P(buf[i].x, buf[i].y);
        a[i] = buf[i].a;
        dp[i] = v[i].first * v[i].second - a[i];
        if (i) dp[i] = max(dp[i], cht.max_y(v[i].second) + v[i].first * v[i].second - a[i]);
        cht.insert_line({-v[i].first, dp[i]});
    }
    for (int i = 0; i < n-1; i++) assert(v[i].second > v[i + 1].second);

    ll ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0;
}