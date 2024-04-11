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

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = abs(a[i]);
    }
    for(int i = 0; i < n; i++){
        if(a[i] == 0){
            cout << "Yes" << endl;
            return;
        }
    }
    int mask = (1<<n)-1;
    vector<int> sum(1<<n);
    for(int s = 0; s < (1<<n); s++){
        for(int i = 0; i < n; i++){
            if(s&(1<<i)) sum[s] += a[i];
        }
    }
    for(int s = 1; s < (1<<n); s++){
        int rem = mask-s;
        for(int t = rem; t > 0; t = (t-1)&rem){
            if(sum[s] == sum[t]){
                cout << "Yes" << endl;
                return;
            }
        }
    }
    cout << "No" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}