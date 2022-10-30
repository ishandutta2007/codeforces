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

const ll INF = 1e18;
using P = pair<int, int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, q; cin >> n >> q;
    vector<ll> a(n), b(n), d(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) {
        d[i] = a[i]-b[i];
    }
    
    vector<ll> d_cumsum(n+1);
    for(int i = 0; i < n; i++) d_cumsum[i+1] = d_cumsum[i] + d[i];
    auto sect_sum = [&](int l, int r){
        return d_cumsum[r]-d_cumsum[l];
    };
    
    segtree<ll> sgt_max(n+1, -INF, [](ll a, ll b){ return max(a, b); }); 
    segtree<ll> sgt_min(n+1, INF, [](ll a, ll b){ return min(a, b); }); 
    for(int i = 0; i <= n; i++){
        sgt_max.update(i, d_cumsum[i]);
        sgt_min.update(i, d_cumsum[i]);
    }

    while(q--){
        int l, r; cin >> l >> r; l--; r--;
        if(sect_sum(l, r+1) != 0){
            cout << -1 << endl;
            continue;
        }
        
        ll s1 = sgt_max.query(l, r+2)-d_cumsum[l];
        if(s1 > 0){
            cout << -1 << endl;
            continue;
        }
        ll s2 = sgt_min.query(l, r+2)-d_cumsum[l];
        cout << max(abs(s1), abs(s2)) << endl;
    }
}