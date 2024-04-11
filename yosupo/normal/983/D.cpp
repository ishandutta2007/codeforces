//#define _GLIBCXX_DEBUG
const bool STR = false;
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <random>
#include <vector>
#include <array>
#include <bitset>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

struct Node {
    using NP = Node*;
    int sz;
    NP l, r;
    set<int, greater<int>> colored, uncolored;
    int ma, mi;
    void update() {
        ma = -1; mi = -1;
        if (sz > 1) {
            ma = max(l->ma, r->ma);
            mi = min(l->mi, r->mi);
        }
        if (colored.size()) ma = max(ma, *begin(colored));
        if (uncolored.size()) {
            mi = max(mi, *begin(uncolored));
        }
        if (ma < mi) ma = -1;
    }
    Node(int sz) : sz(sz) {
        ma = mi = -1;
        if (sz == 1) return;
        l = new Node(sz/2);
        r = new Node(sz-sz/2);
    }
    ~Node() {
        if (sz == 1) return;
        delete l; delete r;
    }
    void addl(int a, int b, int idx, bool col) {
        if (b <= 0 || sz <= a) return;
        if (a <= 0 && sz <= b) {
            if (col) {
                colored.insert(idx);
            } else {
                uncolored.insert(idx);
            }
            update();
            return;
        }
        l->addl(a, b, idx, col);
        r->addl(a-sz/2, b-sz/2, idx, col);
        update();
    }
    void eral(int a, int b, int idx, bool col) {
        if (b <= 0 || sz <= a) return;
        if (a <= 0 && sz <= b) {
            if (col) {
                assert(colored.count(idx));
                colored.erase(idx);
            } else {
                assert(uncolored.count(idx));
                uncolored.erase(idx);
            }
            update();
            return;
        }
        l->eral(a, b, idx, col);
        r->eral(a-sz/2, b-sz/2, idx, col);
        update();        
    }
};

int solve(int n, V<ll> l, V<ll> r, V<int> d, V<int> u) {
    V<int> yv;
    for (int i = 0; i < n; i++) {
        l[i] *= TEN(9); r[i] *= TEN(9);
        l[i] -= i+1; r[i] += i+1;
        yv.push_back(d[i]);
        yv.push_back(u[i]);
    }
    sort(begin(yv), end(yv));
    yv.erase(unique(begin(yv), end(yv)), end(yv));
    for (int i = 0; i < n; i++) {
        d[i] = lower_bound(begin(yv), end(yv), d[i]) - begin(yv);
        u[i] = lower_bound(begin(yv), end(yv), u[i]) - begin(yv);
    }
    using EV = pair<ll, int>; //time, idx
    V<EV> ev;
    for (int i = 0; i < n; i++) {
        ev.push_back(EV(l[i], -(i+1)));
        ev.push_back(EV(r[i], i+1));
    }
    sort(begin(ev), end(ev));
    int m = int(yv.size());
    auto tr = new Node(m);
    V<bool> col(n);
    for (auto e: ev) {
        int idx = e.second;
        if (idx < 0) {
            idx *= -1; idx--;
            //add idx
//            cerr << "ADD " << d[idx] << " " << u[idx] << " " << idx << endl;
            tr->addl(d[idx], u[idx], idx, true);
        } else {
            idx--;
            //era idx
//            cerr << "ERA " << d[idx] << " " << u[idx] << " " << idx << endl;
            tr->eral(d[idx], u[idx], idx, !col[idx]);
        }
        while (tr->ma != -1) {
            int p = tr->ma;
//            cerr << "## FIND! " << p << endl;
            assert(!col[p]);
            col[p] = true;
            tr->eral(d[p], u[p], p, true);
            tr->addl(d[p], u[p], p, false);
        }
    }
    delete tr;
/*    for (int i = 0; i < n; i++) {
        cout << col[i] << ", ";
    }
    cout << endl;*/

    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (col[i]) ans++;
    }
    return ans;
}


int naive(int n, V<ll> l, V<ll> r, V<int> d, V<int> u) {
    using P = pair<ll, ll>;
    set<P> s;
    int ans = 1;
    for (int i = n-1; i >= 0; i--) {
        bool ok = false;
        for (int x = l[i]; x < r[i]; x++) {
            for (int y = d[i]; y < u[i]; y++) {
                if (!s.count(P(x, y))) ok = true;
                s.insert(P(x, y));
            }
        }
        if (ok) ans++;
    }
    return ans;
}

ll rand_int(ll l, ll r) { //[l, r]
    using D = uniform_int_distribution<ll>;
    static random_device rd;
    static mt19937 gen(rd());
    return D(l, r)(gen);
}

int main() {
    if (!STR) {
        int n;
        cin >> n;
        V<ll> l(n), r(n);
        V<int> d(n), u(n);
        for (int i = 0; i < n; i++) {
            cin >> l[i] >> d[i] >> r[i] >> u[i];
        }    
        cout << solve(n, l, r, d, u) << endl;
    } else {
        for (int ph = 0; ph < 100000; ph++) {
            int n = rand_int(1, 6);
            V<ll> l(n), r(n);
            V<int> d(n), u(n);
            for (int i = 0; i < n; i++) {
                l[i] = rand_int(0, 20);
                r[i] = rand_int(l[i]+1, 21);
                d[i] = rand_int(0, 20);
                u[i] = rand_int(d[i]+1, 21);        
            }
            int a1 = solve(n, l, r, d, u);
            int a2 = naive(n, l, r, d, u);
            if (a1 != a2) {
                cout << n << endl;
                for (int i = 0; i < n; i++) {
                    cout << l[i] << " " << d[i] << " " << r[i] << " " << u[i] << endl;
                }

                cout << "# " << a1 << " " << a2 << endl;
            }
            assert(a1 == a2);
        }
    }
}