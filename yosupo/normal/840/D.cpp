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

struct rng {
    struct A {
        int n;
        const bool operator!=(A r) { return n != r.n; }
        A& operator++() { n++; return *this; }
        int operator*() { return n; }
    };
    int l, r;
    rng(int r) : l(0), r(r) {}
    rng(int l, int r) : l(l), r(r) {}
    A begin() { return A{l}; }
    A end() { return A{r}; }
};

int rand_int(int l, int r) { //[l, r]
    static random_device rd;
    static uint32_t y = time(NULL);
    y = y ^ (y << 13); y = y ^ (y >> 17);
    y = y ^ (y << 5);
    return y % (r-l+1) + l;
}


const int B = 500;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    int n, q;
    cin >> n >> q;
//    n = q = 300000;
    V<int> a(n);
    for (int i: rng(n)) {
        cin >> a[i];
//        a[i] = rand_int(1, n);
    }
    V<int> ql(q), qr(q), qk(q);
    for (int i: rng(q)) {
        cin >> ql[i] >> qr[i] >> qk[i];
//        ql[i] = rand_int(1, n);
//        qr[i] = rand_int(ql[i], n);
//        qk[i] = rand_int(2, 5);
        ql[i]--;
    }
    
    V<int> idx(q);
    iota(begin(idx), end(idx), 0);
    sort(begin(idx), end(idx), [&](int l, int r){
        int ax = ql[l]/B, bx = ql[r]/B;
        if (ax != bx) return ax < bx;
        return qr[l] < qr[r];
    });

    V<int> res(q);
    V<int> cnt(n+10);
    int l = 0, r = 0;
    for (int qidx: idx) {
        int nl = ql[qidx], nr = qr[qidx], nk = qk[qidx];
        while (nl < l) {
            cnt[a[--l]]++;
        }
        while (r < nr) {
            cnt[a[r++]]++;
        }
        while (l < nl) {
            cnt[a[l++]]--;
        }
        while (nr < r) {
            cnt[a[--r]]--;
        }
        int ans = TEN(9);
        for (int ph: rng(200)) {
            int u = rand_int(nl, nr-1);
            if (cnt[a[u]]*nk > (nr-nl)) ans = min(ans, a[u]);
        }
        if (ans == TEN(9)) ans = -1;
        res[qidx] = ans;
    }

    for (int d: res) {
        cout << d << endl;
    }
    return 0;
}