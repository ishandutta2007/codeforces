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
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<vector<ll>> v(2);
    ll sum = 0;
    for(int i = 0; i < n; i++){
        ll b; cin >> b;
        sum += b;
        v[a[i]].push_back(b);
    }
    sort(v[0].begin(), v[0].end(), greater<ll>());
    sort(v[1].begin(), v[1].end(), greater<ll>());
    vector<Cumsum<ll>> cumsum;
    for(int i = 0; i < 2; i++) cumsum.push_back(Cumsum<ll>(v[i]));
    ll ans = 0;
    for(int s = 0; s < 2; s++){
        vector<int> pos(2);
        int j = s;
        vector<int> u;
        for(int i = 0; i < n; i++){
            if(pos[j] >= v[j].size()){
                j ^= 1;
            }
            u.push_back(j);
            pos[j]++;
            j ^= 1;
        }
        vector<int> cnt(2);
        for(int i = 1; i < n; i++){
            if(u[i] != u[i-1]) cnt[u[i]]++;
        }
        ll tmp = sum + cumsum[0].sum(0, cnt[0]) + cumsum[1].sum(0, cnt[1]);
        chmax(ans, tmp);
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