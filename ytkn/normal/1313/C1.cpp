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
    vector<int> m(n);
    for(int i = 0; i < n; i++) cin >> m[i];
    auto calc = [&](int c){
        ll ans = m[c];
        int x = m[c];
        for(int i = c-1; i >= 0; i--){
            ans += min(x, m[i]);
            chmin(x, m[i]);
        }
        x = m[c];
        for(int i = c+1; i < n; i++){
            ans += min(x, m[i]);
            chmin(x, m[i]);
        }
        return ans;
    };
    int mx = -1;
    ll sum = 0;
    for(int c = 0; c < n; c++){
        if(chmax(sum, calc(c))) mx = c;
    }
    vector<int> ans(n);
    int x = m[mx];
    ans[mx] = x;
    for(int i = mx-1; i >= 0; i--){
        chmin(x, m[i]);
        ans[i] = x;
    }
    x = m[mx];
    for(int i = mx+1; i < n; i++){
        chmin(x, m[i]);
        ans[i] = x;
    }
    print_vector(ans);
}