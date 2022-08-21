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
using ll = long long;
using ull = unsigned long long;
constexpr int TEN(int n) {return (n==0)?1:10*TEN(n-1);}
using P = pair<int, int>;

struct Node {
    using NP = Node*;

    P ma;

    /*
     init_node, update, push
    */
    void init_node(int idx) {
        ma = P(0, -idx);
    }
    void update() {
        ma = max(l->ma, r->ma);
    }
    void push() {
    }
    void lzdata(int x) {
    }
    void init() {
        init_node(idx);
        if (sz == 1) return;
        l->init(); r->init();
    }
    void add(int k) {
        if (sz == 1) {
            ma.first++;
            return;
        }
        if (k < sz/2) {
            l->add(k);
        } else {
            r->add(k-sz/2);
        }
        update();
    }
    P get(int a, int b) {
        if (b <= 0 or sz <= a) return P(-1, 0);
        if (a <= 0 and sz <= b) {
            return ma;
        }
        push();
        return max(l->get(a, b), r->get(a-sz/2, b-sz/2));
    }

    NP l, r;
    int sz, idx;
    Node(int sz, int idx = 0) : sz(sz), idx(idx) {
        init_node(idx);
        if (sz == 1) return;
        l = new Node(sz/2, idx);
        r = new Node(sz - sz/2, idx + sz/2);
        update();
    }
};


int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i); a[i]--;
    }

    int co[n];
    fill_n(co, n, 0);
    auto tr = new Node(n);
    for (int i = 0; i < n; i++) {
        tr->init();
        for (int j = i; j < n; j++) {
            tr->add(a[j]);
//            printf("%d %d %d\n", i, j, -tr->get(0, n).second);
            co[-tr->get(0, n).second]++;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", co[i]);
    }
    printf("\n");
    return 0;
}