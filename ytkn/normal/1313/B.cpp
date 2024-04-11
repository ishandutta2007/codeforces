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

int count_le(int n, int x, int y){
    auto ok = [&](int a){

    };
}

int count_greater(int n, int x, int y){

}

void solve(){
    int n, x, y; cin >> n >> x >> y;
    if(x > y) swap(x, y);
    int lx = x-1, rx = n-x;
    int ly = y-1, ry = n-y;
    int r_max = 0;
    if(rx > 0 && ry > 0) r_max = 1;
    r_max += max(min(rx-1, ly), 0)+max(min(ry-1, lx), 0);
    r_max += min(max(0, rx-1-ly), max(0, ry-1-lx));
    int l_max = min(rx, ly)+min(ry, lx);
    l_max += min(max(0, ly-rx), max(0, lx-ry));
    cout << n-r_max << ' ' << l_max+1 << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}