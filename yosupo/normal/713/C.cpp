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
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template<class T = ll> constexpr T TEN(int n) {return (n==0)?1:10*TEN<T>(n-1);}

int main() {
    int n;
    cin >> n;
    ll l[n];
    for (int i = 0; i < n; i++) {
        cin >> l[i]; l[i] += (n-i);
    }
    reverse(l, l+n);

    ll off = 0;
    deque<ll> v;
    v.push_back(TEN(10));
    for (int i = 0; i < n; i++) {
        int m = int(v.size());
        ll sm = 0;
        ll z = min(l[i], v[0]);
        for (int j = 0; j < m-1; j++) {
            if (z <= v[j]) break;
            ll u = min(z-v[j], v[j+1]-v[j]);
            sm += (j+1) * u;
        }
        off += sm + (l[i]-z);
        v.push_back(l[i]);
        v.push_back(l[i]);
        sort(begin(v), end(v));
        v.pop_front();
    }
    cout << off << endl;
    return 0;
}