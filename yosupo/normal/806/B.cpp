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

#define tm f__k
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

int n;
int ac[5];
int tm[2][5];

int f(int p, int d, int m, int n) {
    if (tm[p][d] == -1) return 0;
    int fr = 250 - tm[p][d];
    if (2*m > n) return fr*2;
    if (4*m > n) return fr*4;
    if (8*m > n) return fr*6;
    if (16*m > n) return fr*8;
    if (32*m > n) return fr*10;
    return fr*12;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            int x;
            cin >> x;
            if (i <= 1) tm[i][j] = x;
            if (x != -1) ac[j]++;
        }
    }

    for (int m = 0; m < 120*40; m++) {
        int sm = 0;
        for (int j = 0; j < 5; j++) {
            int ma = -TEN(9);
            for (int a = 0; a <= m; a++) {
                if (a && tm[0][j] == -1) break;
                ma = max(ma, f(0, j, ac[j]+a, n+m) - f(1, j, ac[j]+a, n+m));
            }
            sm += ma;
        }
        if (sm > 0) {
            cout << m << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}