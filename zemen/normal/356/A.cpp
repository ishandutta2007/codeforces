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

#define NAME "a"
//~ #undef NAME
#ifndef NAME
    #error "Write problem name"
#endif

#define BASE 524288
int t[BASE * 2];
int upd[BASE * 2];
int winner[1000000];

void push(int v) {
    t[v * 2] = min(t[v * 2], upd[v]);
    upd[v * 2] = min(upd[v * 2], upd[v]);
    t[v * 2 + 1] = min(t[v * 2 + 1], upd[v]);
    upd[v * 2 + 1] = min(upd[v * 2 + 1], upd[v]);
    upd[v] = 999999;
}

int get(int l, int r, int v = 1, int cl = 0, int cr = BASE) {
    if (l <= cl && cr <= r)
        return t[v];
    if (r <= cl || cr <= l)
        return 999999;
    push(v);
    int cc = (cl + cr) / 2;
    return min(
        get(l, r, v * 2, cl, cc),
        get(l, r, v * 2 + 1, cc, cr));
}

void put(int l, int r, int val, int v = 1, int cl = 0, int cr = BASE) {
    if (l <= cl && cr <= r) {
        upd[v] = min(upd[v], val);
        t[v] = min(t[v], val);
        return;
    }
    if (r <= cl || cr <= l)
        return;
    push(v);
    int cc = (cl + cr) / 2;
    put(l, r, val, v * 2, cl, cc);
    put(l, r, val, v * 2 + 1, cc, cr);
}

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < BASE * 2; ++i)
        t[i] = upd[i] = 999999;
    winner[999999] = 0;
    for (int i = 0; i < m; ++i) {
        int l, r, w;
        scanf("%d%d%d", &l, &r, &w);
        put(l, w, i);
        put(w + 1, r + 1, i);
        winner[i] = w;
    }
    for (int i = 1; i <= n; ++i) {
        cout << winner[get(i, i + 1)] << ' ';
    }
}