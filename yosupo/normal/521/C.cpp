//#define NDEBUG

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <cassert>
#include <numeric>
#include <cstdio>

using namespace std;
typedef long long ll;

//x^n
ll pow(ll x, ll n) {
    ll r = 1;
    while (n) {
        if (n & 1) r *= x;
        x *= x;
        n >>= 1;
    }
    return r;
}

//x^n % md
ll pow_mod(ll x, ll n, ll md) {
    ll r = 1;
    while (n) {
        if (n & 1) r = (r * x) % md;
        x = (x * x) % md;
        n >>= 1;
    }
    return r;
}


//x
ll invp(ll x, ll md) {
    return pow_mod(x, md-2, md);
}


const int MN = 100100;
const ll MD = 1e9+7;
int n, k;
ll d[MN];

ll pow10[MN];
ll sum[MN];
ll fact[MN];
ll invFact[MN];

//fact[i]:i! invfact[i]:i! nCk
ll comb_st(int n, int k) {
    if (n < k || k < 0) return 0;
    return fact[n]*invFact[k]%MD*invFact[n-k]%MD;
}

void init() {
    sum[0] = 0;
    for (int i = 0; i < n; i++) {
        sum[i+1] = (sum[i] + d[i]) % MD;
    }
    pow10[0] = 1;
    for (int i = 1; i < MN; i++) {
        pow10[i] = (pow10[i-1] * 10) % MD;
    }
    fact[0] = 1;
    for (int i = 1; i < MN; i++) {
        fact[i] = (fact[i-1] * i) % MD;
    }
    for (int i = 0; i < MN; i++) {
        invFact[i] = invp(fact[i], MD);
    }
}
ll solve() {
    init();
    ll res = 0;
    for (int i = 0; i < n-1; i++) {
        ll r = sum[n-1-i]*pow10[i]; r %= MD;
        r *= comb_st(n-i-2, k-1); r %= MD;
        res += r;
        res %= MD;
    }
    for (int i = 0; i < n; i++) {
        ll r = d[n-i-1]*pow10[i]; r %= MD;
        r *= comb_st(n-i-1, k); r %= MD;
        res += r;
        res %= MD;
    }
    return res;
}

int main() {
    cin >> n >> k;
    string s; cin >> s;
    for (int i = 0; i < n; i++) {
        d[i] = s[i] - '0';
    }
    cout << solve() << endl;
    return 0;
}