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
    int n, k; cin >> n >> k;
    vector<int> p(2*n, -1);
    for(int i = 0; i < k; i++){
        int x, y; cin >> x >> y; x--; y--;
        p[x] = y;
        p[y] = x;
    }
    vector<int> v;
    for(int i = 0; i < 2*n; i++){
        if(p[i] == -1) v.push_back(i);
    }
    for(int i = 0; i < n-k; i++){
        p[v[i]] = v[i+n-k];
        p[v[i+n-k]] = v[i];
    }
    // print_vector(p);
    int ans = 0;
    for(int i = 0; i < 2*n; i++){
        if(i > p[i]) continue;
        for(int j = i+1; j < 2*n; j++){
            if(j > p[j]) continue;
            if(p[i] > j && p[i] < p[j]) ans++;
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