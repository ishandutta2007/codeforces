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

/**
 * ax + by = gcd(a, b)(x, y)gcd(a, b)
 */ 
template <typename T>
T extGCD(T a, T b, T &x, T &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    T d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}

ll f(int n, vector<ll> a){
    ll cur = 0;
    int k = -1;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        cur += a[i];
        if(cur < 0){
            cur = 0;
            k = i;
        }
        chmax(ans, cur*(i-k));
    }
    return ans;
}

ll ok(int n, vector<ll> a){
    auto cumsum = Cumsum<ll>(a);
    ll ans = 0;
    for(int l = 0; l < n; l++){
        for(int r = l+1; r <= n; r++){
            chmax(ans, cumsum.sum(l, r)*(r-l));
        }
    }
    return ans;
}

const int MX = 1000000;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    ll k; cin >> k;
    ll x = 1001, y = 501;
    ll rem = k%2000;
    ll used = k/2000;
    if(rem == 0){
        used--;
        rem += 2000;   
    }
    vector<ll> ans(2000);
    ll Y = -used+rem*501;
    ll X = rem*1001;
    while(Y < 0){
        Y += 1001;
        X += 2000;
    }
    ll base = X/999;
    for(int i = 1001; i < 2000; i++){
        ans[i] = base;
        if(i-1001 < X%999) {
            ans[i]++;
        }
    }
    for(int i = 1000; i >= 0; i--){
        ans[i] = -min((ll)MX, Y);
        Y += ans[i];
    }
    cout << 2000 << endl;
    print_vector(ans);
    // cout << f(2000, ans) - ok(2000, ans) << endl;
}