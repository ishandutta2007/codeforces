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

void dfs(vector<ll> a, vector<ll> &ans){
    ll sum = accumulate(a.begin(), a.end(), 0ll);
    ans.push_back(sum);
    ll a_max = *max_element(a.begin(), a.end());
    ll a_min = *min_element(a.begin(), a.end());
    ll mid = (a_max+a_min)/2;
    vector<ll> al, ar;
    for(ll x: a){
        if(x <= mid) al.push_back(x);
        else ar.push_back(x);
    }
    if(!al.empty() && !ar.empty()) {
        dfs(al, ans);
        dfs(ar, ans);
    }
}

void solve(){
    int n, q; cin >> n >> q;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<ll> sums;
    dfs(a, sums);
    set<ll> st;
    for(ll x: sums) st.insert(x);
    while(q--){
        ll s; cin >> s;
        if(st.count(s)){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    } 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}