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

const ll inf = 1e18;

void solve(){
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<ll> sum(n);
    sum[0] = a[0];
    for(int i = 1; i < n; i++){
        sum[i] = a[i]-sum[i-1];
    }
    vector<ll> odd_min(n+2, inf), even_min(n+2, inf);
    for(int i = n-1; i >= 0; i--){
        if(i+1 <= n-1){
            chmin(odd_min[i], odd_min[i+1]);
            chmin(even_min[i], even_min[i+1]);
        }
        if(i%2 == 0){
            chmin(even_min[i], sum[i]);
        }else{
            chmin(odd_min[i], sum[i]);
        }
    }
    if(sum.back() == 0 && odd_min[0] >= 0 && even_min[0] >= 0){
        cout << "YES" << endl;
        return;
    }
    for(int i = 0; i+1 < n; i++){
        ll tail = sum.back();
        if(i%2 == (n-1)%2){
            tail -= (a[i]-a[i+1])*2;
        }else{
            tail += (a[i]-a[i+1])*2;
        }
        if(tail == 0 && sum[i]-a[i]+a[i+1] >= 0) {
            if(i%2 == 0){
                ll even_mn = even_min[i+1]-(a[i]-a[i+1])*2;
                ll odd_mn = odd_min[i+1]+(a[i]-a[i+1])*2;
                if(even_mn >= 0 && odd_mn >= 0){
                    cout << "YES" << endl;
                    return;
                }
            }else{
                ll even_mn = even_min[i+1]+(a[i]-a[i+1])*2;
                ll odd_mn = odd_min[i+1]-(a[i]-a[i+1])*2;
                if(even_mn >= 0 && odd_mn >= 0){
                    cout << "YES" << endl;
                    return;
                }
            }
        }
        if(sum[i] < 0) break;
    }
    cout << "NO" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
}