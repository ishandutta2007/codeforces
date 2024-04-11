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
using P = pair<ll, ll>;
using T = pair<P, int>;

const int MN = 100100;
T p[MN];

P sub(P a, P b) {
    return P(a.first-b.first, a.second-b.second);
}

ll cross(P a, P b) {
    return a.first*b.second-a.second*b.first;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        p[i] = T(P(x, y), i+1);
    }
    sort(p, p+n);
    ll ma = 4 * 1e18 + 10000000;
    int mi = -1;
    for (int i = 2; i < n; i++) {
        ll d = abs(cross(sub(p[1].first, p[0].first), sub(p[i].first, p[0].first)));
        if (d == 0) continue;
        if (d < ma) {
            ma = d;
            mi = i;
        }
    }
    printf("%d %d %d\n", p[0].second, p[1].second, p[mi].second);
    return 0;
}