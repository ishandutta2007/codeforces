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
    vector<ll> a(n), b(n), c(n);
    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i]; a[i]--;
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i]; b[i]--;
    }
    for(int i = 0; i < n; i++){
        if(a[i] > b[i]) swap(a[i], b[i]);
    }
    ll sum = 0;
    ll ans = 0;
    for(int i = 1; i < n; i++){
        if(a[i] == b[i]) sum = 2;
        else{
            if(i == 1) sum = b[i]-a[i]+2;
            else sum += a[i]+c[i-1]-1-b[i]+2;
        }
        chmax(sum, b[i]-a[i]+2);
        chmax(ans, sum+c[i]-1);
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}