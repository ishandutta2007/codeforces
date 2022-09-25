#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <complex>
#include <cassert>

using namespace std;

#define INF __INT_MAX__
#define INFL __LONG_LONG_MAX__
#define pb push_back
#define fi first
#define se second
#define mp make_pair

typedef long long ll;
typedef long double ld;
typedef complex <double> point;

#define NAME "a"
//~ #undef NAME
#ifndef NAME
    #error "Write problem name"
#endif

int a[200001];
#define BASE 2000000000ll

pair <ll, ll> add(pair <ll, ll> a, pair <ll, ll> b) {
    ll q = a.se + b.se;
    return mp(a.fi + b.fi + q / BASE, q % BASE);
}

pair <ll, ll> mul(ll a, pair <ll, ll> b) {
    b.se *= a;
    b.fi *= a;
    b.fi += b.se / BASE;
    b.se %= BASE;
    return b;
}

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    ll n;
    ll k;
    cin >> n >> k;
    k = -k;
    pair <ll, ll> sum = mp(0, 0);
    ll t;
    ll cnt = 0;
    for (ll i = 1; i <= n; ++i) {
        cin >> t;
        if (add(sum, mp(0, k)) < mul(n - i, mul(t, mp(0, cnt)))) {
            cout << i << '\n';
        } else {
            sum = add(sum, mul(t, mp(0, cnt)));
            ++cnt;
        }
    }
}