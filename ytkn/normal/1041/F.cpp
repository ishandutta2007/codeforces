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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, y1; cin >> n >> y1;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int m, y2; cin >> m >> y2;
    vector<int> b(m);
    for(int i = 0; i < m; i++) cin >> b[i];
    int ans = 2;
    for(int i = 0; i < 30; i++){
        ll x = 1ll<<i;
        vector<map<ll, int>> cnt(2);
        for(int i = 0; i < n; i++){
            ll r = a[i]%x;
            ll p = (a[i]/x)%2;
            if(cnt[p].count(r) == 0) cnt[p][r] = 0;
            cnt[p][r]++;
        }
        for(int i = 0; i < m; i++){
            ll r = b[i]%x;
            ll p = ((b[i]/x)%2)^1;
            if(cnt[p].count(r) == 0) cnt[p][r] = 0;
            cnt[p][r]++;
        }
        for(int p = 0; p < 2; p++){
            for(auto [x, c]: cnt[p]) chmax(ans, c);
        }
    }
    cout << ans << endl;
}