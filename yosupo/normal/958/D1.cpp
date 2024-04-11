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

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    int m;
    cin >> m;
    using P = pair<int, int>;
    V<P> v;
    map<P, int> mp;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf(" (%d+%d)/%d", &a, &b, &c);
        P p = P(a+b, c);
        int g = gcd(p.first, p.second);
        p.first /= g; p.second /= g;
        v.push_back(p);
        mp[p]++;
    }

    for (int i = 0; i < m; i++) {
        cout << mp[v[i]] << " ";
    }
    cout << endl;
    return 0;
}