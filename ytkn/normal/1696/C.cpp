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

using P = pair<ll, ll>;

vector<P> normalize(vector<ll> v, ll m){
    vector<P> ans;
    auto add = [&](ll x, ll cnt){
        if(ans.empty()){
            ans.push_back(P(x, cnt));
            return;
        }
        if(ans.back().first == x){
            ans.back().second += cnt;
        }else{
            ans.push_back(P(x, cnt));
        }
    };
    for(ll x: v){
        ll cnt = 1;
        while(x%m == 0){
            x /= m;
            cnt *= m;
        }
        add(x, cnt);
    }
    return ans;
}

void solve(){
    int n; ll m; cin >> n >> m;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int k; cin >> k;
    vector<ll> b(k);
    for(int i = 0; i < k; i++) cin >> b[i];
    auto na = normalize(a, m), nb = normalize(b, m);
    if(na == nb){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}