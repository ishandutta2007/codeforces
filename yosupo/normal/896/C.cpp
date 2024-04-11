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

struct rng {
    struct A {
        int n;
        const bool operator!=(A r) { return n != r.n; }
        A& operator++() { n++; return *this; }
        int operator*() { return n; }
    };
    int l, r;
    rng(int r) : l(0), r(max(0, r)) {}
    rng(int l, int r) : l(l), r(max(l, r)) {}
    A begin() { return A{l}; }
    A end() { return A{r}; }
};

ll pow_mod(ll x, ll n, ll md) {
    x %= md;
    ll r = 1 % md;
    while (n) {
        if (n & 1) r = (r*x) % md;
        x = (x*x) % md;
        n >>= 1;
    }
    return r;
}

ll seed;
int nxt() {
    auto ret = seed;
    seed = (seed * 7 + 13) % (TEN(9)+7);
    return ret;
}


using R = tuple<int, int, ll>;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    int n, m; ll vmax;
    cin >> n >> m >> seed >> vmax;


    set<R> s;
    for (int i = 0; i < n; i++) {
        ll aa = nxt() % vmax + 1;
//        cout << aa << ", ";
        s.insert(R(i, i+1, aa));
    }
//    cout << endl;

    for (int i = 0; i < m; i++) {
//        cerr << s.size() << endl;
/*        for (auto u: s) {
            int a, b; ll c;
            tie(a, b, c) = u;
            cout << "(" << a << ", " << b << ", " << c << "), ";
        }
        cout << endl;*/

        int op = nxt() % 4 + 1;
        int l = nxt() % n + 1;
        int r = nxt() % n + 1;
        if (l > r) swap(l, r);
        ll x = 0, y = 0;
        if (op == 3) {
            x = nxt() % (r - l + 1) + 1;
        } else {
            x = nxt() % vmax + 1;
        }
        if (op == 4) {
            y = nxt() % vmax + 1;
        }

//        cout << op << " " << l << " " << r << " " << x << " " << y << endl;
        l--;

        {
            //left
            auto it = s.lower_bound(R(l, -1, -1));
            if (it != s.begin()) {
                it--;
                int a, b; ll c;
                tie(a, b, c) = *it;
                it = s.erase(it);
                if (a != l) s.insert(R(a, l, c));                
                if (l != b) s.insert(R(l, b, c));
            }
        }
        {
            //right
            auto it = s.lower_bound(R(r, -1, -1));
            if (it != s.begin()) {
                it--;
                int a, b; ll c;
                tie(a, b, c) = *it;
                it = s.erase(it);
                if (a != r) s.insert(R(a, r, c));                
                if (r != b) s.insert(R(r, b, c));
            }
        }
        if (op == 1) {
            //add
            auto it = s.lower_bound(R(l, -1, -1));
            while (it != s.end() && get<1>(*it) <= r) {
                auto u = *it;
                it = s.erase(it);
                get<2>(u) += x;
                s.insert(u);
            }
        } else if (op == 2) {
            //assign
            auto it = s.lower_bound(R(l, -1, -1));
            while (it != s.end() && get<1>(*it) <= r) {
                it = s.erase(it);
            }
            s.insert(R(l, r, x));
        } else if (op == 3) {
            auto it = s.lower_bound(R(l, -1, -1));
            using P = pair<ll, int>;
            V<P> v;
            while (it != s.end() && get<1>(*it) <= r) {
                int a, b; ll c;
                tie(a, b, c) = *it;
                v.push_back(P(c, b-a));
                it++;
            }
            sort(begin(v), end(v));
            ll ans = -1;
            x--;
            for (auto p: v) {
                if (x < p.second) {
                    ans = p.first;
                    break;
                }
                x -= p.second;
            }
            cout << ans << endl;
        } else {
            ll ans = 0;
            auto it = s.lower_bound(R(l, -1, -1));
            while (it != s.end() && get<1>(*it) <= r) {
                int a, b; ll c;
                tie(a, b, c) = *it;
                ans += (b-a) * pow_mod(c, x, y);
                ans %= y;
                it++;
            }
            cout << ans << endl;
        }
    }
    return 0;
}