#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <deque>
#include <string>

#include <algorithm>
#include <numeric>

#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>

#define pb push_back
#define pbk pop_back
#define mp make_pair
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#define foreach(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
#define len(a) ((int) (a).size())

#ifdef CUTEBMAING
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

using namespace std;

typedef long long int64;
typedef long double ld;
typedef unsigned long long lint;

const int inf = (1 << 30) - 1;
const int64 linf = (1ll << 62) - 1;
const int N = 1e4 + 100;

int n, l, r;
int a[N];
int b[N];

int dp[N][2], ndp[N][2];

int main() {
#ifdef XCODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    vector<pair<int, int>> x;
    for (int i = 0; i < n; i++) {
        x.pb(mp(-b[i], a[i]));
    }
    sort(all(x));
    for (int i = 0; i < n; i++) {
        tie(b[i], a[i]) = x[i];
        b[i] = -b[i];
    }
    for (int i = 0; i < N; i++) {
        dp[i][0] = -inf;
        dp[i][1] = -inf;
    }
    for (int i = l; i <= r; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < N; j++) {
            for (int z = 0; z < 2; z++) {
                ndp[j][z] = -inf;
            }
        }
        for (int j = a[i]; j <= r; j++) {
            for (int z = 0; z < 2; z++) {
                if (dp[j][z] <= -inf) {
                    continue;
                }
                ndp[j - a[i]][z] = max(ndp[j - a[i]][z], dp[j][z] + (j - a[i] <= r && j - a[i] >= l && b[i] == 1));
            }
        }
        for (int j = 0; j <= r; j++) {
            if (b[i]) {
                if (dp[j][0] <= -inf) {
                    continue;
                }
                ndp[j][1] = max(ndp[j][1], dp[j][0]);
            }
        }
        for (int j = 0; j <= r; j++) {
            for (int z = 0; z < 2; z++) {
                ndp[j][z] = max(ndp[j][z], dp[j][z]);
            }
        }
        for (int j = 0; j < N; j++) {
            for (int z = 0; z < 2; z++) {
                dp[j][z] = ndp[j][z];
            }
        }
    }
    cout << max(0, max(dp[0][0], 1 + dp[0][1])) << endl;
    return 0;
}