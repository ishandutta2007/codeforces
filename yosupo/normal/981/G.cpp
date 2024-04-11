constexpr bool DEB = false;
#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

template<uint MD>
struct ModInt {
    using M = ModInt;
    uint v;
    ModInt() : v{0} {}
    ModInt(ll v) : v{normS(v%MD+MD)} {}
    explicit operator bool() const {return v != 0;}
    static uint normS(uint x) {return (x<MD)?x:x-MD;};
    static M make(uint x) {M m; m.v = x; return m;}
    static M inv(const M &x) {return x.pow(MD-2); }
    M operator+(const M &r) const {return make(normS(v+r.v));}
    M operator-(const M &r) const {return make(normS(v+MD-r.v));}
    M operator*(const M &r) const {return make(ull(v)*r.v%MD);}
    M operator/(const M &r) const {return *this*inv(r);}
    M& operator+=(const M &r) {return *this=*this+r;}
    M& operator-=(const M &r) {return *this=*this-r;}
    M& operator*=(const M &r) {return *this=*this*r;}
    M& operator/=(const M &r) {return *this=*this/r;}
    M pow(ll n) const {
        M x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
};
using Mint = ModInt<998244353>;
using P = pair<Mint, Mint>;

struct Node {
    using NP = Node*;
    NP l, r;
    int sz;
    Mint msz;
    V<int> vc;
    V<bool> al, pa;

    void f_add(int a, int b, int x) {
        if (b <= 0 || sz <= a) return;
        vc.push_back(x);
        if (a <= 0 && sz <= b) {
            return;
        }
        l->f_add(a, b, x);
        r->f_add(a-sz/2, b-sz/2, x);
    }
    void f_init() {
        sort(begin(vc), end(vc));
        vc.erase(unique(begin(vc), end(vc)), end(vc));
        al = V<bool>(vc.size());
        pa = V<bool>(vc.size());
        if (sz == 1) return;
        l->f_init();
        r->f_init();
    }
    Mint sm = Mint(0);
    P lz = P(Mint(1), Mint(0));
    void lzdata(P nlz) {
        sm = sm*nlz.first + (msz * nlz.second);
        lz.first *= nlz.first;
        lz.second = lz.second * nlz.first + nlz.second;
    }
    void push() {
        l->lzdata(lz); r->lzdata(lz);
        lz = P(Mint(1), Mint(0));
    }
    void update() {
        sm = l->sm + r->sm;
    }
    int getI(int x) {
        auto it = lower_bound(begin(vc), end(vc), x);
        if (it == vc.end() || *it != x) return -1;
        return it - begin(vc);
    }
    void add(int a, int b, int x, bool have = false, bool fall = true) {
        if (b <= 0 || sz <= a) return;
        int xid = getI(x);
        if (xid != -1 && al[xid]) have = true;
        if (a <= 0 && sz <= b) {
            if (fall) {
                assert(xid != -1);
                al[xid] = true;
                fall = false;
            }
            if (have || xid == -1 || !pa[xid]) {
                if (have) lzdata(P(Mint(2), Mint(0)));
                else lzdata(P(Mint(1), Mint(1)));
                return;
            }
        }
        assert(sz > 1);
        if (fall) {
            assert(xid != -1);
            pa[xid] = true;
        }
        push();
        l->add(a, b, x, have, fall);
        r->add(a-sz/2, b-sz/2, x, have, fall);
        update();
    }
    Mint get(int a, int b) {
        if (b <= 0 || sz <= a) return Mint(0);
        if (a <= 0 && sz <= b) return sm;
        push();
        return l->get(a, b) + r->get(a-sz/2, b-sz/2);
    }
    Node(int sz) : sz(sz), msz(Mint(sz)) {
        if (sz == 1) return;
        l = new Node(sz/2);
        r = new Node(sz-sz/2);
    }
};

ll rand_int(ll l, ll r) { //[l, r]
    using D = uniform_int_distribution<ll>;
    static random_device rd;
    static mt19937 gen(rd());
    return D(l, r)(gen);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    int n, q;
    if (!DEB) {
        cin >> n >> q;
    } else {
        n = 200000; q = 200000;
    }

    V<int> tyv(q), lv(q), rv(q), xv(q);
    for (int i = 0; i < q; i++) {
        int ty, l, r;
        if (!DEB) {
            cin >> ty >> l >> r; l--;
        } else {
            ty = rand_int(1, 10);
            if (ty != 1) ty = 1;
            else ty = 2;

            l = rand_int(0, n-1);
            r = rand_int(0, n-1);
            if (l > r) swap(l, r);
            r++;
        }
        tyv[i] = ty;
        lv[i] = l;
        rv[i] = r;
        if (ty == 1) {
            int x;
            if (!DEB) {
                cin >> x;
            } else {
                x = rand_int(0, 200000);
            }
            xv[i] = x;
        }
    }

    auto tr = new Node(n);
    for (int i = 0; i < q; i++) {
        int ty = tyv[i], l = lv[i], r = rv[i], x = xv[i];
        if (ty == 1) {
            tr->f_add(l, r, x);
        }
    }
    tr->f_init();
    for (int i = 0; i < q; i++) {
        int ty = tyv[i], l = lv[i], r = rv[i], x = xv[i];
        if (ty == 1) {
            tr->add(l, r, x);
        } else {
            cout << tr->get(l, r).v << endl;
        }
    }
    return 0;
}