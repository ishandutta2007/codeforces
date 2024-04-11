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

#define tm f__k
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

int bsr(uint x) { return 31 - __builtin_clz(x); }
int bsr(ull x) { return 63 - __builtin_clzll(x); }
int bsf(uint x) { return __builtin_ctz(x); }
int bsf(ull x) { return __builtin_ctzll(x); }

struct FastSet {
    int N, lg;
    VV<ull> seg;
    FastSet(int N) : N(N) {
        while (N > 1) {
            seg.push_back(V<ull>((N+63)/64));
            N = (N+63)/64;
        }
        lg = seg.size();
    }
    bool test(int x) const {
        int D = x/64, R = x%64;
        return (seg[0][D] & (1ULL<<R)) != 0;
    }
    void set(int x) {
        for (int i = 0; i < lg; i++) {
            int D = x/64, R = x%64;
            seg[i][D] |= (1ULL<<R);
            x /= 64;
        }
    }
    void clear(int x) {
        for (int i = 0; i < lg; i++) {
            int D = x/64, R = x%64;
            seg[i][D] &= ~(1ULL<<R);
            if (i && seg[i-1][x] != 0) {
                seg[i][D] |= (1ULL<<R);
            }
            x /= 64;
        }
    }
    // x
    int next(int x) {
        for (int i = 0; i < lg; i++) {
            int D = x/64, R = x%64;
            if (D == seg[i].size()) break;
            ull B = seg[i][D]>>R;
            if (!B) {
                x = x/64+1;
                continue;
            }
            //find
            x += bsf(B);
            for (int j = i-1; j >= 0; j--) {
                x *= 64;
                int D = x/64;
                x += bsf(seg[j][D]);
            }
            return x;
        }
        return N;
    }
    // x
    int back(int x) {
        for (int i = 0; i < lg; i++) {
            if (x == -1) break;
            int D = x/64, R = x%64;
            ull B = seg[i][D]<<(63-R);
            if (!B) {
                x = x/64-1;
                continue;
            }
            //find
            x += bsr(B)-63;
            for (int j = i-1; j >= 0; j--) {
                x *= 64;
                int D = x/64;
                x += bsr(seg[j][D]);
            }
            return x;
        }
        return -1;
    }    
};

template<class T>
struct Fenwick {
    int N, lg;
    V<T> seg;
    Fenwick(int N) : N(N) {
        seg.resize(N+1);
        lg = bsr(uint(N));
        fill(begin(seg), end(seg), T(0));
    }
    /// ix
    void add(int i, T x) {
        i++;
        while (i <= N) {
            seg[i] += x;
            i += i & -i;
        }
    }
    /// [0, i)sum
    T sum(int i) {
        T s{0};
        while (i > 0) {
            s += seg[i];
            i -= i & -i;
        }
        return s;
    }
    /// [a, b)sum
    T sum(int a, int b) {
        return sum(b) - sum(a);
    }
    /// sum[0, idx) >= xidx
    int sum_lower_bound(T x) {
        if (x <= 0) return 0;
        int res = 0;
        for (int len = 1<<lg; len >= 1; len /= 2) {
            if (res + len <= N && seg[res + len] < x) {
                x -= seg[res+len];
                res += len;
            }
        }
        return res + 1;
    }
};
template<class N>
struct SegTree {
    int lg, sz;
    vector<N> n;
    SegTree() {}
    SegTree(int sz) {
        assert(sz >= 1);
        lg = bsr(uint(2*sz-1));
        sz = 1<<lg;
        this->sz = sz;
        n = vector<N>(2*sz);
        for (int i = 2*sz-1; i >= sz; i--) {
            n[i] = N();
        }
        for (int i = sz-1; i >= 1; i--) {
            n[i] = N(n[2*i], n[2*i+1]);
        }
    }
    void all_update() {
        for (int i = 1; i <= sz-1; i++) {
            n[i].push();
        }
        for (int i = sz-1; i >= 1; i--) {
            n[i].update(n[2*i], n[2*i+1]);
        }
    }
    template<class Q>
    Q single(int idx, Q q) {
        if (idx < 0 || sz <= idx) return q;
        idx += sz;
        for (int i = lg; i >= 1; i--) {
            int k = idx>>i;
            n[k].push(n[2*k], n[2*k+1]);
        }
        q += n[idx];
        if (q.update()) {
            for (int i = 1; i <= lg; i++) {
                int k = idx>>i;
                n[k].update(n[2*k], n[2*k+1]);
            }
        }
        return q;
    }
    template<class Q>
    void query(int a, int b, Q &q, int k, int sz) {
        if (a <= 0 && sz <= b) {
            q += n[k];
            return;
        }
        n[k].push(n[2*k], n[2*k+1]);
        if (a < sz/2) query(a, b, q, 2*k, sz/2);
        if (sz/2 < b) query(a-sz/2, b-sz/2, q, 2*k+1, sz/2);
        if (q.update()) n[k].update(n[2*k], n[2*k+1]);
    }
    template<class Q>
    Q query(int a, int b, Q q) {
        if (a < sz && 0 < b) query(a, b, q, 1, sz);
        return q;
    }
    struct NodeQuery {
        N n;
        static constexpr bool update() { return false; }
        void operator+=(N &r) { N nn; nn.update(n, r); n = nn; }
    };
};

using P = pair<int, int>;
struct Node {
    P mi;
    int lz;
    void init() {
        mi = P(TEN(9), -1);
        lz = 0;
    }
    Node() { init(); } // leaf
    Node(Node &l, Node &r) { init(); update(l, r); }
    void update(const Node &l, const Node &r) {
        mi = min(l.mi, r.mi);
    }
    void push(Node &l, Node &r) {
        if (lz) {
            l.lzdata(lz);
            r.lzdata(lz);
            lz = 0;
        }
    }
    void lzdata(ll x) {
        mi.first += x;
        lz += x;
    }
    // query
    struct MinQuery {
        P mi = P(TEN(9), -1);
        static constexpr bool update() { return false; }
        void operator+=(Node &r) { mi = min(mi, r.mi); }
    };
    struct AddQuery {
        int x;
        static constexpr bool update() { return true; }
        void operator+=(Node &n) { n.lzdata(x); }
    };
    struct SetQuery {
        P x;
        static constexpr bool update() { return true; }
        void operator+=(Node &n) { n.mi = x; }
    };    
};


const int MN = 500500;
int n;
int base[MN];
int idx[MN];

void main2() {
/*    for (int i = 0; i < n; i++) {
        cout << base[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << idx[i] << " ";
    }
    cout << endl;*/
    Fenwick<int> fw(n);
//    FastSet mid(n);
set<int> mid;
    SegTree<Node> plus(n), minus(n);
    for (int ph = 0; ph < n; ph++) {
        int i = idx[ph];
        int h = fw.sum(0, i);
        if (h == base[i]) {
//            mid.set(i);
mid.insert(i);
        } else {
            bool isAdd = h < base[i];
            int dif = abs(base[i] - h);
//            int lm = mid.next(i);
auto it = mid.lower_bound(i); int lm = (it == mid.end() ? n : *it);
            P buf;
            if (isAdd) {
                //add
                buf = plus.query(i, n, Node::MinQuery{}).mi;
            } else {
                //dec
                buf = minus.query(i, n, Node::MinQuery{}).mi;
            }
            int lz = (buf.first == 0) ? buf.second : n;
//            cout << lm << " " << lz << endl;
            int L = i, R = min(lm, lz);
            if (R < n) {
                if (lm < lz) {
                    //mid
//                    mid.clear(lm);
mid.erase(lm);
                    if (isAdd) {
                        minus.single(R, Node::SetQuery{P(0, R)});
                        fw.add(R, -1);
                    } else {
                        plus.single(R, Node::SetQuery{P(0, R)});
                        fw.add(R, 1);
                    }
                } else {
                    //zero
//                    mid.set(R);
mid.insert(R);
                    if (isAdd) {
                        plus.single(R, Node::SetQuery{P(TEN(9), -1)});
                        fw.add(R, -1);
                    } else {
                        minus.single(R, Node::SetQuery{P(TEN(9), -1)});
                        fw.add(R, 1);
                    }
                }
            }

            if (isAdd) {
                plus.single(i, Node::SetQuery{P(dif, i)});
                plus.query(L, R, Node::AddQuery{-1});
                minus.query(L, R, Node::AddQuery{1});
                fw.add(i, 1);
            } else {
                plus.query(L, R, Node::AddQuery{1});
                minus.single(i, Node::SetQuery{P(dif, i)});
                minus.query(L, R, Node::AddQuery{-1});
                fw.add(i, -1);
            }
        }
printf("%d\n", fw.sum(0, n));
    }
}

int main() {
scanf("%d", &n);
    using P = pair<int, int>;
    V<P> v(n);
    for (int i = 0; i < n; i++) {
scanf("%d", &(v[i].first));
        v[i].second = i;
    }
    sort(begin(v), end(v));
    for (int i = 0; i < n; i++) {
        base[i] = v[i].first;
        idx[v[i].second] = i;
    }
    main2();
    return 0;
}