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

using P = pair<int, ll>;

vector<P> run_length(vector<int> &s){
    int n = s.size();
    int pre = s[0];
    int cnt = 1;
    vector<P> ans;
    for(int i = 1; i < n; i++){
        int x = s[i];
        if(x == pre){
            cnt++;
        }else{
            ans.push_back(P(pre, cnt));
            pre = x;
            cnt = 1;
        }
    }
    ans.push_back(P(pre, cnt));
    return ans;
}

template<typename T>
class Cumsum{
    public:
    Cumsum(vector<T> v): v(v){
        n = v.size();
        v_cumsum = vector<T>(n+1, T(0));
        for(int i = 0; i < n; i++) v_cumsum[i+1] = v_cumsum[i]+v[i];
    }
    /**
     * v[l] + ... + v[r-1]
     */ 
    T sum(int l, int r){
        if(r <= l) return T(0);
        if(r > n) r = n;
        if(l < 0) l = 0;
        return v_cumsum[r]-v_cumsum[l];
    }
    private:
    int n;
    vector<T> v;
    vector<T> v_cumsum;
};

ll tri(ll x){
    return (x*(x+1))/2;
}

ll op(ll x, ll y){
    return max(x, y);
}

const ll inf = 1e9;

ll e(){
    return -inf;
}

using Seg = atcoder::segtree<ll, op, e>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<int> a(n);
    vector<ll> b(n);
    vector<ll> c(n);
    vector<ll> d(n);
    auto f = [&](int i, int x){
        return max(i-x, 0);
    };
    for(int i = 0; i < n; i++) {
        cin >> a[i]; a[i]--;
        b[i] = f(i, a[i]);
        if(i > 0) {
            vector<ll> v = {b[i], c[i-1], d[i-1]};
            sort(v.begin(), v.end(), greater<ll>());
            c[i] = v[0];
            d[i] = v[1];
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += i-c[i]+1;
    }
    Seg seg(b);
    Seg seg_d(d);
    auto cumsum = Cumsum<ll>(c);
    auto cumsum_d = Cumsum<ll>(d);
    int m; cin >> m;
    while(m--){
        int p, x; cin >> p >> x; p--; x--;
        x = f(p, x);
        if(x == c[p]){
            cout << ans << endl;
        }else if(x > c[p]){
            int r = upper_bound(c.begin(), c.end(), x)-c.begin();
            ll tmp = ans;
            tmp += cumsum.sum(p, r);
            tmp -= (ll)(r-p)*x;
            cout << tmp << endl;
        }else{
            if(c[p] > b[p] || d[p] == c[p]){
                cout << ans << endl;
                continue;
            }
            ll mx = seg.prod(0, p);
            chmax(mx, (ll)x);
            auto g = [&](ll x){
                return x <= mx;
            };
            auto gg = [&](ll a){
                return a < b[p];
            };
            int r1 = seg.max_right(p+1, g);
            int r2 = seg_d.max_right(p+1, gg);
            assert(r1 <= r2);
            ll tmp = ans;
            tmp += cumsum.sum(p, r2);
            tmp -= (ll)(r1-p)*mx;
            tmp -= cumsum_d.sum(r1, r2);
            cout << tmp << endl;
        }
    }
}