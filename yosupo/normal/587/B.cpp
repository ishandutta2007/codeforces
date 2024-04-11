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

const ll MD = 1e9+7;
const int MN = 1100100;

int main() {
    int n, k;
    ll l;
    cin >> n >> l >> k;
    ll cy, md;
    cy = l / n; md = l % n;
    static int a[MN];
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i);
    }
    int idx[MN];
    iota(idx, idx+n, 0);
    sort(idx, idx+n, [&](const int &l, const int &r){
        return a[l] < a[r];
    });
    int ridx[MN];
    int b[MN];
    for (int i = 0; i < n; i++) {
        ridx[idx[i]] = i;
        b[i] = a[idx[i]];
    }

    int up[MN];
    for (int i = 0; i < n; i++) {
        up[i] = upper_bound(b, b+n, b[i]) - b;
    }

    ll dp[k+1][n], dpsm[k+1][n+1];
    dpsm[1][0] = 0;
    for (int i = 0; i < n; i++) {
        dp[1][i] = 1;
        dpsm[1][i+1] = dpsm[1][i]+1;
    }
    for (int i = 2; i <= k; i++) {
        dpsm[i][0] = 0;
        for (int j = 0; j < n; j++) {
            dp[i][j] = dpsm[i-1][up[j]];
            dpsm[i][j+1] = (dpsm[i][j]+dp[i][j]) % MD;
        }
    }
    // for (int i = 1; i <= k; i++) {
    //     for (int j = 0; j < n; j++) {
    //         printf("%d ", dp[i][j]);
    //     }
    //     printf("\n");
    // }
    ll sm = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            ll c = cy;
            if (idx[j] < md) c++;
            if (c-i+1 <= 0) continue;
            sm += (ll)(c-i+1)%MD * dp[i][j];
            sm %= MD;
        }
    }
    cout << sm << endl;
    return 0;
}