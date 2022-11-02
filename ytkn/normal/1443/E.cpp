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

const ll INF = 1e12;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, q; cin >> n >> q;
    vector<ll> fac(n);
    fac[0] = 1;
    for(int i = 1; i < n; i++){
        fac[i] = min(INF, fac[i-1]*i);
    }
    vector<ll> a(n);
    for(int i = 0; i < n; i++) a[i] = i+1;
    segtree<ll> sgt(n, 0, [](ll a, ll b){ return a+b; });
    for(int i = 0; i < n; i++) sgt.update(i, a[i]);
    ll y = 0;
    int m = min(15, n-1);
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int l, r; cin >> l >> r;
            cout << sgt.query(l-1, r) << endl;
            // for(int i = 0; i < n; i++) cout << sgt.query(i, i+1) << ' ';
            // cout << endl;
        }else{
            int x; cin >> x;
            y += x;
            vector<int> v(m+1);
            ll s = y;
            // cout << y << endl;
            set<int> st;
            for(int i = 0; i <= m; i++) st.insert(n-i);
            for(int i = m; i >= 1; i--){
                v[i] = s/fac[i];
                s %= fac[i];
            }
            for(int i = m; i >= 0; i--) {
                int cnt = 0;
                int p = 0;
                for(int x : st){
                    if(cnt == v[i]){
                        sgt.update(n-i-1, x);
                        p = x;
                        break;
                    }
                    cnt++;
                }
                st.erase(p);
            }
        }
    }
}