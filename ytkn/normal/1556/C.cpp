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
    for(int i = 0; i+1 < v.size(); i++) cout << v[i] << delimiter;
    cout << v.back() << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<ll> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];
    ll ans = 0;
    for(int l = 0; l < n; l+=2){
        ll sum = 0;
        ll mn = 0;
        for(int r = l+1; r < n; r+=2){
            ll l1 = 1, r1 = c[l];
            ll l2 = 1, r2 = c[r];
            chmax(l1, -mn);
            chmax(l2, sum+l1);
            ll tmp = min(r1-l1+1, r2-l2+1);
            ans += max(0ll, tmp);
            if(r+2 < n){
                sum -= c[r];
                chmin(mn, sum);
                sum += c[r+1];
            }
        }
    }
    cout << ans << endl;
}