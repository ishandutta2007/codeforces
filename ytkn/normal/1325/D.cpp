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

using P = pair<ll, ll>;
P none(-1, -1);

P calc(ll u, ll v){
    if(v < 0) return none;
    assert(u <= v);
    if(u == v){
        return P(u, 0);
    }
    int s = u%2, t = v%2;
    if(s != t){
        return none;
    }
    if(s == 1){
        auto [a, b] = calc(u/2, v/2);
        if(a == -1) return none;
        return P(a*2+1, b*2);
    }else{
        auto p = calc(u/2, v/2);
        if(p != none){
            auto [a, b] = p;
            return P(a*2, b*2);
        }
        p = calc(u/2, v/2-1);
        if(p != none){
            auto [a, b] = p;
            return P(a*2+1, b*2+1);
        }
        return none;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    ll u, v; cin >> u >> v;
    if(u > v){
        cout << -1 << endl;
        return 0;
    }
    if(u == 0 && v == 0){
        cout << 0 << endl;
        return 0;
    }
    if(u%2 != v%2){
        cout << -1 << endl;
        return 0;
    }
    if(u == v){
        cout << 1 << endl;
        cout << u << endl;
        return 0;
    }
    auto p = calc(u, v);
    if(p == none){
        cout << 3 << endl;
        cout << u << ' ' << (v-u)/2 << ' ' << (v-u)/2 << endl;
    }else{
        auto [a, b] = p;
        cout << 2 << endl;
        cout << a << ' ' << b << endl;
    }

}