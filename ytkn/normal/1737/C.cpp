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
    vector<int> r(3), c(3);
    auto ok = vec2d(2, 2, false);
    for(int i = 0; i < 3; i++) {
        cin >> r[i] >> c[i]; r[i]--; c[i]--;
        ok[r[i]%2][c[i]%2] = true;
    }
    int x, y; cin >> x >> y; x--; y--;
    if(!ok[x%2][y%2]){
        cout << "NO" << endl;
        return;
    }
    for(int i = 0; i < 3; i++){
        int dx = min(r[i], n-1-r[i]);
        int dy = min(c[i], n-1-c[i]);
        if(dx > 0 || dy > 0) continue;
        bool corner = true;
        for(int j = 0; j < 3; j++){
            if(i == j) continue;
            if(abs(r[i]-r[j])+abs(c[i]-c[j]) > 1) corner = false;
        }
        if(corner){
            if(x == r[i] || y == c[i]){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
            return;
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