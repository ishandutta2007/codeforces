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


using P = pair<int, int>;
const int MN = 400400;
int n, m;
int h[MN];
int a[MN], b[MN];
vector<P> q[MN];
int l[MN], r[MN];

void solve() {
    for (int i = 0; i < m; i++) {
        a[i]--;
    }
    for (int i = 0; i < m; i++) {
        q[a[i]].push_back(P(b[i], i));
    }

    int lre[n], rre[n];

    int l[m], r[m];

    int dp[n];
    fill_n(dp, n, 1<<28);
    for (int i = 0; i < n; i++) {
        for (P p: q[i]) {
            int d = p.first;
            int idx = p.second;
            l[idx] = lower_bound(dp, dp+n, d) - dp;
        }
        lre[i] = lower_bound(dp, dp+n, h[i]) - dp;
        dp[lre[i]] = h[i];
    }

    fill_n(dp, n, -(1<<28));
    for (int i = n-1; i >= 0; i--) {
        for (P p: q[i]) {
            int d = p.first;
            int idx = p.second;
            r[idx] = lower_bound(dp, dp+n, d, greater<int>()) - dp;
        }
        rre[i] = lower_bound(dp, dp+n, h[i], greater<int>()) - dp;
        dp[rre[i]] = h[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, lre[i]+rre[i]+1);
    }

    int co[n];
    fill_n(co, n, 0);
    for (int i = 0; i < n; i++) {
        if (lre[i]+rre[i]+1 < ans) continue;
        co[lre[i]]++;
    }

    for (int i = 0; i < m; i++) {
        int ma = l[i]+r[i]+1;
        ma = max(ma, ans-1);
        if (lre[a[i]]+rre[a[i]]+1 < ans or co[lre[a[i]]] != 1) {
            ma = max(ma, ans);
        }
        printf("%d\n", ma);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    vector<int> v;
    for (int i = 0; i < n; i++) {
        scanf("%d", h+i);
        v.push_back(h[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", a+i, b+i);
        v.push_back(b[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < n; i++) {
        h[i] = lower_bound(v.begin(), v.end(), h[i]) - v.begin();
    }
    for (int i = 0; i < m; i++) {
        b[i] = lower_bound(v.begin(), v.end(), b[i]) - v.begin();
    }

    solve();
    return 0;
}