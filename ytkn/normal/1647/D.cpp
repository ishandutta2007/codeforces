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

bool is_prime(int n){
    for(int i = 2; i*i <= n; i++){
        if(n%i == 0) return false;
    }
    return true;
}

void solve(){
    ll x, d; cin >> x >> d;
    if(x%(d*d) != 0){
        cout << "NO" << endl;
        return;
    }
    ll p = x;
    int cnt = 0;
    while(p%d == 0){
        p /= d;
        cnt++;
    }
    if(!is_prime(p)){
        cout << "YES" << endl;
        return;
    }
    if(cnt == 2){
        cout << "NO" << endl;
        return;
    }
    if(is_prime(d)){
        cout << "NO" << endl;
        return;
    }
    if(p == 1){
        cout << "YES" << endl;
        return;
    }
    ll q = d;
    int c = 0;
    while(q%p == 0){
        c++;
        q /= p;
    }
    if(q != 1){
        cout << "YES" << endl;
        return;
    }
    if(cnt == 3 && c == 2){
        cout << "NO" << endl;
        return;
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