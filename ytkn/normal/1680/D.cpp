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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; ll k; cin >> n >> k;
    vector<ll> a(n);
    vector<int> cnt(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 0) cnt[i] = 1;
    }
    auto cumsum_len = Cumsum<ll>(a);
    auto cumsum_cnt = Cumsum<int>(cnt);
    auto min_dist = [&](int l, int r){
        ll len_fixed = cumsum_len.sum(l, r);
        ll len_additional = k*cumsum_cnt.sum(l, r);
        return len_fixed-len_additional;
    };
    auto max_dist = [&](int l, int r){
        ll len_fixed = cumsum_len.sum(l, r);
        ll len_additional = k*cumsum_cnt.sum(l, r);
        return len_fixed+len_additional;
    };
    auto sub_solve = [&]()->ll{
        ll ans = -1;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j <= n; j++){
                ll ar = -min_dist(0, i);
                ll br = -min_dist(j, n);
                if(ar < 0) continue;
                if(br < 0) continue;
                ll al = max(0ll, -max_dist(0, i));
                ll bl = max(0ll, -max_dist(j, n));
                ll cl = min_dist(i, j);
                ll cr = max_dist(i, j);
                
                ll l = max(al+bl, cl);
                ll r = min(ar+br, cr);
                if(r < l) continue;
                chmax(ans, r);
            }
        }
        return ans;
    };
    ll ans = sub_solve();
    for(int i = 0; i < n; i++) a[i] *= -1;
    cumsum_len = Cumsum<ll>(a);
    chmax(ans, sub_solve());
    if(ans == -1){
        cout << -1 << endl;
    }else{
        cout << ans+1 << endl;
    }
}