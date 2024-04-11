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

const int N = 400000;
vector<int> divs[N];

void init(){
    for(int x = 1; x <= N; x++){
        for(int i = 0; i*x <= N; i++){
            divs[x*i].push_back(x);
        }
    }
}

ll tri(ll x){
    return (x*(x-1))/2;
}

void solve(){
    ll l, r; cin >> l >> r;
    ll cnt = r-l+1;
    ll ans = (cnt*(cnt-1)*(cnt-2))/6;
    for(int k = l+2; k <= r; k++){
        ll neg = 0;
        auto count = [&](int x, int l, int r){
            if(l >= r) return 0ll;
            auto pr = lower_bound(divs[x].begin(), divs[x].end(), r);
            auto pl = lower_bound(divs[x].begin(), divs[x].end(), l);
            return (ll)(pr-pl);
        };
        for(int i: divs[2*k]){
            if(i >= k) break;
            if(i < l) continue;
            neg += count(2*k, i+1, k);
            neg -= count(2*k, i+1, k-i+1);
        }
        for(int i: divs[k]){
            if(i >= k) break;
            if(i < l) continue;
            neg += count(k, i+1, k-i+1);
        }
        ans -= neg;
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