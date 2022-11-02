#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <cmath>
#include <numeric>
#include <functional>
#include <cassert>

#include <algorithm>
#include <cassert>
#include <vector>


#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}

int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal

}  // namespace atcoder


namespace atcoder {

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

}  // namespace atcoder


#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

template<typename T>
vector<vector<T>> vec2d(int n, int m, T v){
    return vector<vector<T>>(n, vector<T>(m, v));
}

template<typename T>
vector<vector<vector<T>>> vec3d(int n, int m, int k, T v){
    return vector<vector<vector<T>>>(n, vector<vector<T>>(m, vector<T>(k, v)));
}

template<typename T>
void print_vector(vector<T> v, char delimiter=' '){
    if(v.empty()) {
        cout << endl;
        return;
    }
    for(int i = 0; i+1 < v.size(); i++) cout << v[i] << delimiter;
    cout << v.back() << endl;
}

const int inf = 2e9;

int op(int x, int y){
    return max(x, y);
}

int e(){
    return -inf;
}

using Seg = atcoder::segtree<int, op, e>;

void solve(){
    int n; cin >> n;
    auto a = vec2d(2, n, 0);
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            if(i != 0 || j != 0) a[i][j]++;
        }
    }
    auto calc = [&](vector<int> b, vector<int> c, int p){
        Seg seg_left(c), seg_right(b);
        int ans = inf;
        for(int x = p; x < n; x += 2){
            chmin(ans, max(0, op(seg_left.prod(0, x), seg_right.prod(x, n) - (x/2)*2)));
        }
        return ans;
    };
    int ans = inf;
    {
        auto b = vec2d(2, n, 0);
        auto c = vec2d(2, n, 0);
        for(int j = 0; j < n; j++){
            b[0][j] = a[0][j]-j;
            b[1][j] = a[1][j]-n-(n-1-j);
            if(j%2 == 0){
                c[0][j] = a[0][j]-2*j;
                c[1][j] = a[1][j]-2*j-1;
            }else{
                c[0][j] = a[0][j]-2*j-1;
                c[1][j] = a[1][j]-2*j;
            }
        }
        vector<int> bb(n), cc(n);
        for(int i = 0; i < n; i++) bb[i] = max(b[0][i], b[1][i]);
        for(int i = 0; i < n; i++) cc[i] = max(c[0][i], c[1][i]);
        chmin(ans, calc(bb, cc, 0)+2*n-1);
    }
    {
        auto b = vec2d(2, n, 0);
        auto c = vec2d(2, n, 0);
        b[0][0] = a[0][0];
        b[1][0] = a[1][0]-1;
        for(int j = 0; j < n; j++){
            if(j > 0){
                b[0][j] = a[0][j]-n-(n-j);
                b[1][j] = a[1][j]-(j+1);
            }
            if(j%2 == 0){
                c[0][j] = a[0][j]-2*j;
                c[1][j] = a[1][j]-2*j-1;
            }else{
                c[0][j] = a[0][j]-2*j-1;
                c[1][j] = a[1][j]-2*j;
            }
        }
        vector<int> bb(n), cc(n);
        for(int i = 0; i < n; i++) bb[i] = max(b[0][i], b[1][i]);
        for(int i = 0; i < n; i++) cc[i] = max(c[0][i], c[1][i]);
        chmin(ans, calc(bb, cc, 1)+2*n-1);
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}