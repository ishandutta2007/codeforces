#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

const bool DEB = false;
ll ans;
int qc;

bool query(ll x, ll y) {
    if (DEB) {
        qc++;
        ll a = x % ans, b = y % ans;
        return a >= b;
    } else {
        cout << "? " << x << " " << y << endl;
        string s;
        cin >> s;
        return s == "x";
    }
}

void answer(ll z) {
    if (DEB) {
        assert(ans == z);
        cerr << "correct qc: " << qc << endl;
    } else {
        cout << "! " << z << endl;
    }
}

ll rand_int(ll l, ll r) { //[l, r]
    static random_device rd;
    static mt19937 gen(rd());
    return uniform_int_distribution<ll>(l, r)(gen);
}

void solve() {
    ll a = 0, b = 1;
    while (true) {
        bool f = query(a, b);
        if (!f) {
            a = b;
            b *= 2;
            continue;
        }
        break;
    }
    ll lw = a, up = b;
    while (up - lw > 1) {
        ll md = (lw + up) / 2;
        if (!query(md, a)) {
            up = md;
        } else {
            lw = md;
        }
    }
    answer(up);
}

void check(ll _ans) {
    cerr << "check : " << _ans << endl;
    ans = _ans;
    qc = 0;
    solve();
}

int main() {
    if (DEB) {
        for (int i = 1; i <= 10; i++) {
            check(rand_int(1, TEN(9)));
        }
    } else {
        while (true) {
            string s;
            cin >> s;
            if (s == "end") break;
            assert(s == "start");
            solve();
        }
    }
    return 0;
}