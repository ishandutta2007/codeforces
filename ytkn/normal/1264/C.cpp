#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <functional>
#include <cassert>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

class ModInt{
    public:
    ll v;
    ModInt(ll _v = 0){
        if(_v >= MOD) _v %= MOD;
        v = _v;
    }
    ModInt operator+(ll n){
        return ModInt((v+n)%MOD);
    }
    ModInt operator-(ll n){
        return ModInt((v-n+MOD)%MOD);
    }
    ModInt operator*(ll n){
        if(n >= MOD) n %= MOD;
        return ModInt((v*n)%MOD);
    }
    ModInt operator/(ll n){
        return ModInt((ModInt(n).inv()*v).v%MOD);
    }

    void operator+=(ll n){
        v = (v+n)%MOD;
    }
    void operator-=(ll n){
        v = (v-n+MOD)%MOD;
    }
    void operator*=(ll n){
        v = (v*n+MOD)%MOD;
    }
    
    
    ModInt operator+(ModInt n){
        return ModInt((v+n.v)%MOD);
    }
    ModInt operator-(ModInt n){
        return ModInt((v-n.v+MOD)%MOD);
    }
    ModInt operator*(ModInt n){
        return ModInt((v*n.v)%MOD);
    }
    ModInt operator/(ModInt n){
        return ModInt((n.inv()*v).v%MOD);
    }

    void operator+=(ModInt n){
        v = (v+n.v)%MOD;
    }
    void operator-=(ModInt n){
        v = (v-n.v+MOD)%MOD;
    }
    void operator*=(ModInt n){
        v = (v*n.v)%MOD;
    }

    void operator=(ModInt n){
        v = n.v;
    }
    bool operator==(ModInt n){
        return v == n.v;
    }
    bool operator!=(ModInt n){
        return v != n.v;
    }
    void operator=(ll n){
        v = n%MOD;
    }

    ModInt inv(){
        if(v == 1) return ModInt(1);
        else return ModInt(MOD-ModInt(MOD%v).inv().v*(MOD/v)%MOD);
    }
};

ostream& operator<<(ostream& os, const ModInt& m){
    os << m.v;
    return os;
}

istream & operator >> (istream &in,  ModInt &m){
    in >> m.v;
    return in;
}

template <typename T, typename S>
struct LazySegmentTree {
    int n;
    T unit;
    S unit_lazy;
    vector<T> node;
    vector<S> lazy;
    vector<bool> lazyFlag;

    T (*calc)(T, T);
    S (*propagateLazy)(S, S);
    T (*merge)(S, T);

    LazySegmentTree(vector<T> v, T UNIT, S UNIT_LAZY, T (*_calc)(T, T), S (*_propagateLazy)(S, S), T (*_merge)(S, T)) {
        int sz = (int)v.size();
        unit = UNIT;
        unit_lazy = UNIT_LAZY;
        calc = _calc;
        propagateLazy = _propagateLazy;
        merge = _merge;
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, unit);
        lazy.resize(2*n-1, UNIT_LAZY);
        lazyFlag.resize(2*n-1, false);

        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = calc(node[i*2+1], node[i*2+2]);
    }

    void lazyEvaluate(int k, int l, int r) {
        if(lazyFlag[k]) {
            node[k] = merge(node[k], lazy[k]);
            if(r - l > 1) {
                lazy[k*2+1] = propagateLazy(lazy[k*2+1], lazy[k]);
                lazy[k*2+2] = propagateLazy(lazy[k*2+2], lazy[k]);
                lazyFlag[k*2+1] = lazyFlag[k*2+2] = true;
            }
            lazyFlag[k] = false;
            lazy[k] = unit_lazy;
        }
    }

    //[a, b)
    //[a, b]update(a, b+1, x)
    void update(int a, int b, S x, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        lazyEvaluate(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            lazy[k] = propagateLazy(lazy[k], x);
            lazyFlag[k] = true;
            lazyEvaluate(k, l, r);
        }
        else {
            update(a, b, x, 2*k+1, l, (l+r)/2);
            update(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = calc(node[2*k+1], node[2*k+2]);
        }
    }

    //[a, b)
    //[a, b]query(a, b+1)
    T query(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        lazyEvaluate(k, l, r);
        if(b <= l || r <= a) return unit;
        if(a <= l && r <= b) return node[k];
        T vl = query(a, b, 2*k+1, l, (l+r)/2);
        T vr = query(a, b, 2*k+2, (l+r)/2, r);
        return calc(vl, vr);
    }
};

using mint = ModInt;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, q; cin >> n >> q;
    vector<mint> p(n);
    set<int> st;
    st.insert(0);
    st.insert(n);
    for(int i = 0; i < n; i++){
        cin >> p[i];
        p[i] *= mint(100).inv();
    }

    vector<mint> cum_prod(n+1, mint(1));
    for(int i = 0; i < n; i++) cum_prod[i+1] = cum_prod[i]*p[i];

    auto sect_prod = [&](int l, int r){ // [l, r)
        return (cum_prod[r]*cum_prod[l].inv()).inv();
    };

    vector<mint> v(n);
    for(int i = 0; i < n; i++) {
        v[i] = sect_prod(i, n);
    }
    
    LazySegmentTree<mint, mint> sgt(
        v,
        mint(0),
        mint(1),
        [](mint a, mint b){ return a+b; },
        [](mint a, mint b){ return a*b; },
        [](mint a, mint b){ return a*b; }
    );

    while(q--){
        int u; cin >> u; u--;
        if(st.count(u)){
            auto ptr = st.upper_bound(u);
            int r = *ptr; ptr--; ptr--;
            int l = *ptr;
            sgt.update(l, u, sect_prod(u, r));
            st.erase(u);
        }else{
            auto ptr = st.upper_bound(u);
            int r = *ptr; ptr--;
            int l = *ptr;
            sgt.update(l, u, sect_prod(u, r).inv());
            st.insert(u);
        }
        cout << sgt.query(0, n) << endl;
    }
}