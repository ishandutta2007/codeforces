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

using P = pair<int, int>;
using T = tuple<ll, int, int>;
const ll inf = 1e18;

vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

void solve(){
    int n; cin >> n;
    auto c = vec2d(2*n, 2*n, 0ll);
    for(int i = 0; i < 2*n; i++){
        for(int j = 0; j < 2*n; j++){
            cin >> c[i][j];
        }
    }
   
    priority_queue<T, vector<T>, greater<T>> que;
    auto dist = vec2d(2*n, 2*n, inf);
    auto set_dist = [&](int i, int j, ll d){
        if(chmin(dist[i][j], d)){
            que.push(T(d, i, j));
        }
    };
    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ans += c[i][j];
            c[i][j] = 0;
            set_dist(i, j, 0);
        }
    }
    for(int i = n; i < 2*n; i++){
        for(int j = n; j < 2*n; j++){
            ans += c[i][j];
            c[i][j] = 0;
        }
    }
    ll mn = inf;
    for(int i: {0, n-1}){
        for(int j: {n, 2*n-1}){
            chmin(mn, c[i][j]);
            chmin(mn, c[j][i]);
        }
    }
    // for(int i = 0; i < 2*n; i++) print_vector(dist[i]);
    cout << mn+ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}