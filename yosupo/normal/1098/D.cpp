#include <bits/stdc++.h>
#include <ostream>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

// bit op
int popcnt(uint x) { return __builtin_popcount(x); }
int popcnt(ull x) { return __builtin_popcountll(x); }
int bsr(uint x) { return 31 - __builtin_clz(x); }
int bsr(ull x) { return 63 - __builtin_clzll(x); }
int bsf(uint x) { return __builtin_ctz(x); }
int bsf(ull x) { return __builtin_ctzll(x); }

template <class T> struct Fenwick {
    int n;
    V<T> seg;
    Fenwick(int _n = 0) : n(_n), seg(n + 1) {}
    /// ix
    void add(int i, T x) {
        i++;
        while (i <= n) {
            seg[i] += x;
            i += i & -i;
        }
    }
    /// [0, i)sum
    T sum(int i) {
        T s = 0;
        while (i > 0) {
            s += seg[i];
            i -= i & -i;
        }
        return s;
    }
    /// [a, b)sum
    T sum(int a, int b) { return sum(b) - sum(a); }
    /// sum[0, idx) >= xidx(sum[0, n) < x  n+1)
    int sum_lower_bound(T x) {
        if (x <= 0) return 0;
        int res = 0, len = 1;
        while (2 * len <= n) len *= 2;
        for (; len >= 1; len /= 2) {
            if (res + len <= n && seg[res + len] < x) {
                res += len;
                x -= seg[res];
            }
        }
        return res + 1;
    }
};

struct FastSet {
    static constexpr size_t B = 64;
    size_t n, lg;
    VV<ull> seg;
    FastSet(size_t _n) : n(_n) {
        do {
            seg.push_back(V<ull>((_n + B - 1) / B));
            _n = (_n + B - 1) / B;
        } while (_n > 1);
        lg = seg.size();
    }
    bool operator[](size_t i) const {
        return (seg[0][i / B] >> (i % B) & 1) != 0;
    }
    void set(size_t i) {
        for (size_t h = 0; h < lg; h++) {
            seg[h][i / B] |= 1ULL << (i % B);
            i /= B;
        }
    }
    void reset(size_t i) {
        for (size_t h = 0; h < lg; h++) {
            seg[h][i / B] &= ~(1ULL << (i % B));
            if (seg[h][i / B]) break;
            i /= B;
        }
    }
    // x
    ssize_t next(size_t i) {
        for (ssize_t h = 0; h < ssize_t(lg); h++) {
            if (i / 64 == seg[h].size()) break;
            ull d = seg[h][i / B] >> (i % B);
            if (!d) {
                i = i / B + 1;
                continue;
            }
            // find
            i += bsf(d);
            for (ssize_t g = h - 1; g >= 0; g--) {
                i *= 64;
                i += bsf(seg[g][i / B]);
            }
            return i;
        }
        return n;
    }
    // x
    ssize_t prev(ssize_t i) {
        i--;
        for (ssize_t h = 0; h < ssize_t(lg); h++) {
            if (i == -1) break;
            ull d = seg[h][i / B] << (63 - i % 64);
            if (!d) {
                i = i / 64 - 1;
                continue;
            }
            // find
            i += bsr(d) - 63;
            for (ssize_t g = h - 1; g >= 0; g--) {
                i *= 64;
                i += bsr(seg[g][i / 64]);
            }
            return i;
        }
        return -1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    using P = pair<int, int>;
    V<P> ques(q);
    V<int> xs;
    for (int ph = 0; ph < q; ph++) {
        char c; int x;
        cin >> c >> x;
        ques[ph] = P(c == '+' ? 1 : -1, x);
        xs.push_back(x);
    }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    int n = int(xs.size());
    auto fw = Fenwick<ll>(n);
    auto fs = FastSet(n);
    V<int> cnt(n);
    int allc = 0;
    for (auto que: ques) {
        ll x = que.second;
        int xi = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
        if (que.first == 1) {
            //inc
            allc++;
            fw.add(xi, x);
            if (cnt[xi] == 0) {
                fs.set(xi);
            }
            cnt[xi]++;
        } else {
            //del
            allc--;
            fw.add(xi, -x);
            cnt[xi]--;
            if (cnt[xi] == 0) {
                fs.reset(xi);
            }
        }

        if (!allc) {
            cout << 0 << "\n";
            continue;
        }
        int ans = 0;
        ll sm = xs[fs.next(0)];
        while (2 * sm < xs.back()) {
            int smi = lower_bound(xs.begin(), xs.end(), int(2 * sm + 1)) - xs.begin();
            ll nsm = fw.sum(smi);
            int nx = fs.next(smi);
            if (nx == n) break;
            if (xs[nx] <= nsm * 2) {
                sm = nsm;
                continue;
            }
            ans++;
            sm = nsm + xs[nx];
        }
        cout << allc - 1 - ans << "\n";
    }
    return 0;
}