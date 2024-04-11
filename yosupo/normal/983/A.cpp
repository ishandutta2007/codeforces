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
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

ll gcd(ll a, ll b) {
    while (b) {
        ll tmp = a%b;
        a = b;
        b = tmp;
    }
    return a;
}

bool solve(ll a, ll b, ll c) {
    ll g = gcd(a, b);
    a /= g; b /= g;
    if (a == 0) return true;

    while (true) {
        ll g = gcd(b, c);
        if (g == 1) break;
        while (b % g == 0) b /= g;
        c = g;
    }
    return b == 1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    ll t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (solve(a, b, c)) {
            cout << "Finite" << endl;
        } else {
            cout << "Infinite" << endl;
        }
    }
    return 0;
}