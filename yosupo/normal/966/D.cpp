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

V<int> ans;
void check(const V<int> &nans) {
    if (ans.size() && ans.size() <= nans.size()) return;
    ans = nans;
}

int n;
VV<int> g;
V<bool> one;

void solve1() {
    V<int> res = V<int>(n, TEN(9));
    V<int> bk = V<int>(n, -1);

    using P = pair<int, int>;
    queue<P> q;
    q.push(P(0, 0));
    res[0] = 0;
    while (!q.empty()) {
        P p = q.front(); q.pop();
        if (res[p.second] < p.first) continue;
        for (int d: g[p.second]) {
            if (p.first+1 < res[d]) {
                bk[d] = p.second;
                res[d] = p.first+1;
                q.push(P(res[d], d));
            }
        }
    }

    if (bk[n-1] != -1) {        
        V<int> nans;
        int s = n-1;
        while (s != -1) {
            nans.push_back(s);
            s = bk[s];
        }
        reverse(begin(nans), end(nans));
        check(nans);
    }

    {
        int ma = TEN(9), mi = -1;
        for (int i = 1; i < n-1; i++) {
            if (one[i]) continue;
            if (res[i] < ma) {
                ma = res[i];
                mi = i;
            }
        }
        if (mi != -1) {
            V<int> nans;
            int s = mi;
            while (s != -1) {
                nans.push_back(s);
                s = bk[s];
            }
            reverse(begin(nans), end(nans));
            nans.push_back(0);
            nans.push_back(n-1);
            check(nans);
        }
    }
}


void solve2() {
    VV<int> ng(n);
    for (int i: g[0]) {
        for (int j: g[i]) {
            if (!one[j]) continue;
            ng[i].push_back(j);
        }
    }
    bitset<3*TEN(5)> buf;
    for (int i: g[0]) {
        for (int d: g[i]) {
            buf[d] = true;
        }
        for (int j: ng[i]) {
            for (int k: ng[j]) {
                if (i == k) continue;
                if (buf[k]) continue;
                V<int> nans = {0, i, j, k, i, n-1};
                check(nans);
                return;
            }
        }
        for (int d: g[i]) {
            buf[d] = false;
        }
    }
}


int main() {
    int m;
    scanf("%d %d", &n, &m);
    g = VV<int>(n);
    one = V<bool>(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b); a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int d: g[0]) {
        one[d] = true;
    }

    solve1();
    solve2();

    if (ans.size() == 0) {
        cout << "-1" << endl;
        return 0;
    }
    cout << ans.size()-1 << endl;
    for (int d: ans) {
        cout << d+1 << " ";
    }
    cout << endl;
    return 0;
}