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
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
int bsr(int x) { return 31 - __builtin_clz(x); }

int h;
int counter;
vector<int> dp[1<<7];
bool used[1<<7];

void getHeight() {
    cin >> h;
    if (h == 0) exit(0);
    counter = 0;
    assert(2 <= h && h <= 7);
}

void ans(int p) {
    cout << "! " << p+1 << endl; fflush(stdout);
    throw 0;
}

vector<int> query(int p) {
    if (used[p]) return dp[p];
    used[p] = true;
    if (counter == 16) {
        //pray for ac
        ans(p);
    }
    counter++;
    dp[p].clear();
    cout << "? " << p+1 << endl; fflush(stdout);
    int k;
    cin >> k;
    if (k == 0) exit(0);
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x; x--;
        dp[p].push_back(x);
    }
    if (k == 2) {
        ans(p);
    }
    return dp[p];
}


vector<int> dfs(int p, int b) {
    auto x = query(p);
    if (x.size() == 1) {
        return {p};
    }
    for (int d: x) {
        if (d != b) {
            auto v = dfs(d, p);
            v.push_back(p);
            return v;
        }
    }
    assert(false);
}

void allcheck(int p, int b, int dp) {
    if (dp == h+1) return;
    auto x = query(p);
    for (int d: x) {
        if (d == b) continue;
        allcheck(d, p, dp+1);
    }
}

void dfs2(int p, int b, int dps) {
    if (dps >= h-2) {
        allcheck(p, b, dps);
    }
    auto v = query(p);
    v.erase(remove(begin(v), end(v), b), end(v));
    auto v2 = dfs(v[0], p);
    if (v2.size() == dps-1) {
        dfs2(v[1], p, dps+1);
    } else {
        vector<int> vl(dps-1, -1);
        vl.push_back(p);
        reverse(begin(v2), end(v2));
        for (int d: v2) {
            vl.push_back(d);
        }
        int mid = vl.size()/2;
        auto p = vl[mid];
        auto vx = query(p);
        for (int d: vx) {
            if (d == vl[mid-1] || d == vl[mid+1]) continue;
            dfs2(d, p, mid+2);
            assert(false);
        }
    }
}

void solve() {
    fill_n(used, 1<<7, false);
    getHeight();

    auto x = query(0);

    auto vl = dfs(x[0], 0);
    vl.push_back(0);
    if (x.size() == 3) {
        auto vr = dfs(x[1], 0);
        reverse(begin(vr), end(vr));
        for (int q: vr) {
            vl.push_back(q);
        }
    }

    int mid = vl.size()/2;
    auto p = vl[mid];
    auto vx = query(p);
    for (int d: vx) {
        if (d == vl[mid-1] || d == vl[mid+1]) continue;
        dfs2(d, p, mid+2);
        assert(false);
    }
}

int main() {
    cout << setprecision(20);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        try {
            solve();
        } catch (int d) {
        }
    }
    return 0;
}