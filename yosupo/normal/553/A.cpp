#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const ll MD = 1e9+7;
const int MK = 1100;
const int MN = 2020;
// x^n % md
ll pow_mod(ll x, ll n, ll md) {
    ll r = 1;
    while (n) {
        if (n & 1) r = (r * x) % md;
        x = (x * x) % md;
        n >>= 1;
    }
    return r;
}

/// x, , mdxmd
ll invp(ll x, ll md) {
    return pow_mod(x, md-2, md);
}

ll fact[MN], invFact[MN];

//fact[i]:i! invFact[i]:i! nCk
ll comb_st(int n, int k) {
    if (n < k || k < 0) return 0;
    return fact[n]*invFact[k]%MD*invFact[n-k]%MD;
}

int k;
int d[MK];

int main() {
    fact[0] = 1;
    for (int i = 1; i < MN; i++) {
        fact[i] = fact[i-1]*i;
        fact[i] %= MD;
    }
    for (int i = 0; i < MN; i++) {
        invFact[i] = invp(fact[i], MD);
    }

    cin >> k;
    ll sm = 0;
    ll res = 1;
    for (int i = 0; i < k; i++) {
        cin >> d[i];
        res *= comb_st(sm+d[i]-1, sm);
        res %= MD;
        sm += d[i];
    }
    cout << res << endl;
    return 0;
}