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

const int inf = (1e9)+5;

void solve(){
    int n, m; cin >> n >> m;
    auto a = vec2d(n, m, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    int ci = -1, cj = -1;
    for(int i = 0; i < n; i++){
        auto b = a[i];
        sort(b.begin(), b.end());
        if(a[i] == b) continue;
        for(int j = 0; j < m; j++){
            if(a[i][j] == b[j]) continue;
            if(ci == -1){
                ci = j;
            }else if(cj == -1){
                cj = j;
            }
        }
    }
    auto ok = [&](int ci, int cj){
        auto b = a;
        for(int i = 0; i < n; i++){
            swap(b[i][ci], b[i][cj]);
        }
        for(int i = 0; i < n; i++){
            for(int j = 1; j < m; j++){
                if(b[i][j-1] > b[i][j]) return false;
            }
        }
        return true;
    };
    if(ci == -1){
        ci = 0;
        cj = 0;
    }
    if(ok(ci, cj)){
        cout << ci+1 << ' ' << cj+1 << endl;
    }else{
        cout << -1 << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}