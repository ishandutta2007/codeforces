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

int main() {
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    for (int i = 1; i <= k; i++) {
        ll dif = 2*n + 1 - 4*i;
        if (dif < 0) break;
        ans += dif;
    }
    cout << ans << endl;
    return 0;
}