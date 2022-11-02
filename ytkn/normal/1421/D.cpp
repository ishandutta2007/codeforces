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

vector<ll> dx = {1, 0, -1, -1, 0, 1};
vector<ll> dy = {1, 1, 0, -1, -1, 0};
const ll inf = 4e18;

void solve(){
    ll x, y; cin >> x >> y;
    vector<ll> c(6);
    for(int i = 0; i < 6; i++) cin >> c[i];
    ll ans = inf;
    for(int i = 0; i < 6; i++){
        for(int j = i+1; j < 6; j++){
            if(j == i+3) continue;
            // dx[i]*a+dx[j]*b = x
            // dy[i]*a+dy[j]*b = y
            ll det = dx[i]*dy[j]-dx[j]*dy[i];
            ll a = (x*dy[j]-y*dx[j])/det;
            ll b = (dx[i]*y-dy[i]*x)/det;
            if(a < 0 || b < 0) continue;
            assert(dx[i]*a+dx[j]*b == x);
            assert(dy[i]*a+dy[j]*b == y);
            chmin(ans, c[i]*a+c[j]*b);
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