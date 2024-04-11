#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

template <typename T>
struct LazySegmentTree {
    int n;
    T unit;
    vector<T> node, lazy;
    vector<bool> lazyFlag;

    T calc(T a, T b){
        T ans;
        ans = min(a, b); //
        return ans;
    }

    T lazyEvaluateNode(T node, T lazy){
        return node+lazy; //
    }

    T clearLazy(){
        return 0; //
    }

    LazySegmentTree(vector<T> v, T UNIT) {
        int sz = (int)v.size();
        unit = UNIT;
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, 0);
        lazy.resize(2*n-1, 0);
        lazyFlag.resize(2*n-1, false);

        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = calc(node[i*2+1], node[i*2+2]);
    }

    void lazyEvaluate(int k, int l, int r) {
        if(lazyFlag[k]) {
            node[k] = lazyEvaluateNode(node[k], lazy[k]);
            if(r - l > 1) {
                lazy[k*2+1] = lazyEvaluateNode(lazy[k*2+1], lazy[k]);
                lazy[k*2+2] = lazyEvaluateNode(lazy[k*2+2], lazy[k]);
                lazyFlag[k*2+1] = lazyFlag[k*2+2] = true;
            }
            lazyFlag[k] = false;
            lazy[k] = clearLazy();
        }
    }

    //[a, b)
    //[a, b]update(a, b+1, x)
    void update(int a, int b, T x, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        lazyEvaluate(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            lazy[k] += x;
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

int N;
ll a[200005];
int p[200000];
ll cost[200005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> N;
    for(int i = 0; i < N; i++) cin >> p[i];
    for(int i = 0; i < N; i++){
        cin >> a[i];
        cost[p[i]] = a[i];
    }
    vector<ll> v;
    v.push_back(0);
    ll tmp = 0;
    for(int i = 1; i <= N; i++){
        tmp += cost[i];
        v.push_back(tmp);
    }
    LazySegmentTree<ll> sgt(v, 1e+15);
    ll ans = 1e+15;
    // for(int i = 0; i <= N; i++){
    //     cout << sgt.query(i, i+1) << ' ';
    // }
    // cout << endl;
    for(int i = 0; i < N-1; i++){
        int c = p[i];
        sgt.update(0, c, cost[c]);
        sgt.update(c, N+1, -cost[c]);
        ll tmp = sgt.query(0, N+1);
        // for(int i = 0; i <= N; i++){
        //     cout << sgt.query(i, i+1) << ' ';
        // }
        // cout << endl;
        ans = min(tmp, ans);
    }
    cout << ans << endl;
}