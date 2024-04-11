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

/// g:gcd(a, b), ax+by=g
struct EG { ll g, x, y; };
EG ext_gcd(ll a, ll b) {
    if (b==0) {
        if (a >= 0) return EG{a, 1, 0};
        else return EG{-a, -1, 0};
    } else {
        auto e = ext_gcd(b, a%b);
        return EG{e.g, e.y, e.x-a/b*e.y};
    }
}

ll inv_mod(ll x, ll md) {
    if (x == 0) return 0;
    auto z = ext_gcd(x, md).x;
    return (z % md + md) % md;
}

using Q = pair<ll, ll>;

map<int, Q> mp;

int main() {
    srand(time(NULL));
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20) << fixed;

    ll u, v, p;
    cin >> u >> v >> p;

    for (int ph = 0; ph < 100000; ph++) {
        Q q;
        int nw = u;
        int bk = -1;
        for (int i = 0; i < 50; i++) {
            int ty;
            while (true) {
                ty = rand() % 3;
                if (bk == 1 && ty == 0) continue;
                if (bk == 0 && ty == 1) continue;
                if (bk == 2 && ty == 2) continue;
                break;
            }
            bk = ty;
            if (ty == 0) {
                nw++; if (nw == p) nw = 0;
                q.first |= (1LL<<i);
            } else if (ty == 1) {
                nw--; if (nw == -1) nw = p-1;
                q.second |= (1LL<<i);
            } else {
                nw = inv_mod(nw, p);                
            }
        }
        if (mp.count(nw)) continue;
        mp[nw] = q;
    }
//    cout << mp.size() << endl;

    V<int> buf(50);
    while (true) {
        int nw = v;
        int bk = -1;
        for (int i = 0; i < 50; i++) {
            int ty;
            while (true) {
                ty = rand() % 3;
                if (bk == 1 && ty == 0) continue;
                if (bk == 0 && ty == 1) continue;
                if (bk == 2 && ty == 2) continue;
                break;
            }
            bk = ty;
            if (ty == 0) {
                nw++; if (nw == p) nw = 0;
                buf[i] = 1;
            } else if (ty == 1) {
                nw--; if (nw == -1) nw = p-1;
                buf[i] = 0;
            } else {
                nw = inv_mod(nw, p);
                buf[i] = 2;
            }
        }
        static int g = 0; g++;
        auto it = mp.find(nw);
        if (it != mp.end()) {
            ll mid = it->first;
            if (mid - nw > 98) continue;
//            cout << "FIND! " << g << " " << mid << " " << nw << endl;
            Q q = it->second;
            V<int> ans;
            for (int i = 0; i < 50; i++) {
                if (q.first & (1LL << i)) ans.push_back(0);
                else if (q.second & (1LL << i)) ans.push_back(1);
                else ans.push_back(2);
            }
            for (int i = 0; i < mid - nw; i++) {
                ans.push_back(0);
            }
            for (int i = 49; i >= 0; i--) {
                ans.push_back(buf[i]);
            }

            int deb = u;
            for (auto ty: ans) {
                if (ty == 0) {
                    deb++; if (deb == p) deb = 0;                    
                } else if (ty == 1) {
                    deb--; if (deb == -1) deb = p-1;
                } else {
                    deb = inv_mod(deb, p);
                }
            }
//            cout << u << " " << v << " " << deb << endl;
            assert(deb == v);
            cout << ans.size() << endl;
            for (auto ty: ans) {
                cout << (ty+1) << " ";
            }
            cout << endl;
            return 0;
        }
    }
    return 0;
}