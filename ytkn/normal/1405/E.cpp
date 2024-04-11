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
typedef pair<int, int> P;

template <typename T>
struct bit{
    int n;
    vector<T> data;

    bit(int n_){
        n = 1;
        while(n < n_) n *= 2;
        data = vector<T>(n+1);
        for(int i = 0; i <= n; i++) data[i] = 0;
    }
    
    T sum(int i){
        T ret = 0;
        while(i > 0){
            ret += data[i];
            i -= i&-i;
        }
        return ret;
    }

    void add(int i, T x){
        while(i <= n){
            data[i] += x;
            i += i&-i;
        }
    }
};

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

struct node{
    int val, idx;
};

node calc(node a, node b){
    if(a.val < b.val) return a;
    return b; 
}

int propagate(int a, int b){
    return a+b;
}

node merge(node a, int x){
    return (node){a.val+x, a.idx};
}

int n, q;
vector<int> a;
vector<int> X, Y;
// xsort
vector<int> x, y;
vector<int> idx;
vector<int> ans;

void input(){
    cin >> n >> q;
    a = vector<int>(n+1);
    X = vector<int>(n);
    Y = vector<int>(n);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] -= i;
    }
    for(int i = 0; i < q; i++) {
        cin >> X[i] >> Y[i];
    }
}

void sort_queries(){
    vector<P> v;
    x = vector<int>(q);
    y = vector<int>(q);
    idx = vector<int>(q);
    for(int i = 0; i < q; i++){
        v.push_back(P(X[i], i));
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < q; i++){
        idx[i] = v[i].second;
        x[i] = X[idx[i]];
        y[i] = Y[idx[i]];
    }
}

void solve(){
    sort_queries();
    ans = vector<int>(n);
    bit<int> bt(n); // index
    int erasable_cnt = 0;
    
    for(int i = 1; i <= n; i++){
        bool is_erasable = (a[i] <= 0 && a[i]+erasable_cnt >= 0);
        if(is_erasable){
            bt.add(i, 1);
            a[i] += erasable_cnt;
            erasable_cnt++;
        }else{
            a[i] = 1e9;
        }
    }
    vector<node> vn;
    vn.push_back((node){n+1, 0});
    for(int i = 1; i <= n; i++) vn.push_back((node){a[i], i});
    LazySegmentTree<node, int> sgt(vn, (node){(int)1e9, 0}, 0, calc, propagate, merge);
    int cur_idx = 0;
    for(int l = 0; l <= n; l++){
        // cout << "l:" << l << endl;
        bool is_erasable = false;
        if(l != 0){
            is_erasable = (bt.sum(l)-bt.sum(l-1)) == 1;
        }
        if(is_erasable){
            // cout << "revert:" << l << endl;
            auto min_node = sgt.query(l, l+1);
            int dif = n+1-min_node.val;
            sgt.update(min_node.idx, min_node.idx+1, dif);
            sgt.update(l, n+2, -1);
            bt.add(l, -1);
        }
        while(true){
            auto min_node = sgt.query(0, n+2);
            if(min_node.val < 0){
                // cout << "revert:" << min_node.idx << endl;
                sgt.update(min_node.idx, n+2, -1);
                int dif = n+1-min_node.val;
                sgt.update(min_node.idx, min_node.idx+1, dif);
                bt.add(min_node.idx, -1);
            }else{
                break;
            }
        }
        while(cur_idx < q && x[cur_idx] <= l){
            int i = idx[cur_idx];
            ans[i] = bt.sum(n-y[cur_idx]);
            // cout << x[cur_idx] << ' ' << y[cur_idx] << ' ' << i << ' ' << bt.sum(n) << endl;
            cur_idx++;
        }
    }
    for(int i = 0; i < q; i++) {
        // cout << idx[i] << endl;
        cout << ans[i] << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    input();
    solve();
}