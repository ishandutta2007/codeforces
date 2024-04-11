#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<P, ll> Ppl;

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
    T (*merge)(T, S);

    LazySegmentTree(vector<T> v, T UNIT, S UNIT_LAZY, T (*_calc)(T, T), S (*_propagateLazy)(S, S), T (*_merge)(T, S)) {
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

ll propagate(ll a, ll b){
    return a+b;
}

ll calc(ll a, ll b){
    return max(a, b);
}

ll merge(ll a, ll b){
    return a+b;
}

int n, m, p;
// asort
ll a[200000], ca[200000];
// bsort
ll b[200000], cb[200000];
// xsort
ll x[200000], y[200000], z[200000];

void input(){
    cin >> n >> m >> p;
    for(int i = 0; i < n; i++) cin >> a[i] >> ca[i];
    for(int i = 0; i < m; i++) cin >> b[i] >> cb[i];
    for(int i = 0; i < p; i++) cin >> x[i] >> y[i] >> z[i];
}

void sort_items(){
    vector<P> v;
    for(int i = 0; i < n; i++) v.push_back(P(a[i], ca[i]));
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        a[i] = v[i].first;
        ca[i] = v[i].second;
    }
    v.clear();

    for(int i = 0; i < m; i++) v.push_back(P(b[i], cb[i]));
    sort(v.begin(), v.end());
    for(int i = 0; i < m; i++){
        b[i] = v[i].first;
        cb[i] = v[i].second;
    }

    vector<Ppl> u;
    for(int i = 0; i < p; i++) u.push_back(Ppl(P(x[i], y[i]), z[i]));
    sort(u.begin(), u.end());
    for(int i = 0; i < p; i++){
        x[i] = u[i].first.first;
        y[i] = u[i].first.second;
        z[i] = u[i].second;
    }
}

const ll INF = 1e15;

void solve(){
    sort_items();
    vector<ll> v(m);
    for(int i = 0; i < m; i++){
        v[i] = -cb[i];
    }
    LazySegmentTree<ll, ll> sgt(v, -INF, 0, calc, propagate, merge);
    
    ll ans = -INF;
    int cur = 0;
    for(int i = 0; i < n; i++){
        while(cur < p && x[cur] < a[i]){
            if(y[cur] < b[0]){
                sgt.update(0, m, z[cur]);
            }else if(y[cur] >= b[m-1]){

            }else{
                auto ptr = upper_bound(b, b+m, y[cur]);
                int d = ptr-b;
                sgt.update(d, m, z[cur]);
            }
            cur++;
        }
        // cout << cur << ' ' << sgt.query(0, m)-ca[i] << endl;
        ans = max(ans, sgt.query(0, m)-ca[i]);
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    input();
    solve();
}