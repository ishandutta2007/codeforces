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

const ll inf = 1e12;
vector<ll> facs;

void init(){
    facs.push_back(1);
    for(ll x = 1; ;x++){
        ll f = facs.back()*x;
        if(f > inf) break;
        facs.push_back(f);
    }
}

void solve(){
    ll n; cin >> n;
    auto sub_solve = [&](int s){
        ll sum = 0;
        int ans = 0;
        for(int i = 1; i <= 14; i++){
            if(s&(1<<i)){
                sum += facs[i];
                ans++;
            }
        }
        if(sum > n) return 100000;
        ll rem = n-sum;
        while(rem){
            if(rem&1) ans++;
            rem /= 2;
        }
        return ans;
    };
    int ans = 100000;
    for(int s = 0; s < (1<<15); s++){
        if(s&1) continue;
        chmin(ans, sub_solve(s));
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    init();
    int t; cin >> t;
    while(t--) solve();
}