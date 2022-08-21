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
    rng(int r) : l(0), r(max(0, r)) {}
    rng(int l, int r) : l(l), r(max(l, r)) {}
    A begin() { return A{l}; }
    A end() { return A{r}; }
};

int main() {
    int n, m, c;
    cin >> n >> m >> c;
    int l = 0, r = n;
    V<int> d(n);
    while (true) {
        if (l == r) break;
        int x;
        cin >> x; x--;
        if (x < c/2) {
            int nx = -1;
            for (int i = 0; i < l; i++) {
                if (x < d[i]) {
                    nx = i;
                    break;
                }
            }
            if (nx != -1) {
                cout << (nx+1) << endl;
                d[nx] = x;
                continue;                
            }
            cout << (l+1) << endl;
            d[l] = x; l++;
        } else {
            int nx = -1;
            for (int i = n-1; i >= r; i--) {
                if (d[i] < x) {
                    nx = i;
                    break;
                }
            }
            if (nx != -1) {
                cout << (nx+1) << endl;
                d[nx] = x;
                continue;                
            }
            cout << (r) << endl;
            r--; d[r] = x;
        }
    }
    return 0;
}