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
#include <random>

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

vector<int> gen_array(int n, int l, int r){
    int d = r-l;
    random_device rnd;
    mt19937 mt(rnd());
    vector<int> ans(n);
    int x = mt();
    for(int i = 0; i < n; i++) ans[i] = l+(mt()%d);
    return ans;
}

vector<ll> naive(vector<ll> a, vector<ll> b){
    int n = a.size()-1;
    vector<ll> ans(n+1);
    for(int i = 1; i <= n; i++){
        ll x = b[i]-a[i];
        for(int j = 1; i*j <= n; j++){
            a[i*j] += x;
        }
        ans[i] = x;
    }
    return ans;
}

vector<ll> calc(int n){
    vector<ll> a(n+1), b(n+1);
    b[1] = 1;
    return naive(a, b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<ll> a(n+1), b(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    
    b[1] = 0;
    auto v = naive(a, b);
    auto u = calc(n);

    vector<ll> pos_effect, neg_effect;
    ll sum = 0;
    for(int i = 1; i <= n; i++){
        if(u[i] > 0){
            pos_effect.push_back(-v[i]);
        }else if(u[i] < 0){
            neg_effect.push_back(v[i]);
        }else{
            sum += abs(v[i]);
        }
    }
    sort(pos_effect.begin(), pos_effect.end());
    sort(neg_effect.begin(), neg_effect.end());
    auto pos_cumsum = Cumsum<ll>(pos_effect);
    auto neg_cumsum = Cumsum<ll>(neg_effect);
    
    auto calc = [&](Cumsum<ll> &cumsum, vector<ll> &data, ll x) -> ll{
        ll m = data.size();
        ll c = lower_bound(data.begin(), data.end(), x) - data.begin();
        ll ans = -(cumsum.sum(0, c)-x*c);
        ans += cumsum.sum(c, m) - x*(m-c);
        return ans;
    };
    // print_vector(v);
    // print_vector(u);
    int q; cin >> q;
    while(q--){
        ll x; cin >> x;
        ll ans = sum+calc(pos_cumsum, pos_effect, x)+calc(neg_cumsum, neg_effect, x);
        // cout << calc(pos_cumsum, pos_effect, x) << ' ' << calc(neg_cumsum, neg_effect, x) << endl;
        cout << ans << endl;
        // ans = sum;
        // for(int i = 1; i <= n; i++){
        //     if(u[i] == 0) continue;
        //     ans += abs(v[i]+x*u[i]);
        // }
        // cout << ans << endl;
    }
}