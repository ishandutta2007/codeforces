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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<ll> b(n);
    for(int i = 0; i < n; i++) cin >> b[i];
    vector<int> ans;
    for(int i = 0; i < 60; i++){
        ll x = 1ll<<i;
        vector<int> v;
        for(int j = 0; j < n; j++){
            if(b[j]%x != 0) continue;
            if(b[j]%(2*x) == x) {
                v.push_back(j);
            }
        }
        if(v.size() > ans.size()) ans = v;
    }
    vector<bool> ok(n);
    for(int i: ans){
        ok[i] = true;
    }
    vector<ll> v;
    for(int i = 0; i < n; i++){
        if(!ok[i]) v.push_back(b[i]);
    }
    cout << v.size() << endl;
    print_vector(v);
}