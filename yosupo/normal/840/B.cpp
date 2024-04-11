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

const int MN = 300300;
struct E {
    int to, id;
};
int n, m;
V<E> g[MN];
int d[MN];
bool used[MN] = {};
V<int> res;

int dfs(int p) {
    used[p] = true;
    int sm = d[p];
    for (auto e: g[p]) {
        int d = e.to;
        if (used[d]) continue;
        if (dfs(d)) {
            res.push_back(e.id);
            sm = 1-sm;
        }
    }
    return sm;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    cin >> n >> m;
    int sm = 0;
    int sp = -1;
    for (int i: rng(n)) {
        cin >> d[i];
        if (d[i] == -1) {
            if (sp == -1) {
                sp = i;
                continue;
            }
            d[i] = 0;
        }
        sm += d[i]; sm %= 2;
    }
    if (sm && sp == -1) {
        //Impossible
        cout << -1 << endl;
        return 0;
    }
    d[sp] = sm;
    
    for (int i: rng(m)) {
        int a, b;
        cin >> a >> b; a--; b--;
        g[a].push_back(E{b, i+1});
        swap(a, b);
        g[a].push_back(E{b, i+1});
    }

    dfs(0);
    
    cout << res.size() << endl;
    for (int d: res) {
        cout << d << endl;
    }
    return 0;
}