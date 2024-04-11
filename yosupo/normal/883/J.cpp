#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

struct Node {
    using NP = Node*;
    NP l, r;
    int sz;
    ll mi = 0, lz = 0;
    Node(int sz) : sz(sz) {
        if (sz == 1) return;
        l = new Node(sz/2);
        r = new Node(sz - sz/2);
    }
    void lzadd(ll x) {
        mi += x;
        lz += x;
    }
    void push() {
        l->lzadd(lz);
        r->lzadd(lz);
        lz = 0;
    }
    void update() {
        mi = min(l->mi, r->mi);
    }
    void add(int a, int b, ll x) {
        if (b <= 0 || sz <= a) return;
        if (a <= 0 && sz <= b) {
            lzadd(x);
            return;
        }
        push();
        l->add(a, b, x);
        r->add(a-sz/2, b-sz/2, x);
        update();
    }
    ll get(int a, int b) {
        if (b <= 0 || sz <= a) return TEN(18);
        if (a <= 0 && sz <= b) {
            return mi;
        }
        push();        
        return min(l->get(a, b), r->get(a-sz/2, b-sz/2));
    }
};

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    V<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    using P = pair<ll, ll>;
    V<ll> b(m), c(m);
    for (int i = 0; i < m; i++) cin >> b[i];
    for (int i = 0; i < m; i++) cin >> c[i];

    
    V<P> p(m);
    for (int i = 0; i < m; i++) {
        p[i] = P(b[i], i);
    }

    sort(begin(p), end(p), [&](const P &l, const P &r){
        return l.first < r.first;
    });

    V<int> pos(m, -1);

    int cnt = 0;
    ll ma = -1;
    for (int i = n-1; i >= 0; i--) {
        while (cnt < m && p[cnt].first <= a[i]) {
            pos[p[cnt].second] = i;
            cnt++;
        }
    }

    Node* tr = new Node(n);    
    for (int i = 0; i < n; i++) {
        tr->add(i, n, a[i]);
    }

    V<int> idx(m);
    iota(begin(idx), end(idx), 0);
    sort(begin(idx), end(idx), [&](int l, int r){
        return c[l] < c[r];
    });

    int ans = 0;
    for (int i: idx) {
        int p = pos[i];
        ll d = c[i];
        if (p == -1) continue;
//        cout << "query " << p << " " << d << " -> "  << tr->get(p, n) << endl;
        ll u = tr->get(p, n);
        if (u < d) continue;
        ans++;
        tr->add(p, n, -d);
    }

    cout << ans << endl;

    return 0;
}