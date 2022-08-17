#include <cstdio>
#include <cassert>
#include <memory.h>
#include <iostream>
#include <tuple>
using namespace std;

typedef long long llong;

const int N = 2050;

struct trip {
    llong a, b, c;
    trip(llong _a, llong _b, llong _c) {
        a = _a, b = _b, c = _c;
    }
    void fill(llong& a, llong &b, llong& c) {
        a = this->a, b = this->b, c = this->c;
    }
    friend bool operator ==(const trip& a, const trip& b) {
        return a.a == b.a && a.b == b.b && a.c == b.c;
    }
    trip(){}
};

trip P[N];

llong gcd(llong a, llong b) {
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

trip norm(trip t) {
    llong a, b, c;
    t.fill(a, b, c);
    llong g = gcd(gcd(abs(a), abs(b)), abs(c));
    assert(g != 0);
    a /= g;
    b /= g;
    c /= g;
    if (a < 0 || (a == 0 && b < 0) || (a == 0 && b == 0 && c < 0))
        a = -a, b = -b, c = -c;
    return trip(a, b, c);
}

const int HT = 1 << 22;

int T[HT];
trip L[HT];

void inc(trip l) {
    llong a, b, c;
    l.fill(a, b, c);
    int h = abs(a * 424243 + b * 4243 + c * 43) & (HT - 1);
    while (L[h].a != -1 && !(L[h] == l)) {
        h = (h + 1) & (HT - 1);
    }
    if (L[h].a == -1)
        L[h] = l;
    T[h]++;
}

llong c2toc3[N * N];

const int MOD = 1e9 + 7;
int mul(int a, int b) {
    int res = 1ll * a * b % MOD;
    if (res < 0)
        res += MOD;
    return res;
}

int powmod(int x, int b) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = mul(res, x);
        b >>= 1;
        x = mul(x, x);
    }
    return res;
}

int inv(int x) {
    return powmod(x, MOD - 2);
}

int main() {
    int n;
    scanf("%d", &n);
    int cnt_origin = 0;
    int pt = 0;
    for (int i = 0; i < n; i++) {
        llong a, b, c;
        cin >> a >> b >> c;
        if (c == 0)
            cnt_origin++;
        else
            P[pt++] = norm(trip(a * c, b * c, a * a + b * b));
    }
    memset(L, -1, sizeof(L));
    for (int i = 0; i < pt; i++) {
        for (int j = 0; j < i; j++) {
            llong x1, y1, z1;
            P[i].fill(x1, y1, z1);
            llong x2, y2, z2;
            P[j].fill(x2, y2, z2);
            auto l = norm(trip(x1 * z2 - x2 * z1, y1 * z2 - y2 * z1, 0));
            int xx1 = mul(x1 % MOD, inv(z1 % MOD));
            int yy1 = mul(y1 % MOD, inv(z1 % MOD));
            int xx2 = l.a % MOD, yy2 = l.b % MOD;
            int vp = mul(xx1, yy2) - mul(xx2, yy1);
            if (vp < 0)
                vp += MOD;
            if (vp >= MOD)
                vp -= MOD;
            l.c = vp;
            inc(l); 
        }
    }
    for (int k = 0; k <= pt; k++) {
        c2toc3[k * (k - 1) / 2] = 1ll * k * (k - 1) * (k - 2) / 6;
    }
    llong ans = 0;
    for (int i = 0; i < HT; i++) {
        ans += c2toc3[T[i]];
    }
    ans += 1ll * cnt_origin * (cnt_origin - 1) / 2 * (n - cnt_origin);
    cout << ans << endl;
}