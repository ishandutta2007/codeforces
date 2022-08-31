#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cmath>
#include <complex>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>
#include <valarray>
#include <list>

using namespace std;

typedef long long ll;

const int MN = 52;

int n, m;
int cnt[1<<20];
double dp[1<<20];
bool used[1<<20];
double solve(int mp) {
    if (cnt[mp] == n) return 0;
    if (used[mp]) return dp[mp];
    used[mp] = true;
    int c = 0;
    double res = 0;
    for (int i = 0; i < m; i++) {
        if (mp & 1<<i) continue;
        c++;
        res += solve(mp | 1<<i);
    }
    return dp[mp] = res/c+(n-cnt[mp]);
}

int lastb[1<<20];

int main() {
    lastb[0] = -1;
    for (int i = 1; i < 1<<20; i++) {
        for (int j = 0; j < 20; j++) {
            if (i & 1<<j) {
                lastb[i] = j;
                break;
            }
        }
    }
    cin >> n;
    if (n == 1) {
        printf("0\n");
        return 0;
    }
    string s[MN];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    m = s[0].size();
    for (int i = 0; i < n; i++) {
        ll mp[20] = {};
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                if (s[k][j] == s[i][j]) {
                    mp[j] |= (1LL<<k);
                }
            }
        }
        vector<ll> dp(1<<m);
        dp[0] = (1LL<<n)-1;
        for (int j = 1; j < 1<<m; j++) {
            int k = lastb[j];
            dp[j] = dp[j & ~(1<<k)] & mp[k];
            if (dp[j] == 1LL<<i) {
                cnt[j] += 1;
            }
        }
    }
    printf("%.20f", solve(0)/n);
    return 0;
}