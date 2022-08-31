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

ll down(ll x) {
    ll l = 1, r = TEN(5)+TEN(4);
    while (r-l > 1) {
        ll md = (l+r)/2;
        if (md*md*md <= x) {
            l = md;
        } else {
            r = md;
        }
    }
    return l;
}

using P = pair<ll, ll>;
map<ll, P> dp;
P calc(ll x) {
    if (x == 0) {
        return P(0, 0);
    }
    if (dp.count(x)) return dp[x];
    ll lo = down(x), lo3 = lo*lo*lo;
    P up = calc(x%lo3);
    P down = calc(lo3-1);
    up.first += x/lo3; up.second += x/lo3*lo3;
    down.first += x/lo3-1; down.second += (x/lo3-1)*lo3;
    return dp[x] = max(up, down);
}

int main() {
    ll x;
    cin >> x;
    P p = calc(x);
    cout << p.first << " " << p.second << endl;
    return 0;
}