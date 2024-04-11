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
    string s; cin >> s;
    int cnt = 0;
    for(char c: s){
        if(c == '1') cnt++;
    }
    if(cnt == 0 || cnt%2 == 1){
        cout << "NO" << endl;
        return;
    }
    vector<int> vs;
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            vs.push_back(i);
        }
    }
    cout << "YES" << endl;
    vector<int> us;
    for(int v: vs){
        for(int i = v; ; i = (i+1)%n){
            int j = (i+1)%n;
            if(s[j] == '1') {
                us.push_back(i);
                break;
            }
            cout << i+1 << ' ' << j+1 << endl;
        }
    }
    int m = us.size();
    for(int i = 1; i < m; i++){
        cout << us[0]+1 << ' ' << us[i]+1 << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}