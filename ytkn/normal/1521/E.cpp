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

int max_single(int n){
    int k = n/2;
    if(n%2 == 0){
        return 2*k*k;
    }else{
        return (2*k+1)*(k+1);
    }
}

int max_all(int n){
    int k = n/2;
    if(n%2 == 0){
        return 3*k*k;
    }else{
        return 3*k*k+4*k+1;
    }
}

using P = pair<int, int>;

void solve(){
    int m, k; cin >> m >> k;
    vector<int> a(k);
    vector<P> vp(k);
    for(int i = 0; i < k; i++) {
        cin >> a[i];
        vp[i] = P(a[i], i);
    }
    sort(vp.begin(), vp.end(), greater<P>());
    int a_max = *max_element(a.begin(), a.end());
    auto ok = [&](int x){
        if(max_all(x) < m) return false;
        if(max_single(x) < a_max) return false;
        return true;
    };
    int ans = 1;
    if(!ok(1)){
        int l = 1, r = 10000;
        while(r-l > 1){
            int x = (l+r)/2;
            if(!ok(x)) l = x;
            else r = x;
        }
        ans = r;
    }
    vector<P> indices;
    for(int i = 0; i < ans; i+=2){
        for(int j = 1; j < ans; j+=2){
            indices.push_back(P(i, j));
        }
    }
    for(int i = 0; i < ans; i+=2){
        for(int j = 0; j < ans; j+=2){
            indices.push_back(P(i, j));
        }
    }
    for(int i = 1; i < ans; i+=2){
        for(int j = 0; j < ans; j+=2){
            indices.push_back(P(i, j));
        }
    }
    int idx = 0;
    auto f = vec2d(ans, ans, 0);
    for(auto [cnt, x]: vp){
        for(int i = 0; i < cnt; i++){
            auto [a, b] = indices[idx];
            f[a][b] = x+1;
            idx++;
        }  
    }
    cout << ans << endl;
    for(auto v: f) print_vector(v);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}