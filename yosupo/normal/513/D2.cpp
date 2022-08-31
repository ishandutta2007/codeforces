#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <cstdio>
#include <tuple>
#include <cstring>
#include <set>
#include <valarray>
#include <queue>
#include <algorithm>
#include <deque>

using namespace std;
typedef long long ll;
typedef tuple<int, int, int> T;
const int MN = 1100100;
template <int S>
struct RangeMaxQuery {
    static const int N = 1<<S;
    typedef ll D;
    static const D INF = 1LL<<62;
    D seg[2*N];

    void init() {
        fill_n(seg, 2*N, +INF);
    }

    void init(int n, D x[]) {
        init();
        for (int i = 0; i < n; i++) {
            seg[i+S] = x[i];
        }
        for (int i = N-1; i >= 1; i--) {
            seg[i] = max(seg[i*2], seg[i*2+1]);
        }
    }

    void set(int i, D x) {
        i += N;
        seg[i] = x;
        while (i) {
            i /= 2;
            seg[i] = max(seg[i*2], seg[i*2+1]);
        }
    }

    D get(int a, int b, int k = 1, int l = 0, int r = N) {
        if (r <= a || b <= l) return -INF;
        if (a <= l && r <= b) return seg[k];
        int md = (l+r)/2;
        D dl = get(a, b, k*2, l, md);
        D dr = get(a, b, k*2+1, md, r);
        return max(dl, dr);
    }
};

RangeMaxQuery<20> rmq;
vector<int> g[MN][2];
vector<int> res;
int lm[MN];
bool used[MN] = {};
bool rf = true;
int ma[MN];
void solve(int a, int r) {
    if (a == r) return;
    if (r < rmq.get(a, a+1)) {
        rf = false;
        return;
    }
    if (used[a]) {
        rf = false;
        return;
    }
    used[a] = true;
    if (g[a][0].size()) {
        solve(a+1, lm[a]);
        res.push_back(a);
        solve(lm[a], r);
    } else {
        res.push_back(a);
        solve(a+1, r);
    }
}

vector<T> e;
int main() {
    rmq.init();
    int n, c;
    cin >> n >> c;
    for (int i = 0; i < c; i++) {
        int a, b; string s;
        cin >> a >> b >> s; a--; b--;
        if (b <= a) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        if (s == "LEFT") {
            e.push_back(T(a, b, 0));
        } else {
            e.push_back(T(a, b, 1));
        }
    }
    sort(e.begin(), e.end());
    e.erase(unique(e.begin(), e.end()), e.end());
    for (T t: e) {
        int a, b, c;
        tie(a, b, c) = t;
        g[a][c].push_back(b);
    }
    for (int i = n-1; i >= 0; i--) {
        lm[i] = i+1;
        if (g[i][0].size()) {
            lm[i] = rmq.get(i+1, g[i][0].back()+1);
        }
        int u = lm[i];
        if (g[i][1].size()) {
            if (lm[i] > g[i][1].front()) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
            u = max<int>(u, rmq.get(i+1, g[i][1].back()+1));
        }
        rmq.set(i, u);
    }
    solve(0, n);
    if (!rf) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    for (int d: res) {
        printf("%d ", d+1);
    } printf("\n");
    return 0;
}