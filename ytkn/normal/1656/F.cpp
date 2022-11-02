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

const ll inf = 4e18;

void solve(){
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    ll a_sum = accumulate(a.begin(), a.end(), 0ll);
    {
        ll x = (a_sum-a[0]) + a[0]*(n-1);
        if(x > 0){
            cout << "INF" << endl;
            return;
        }
    }
    {
        ll x = (a_sum-a.back()) + a.back()*(n-1);
        if(x < 0){
            cout << "INF" << endl;
            return;
        }
    }
    ll ans = -inf;
    auto cumsum = Cumsum<ll>(a);
    for(ll x_: a){
        ll x = -x_;
        if(a[0]+x >= 0){
            ll tmp = (a_sum-a[0]+x*(n-1))*(a[0]+x);
            tmp -= x*x*(n-1);
            chmax(ans, tmp);
        }else if(a.back()+x <= 0){
            ll tmp = (a_sum-a.back()+x*(n-1))*(a.back()+x);
            tmp -= x*x*(n-1);
            chmax(ans, tmp);
        }else{
            // a >= -x
            auto p = lower_bound(a.begin(), a.end(), -x);
            ll c = p-a.begin();
            ll neg_sum = cumsum.sum(0, c)+c*x;
            ll pos_sum = cumsum.sum(c, n)+(n-c)*x;
            ll tmp = neg_sum*(a.back()+x) + pos_sum*(a[0]+x);
            tmp -= (a.back()+x)*(a[0]+x);
            tmp -= x*x*(n-1);
            chmax(ans, tmp);
        }
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}