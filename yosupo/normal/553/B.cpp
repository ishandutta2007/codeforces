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
typedef long long ll;
typedef unsigned long long ull;

const int MN = 100;
const ll INF = 1100100100100100100LL;

ll dp[MN];
ll calc(int x) {
    if (x <= 1) return 1;
    if (dp[x] != -1) return dp[x];
    return dp[x] = min(INF, calc(x-1)+calc(x-2));
}

int res[MN];
int main() {
    memset(dp, -1, sizeof(dp));
    int n; ll k;
    cin >> n >> k;
    int i = 0;
    while (i < n) {
        if (k <= calc(n-1-i)) {
            res[i] = i;
            i++;
        } else {
            k -= calc(n-1-i);
            res[i] = i+1;
            res[i+1] = i;
            i += 2;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << res[i]+1 << " ";
    } cout << endl;
    return 0;
}