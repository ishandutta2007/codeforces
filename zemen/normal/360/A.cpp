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

#define INF 1000000000
#define INFL 1000000000000000001ll
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

ll a[100000];
ll b[100000];

int q[100000];
int lb[100000];
int rb[100000];
ll v[100000];
int m, n;

char check() {
    for (int i = 0; i < n; ++i)
        if (llabs(a[i]) > 1000000000ll)
            return 1;
    memset(b, 0, sizeof(b));
    for (int ii = 0; ii < m; ++ii) {
        if (q[ii] == 1) {
            for (int i = lb[ii]; i < rb[ii]; ++i)
                b[i] += v[ii];
        } else {
            ll val = -INF;
            for (int i = lb[ii]; i < rb[ii]; ++i)
                val = max(val, a[i] + b[i]);
            if (val != v[ii])
                return 1;
        }
    }
    return 0;
}

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        a[i] = INF;
    for (int ii = 0; ii < m; ++ii) {
        int op, l, r;
        ll c;
        cin >> op >> l >> r >> c;
        --l;
        q[ii] = op;
        lb[ii] = l;
        rb[ii] = r;
        v[ii] = c;

        if (op == 1) {
            for (int i = l; i < r; ++i)
                b[i] += c;
        } else {
            char ok = 0;
            for (int i = l; i < r; ++i) {
                a[i] = min(a[i], c - b[i]);
                if (c - b[i] == a[i])
                    ok = 1;
            }
            if (!ok) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    if (check()) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i)
        cout << a[i] << ' ';
    cout << '\n';
}