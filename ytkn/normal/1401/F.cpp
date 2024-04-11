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
    if(v.empty()) {
        cout << endl;
        return;
    }
    for(int i = 0; i+1 < v.size(); i++) cout << v[i] << delimiter;
    cout << v.back() << endl;
}

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

    T sum(int l, int r){
        if(l > r) swap(l, r);
        // cout << "[" << l << ", " << r << ")" << endl;
        return sum(r-1) - sum(l-1);
    }

    void add(int i, T x){
        while(i <= n){
            data[i] += x;
            i += i&-i;
        }
    }
};
int xo = 0;
bit<ll> bt(1);
vector<int> a;

ll sum_naive(int l, int r) {
    if(l == r) return 0;
    ll ans = 0;
    for(int i = l; i < r; i++){
        ans += a[i^xo];
    }
    return ans;
};

ll sum(int l, int r, int depth, int n) {
    if(l == r) return 0;
    // cout << l << ',' << r << ' ' << depth << endl;
    ll ans = 0;
    int x = 1<<depth;
    assert(l%x == 0);
    assert(r%x == 0);
    int all_bits = (1<<n)-1;
    int mask = (1<<(depth))-1;
    int xx = xo&(all_bits^mask);
    if(l&x){
        int lx = l^xx;
        assert((lx&mask) == 0);
        ans += bt.sum(lx+1, lx+x+1);
        l += x;
    }
    if(r&x){
        int lx = (r-x)^xx;
        assert((lx&mask) == 0);
        ans += bt.sum(lx+1, lx+x+1);
        r -= x;
    }
    ans += sum(l, r, depth+1, n);
    return ans;
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, q; cin >> n >> q;
    int m = 1<<n;
    bt = bit<ll>(m);
    a.resize(m);
    for(int i = 0; i < m; i++) {
        cin >> a[i];
        bt.add(i+1, a[i]);
    }
    auto rep = [&](int x, int k){
        x ^= xo;
        bt.add(x+1, -a[x]);
        a[x] = k;
        bt.add(x+1, a[x]);
    };
    auto rev = [&](int k){
        for(int i = 0; i <= k-1; i++) xo ^= 1<<i;
    };
    auto sw = [&](int k){
        xo ^= 1<<k;
    };

    while(q--){
        int t; cin >> t;
        if(t == 1){
            int x, k; cin >> x >> k; x--;
            rep(x, k);
        }else if(t == 2){
            int k; cin >> k;
            rev(k);
        }else if(t == 3){
            int k; cin >> k;
            sw(k);
        }else{
            int l, r; cin >> l >> r; l--;
            // cout << sum_naive(l, r) << endl;
            cout << sum(l, r, 0, n) << endl;
        }
        // for(int i = 0; i < m; i++){
        //     cout << a[i^xo] << ' ';
        // }
        // cout << endl;
        // for(int i = 0; i < m; i++){
        //     cout << bt.sum((i^xo)+1, (i^xo)+2) << ' ';
        // }
        // cout << endl;
    }
}