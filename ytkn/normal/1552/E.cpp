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

// calc ceil(a/b) 
template<typename T>
T ceil_div(T a, T b){
    return (a+b-1)/b;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, k; cin >> n >> k;
    vector<int> c(n*k);
    for(int i = 0; i < n*k; i++) {
        cin >> c[i]; c[i]--;
    }
    int x = ceil_div(n, k-1);
    vector<bool> ok(n);
    auto all_ok = [&](){
        for(int i = 0; i < n; i++){
            if(!ok[i]) return false;
        }
        return true;
    };
    vector<int> a(n), b(n);
    int i = 0;
    while(!all_ok()){
        vector<int> cnt(n);
        int rem = x;
        for(; i < n*k; i++){
            if(ok[c[i]]) continue;
            cnt[c[i]]++;
            if(cnt[c[i]] == 1){
                a[c[i]] = i;
            }
            if(cnt[c[i]] == 2){
                ok[c[i]] = true;
                b[c[i]] = i;
                rem--;
            }
            if(rem == 0) break;
        }
    }
    for(int i = 0; i < n; i++){
        cout << a[i]+1 << ' ' << b[i]+1 << endl;
    }
}