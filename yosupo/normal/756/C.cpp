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

const int MN = 100100;

struct Node {
    using NP = Node*;
    NP l, r;
    int sz, d;
    int de, up;
    int query(int h) {
        if (up <= h) return -1;
        if (sz == 1) return d;
        if (h < r->up) return r->query(h);
        return l->query(h - r->up + r->de);
    }
    void set(int k, int x) {
        if (sz == 1) {
            if (x == -1) {
                d = -1;
                de = 1; up = 0;
            } else {
                d = x;
                de = 0; up = 1;
            }
            return;
        }
        if (k < l->sz) l->set(k, x);
        else r->set(k-sz/2, x);
        //update
        de = l->de + max(0, r->de - l->up);
        up = max(0, l->up - r->de) + r->up;
    }
    Node(int sz) : sz(sz) {
        d = 0; de = up = 0;
        if (sz == 1) return;
        l = new Node(sz/2);
        r = new Node(sz-sz/2);
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    int n;
    cin >> n;
    auto tr = new Node(n);
    for (int i = 0; i < n; i++) {
        int p; cin >> p; p--;
        int t; cin >> t;
        if (t == 0) {
            tr->set(p, -1);
        } else {
            int x; cin >> x;
            tr->set(p, x);
        }
        cout << tr->query(0) << endl;
    }
    return 0;
}