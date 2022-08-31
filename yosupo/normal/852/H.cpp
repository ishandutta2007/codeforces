#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
template <class T> using VVV = V<VV<T>>;
template <class T> T chmax(T& l, const T& r) { l = max(l, r); }

template <class T> ostream& operator<<(ostream& os, const V<T> &v) {
    os << "[";
    for (auto d: v) os << d << ", ";
    return os << "]";
}

using D = ll;
const D EPS = 0;

int sgn(D a) { return (a < -EPS) ? -1 : (a > EPS); }
int sgn(D a, D b) { return sgn(a - b); }
struct Pt2 {
    D x, y;
    Pt2(D _x = D(), D _y = D()) : x(_x), y(_y) {}
    Pt2 operator+(const Pt2& r) const { return Pt2(x + r.x, y + r.y); }
    Pt2 operator-(const Pt2& r) const { return Pt2(x - r.x, y - r.y); }
    Pt2 operator*(const Pt2& r) const { return Pt2(x*r.x-y*r.y, x*r.y+y*r.x);
    }

    Pt2 operator*(const D& r) const { return Pt2(x * r, y * r); }
    Pt2 operator/(const D& r) const { return Pt2(x / r, y / r); }

    Pt2& operator+=(const Pt2& r) { return *this = *this + r; }
    Pt2& operator-=(const Pt2& r) { return *this = *this - r; }
    Pt2& operator*=(const Pt2& r) { return *this = *this * r; }
    Pt2& operator*=(const D& r) { return *this = *this * r; }
    Pt2& operator/=(const D& r) { return *this = *this / r; }

    Pt2 operator-() const { return Pt2(-x, -y); }

    bool operator<(const Pt2& r) const { return 2*sgn(x, r.x)+sgn(y, r.y)<0; }
    bool operator==(const Pt2& r) const { return sgn((*this-r).rabs()) == 0; }

    D norm() const { return x * x + y * y; }
    D rabs() const { return max(std::abs(x), std::abs(y)); }  // robust abs

    pair<D, D> to_pair() const { return make_pair(x, y); }
};
ostream& operator<<(ostream& os, const Pt2& p) {
    return os << "P(" << p.x << ", " << p.y << ")";
}

using P = Pt2;

D cross(P a, P b) { return a.x * b.y - a.y * b.x; }
D dot(P a, P b) { return a.x * b.x + a.y * b.y; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20) << fixed;
    int n, k;
    cin >> n >> k; k--;
    V<P> ps(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ps[i] = P(x, y);
    }

    sort(ps.begin(), ps.end(), [&](P a, P b) {
        if (a.y != b.y) return a.y < b.y;
        return a.x > b.x;
    });

    ll ans = 0;
    for (int s = k; s < n; s++) {
        //use[0, s) + s
        P st = ps[s];
        sort(ps.begin(), ps.begin() + s, [&](P a, P b) {
            return cross(a - st, b - st) > 0;
        });

//        cerr << V<P>(ps.begin(), ps.begin() + s) << " : " << st << endl;
        VV<int> vid(s);
        for (int i = 0; i < s; i++) {
            V<int> buf;
            for (int j = i+1; j < s; j++) buf.push_back(j);
            sort(buf.begin(), buf.end(), [&](int l, int r) {
                return cross(ps[l] - ps[i], ps[r] - ps[i]) > 0;
            });

            for (int d: buf) {
                while (vid[i].size() && vid[i].back() > d) vid[i].pop_back();
                vid[i].push_back(d);
            }
//            cerr << i << " : " << vid[i] << endl;
        }

        //static ll dp[202][52][202];
        VVV<ll> dp(s);
        for (int i = 0; i < s; i++) {
            dp[i] = VV<ll>(k + 1, V<ll>(vid[i].size() + 1, -TEN(18)));
            //for (int uc = 0; uc <= k; uc++) fill_n(dp[i][uc], 202, -TEN(18));
            dp[i][1][0] = 0;
        }

        for (int i = 0; i < s; i++) {
            int m = int(vid[i].size());
            for (int j = 0; j < m; j++) {
                int ni = vid[i][j];
                int nj = lower_bound(vid[ni].begin(), vid[ni].end(), ps[ni] - ps[i], [&](int a, P b) {
                    return cross(ps[a] - ps[ni], b) > 0;
                }) - vid[ni].begin();
                ll cng = cross(ps[i] - st, ps[ni] - st);
                for (int uc = 1; uc <= k; uc++) {
                    chmax(dp[i][uc][j + 1], dp[i][uc][j]);
                    if (uc < k) {
                        chmax(dp[ni][uc + 1][nj], dp[i][uc][j] + cng);
                    }
                }
            }
            ans = max(ans, dp[i][k][m]);
/*            if (dp[i][k][m]) {
                cerr << "FIND! " << s << " " << i << endl;
            }*/
        }
    }
    string s = to_string(ans / 2);
    if (ans % 2) s += ".50";
    else s += ".00";
    cout << s << endl;
    return 0;
}