const bool DEBUG = false;
const int N_BASE = 50000;

#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

using D = double;
using P = complex<D>;

ll rand_int(ll l, ll r) { //[l, r]
    using Dist = uniform_int_distribution<ll>;
    static random_device rd;
    static mt19937 gen(rd());
    return Dist(l, r)(gen);
}
D rand_D(D l, D r) { //[l, r]
    using Dist = uniform_real_distribution<D>;
    static random_device rd;
    static mt19937 gen(rd());
    return Dist(l, r)(gen);
}

const D PI = acos(D(-1)), EPS = 1e-10;

int sgn(D a) {
    if (abs(a) <= EPS) return 0;
    return (a < 0) ? -1 : 1;
}
bool near(P a, P b) { return !sgn(abs(a-b)); }
D mabs(P p) { return abs(p.real()) + abs(p.imag()); }

bool lessP(P l, P r) {
    if (sgn(r.real()-l.real())) return l.real() < r.real();
    if (sgn(r.imag()-l.imag())) return l.imag() < r.imag();
    return false;
}

D cross(P a, P b) { return a.real()*b.imag() - a.imag()*b.real(); }
D dot(P a, P b) { return a.real()*b.real() + a.imag()*b.imag(); }

int N, N1, N2;
V<P> p1, p2;

using Pi = pair<int, int>;
using K = pair<Pi, int>;
V<K> mp_p1, mp_p2;


Pi roundp(P p) {
    int x = int(round(p.real()));
    int y = int(round(p.imag()));
    return Pi(x, y);
}

V<int> ans1, ans2;

void shuff(V<P> &v, V<int> &ans) {
    assert(DEBUG);
    D dx = rand_D(-10000, 10000);
    D dy = rand_D(-10000, 10000);
    P d = P(dx, dy);
    D th = rand_D(0, 2*PI);
    P ar = polar<D>(1.0, th);
    for (auto &p: v) {
        p = (p + d) * ar;
        D x = round(p.real() * 100) / 100;
        D y = round(p.imag() * 100) / 100;
        p = P(x, y);
    }
    ans = V<int>(v.size());
    iota(begin(ans), end(ans), 0);
    V<P> v2(v.size());
    for (int i = 0; i < int(v.size()); i++) {
        v2[ans[i]] = v[i];
    }
    v = v2;
}
V<int> answer(V<Pi> v) {
    if (DEBUG) {
        set<Pi> st;
        assert(ans1.size() == N1);
        assert(ans2.size() == N2);
        for (int i = 0; i < N; i++) {
            st.insert(Pi(ans1[i], ans2[i]));
        }
        int ans = 0;
        for (auto pi: v) {
            if (st.count(pi)) {
                ans++;
                st.erase(pi);
            }
        }
        cout << "YOUR ANSWER: " << ans << " / " << N << endl;
    } else {
        while (v.size() < N) v.push_back(Pi(0, 0));
        for (auto p: v) {
            cout << p.first+1 << " " << p.second+1 << endl;
        }
    }
    exit(0);
}

void make() {
    if (DEBUG) {
        N1 = N + rand_int(0, N/2);
        N2 = N + rand_int(0, N/2);
        p1 = V<P>(N1); p2 = V<P>(N2);
        for (int i = 0; i < N; i++) {
            D x = rand_D(-10000, 10000);
            D y = rand_D(-10000, 10000);
            p1[i] = p2[i] = P(x, y);
        }
        for (int i = N; i < N1; i++) {
            D x = rand_D(-10000, 10000);
            D y = rand_D(-10000, 10000);
            p1[i] = P(x, y);
        }
        for (int i = N; i < N2; i++) {
            D x = rand_D(-10000, 10000);
            D y = rand_D(-10000, 10000);
            p2[i] = P(x, y);
        }
        shuff(p1, ans1); shuff(p2, ans2);
    } else {
        cin >> N;
        cin >> N1;
        p1 = V<P>(N1);
        for (int i = 0; i < N1; i++) {
            D x, y;
            cin >> x >> y;
            p1[i] = P(x, y);
        }
        cin >> N2;
        p2 = V<P>(N2);
        for (int i = 0; i < N2; i++) {
            D x, y;
            cin >> x >> y;
            p2[i] = P(x, y);
        }
    }


    for (int i = 0; i < N1; i++) {
        mp_p1.push_back(K(roundp(p1[i]), i));
    }    
    for (int i = 0; i < N2; i++) {
        mp_p2.push_back(K(roundp(p2[i]), i));
    }    
    sort(begin(mp_p1), end(mp_p1));
    sort(begin(mp_p2), end(mp_p2));
}



void check(int i1, int j1, int i2, int j2) {
    P di1 = -p1[i1], di2 = p2[i2];
    P base1 = polar<D>(1.0, -arg(p1[j1] - p1[i1]));
    P base2 = polar<D>(1.0, arg(p2[j2] - p2[i2]));

    V<Pi> res;
    for (int i = 0; i < N1; i++) {
        P q1 = p1[i]; q1 += di1; q1 *= base1; q1 *= base2; q1 += di2;
        Pi key = roundp(q1);
        auto it = lower_bound(begin(mp_p2), end(mp_p2), K(key, -1));
        if (it != mp_p2.end() && it->first == key) {
            res.push_back(Pi(i, it->second));
        }
        if (i == N1/40 && res.size() <= 10) break;
    }
    if (res.size() > N*9 / 10) answer(res);
}

D norm(const P &p) {
    return p.real() * p.real() + p.imag() * p.imag();
}
void solve() {
    map<D, Pi> mp;
    constexpr int B = 13000;
    for (int ph = 0; ph < B; ph++) {
        int i = rand_int(0, N1-1);
        D mi = 1e100; int mj = -1;
        for (int j = 0; j < N1; j++) {
            if (i == j) continue;
            D di = norm(p1[i]-p1[j]);
            if (di < mi) {
                mi = di;
                mj = j;
            }
        }
        mp[sqrt(mi)] = Pi(i, mj);
    }
//    cerr << "START!" << endl;
    for (int ph = 0; ph < B; ph++) {
        int i = rand_int(0, N2-1);
        D mi = 1e100; int mj = -1;
        for (int j = 0; j < N2; j++) {
            if (i == j) continue;
            D di = norm(p2[i]-p2[j]);
            if (di < mi) {
                mi = di;
                mj = j;
            }
        }
        mi = sqrt(mi);
        auto it = mp.lower_bound(mi);
        if (it == mp.end()) continue;
        auto buf = *it;
//        cerr << mi << " " << buf.first << " " << abs(mi-buf.first) << endl;
        if (abs(mi - buf.first) < 1e-2) {
            cerr << "FIND? " << mi << " " << buf.first << endl;
            check(buf.second.first, buf.second.second, i, mj);
            check(buf.second.first, buf.second.second, mj, i);
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    N = N_BASE;
    make();
    solve();
    return 0;
}