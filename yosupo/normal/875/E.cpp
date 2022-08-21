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

int n;
int st;
V<int> a;

bool calc(int md) {
    set<int> s;
    s.insert(st);
    for (int i: rng(1, n+1)) {
        int x = a[i];
        while (s.size()) {
            int y = *s.begin();
            if (abs(x-y) > md) s.erase(y);
            else break;
        }
        while (s.size()) {
            int y = *s.rbegin();
            if (abs(x-y) > md) s.erase(y);
            else break;
        }
        if (abs(x-a[i-1]) <= md) s.insert(a[i-1]);
        if (s.size() == 0) return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    cin >> n;
    a = V<int>(n+1);
    cin >> st >> a[0];
    for (int i: rng(n)) {
        cin >> a[i+1];
    }
//    cout << calc(1) << endl;
//    return 0;
    int l = abs(st-a[0])-1, r = TEN(9)+10;
    while (r-l > 1) {
        int md = (l+r)/2;
        if (!calc(md)) {
            l = md;
        } else {
            r = md;
        }
    }
    cout << r << endl;
    return 0;
}