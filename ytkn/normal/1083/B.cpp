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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; ll k; cin >> n >> k;
    string s, t; cin >> s >> t;
    if(s == t){
        cout << n << endl;
        return 0;
    }
    if(k == 1){
        cout << n << endl;
        return 0;
    }
    int idx = -1;
    for(int i = 0; i < n; i++){
        if(s[i] != t[i]){
            idx = i;
            break;
        }
    }
    ll ans = (n-idx)*2 + idx;
    k -= 2;
    ll cnt = 0;
    ll x = 0;
    for(int i = idx+1; i < n; i++){
        cnt *= 2;
        if(s[i] == 'a'){
            cnt++;
        }
        if(t[i] == 'b'){
            cnt++;
        }
        ll used = min(cnt-x, k);
        x += used;
        ans += (n-i)*used;
        k -= used;
        if(k == 0) break;
    }
    cout << ans << endl;
}