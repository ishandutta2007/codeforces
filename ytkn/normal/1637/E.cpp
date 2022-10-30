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
class Compress{
    public:
    vector<T> data;
    int offset;
    Compress(vector<T> data_, int offset=0): offset(offset){
        set<T> st;
        for(T x: data_) st.insert(x);
        for(T x: st) data.push_back(x);
    };
    int operator[](T x) {
        auto p = lower_bound(data.begin(), data.end(), x);
        assert(x == *p);
        return offset+(p-data.begin());
	}
    T inv(int x){
        return data[x-offset];
    }
    int size(){
        return data.size();
    }
};

using P = pair<ll, ll>;

void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n);
    map<int, int> cnt;
    set<int> st;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(cnt.count(a[i])) cnt[a[i]]++;
        else cnt[a[i]] = 1;
        st.insert(a[i]);
    }
    auto cpa = Compress<int>(a);
    int nn = cpa.size();
    vector<int> v;
    for(auto [x, c]: cnt) {
        v.push_back(c);
    }
    auto cp = Compress<int>(v);
    int sz = cp.size();
    vector<vector<int>> inv(sz);
    for(int x: cpa.data){
        int i = cp[cnt[x]];
        inv[i].push_back(x);
    }
   
    vector<vector<int>> bad(nn);
    for(int i = 0; i < m; i++){
        int x, y;  cin >> x >> y;
        if(st.count(x) == 0) continue;
        if(st.count(y) == 0) continue;
        int xi = cpa[x];
        int yi = cpa[y];
        bad[xi].push_back(y);
        bad[yi].push_back(x);
    }
    for(int i = 0; i < sz; i++) {
        sort(inv[i].begin(), inv[i].end(), greater<int>());
    }
    
    ll ans = 0;
    for(int i = 0; i < nn; i++) {
        ll x = cpa.data[i];
        sort(bad[i].begin(), bad[i].end());
        // print_vector(bad[i]);
        ll cx = cnt[x];
        ll ci = cp[cx];
        // cout << x << ' ' << ci << endl;
        for(int j = 0; j <= ci; j++){
            ll cy = cp.data[j];
            for(ll y: inv[j]){
                if(y == x) continue;
                auto p = lower_bound(bad[i].begin(), bad[i].end(), y);
                if(p != bad[i].end() && *p == y) continue;
                chmax(ans, (cx+cy)*(x+y));
                break;
            }
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