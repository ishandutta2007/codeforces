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

template<typename T>
class Cumsum{
    public:
    Cumsum(vector<T> v): v(v){
        n = v.size();
        v_cumsum = vector<T>(n+1, T(0));
        for(int i = 0; i < n; i++) v_cumsum[i+1] = v_cumsum[i]+v[i];
    }
    /**
     * v[l] + ... + v[r-1]
     */ 
    T sum(int l, int r){
        if(r <= l) return T(0);
        if(r > n) r = n;
        if(l < 0) l = 0;
        return v_cumsum[r]-v_cumsum[l];
    }
    private:
    int n;
    vector<T> v;
    vector<T> v_cumsum;
};

void solve(){
    int n; cin >> n;
    vector<int> u(n), s(n);
    for(int i = 0; i < n; i++) {
        cin >> u[i];
        u[i]--;
    }
    for(int i = 0; i < n; i++) cin >> s[i];
    vector<vector<ll>> v(n);
    for(int i = 0; i < n; i++){
        v[u[i]].push_back(s[i]);
    }
    vector<Cumsum<ll>> cumsum;
    for(int i = 0; i < n; i++) {
        sort(v[i].begin(), v[i].end(), greater<ll>());
        cumsum.push_back(Cumsum<ll>(v[i]));
    }
    vector<int> p;
    vector<int> q;
    for(int i = 0; i < n; i++) p.push_back(i);
    for(int k = 1; k <= n; k++){
        for(int i: p){
            if(v[i].size() >= k) q.push_back(i);
        }
        ll ans = 0;
        for(int i: q){
            int sz = v[i].size();
            int x = (sz/k)*k;
            ans += cumsum[i].sum(0, x);
        }
        p = q;
        q.clear();
        cout << ans << ' ';
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