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
#include <ctime>
#include <random>
 
using namespace std;
typedef long long ll;

const ll MD = 1e9+7;
const int MN = 4040;
ll comb[MN][MN] = {};

void init() {
    comb[0][0] = 1;
    for (int i = 1; i < MN; i++) {
        comb[i][0] = 1;
        for (int j = 1; j < MN; j++) {
            comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
            comb[i][j] %= MD;
        }
    }
}

ll dp[MN];
int main() {
    clock_t st = clock();
    while ((double)(clock() - st) * 1000 / CLOCKS_PER_SEC < 500) {}
    init();
    dp[0] = 1;
    for (int i = 1; i < MN; i++) {
        dp[i] = 0;
        for (int j = 1; j <= i; j++) {
            dp[i] += comb[i-1][j-1] * dp[i-j];
            dp[i] %= MD;
        }
    }

    int n;
    cin >> n;
    ll sm = 0;
    for (int i = 1; i <= n; i++) {
        sm += comb[n][i]*dp[n-i];
        sm %= MD;
    }
    cout << sm << endl;
    return 0;
}