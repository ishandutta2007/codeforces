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
using P = pair<ll, ll>;


/// x^n % md
ll pow_mod(ll x, ll n, ll md) {
    ll r = 1;
    while (n) {
        if (n & 1) r = (r * x) % md;
        x = (x * x) % md;
        n >>= 1;
    }
    return r;
}

const int MN = 200200;
const ll MD = 1e9+7;

struct Node {
    using NP = Node*;

    ll sm, lz;

    /*
     init_node, update, push
    */
    void init_node() {
        sm = 1;
    }
    void update() {
        sm = l->sm * r->sm % (MD - 1);
    }

    void set(int k, ll x) {
        if (sz == 1) {
            sm = x;
            return;
        }
        if (k < sz/2) {
            l->set(k, x);
        } else {
            r->set(k-sz/2, x);
        }
        update();
    }
    ll get(int a, int b) {
        if (b <= 0 or sz <= a) return 1;
        if (a <= 0 and sz <= b) {
            return sm;
        }
        return l->get(a, b)*r->get(a-sz/2, b-sz/2) % (MD-1);
    }

    NP l, r;
    int sz;
    Node(int sz) : sz(sz) {
        init_node();
        if (sz == 1) return;
        l = new Node(sz/2);
        r = new Node(sz - sz/2);
        update();
    }
};

int main() {
    int n;
    scanf("%d", &n);
    map<ll, ll> mp;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        mp[x]++;
    }
    vector<P> v;
    for (auto p: mp) {
        v.push_back(p);
    }
    int m = (int)v.size();
    auto tr = new Node(m);
    for (int i = 0; i < m; i++) {
//        printf("se %d %lld\n", i, v[i].second+1);
        tr->set(i, v[i].second+1);
    }
    ll res = 1;
    for (int i = 0; i < m; i++) {
        ll co = v[i].second * (v[i].second+1) / 2; co %= (MD-1);
        co *= tr->get(0, i); co %= (MD-1);
        co *= tr->get(i+1, m); co %= (MD-1);
        res *= pow_mod(v[i].first, co, MD);
        res %= MD;

//        printf("deb %d %lld %lld\n", i, tr->get(0, i), tr->get(i+1,m));
    }
    cout << res << endl;
    return 0;
}