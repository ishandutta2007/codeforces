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

const ll MD = 1e9+7;

const int MN = 300100;

ll fact[MN], invFact[MN];

/// x^n % md
ll pow_mod(ll x, ll n, ll md) {
    ll r = 1;
    while (n) {
        if (n & 1) r = (r * x) % md;
        x = (x * x) % md;
        n >>= 1;
    }
    return r;
}

/// x, mdxmd
ll invp(ll x, ll md) {
    return pow_mod(x, md-2, md);
}

void init() {
    fact[0] = 1;
    for (int i = 1; i < MN; i++) {
        fact[i] = fact[i-1] * i;
        fact[i] %= MD;
    }
    for (int i = 0; i < MN; i++) {
        invFact[i] = invp(fact[i], MD);
    }
}

//fact[i]:i! invFact[i]:i! nCk
ll comb_st(int n, int k) {
    if (n < k || k < 0) return 0;
    return fact[n]*invFact[k]%MD*invFact[n-k]%MD;
}



const int MM = 2020;

int h, w, n;

int x[MM], y[MM];


ll dp[MM];
ll calc(int id) {
    if (dp[id] != -1) return dp[id];
    int xx = x[id], yy = y[id];
    ll r = comb_st(x[id]+y[id], x[id]);
    for (int i = 0; i < n; i++) {
        int nx = x[i], ny = y[i];
        if (xx == nx && yy == ny) continue;
        if (nx > xx || ny > yy) continue;
        r -= calc(i)*comb_st(xx-nx + yy-ny, xx-nx);
        r %= MD;
    }
    r = (r%MD+MD) % MD;
    return dp[id] = r;
}



int main() {
    init();
    memset(dp, -1, sizeof(dp));
    cin >> h >> w >> n;
    for (int i = 0; i < n; i++) {
        cin >> y[i] >> x[i]; x[i]--; y[i]--;
    }
    y[n] = h-1; x[n] = w-1; n++;
    cout << calc(n-1) << endl;
    return 0;
}