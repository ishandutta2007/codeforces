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

const string target = "abacaba";

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    auto ok = [&](int i){
        auto t = s;
        for(int j = 0; j < 7; j++){
            if(t[i+j] == '?') {
                t[i+j] = target[j];
                continue;
            }
            if(t[i+j] != target[j]) return false;
        }
        for(int j = 0; j+7 <= n; j++){
            if(i == j) continue;
            if(t.substr(j, 7) == target) return false;
        }
        
        return true;
    };
    for(int i = 0; i < n; i++){
        if(ok(i)){
            for(int j = 0; j < n; j++){
                if(s[j] == '?') s[j] = 'z';
            }
            for(int j = 0; j < 7; j++){
                s[i+j] = target[j];
            }
            cout << "YES" << endl;
            cout << s << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}