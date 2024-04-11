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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    int q;
    cin >> q;
    auto get_level = [&](ll x) {
        int lv = 0;
        while (x > 1) {
            lv++;
            x >>= 1;
        }
        return lv;
    };
    V<ll> cy(61);
    auto add_k = [&](int lv, ll k) {
        ll md = 1ULL << lv;
        cy[lv] += k;
        cy[lv] = (cy[lv] % md + md) % md;
    };
    for (int ph = 0; ph < q; ph++) {
        int ty;
        cin >> ty;
        if (ty == 1) {
            ll x, k;
            cin >> x >> k;
            auto lv = get_level(x);
            add_k(lv, k);
        } else if (ty == 2) {
            ll x, k;
            cin >> x >> k;
            auto lv = get_level(x);
            for (int i = lv; i <= 60; i++) {
                add_k(i, k);
                k *= 2;
            }
        } else {
            ll x;
            cin >> x;
            auto lv = get_level(x);
            {
                ll md = 1ULL << lv;
                x -= md;
                x += cy[lv];
                x %= md;
                x += md;
            }
            while (x > 1) {
                ll md = 1ULL << lv;
                ll y = x - md;
                y += (md - cy[lv]);
                y %= md;
                y += md;
                cout << y << " ";
                lv--;
                x >>= 1;
            }
            cout << "1" << endl;
        }
    }
    return 0;
}