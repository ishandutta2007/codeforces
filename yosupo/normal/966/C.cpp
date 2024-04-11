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

const int LG = 61;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    int n;
    cin >> n;
    VV<ll> g(LG);
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        for (int l = LG-1; l >= 0; l--) {
            if (x & (1LL<<l)) {
                g[l].push_back(x);
                break;
            }
        }
    }

    V<ll> res;
    for (int l = LG-1; l >= 0; l--) {
        if (g[l].size() == 0) continue;
        V<ll> nres;
        nres.push_back(g[l].back()); g[l].pop_back();
        for (auto d: g[l]) {
            while (true) {
                if (res.size() == 0) {
                    cout << "No" << endl;
                    return 0;
                }
                nres.push_back(res.back()); res.pop_back();
                if (nres.back() & (1LL<<l)) break;
            }
            nres.push_back(d);
        }
        while (res.size()) {
            nres.push_back(res.back()); res.pop_back();            
        }
        reverse(begin(nres), end(nres));
        res = nres;
    }
    reverse(begin(res), end(res));
    cout << "Yes" << endl;
    for (auto d: res) {
        cout << d << " ";
    }
    cout << endl;
    return 0;
}