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
    ll k; cin >> k;
    if(k%2 == 1){
        cout << -1 << endl;
        return;
    }
    k /= 2;
    vector<ll> v(60);
    for(int i = 0; i < 60; i++){
        v[i] = (1ll<<i)-1;
    }
    int idx = 59;
    vector<int> ans;
    while(k > 0){
        while(v[idx] > k) idx--;
        int x = k/v[idx];
        for(int i = 0; i < x; i++) ans.push_back(idx);
        k %= v[idx];
    }
    cout << accumulate(ans.begin(), ans.end(), 0) << endl;
    for(int x: ans){
        cout << 1 << ' ';
        for(int i = 0; i < x-1; i++) cout << 0 << ' ';
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}