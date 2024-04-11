#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

template<class T> ostream& operator<<(ostream& os, const V<T> &v) {
    cout << "[";
    for (auto p: v) cout << p << ", ";
    cout << "]";
    return os;
}

ll rand_int(ll l, ll r) { // [l, r]
    using D = uniform_int_distribution<ll>;
    static random_device rd;
    static mt19937 gen(rd());
    return D(l, r)(gen);
}


const bool DEB = false;
ll n;
ll deb_x, deb_y;
void init() {
    if (DEB) {
        n = TEN(18) - 1919;
//        n = rand_int(1, TEN(18));
        deb_x = rand_int(1, n);
        deb_y = rand_int(1, n);
    } else {
        cin >> n;
    }
}


int query(ll x, ll y) {
    assert(1 <= x && x <= n);
    assert(1 <= y && y <= n);
    if (DEB) {
        static int gc = 0;
        gc++;
        V<int> pred;
        if (deb_x < x || deb_y < y) pred.push_back(3);
        if (x < deb_x) pred.push_back(1);
        if (y < deb_y) pred.push_back(2);
        int c = int(pred.size());
        if (c) return pred[rand_int(0, c-1)];
        cout << "CONGRAT! : " << gc << " " << deb_x << " " << deb_y << endl;
        assert(deb_x == x && deb_y == y);
        exit(0);
    } else {
        cout << x << " " << y << endl;
        int ty;
        cin >> ty;
        if (ty == 0) exit(0);
        return ty;
    }
}

void solve(ll la, ll lb, ll ua, ll ub);

// [la, ua], [lb, ub], query(ma, mb) == 3
void solve(ll la, ll lb, ll ua, ll ub, ll ma, ll mb) {
    if (ma == la) {
        solve(la, lb, ua, mb-1);
        assert(false);
    }
    if (mb == lb) {
        solve(la, lb, ma-1, ub);
        assert(false);
    }

    ll da = ma - la + 1;
    ll db = mb - lb + 1;
    if (da > db) {
        ll xa = (ma + la) / 2;
        int ty1 = query(xa, mb);
        if (ty1 == 1) {
            solve(xa+1, lb, ua, ub, ma, mb);
            assert(false);
        }
        if (ty1 == 2) {
            solve(la, mb+1, ma-1, ub);
            assert(false);
        }
        solve(la, lb, ua, ub, xa, mb);
    } else {
        ll xb = (mb + lb) / 2;
        int ty1 = query(ma, xb);
        if (ty1 == 2) {
            solve(la, xb+1, ua, ub, ma, mb);
            assert(false);
        }
        if (ty1 == 1) {
            solve(ma+1, lb, ua, mb-1);
            assert(false);
        }
        solve(la, lb, ua, ub, ma, xb);
    }
    assert(false);
}

// [la, ua], [lb, ub]
void solve(ll la, ll lb, ll ua, ll ub) {
    if (la == ua && lb == ub) query(la, lb);
    ll ma = (3 * la + ua) / 4;
    ll mb = (3 * lb + ub) / 4;
    int ty = query(ma, mb);
    if (ty == 1) {
        // ma < true_a
        solve(ma+1, lb, ua, ub);
        assert(false);
    }
    if (ty == 2) {
        // mb < true_b
        solve(la, mb+1, ua, ub);
        assert(false);
    }
    solve(la, lb, ua, ub, ma, mb);
}

int main() {
    init();
    solve(1, 1, n, n);

    assert(false);
    return 0;
}