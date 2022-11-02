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

// calc ceil(a/b) 
template<typename T>
T ceil_div(T a, T b){
    return (a+b-1)/b;
}

ll calc(ll a, ll b){
    if(a < b) swap(a, b);
    if(a >= 2*b){
        return ceil_div(a, 2ll);
    }
    ll d = a-b;
    ll ans = d;
    a -= 2*d;
    b -= d;
    ans += 2*(a/3);
    int rem = a%3;
    ans += rem;
    return ans;
}

ll calc2(ll a, ll b){
    if(a%2 == 0 || b%2 == 0){
        return ceil_div(a, 2ll) + ceil_div(b, 2ll);
    }
    return (a/2)+(b/2)+1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    auto b = a;
    sort(b.begin(), b.end());
    ll ans = ceil_div(b[0], 2ll) + ceil_div(b[1], 2ll);
    for(int i = 0; i < n-1; i++){
        chmin(ans, calc(a[i], a[i+1]));
    }
    for(int i = 0; i < n-2; i++){
        chmin(ans, calc2(a[i], a[i+2]));
    }
    cout << ans << endl;
}