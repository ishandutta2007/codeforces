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

using R = double;
int main() {
    ll n, k;
    R l, v1, v2;
    cin >> n >> l >> v1 >> v2 >> k;
    ll m = (n+k-1)/k;
    R x = l/v2, y = l/v1;
    for (int i = 0; i < 200; i++) {
        R md = (x+y)/2;
        R z = (md*v1*v2 - v2*l) / (v1-v2);
        R w = 2*z*v1 / (v1+v2);
        ll c = ll(ceil((l-z)/w));
        if (c < m) {
            x = md;
        } else {
            y = md;
        }
    }
    printf("%.20lf\n", x);
    return 0;
}