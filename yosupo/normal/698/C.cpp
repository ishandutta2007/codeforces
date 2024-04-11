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

using R = double;

int main() {
    int n, k;
    cin >> n >> k;
    R a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    R x[1<<n];
    fill_n(x, 1<<n, 0);
    x[0] = 1.0;
    R ans[n];
    fill_n(ans, n, 0);
    for (int fe = 0; fe <= k; fe++) {
        for (int i = 0; i < (1<<n); i++) {
            if (__builtin_popcount(i) != fe) continue;
            R sm = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1<<j)) continue;
                sm += a[j];
            }
            if (fe == k or sm == 0) {
                for (int j = 0; j < n; j++) {
                    if (i & (1<<j)) {
                        ans[j] += x[i];
                    }
                }
                continue;
            }
            for (int j = 0; j < n; j++) {
                if (i & (1<<j)) continue;
                x[i | (1<<j)] += x[i] * a[j] / sm;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%.20lf ", ans[i]);
    }
    printf("\n");
    return 0;
}