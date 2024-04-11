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
using ll = long long;
using ull = unsigned long long;
constexpr int TEN(int n) {return (n==0)?1:10*TEN(n-1);}

const int MN = 500500;
ll a[MN];

ll solve(int n, ll k) {
    ll sm = 0;
    for (int i = 0; i < n; i++) {
        sm += a[i];
    }

    ll L, R;
    ll l, r; 
    l = (sm + n-1) / n - 1, r = 1LL<<32;
    while (r-l > 1) {
        ll md = (l+r)/2;
        ll sm2 = 0;
        for (int i = 0; i < n; i++) {
            sm2 += max(0LL, a[i] - md);
        }
        if (sm2 <= k) {
            r = md;
        } else {
            l = md;
        }
    }
    R = r;
    l = 0, r = sm / n + 1;
    while (r-l > 1) {
        ll md = (l+r)/2;
        ll sm2 = 0;
        for (int i = 0; i < n; i++) {
            sm2 += max(0LL, md - a[i]);
        }
        if (sm2 <= k) {
            l = md;
        } else {
            r = md;
        }
    }
    L = l;
//    cout << L << " " << R << endl;
    return R-L;
}
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        int aa;
        scanf("%d", &aa);
        a[i] = aa;
    }
    cout << solve(n, k) << endl;
    return 0;
}