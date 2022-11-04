#include <bits/stdc++.h>
using namespace std;

const size_t maxn = 1 << 20;
const int mod = 998244353;

char a[maxn], l[maxn << 1], r[maxn << 1];
int zl[maxn << 1], zr[maxn << 1];
int la, ll, lr;
int dp[maxn], sum[maxn];

void add(int &dp, int val) {
    if (val >= mod) val -= mod;
    dp += val;
    if (dp >= mod) dp -= mod;
}

void z_func(char str[], int z[]) {
    int len = strlen(str);
    for (int i = 1, l = 0, r = 0; i < len; ++i) {
        if (i <= r) z[i] = min(z[i - l], r - i + 1);
        for (; i + z[i] < len && str[i + z[i]] == str[z[i]]; ++z[i]) {}
        if (r <= i + z[i] - 1) { l = i; r = i + z[i] - 1; }
    }
}

bool larger(int i) {
    if (i < 0) return false;
    int pos = zl[i];
    if (pos == ll) return true;
    return l[pos] < a[i + pos];
}

bool smaller(int i) {
    if (i < 0) return true;
    int pos = zr[i];
    if (pos == lr) return true;
    return a[i + pos] < r[pos];
}

int main() {
    scanf("%s", a); la = strlen(a);
    scanf("%s", l); ll = strlen(l); l[ll] = '#';
    for (int i = 0; i < la; ++i) l[ll + 1 + i] = a[i];
    scanf("%s", r); lr = strlen(r); r[lr] = '#';
    for (int i = 0; i < la; ++i) r[lr + 1 + i] = a[i];
    z_func(l, zl); z_func(r, zr);
    for (int i = 0; i < la; ++i) zl[i] = zl[i + ll + 1];
    for (int i = 0; i < la; ++i) zr[i] = zr[i + lr + 1];
    for (int i = 0; i < la; ++i) {
        if (i) add(sum[i], sum[i - 1]);
        int rb = i - ll;
        if (larger(i - ll + 1)) ++rb;
        int lb = i - lr + 2;
        if (smaller(i - lr + 1)) --lb;
        if (lb <= 0 && 0 <= rb) {
            add(dp[i], 1);
        }
        lb = max(lb, 0);
        rb = min(rb, i);
        if (lb <= rb) {
            add(dp[i], sum[rb]);
            add(dp[i], mod - (lb ? sum[lb - 1] : 0));
        }
        if (rb == i && a[i] == '0') {
            add(dp[i], i ? dp[i - 1] : 0);
        }
        if (a[i + 1] != '0') {
            add(sum[i + 1], dp[i]);
        }
    }
    printf("%d\n", dp[la - 1]);
    return 0;
}