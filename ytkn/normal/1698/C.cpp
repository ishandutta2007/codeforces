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
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<ll> pos, neg;
    int cnt0 = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > 0){
            pos.push_back(a[i]);
        }else if(a[i] < 0){
            neg.push_back(a[i]);
        }else{
            cnt0++;
        }
    }
    if(pos.size() >= 3){
        cout << "NO" << endl;
        return;
    }
    if(neg.size() >= 3){
        cout << "NO" << endl;
        return;
    }
    vector<ll> v = pos;
    for(ll x: neg) v.push_back(x);
    if(cnt0) v.push_back(0);
    auto ok = [&](ll x){
        for(ll y: v){
            if(y == x) return true;
        }
        return false;
    };
    int m = v.size();
    for(int s = 0; s < (1<<m); s++){
        int cnt = 0;
        ll sum = 0;
        for(int i = 0; i < m; i++){
            if(s&(1<<i)){
                sum+=v[i];
                cnt++;
            }
        }
        if(cnt == 3){
            if(!ok(sum)){
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}