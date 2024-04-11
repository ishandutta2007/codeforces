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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i]; a[i]--;
    }
    vector<int> pos(n, -1);
    for(int i = 0; i < n; i++) {
        cin >> b[i]; b[i]--;
        if(b[i] != -1) pos[b[i]] = i;
    }
    if(pos[0] != -1){
        bool ok = true;
        for(int i = pos[0]; i < n; i++){
            int j = i-pos[0];
            if(b[i] != j) {
                ok = false;
            }
        }
        int m = n-1-pos[0];
        for(int x = m+1; x < n; x++){
            int put_iter = x-m-1;
            if(pos[x] >= put_iter) ok = false;
        }
        if(ok){
            cout << pos[0] << endl;
            return 0;
        }
    }
    auto ok = [&](int x)->bool{
        for(int i = 0; i < n; i++){
            int put_iter = i+(x-n);
            // cout << i << ' ' << put_iter << endl;
            if(pos[i] >= put_iter) return false;
        }
        return true;
    };
    if(ok(n)){
        cout << n << endl;
        return 0;
    }
    int l = n, r = 2*n;
    while(r-l > 1){
        int x = (l+r)/2;
        // cout << x << ' ' << ok(x) << endl;
        if(ok(x)) r = x;
        else l = x;
    }
    cout << r << endl;
}