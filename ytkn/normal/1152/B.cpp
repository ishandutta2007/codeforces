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

int msb(ll n){
    for(int i = 60; i >= 0; i--){
        if(n&(1ll<<i)) return i;
    }
}

void solve(){
    ll n; cin >> n;
    vector<int> v;
    auto ok = [&](ll n){
        int m = msb(n);
        return n == (1ll<<(m+1))-1;
    };
    for(int i = 0;!ok(n); i++){
        if(i%2 == 0){
            int m = msb(n);
            for(int j = m; j >= 0; j--){
                if(n&(1ll<<j)) continue;
                v.push_back(j+1);
                n ^= (1ll<<(j+1))-1;
                break;
            }
        }else{
            v.push_back(-1);
            n++;
        }
    }
    cout << v.size() << endl;
    for(int x: v){
        if(x == -1) continue;
        cout << x << ' ';
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    solve();
}