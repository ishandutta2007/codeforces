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
    sort(a.begin(), a.end());
    auto ok = [&](int k){
        vector<bool> del(n);
        for(int i = 0; i < k; i++){
            bool find = false;
            for(int j = n-1; j >= 0; j--){
                if(!del[j] && a[j] <= k-i){
                    del[j] = true;
                    find = true;
                    break;
                }
            }
            if(!find) return false;
            for(int j = 0; j < n; j++){
                if(!del[j]){
                    del[j] = true;
                    break;
                }
            }
        }
        return true;
    };
    if(!ok(0)){
        cout << 0 << endl;
        return;
    }
    if(ok(n)){
        cout << n << endl;
        return;
    }
    int l = 0, r = n;
    while(r-l > 1){
        int k = (l+r)/2;
        if(ok(k)) l = k;
        else r = k;
    }
    cout << l << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}