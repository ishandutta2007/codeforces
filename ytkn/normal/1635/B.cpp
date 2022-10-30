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
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> idx;
    for(int i = 1; i+1 < n; i++){
        if(a[i] > a[i-1] && a[i] > a[i+1]){
            idx.push_back(i);
        }
    }
    int m = idx.size();
    int i = 0;
    int ans = 0;
    while(i+1 < m){
        int i1 = idx[i], i2 = idx[i+1];
        if(i1+2 == i2){
            a[i1+1] = max(a[i1], a[i2]);
            ans++;
            i += 2;
        }else{
            i++;
        }
    }
     for(int i = 1; i+1 < n; i++){
        if(a[i] > a[i-1] && a[i] > a[i+1]){
            ans++;
            a[i] = max(a[i-1], a[i+1]);
        }
    }

    cout << ans << endl;
    print_vector(a);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}