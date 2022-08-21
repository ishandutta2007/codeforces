#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int INF = 1e9+10000;
struct Node {
    typedef Node* NP;
    int sz, d;
    NP l, r;
    Node() {
        l = r = nullptr; d = INF;
    }
    Node(int sz) : sz(sz) {
        assert(sz);
        l = r = nullptr; d = INF;
    }

    void set(int a, int b, int x) {
        if (a <= 0 && sz <= b) {
            d = min(d, x);
            return;
        }
        if (b <= 0 || sz <= a) {
            return;
        }
        if (l == nullptr) {
            l = new Node(sz/2);
        }
        l->set(a, b, x);
        if (r == nullptr) {
            r = new Node(sz - sz/2);
        }
        r->set(a-sz/2, b-sz/2, x);
    }
    int get(int x) {
        if (sz == 1) {
            return d;
        }
        if (x < sz/2) {
            if (l == nullptr) {
                return d;
            }
            return min(d, l->get(x));
        } else {
            if (r == nullptr) {
                return d;
            }
            return min(d, r->get(x - sz/2));
        }
    }
};


int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    Node w(n), h(n);
    w.d = n; h.d = n;
    for (int i = 0; i < q; i++) {
        int x, y; char c;
        scanf("%d %d %c", &x, &y, &c); x--; y--;
        if (c == 'U') {
            int p = w.get(x)-x;
            printf("%d\n", p);
            w.set(x, x+1, x);
            h.set(y-p+1, y+1, y);
        } else {
            int p = h.get(y)-y;
            printf("%d\n", p);
            w.set(x-p+1, x+1, x);
            h.set(y, y+1, y);
        }

    }
    return 0;
}