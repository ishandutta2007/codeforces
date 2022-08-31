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
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template<class T = ll> constexpr T TEN(int n) {return (n==0)?1:10*TEN<T>(n-1);}

const int MN = 20;

int dp[2][MN+1][1<<MN];

int main() {
    int n, m;
    cin >> n >> m;
    char s[MN][100100];
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    for (int i = 0; i < m; i++) {
        int a = 0;
        for (int j = 0; j < n; j++) {
            if (s[j][i] == '1') {
                a += (1<<j);
            }
        }
        dp[0][0][a]++;
    }
    for (int i = 0; i < n; i++) {
        auto &dp1 = dp[i%2], &dp2 = dp[1-(i%2)];
        int MSK = 1<<i;
        for (int c = 0; c <= n; c++) {
            for (int f = 0; f < (1<<n); f++) {
                dp2[c][f] = 0;
            }
        }
        for (int c = 0; c <= n; c++) {
            for (int f = 0; f < (1<<n); f++) {
                if (!dp1[c][f]) continue;
                int a = (f & MSK) ? 1 : 0;
                dp2[c+a  ][f & ~MSK] += dp1[c][f];
                dp2[c+1-a][f |  MSK] += dp1[c][f];
            }
        }
    }

    auto &dp1 = dp[n%2];
    int ans = TEN(9);
    for (int f = 0; f < (1<<n); f++) {
        int buf = 0;
        for (int c = 0; c <= n; c++) {
            buf += dp1[c][f] * min(c, n-c);
        }
        ans = min(ans, buf);
    }
    cout << ans << endl;
    return 0;
}