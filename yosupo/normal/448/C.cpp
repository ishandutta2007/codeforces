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

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

const int MN = 5200;

int n;
ll d[MN];
ll mi[MN][MN];
ll solve(int l, int r, ll u) {
    if (l >= r) return 0;
    ll res = (mi[l][r]-u);
    int j = l;
    for (int i = l; i < r; i++) {
        if (d[i] == mi[l][r]) {
            res += solve(j, i, mi[l][r]);
            j = i+1;
        }
    }
    res += solve(j, r, mi[l][r]);
    res = min(res, (ll)(r-l));
    return res;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    for (int i = 0; i < n; i++) {
        mi[i][i+1] = d[i];
        for (int j = i+2; j <= n; j++) {
            mi[i][j] = min(mi[i][j-1], d[j-1]);
        }
    }
    cout << solve(0, n, 0) << endl;
    return 0;
}