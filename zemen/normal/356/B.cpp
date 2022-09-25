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

#define INF 1000000001
#define INFL 1000000000000000001ll
#define pb push_back
#define fi first
#define se second
#define mp make_pair

typedef long long ll;
typedef long double ld;
typedef complex <double> point;

#define NAME "b"
//~ #undef NAME
#ifndef NAME
    #error "Write problem name"
#endif

char s[1000010];
char t[1000010];
int cnt[1000001][26];

ll gcd(ll a, ll b) {
    while (a && b)
        if (a > b)
            a %= b;
        else
            b %= a;
    return a ? a : b;
}

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    ll n, m;
    cin >> n >> m;
    scanf("\n");
    gets(s);
    gets(t);
    ll l1 = strlen(s);
    ll l2 = strlen(t);
    ll g = gcd(l1, l2);
    for (int i = 0; i < l2; ++i)
        cnt[i % g][t[i] - 'a']++;
    ll per = (l1 * l2) / g;
    assert((n * l1) % per == 0);
    ll c = (n * l1) / per;
    //~ cerr << c << '\n';
    ll res = n * l1;
    for (int i = 0; i < l1; ++i)
        res -= c * cnt[i % g][s[i] - 'a'];
    cout << res << '\n';
}