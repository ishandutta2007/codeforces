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

void solve(){
    ll n, m; cin >> n >> m;
    int k; cin >> k;
    vector<ll> a(k);
    for(int i = 0; i < k; i++) cin >> a[i];
    auto ok = [&](){
        vector<ll> b;
        for(int i = 0; i < k; i++){
            if(a[i] >= 2*n) b.push_back(a[i]/n);
        }
        sort(b.begin(), b.end());
        ll sum = accumulate(b.begin(), b.end(), 0ll);
        if(sum > m) {
            if(b.back() == 2 && (m%2 == 1)) return false;
            return true;
        }
        if(sum < m) return false;
        return true; 
    };
    if(ok()){
        cout << "Yes" << endl;
        return;
    }
    swap(n, m);
    if(ok()){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}