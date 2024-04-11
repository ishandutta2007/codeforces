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
    ll n, T, a, b; cin >> n >> T >> a >> b;
    vector<int> hard(n);
    for(int i = 0; i < n; i++) cin >> hard[i];
    int n_easy = 0, n_hard = 0;
    for(int i = 0; i < n; i++){
        if(hard[i]) n_hard++;
        else n_easy++;
    }
    vector<ll> t(n);
    for(int i = 0; i < n; i++) cin >> t[i];
    set<ll> asks;
    map<int, vector<int>> mandatory;
    for(int i = 0; i < n; i++){
        mandatory[t[i]].push_back(hard[i]);
        if(t[i] != 0) asks.insert(t[i]-1);
        asks.insert(t[i]);
    }
    asks.insert(T-1);
    asks.insert(T);
    ll ans = 0;
    ll cnt_easy = 0, cnt_hard = 0;
    for(ll t: asks){
        if(mandatory.count(t)) {
            for(int h: mandatory[t]){
                if(h == 1) cnt_hard++;
                else cnt_easy++;
            }
        }
        ll rem = t-(cnt_easy*a+cnt_hard*b);
        if(rem < 0) continue;
        ll rem_easy = n_easy-cnt_easy;
        ll rem_hard = n_hard-cnt_hard;
        if(rem_easy*a > rem){
            ll x = rem/a;
            chmax(ans, cnt_easy+cnt_hard+x);
        }else{
            ll rem = t-(n_easy*a+cnt_hard*b);
            ll x = rem/b;
            chmin(x, rem_hard);
            chmax(ans, n_easy+cnt_hard+x);
        }
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}