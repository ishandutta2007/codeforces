#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
const int MN = 100010;
const int LMN = 17;

complex<ll> d[MN];
int p[LMN][MN], dp[MN];
int c[MN], cc = 0;
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        ll x, h;
        scanf("%I64d %I64d", &x, &h);
        d[n-i-1] = complex<ll>(x, h);
    }
    p[0][0] = -1;
    dp[0] = 1;
    cc = 1;
    c[0] = 0;
    for (int i = 1; i < n; i++) {
        int l = 0, r = cc;
        while (r - l > 1) {
            int ml = (l*2+r)/3, mr = (l+r*2)/3;
            complex<ll> dl = d[c[ml]] - d[i], dr = d[c[mr]] - d[i];
            if (dl.real()*dr.imag() >= dl.imag()*dr.real()) {
                l = ml+1;
            } else {
                r = mr;
            }
        }
        p[0][i] = c[l];
        dp[i] = dp[c[l]] + 1;
        c[l+1] = i;
        cc = l+2;
    }
    for (int i = 1; i < LMN; i++) {
        for (int j = 0; j < n; j++) {
            if (p[i-1][j] < 0) p[i][j] = -1;
            else p[i][j] = p[i-1][p[i-1][j]];
        }
    }
    int q;
    scanf("%d", &q);
    vector<int> res;
    for (int i = 0; i < q; i++) {
        int a, b, r = 0;
        scanf("%d %d", &a, &b); a = n-a; b = n-b;
        if (dp[a] < dp[b]) swap(a, b);
        int dp2 = dp[a] - dp[b];
        for (int j = 0; j < LMN; j++) {
            if ((dp2 >> j) & 1) {
                a = p[j][a];
            }
        }
        if (a == b) {
            r = a;
        } else {
            for (int j = LMN-1; j >= 0; j--) {
                if (p[j][a] != p[j][b]) {
                    a = p[j][a]; b = p[j][b];
                }
            }
            r = p[0][a];
        }
        res.push_back(n-r);
    }
    for (int i = 0; i < res.size(); i++) {
        printf("%d", res[i]);
        if (i == res.size()-1) {
            printf("\n");
        } else {
            printf(" ");
        }
    }
    return 0;
}