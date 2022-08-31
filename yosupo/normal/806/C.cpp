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

int bsr(uint x) { return 31 - __builtin_clz(x); }
int bsr(ull x) { return 63 - __builtin_clzll(x); }
int bsf(uint x) { return __builtin_ctz(x); }
int bsf(ull x) { return __builtin_ctzll(x); }

const int MB = 50;

int base[MB];
int st[MB];

bool check(int c) {
    int c0 = 0, c1 = c;
    for (int i = 0; i < MB-1; i++) {
        c0 += st[i];
        if (c0+c1 <= base[i]) {
            //inc
            int u = base[i] - (c0+c1);
            if (c1 < u) return false;
            c1 -= u;
            c0 += u;
        } else {
            //dec
            if (i == 0) return false;
            int dec = (c0+c1) - base[i];
            int dec0 = min(c0, dec);
            c0 -= dec0;
            dec -= dec0;
            int dec1 = min(c1, dec);
            c1 -= dec1;
            dec -= dec1;
            if (dec) return false;
        }
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    int n;
    cin >> n;
    int offset = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        int u = bsr(ull(x));
        if (x == (1LL<<u)) {
            // pow 2
            base[u]++;
        } else {
            for (int i = 0; i <= u; i++) {
                base[i]--;
            }
            offset++;
            st[u+1]++;
        }
    }

/*    for (int i = 0; i < MB; i++) {
        cout << base[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < MB; i++) {
        cout << st[i] << " ";
    }
    cout << endl;*/

    V<int> ok;
    for (int i = 0; i <= n; i++) {
        if (check(i)) ok.push_back(i+offset);
    }

    if (ok.size() == 0) {
        cout << -1 << endl;
    } else {
        for (int d: ok) {
            cout << d << " ";
        }
        cout << endl;
    }
    return 0;
}