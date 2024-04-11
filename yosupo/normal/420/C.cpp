#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>

using namespace std;
#include <algorithm>

//0-indexed overflow-> max:Height*MOD sum's comment out:2*MOD
template <class T, int SIZE, T MOD>
struct BinaryIndexedTree {
    using uint = unsigned int;
    T seg[SIZE];
    
    inline void init() {
        fill_n(seg, SIZE, 0);
    }

    inline void add(uint i, T x) {
        while (i < SIZE) {
            seg[i] += x;
            if (MOD) seg[i] %= MOD;
            i += (i+1) & ~i;
        }
    }
    //[0, i)
    inline T sum(uint i) {
        T s = 0;
        uint d = 1;
        while (i >= d) {
            i -= d;
            s += seg[i];
            //if (MOD) s %= MOD;
            d = (i+1) & ~i;
        }
        if (MOD) s = (s % MOD + MOD) % MOD;
        return s;
    }
    //[a, b)
    inline T sum(uint a, uint b) {
        T d = sum(b) - sum(a);
        if (MOD) {
            d = (d + MOD) % MOD;
        }
        return d;
    }
};

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

const int MN = 300030;
BinaryIndexedTree<int, MN, 0> b;

int q[MN] = {};
vector<int> v[MN];
int main() {
    int n, p;
    cin >> n >> p;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        if (a > b) swap(a, b);
        v[b].push_back(a);
        q[a]++; q[b]++;
    }
    ll res = 0;
    for (int i = 0; i < n; i++) {
        for (int d: v[i]) {
            b.add(MN-3-q[d], -1);
            q[d]--;
            b.add(MN-3-q[d], 1);
        }
        int u = p-q[i];
        if (u < 0) {
            res += i;
        } else {
            res += b.sum(MN-2-u);
        }
        for (int d: v[i]) {
            b.add(MN-3-q[d], -1);
            q[d]++;
            b.add(MN-3-q[d], 1);
        }
        b.add(MN-3-q[i], 1);
    }
    cout << res << endl;
    return 0;
}