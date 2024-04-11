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
#include <complex>
#include <cmath>
#include <stack>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

template <int SIZE>
struct FenwickTree {
    ll seg[SIZE];
    
    void init() {
        fill_n(seg, SIZE, 0);
    }

    void add(int i, ll x) {
        while (i < SIZE) {
            seg[i] += x;
            i += (i+1) & ~i;
        }
    }

    //[0, i)
    ll sum(int i) {
        ll s = 0;
        int d = 1;
        while (i >= d) {
            i -= d;
            s += seg[i];
            d = (i+1) & ~i;
        }
        return s;
    }

    //[a, b)
    ll sum(int a, int b) {
        ll d = sum(b) - sum(a);
        return d;
    }
};

const int MN = 200100;
vector<int> g[MN];
int h[MN];
int c;
int cl[MN], cr[MN];
void dfs(int a, int b, int hh) {
    cl[a] = c;
    h[a] = hh;
    c++;
    for (int i: g[a]) {
        if (i == b) continue;
        dfs(i, a, hh+1);
    }
    cr[a] = c;
}

FenwickTree<MN> f1, f2;
int f[MN];
int main() {
    f1.init(), f2.init();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        scanf("%d", f+i);
    }
    for (int i = 0; i < n-1; i++) {
        int a, b;
        scanf("%d %d", &a, &b); a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, -1, 0);
    for (int i = 0; i < m; i++) {
        int t, x;
        scanf("%d %d", &t, &x); x--;
        int u = (h[x]%2) ? -1 : 1;
        if (t == 1) {
            int v;
            scanf("%d", &v);
            if (u == 1) {
                f1.add(cl[x],v);
                f1.add(cr[x],-v);
            } else {
                f2.add(cl[x],v);
                f2.add(cr[x],-v);
            }
        } else {
            printf("%I64d\n", f[x]+u*f1.sum(cl[x]+1)-u*f2.sum(cl[x]+1));
        }
    }
    return 0;
}