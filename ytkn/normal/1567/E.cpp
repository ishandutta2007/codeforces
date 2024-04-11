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
    for(int i = 0; i+1 < v.size(); i++) cout << v[i] << delimiter;
    cout << v.back() << endl;
}

struct node{
    ll through, l, r, middle;
};

node e = node{0, 0, 0, 0};

ll tri(ll n){
    return (n*(n+1))/2;
}

node add(node n1, node n2){
    if(n1.through > 0 && n2.through > 0){
        return node{n1.through+n2.through, 0, 0, 0};
    }
    if(n1.through > 0){
        return node{0, n1.through+n2.l, n2.r, n2.middle};
    }
    if(n2.through > 0){
        return node{0, n1.l, n1.r+n2.through, n1.middle};
    }
    return node{0, n1.l, n2.r, n1.middle+n2.middle+tri(n1.r+n2.l)};
}

template <typename T>
struct segtree{
    int n;
    T UNIT;
    vector<T> dat;
    T (*calc)(T, T);

    segtree(int n_, T unit, T (*_calc)(T, T)){
        UNIT = unit;
        calc = _calc;
        n = 1;
        while(n < n_) n *= 2;
        dat = vector<T>(2*n);
        for(int i = 0; i < 2*n; i++) dat[i] = UNIT;
    }

    void insert(int k, T a){
        dat[k+n-1] = a;
    }
    void update_all(){
        for(int i = n-2; i >= 0; i--){
            dat[i] = calc(dat[i*2+1], dat[i*2+2]);
        }
    }
    //k(0-indexed)a
    void update(int k, T a){
        k += n-1;
        dat[k] = a;
        while(k > 0){
            k = (k-1)/2;
            dat[k] = calc(dat[k*2+1], dat[k*2+2]);
        }
    }

    //[a, b)
    //[a, b]query(a, b+1)
    T query(int a, int b, int k=0, int l=0, int r=-1){
        if(r < 0) r = n;
        if(r <= a || b <= l) return UNIT;
        if(a <= l && r <= b) return dat[k];
        else{
            T vl = query(a, b, k*2+1, l, (l+r)/2);
            T vr = query(a, b, k*2+2, (l+r)/2, r);
            return calc(vl, vr);
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    segtree<node> sgt(n-1, e, add);
    for(int i = 0; i < n-1; i++){
        if(a[i] <= a[i+1]) sgt.update(i, node{1, 0, 0, 0});
        
    }
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int i, y; cin >> i >> y; i--;
            a[i] = y;
            if(i > 0){
                if(a[i-1] <= a[i]) sgt.update(i-1, node{1, 0, 0, 0});
                else sgt.update(i-1, e);
            }
            if(i < n-1){
                if(a[i] <= a[i+1]) sgt.update(i, node{1, 0, 0, 0});
                else sgt.update(i, e);
            }
        }else{
            int l, r; cin >> l >> r; l--;
            auto nd = sgt.query(l, r-1);
            cout << nd.middle+tri(nd.l)+tri(nd.r)+tri(nd.through)+r-l << endl;
        }
    }
}