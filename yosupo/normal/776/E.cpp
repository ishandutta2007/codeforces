#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <random>
#include <vector>
#include <array>
#include <bitset>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

ll f(ll n) {
    if (n == 1) return 1;
    if (n == 2) return 1;

    ll buf = n;
    ll m = n;
    for (ll i = 2; i*i <= n; i++) {
        if (m % i) continue;
        while (m % i == 0) m /= i;
        buf /= i;
        buf *= (i-1);
    }
    if (m > 1) {
        buf /= m;
        buf *= (m-1);
    }
    return buf;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    ll n, k;
    cin >> n >> k;
    k = (k+1)/2;
    for (int i = 0; i < k; i++) {
        if (n == 1) break;
        n = f(n);
    }
    n %= TEN(9)+7;
    cout << n << endl;
    return 0;
}