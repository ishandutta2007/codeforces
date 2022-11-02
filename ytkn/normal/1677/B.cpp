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
    int n, m; cin >> n >> m;
    swap(n, m);
    string s; cin >> s;
    int ans = 0;
    int prev_idx = -1;
    vector<bool> ok(n);
    vector<int> del(n), add(n);
    int same = 0;
    int cnt = 0;
    for(int i = 0; i < n*m; i++){
        same -= del[i%n];
        same += add[i%n];
        if(s[i] == '1'){
            if(ok[i%n]){
                same++;
            }
            cnt++;
            if(prev_idx != -1 && prev_idx+n-1 >= i){
                same++;
                add[i%n]++;
                int pi = prev_idx%n;
                del[pi]++;
            }
            ok[i%n] = true;
            prev_idx = i;
        }
        // cout << cnt << ' ' << same << endl;
        cout << cnt*2-same << ' ';
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}