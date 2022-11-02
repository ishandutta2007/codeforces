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
    int n, q; cin >> n >> q;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> prev_non_zero(n+1, -1);
    vector<int> next_non_zero(n+1, n);
    for(int i = 0; i < n; i++){
        if(a[i] != 0){
            prev_non_zero[i] = i;
        }else{
            if(i > 0) prev_non_zero[i] = prev_non_zero[i-1];
        }
    }
    for(int i = n-1; i >= 0; i--){
        if(a[i] != 0){
            next_non_zero[i] = i;
        }else{
            if(i+1 < n) next_non_zero[i] = next_non_zero[i+1];
        }
    }
    vector<ll> cumsum(n+1);
    vector<ll> cumxor(n+1);
    for(int i = 0; i < n; i++){
        cumsum[i+1] = cumsum[i]+a[i];
        cumxor[i+1] = cumxor[i]^a[i];
    }
    auto f = [&](int l, int r){
        return (cumsum[r]-cumsum[l]) - (cumxor[r]^cumxor[l]);
    };
    while(q--){
        int l, r; cin >> l >> r; l--;
        int l0 = l, r0 = r;
        ll mx = f(l, r);
        if(mx == 0){
            cout << l+1 << ' ' << l+1 << endl;
            continue;
        }
        vector<int> ls = {l}, rs = {r};
        int cur = next_non_zero[l];
        while(true){
            if(cur >= r) break;
            ls.push_back(cur);
            if(f(l, cur+1) == 0){
                cur = next_non_zero[cur+1];
            }else{
                break;
            }
        }
        cur = prev_non_zero[r-1];
        while(true){
            if(cur <= l) break;
            rs.push_back(cur+1);
            if(f(cur, r) == 0){
                cur = prev_non_zero[cur-1];
            }else{
                break;
            }
        }
        for(int l: ls){
            for(int r: rs){
                if(r <= l) continue;
                if(f(l, r) == mx && r-l < r0-l0){
                    l0 = l;   
                    r0 = r;   
                }
            }
        }

        cout << l0+1 << ' ' << r0 << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}