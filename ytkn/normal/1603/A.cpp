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

vector<ll> v;
const ll N_MAX = 1e9;

ll lcm(ll x, ll y){
    ll g = gcd(x, y);
    return (x/g)*y;
}

void init(){
    v.resize(2);
    v[0] = 1;
    v[1] = 1;
    int cur = 2;
    while(true){
        ll tmp = lcm(v[cur-1], cur);
        if(tmp > N_MAX) break;
        v.push_back(tmp);
        cur++;
    }
}

void solve(){
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int m = v.size()-1;
    for(int i = 0; i+2 <= m && i < n; i++){
        bool ok = false;
        for(int j = 2; j <= i+2; j++){
            if(a[i]%v[j] != 0) ok = true;
        }
        if(!ok){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    init();
    // print_vector(v);
    int t; cin >> t;
    while(t--) solve();
}