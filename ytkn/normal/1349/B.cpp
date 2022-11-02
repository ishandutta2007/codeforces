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
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    if(n == 1){
        if(a[0] == k) cout << "yes" << endl;
        else cout << "no" << endl;
        return;
    }
    int cnt_k = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == k){
            cnt_k++;
        }
    }
    auto med = [&](vector<int> v){
        sort(v.begin(), v.end());
        int n = v.size();
        return v[(n-1)/2];
    };
    if(cnt_k == 0) {
        cout << "no" << endl;
        return;
    }
    for(int i = 0; i < n-2; i++){
        if(med({a[i], a[i+1], a[i+2]}) >= k){
            cout << "yes" << endl;
            return;
        }
    }
    for(int i = 0; i < n-1; i++){
        if(med({a[i], a[i+1]}) == k){
            cout << "yes" << endl;
            return;
        }
    }
    
    for(int i = 0; i < n-1; i++){
        if(a[i] > k && a[i+1] > k){
            cout << "yes" << endl;
            return;
        }
    }
    cout << "no" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}