#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <ostream>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

using PV = pair<V<ll>, V<ll>>;

ll solve(V<ll> vl, V<ll> vr, ll k) {
    V<int> pl = {0, int(vl.size())};
    V<int> pr = {0, int(vr.size())};
    ll ans = 0;
    V<ll> nvl, nvr;
    V<int> npl, npr;
    V<ll> buf00, buf01, buf10, buf11;
    for (int ph = 62; ph >= 0; ph--) {
        int n = int(pl.size()) - 1;

        ll lw_sm = 0;
        for (int i = 0; i < n; i++) {
            ll c00 = 0, c01 = 0, c10 = 0, c11 = 0;
            for (int j = pl[i]; j < pl[i+1]; j++) {
                ll d = vl[j];
                if (d & (1LL << ph)) c01++;
                else c00++;
            }
            for (int j = pr[i]; j < pr[i+1]; j++) {
                ll d = vr[j];
                if (d & (1LL << ph)) c11++;
                else c10++;
            }
            lw_sm += c00 * c10 + c01 * c11;
        }
        bool nx_lw = k < lw_sm;
        nvl.clear(); nvr.clear();
        npl.clear(); npl.push_back(0);
        npr.clear(); npr.push_back(0);
        for (int i = 0; i < n; i++) {
            buf00.clear(); buf01.clear(); buf10.clear(); buf11.clear();
            for (int j = pl[i]; j < pl[i + 1]; j++) {
                ll d = vl[j];
                bool g = (d & (1LL << ph)) != 0;
                if (g) buf00.push_back(d);
                else buf01.push_back(d);
            }
            for (int j = pr[i]; j < pr[i + 1]; j++) {
                ll d = vr[j];
                bool g = (d & (1LL << ph)) != 0;
                if (!nx_lw) g = !g;
                if (g) buf10.push_back(d);
                else buf11.push_back(d);
            }
            if (buf00.size() && buf10.size()) {
                nvl.insert(nvl.end(), buf00.begin(), buf00.end());
                nvr.insert(nvr.end(), buf10.begin(), buf10.end());
                npl.push_back(int(nvl.size()));
                npr.push_back(int(nvr.size()));
            }
            if (buf01.size() && buf11.size()) {
                nvl.insert(nvl.end(), buf01.begin(), buf01.end());
                nvr.insert(nvr.end(), buf11.begin(), buf11.end());
                npl.push_back(int(nvl.size()));
                npr.push_back(int(nvr.size()));
            }
        }
        swap(vl, nvl); swap(vr, nvr);
        swap(pl, npl); swap(pr, npr);
        if (!nx_lw) {
            ans += (1LL << ph);
            k -= lw_sm;
        }
    }
    return ans;
}

ll rand_int(ll l, ll r) { //[l, r]
    static mt19937 gen(114514);
    return uniform_int_distribution<ll>(l, r)(gen);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; ll k;
//    n = TEN(6);
//    k = TEN(10);
    cin >> n >> k; k--;
    V<ll> w(n);
    w[0] = 0;
    for (int i = 1; i < n; i++) {
        int p; ll x;
        p = i-1;
//        x = rand_int(0, (1LL<<62) - 1);
        cin >> p >> x; p--;
        w[i] = w[p] ^ x;
    }
    cout << solve(w, w, k) << endl;

    return 0;
}