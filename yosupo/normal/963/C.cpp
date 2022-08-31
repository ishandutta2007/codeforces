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

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    int n;
    cin >> n;

    using P = pair<ll, ll>;
    map<P, ll> ls;
    V<ll> wv(n), hv(n), cv(n);
    for (int i = 0; i < n; i++) {
        cin >> wv[i] >> hv[i] >> cv[i];
        ll w = wv[i], h = hv[i], c = cv[i];
        ls[P(w, h)] = c;
    }
    V<ll> ws = wv;
    sort(begin(ws), end(ws));
    ws.erase(unique(begin(ws), end(ws)), end(ws));
    V<ll> hs = hv;
    sort(begin(hs), end(hs));
    hs.erase(unique(begin(hs), end(hs)), end(hs));

    for (ll w: ws) {
        for (ll h: hs) {
            if (ls.count(P(w, h)) == 0) {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    
    map<ll, ll> mp;
    for (int i = 0; i < n; i++) {
        ll w = wv[i], h = hv[i], c = cv[i];
        ll z = mp[w];
        mp[w] = gcd(z, c);
    }
    
    map<ll, ll> mp2;
    for (int i = 0; i < n; i++) {
        ll w = wv[i], h = hv[i], c = cv[i];
        mp2[h] = c / mp[w];
    }

    for (ll w: ws) {
        for (ll h: hs) {
            ll c = ls[P(w, h)];
            if (mp2[h] != c / mp[w]) {
                cout << 0 << endl;
                return 0;
            }
            
        }
    }
    
    ll g = 0;
    for (auto p: mp) {
        g = gcd(g, p.second);
    }

    ll ans = 0;
    for (ll i = 1; i*i <= g; i++) {
        if (g % i) continue;
        ans++;
        if (i*i != g) ans++;
    }
    cout << ans << endl;
    return 0;
}