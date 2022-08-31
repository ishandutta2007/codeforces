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

template<class T>
struct Fenwick {
    int N;
    vector<T> seg;
    Fenwick(int N) : N(N) {
        seg.resize(N+1);
        fill_n(begin(seg), N+1, 0);
    }
    /// ix
    void add(int i, T x) {
        i++;
        while (i <= N) {
            seg[i] += x;
            i += i & -i;
        }
    }
    /// [0, i)sum
    T sum(int i) {
        T s{0};
        while (i > 0) {
            s += seg[i];
            i -= i & -i;
        }
        return s;
    }
    /// [a, b)sum
    T sum(int a, int b) {
        return sum(b) - sum(a);
    }
};

int main() {
    int n, k;
    scanf("%d %d", &n, &k); k = min(k, n-k);
    Fenwick<int> fw(n);
    int st = 0;
    ll co = 1;
    for (int i = 0; i < n; i++) {
        int nx = st + k; if (nx >= n) nx -= n;
        int l = nx - (n-k); if (l < 0) l += n;
        int r = nx - k; if (r < 0) r += n;
        //[l, r]
        int dif = (i+1);
        if (l <= r) {
            dif -= fw.sum(l, r+1);
        } else {
            dif -= i - fw.sum(r+1, l);
        }
//        cout << st << " " << nx << " " << l << " " << r << " " << dif << endl;
        co += dif;
        printf("%lld ", co);
        fw.add(nx, 1);
        st = nx;
    }
    printf("\n");
    return 0;
}