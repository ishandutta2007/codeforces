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
    int n; ll x, y; cin >> n >> x >> y;
    string a, b; cin >> a >> b;
    bool ok = true;
    vector<int> v;
    for(int i = 0; i < n; i++){
        if(a[i] != b[i]) {
            ok = !ok;
            v.push_back(i);
        }
    }
    if(!ok){
        cout << -1 << endl;
        return;
    }
    if(v.size() == 2){
        if(v[0]+1 != v[1]){
            cout << y << endl;
            return;
        }
        for(int i = 0; i < n; i++){
            if(i == v[0] || i == v[1]) continue;
            int mn = min(abs(i-v[0]), abs(i-v[1]));
            if(mn > 1){
                cout << min(2*y, x) << endl;
                return;
            }
        }
        cout << x << endl;
    }else{
        cout << y*v.size()/2 << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}