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

int sub_solve(int k, vector<int> a){
    if(a.size() == (1<<k)) return 0;
    if(a.empty()) return 0;
    vector<int> vl, vr;
    int x = 1<<(k-1);
    for(int p: a){
        if(p >= x) vr.push_back(p^x);
        else vl.push_back(p);
    }
    int ans = 0;
    if(vl.empty()){
        ans += x;
        ans += sub_solve(k-1, vr);
    }else if(vr.empty()){
        ans += sub_solve(k-1, vl);
    }else if(vr.size() == x){
        ans = x;
        ans += sub_solve(k-1, vl);
    }else{
        ans += sub_solve(k-1, vr);
    }
    return ans;
}

int msb(int x){
    for(int i = 17; i >= 0; i--){
        if(x&(1<<i)) return i;
    }
}

void solve(){
    int l, r; cin >> l >> r;
    int n = r-l+1;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << sub_solve(17, a) << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}