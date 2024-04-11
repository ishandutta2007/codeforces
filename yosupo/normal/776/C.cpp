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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    int n, k;
    cin >> n >> k;
    V<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<ll, int> s;
    s[0]++;
    ll sm = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        sm += a[i];
        //count
        ll base = 1;
        int flag = 0;
        while (true) {
            if (s.count(sm-base)) ans += s[sm-base];
            base *= k;
            flag++;
            if (k == 1 && flag == 1) break;
            if (k == -1 && flag == 2) break;
            if (abs(base) > 1e17) break;
        }
        s[sm]++;
    }
    cout << ans << endl;
    return 0;
}