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

bool is_decreasing(const vector<int> &v){
    int n = v.size();
    for(int i = 0; i < n-1; i++){
        if(v[i] <= v[i+1]) return false;
    }
    return true;
}

bool is_increasing(const vector<int> &v){
    int n = v.size();
    for(int i = 0; i < n-1; i++){
        if(v[i] >= v[i+1]) return false;
    }
    return true;
}

const int inf = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> dp_inc(n, -inf), pre_inc(n, -1);
    vector<int> dp_dec(n, inf), pre_dec(n, -1);
    dp_inc[0] = inf;
    dp_dec[0] = -inf;
    for(int i = 1; i < n; i++){
        // i-1, i
        if(dp_inc[i-1] != -inf && a[i-1] < a[i]){
            dp_inc[i] = dp_inc[i-1];
            pre_dec[i] = pre_dec[i-1];
        }
        // i-1, i
        if(dp_dec[i-1] < a[i] && chmax(dp_inc[i], a[i-1])){
            pre_dec[i] = i-1;
        }
        // i-1, i
        if(dp_dec[i-1] != inf && a[i-1] > a[i]){
            dp_dec[i] = dp_dec[i-1];
            pre_inc[i] = pre_inc[i-1];
        }
        // i-1, i
        if(dp_inc[i-1] > a[i] && chmin(dp_dec[i], a[i-1])){
            pre_inc[i] = i-1;
        }
    }
    if(dp_inc[n-1] != -inf){
        cout << "YES" << endl;
        vector<int> ans(n, 0);
        int idx = pre_dec[n-1];
        while(idx != -1){
            for(int i = pre_inc[idx]+1; i <= idx; i++) ans[i] = 1;
            idx = pre_inc[idx];
            if(idx == -1) break;
            idx = pre_dec[idx];
        }
        print_vector(ans);
        return 0;
    }
    if(dp_dec[n-1] != inf){
        cout << "YES" << endl;
        vector<int> ans(n, 1);
        int idx = pre_inc[n-1];
        while(idx != -1){
            for(int i = pre_dec[idx]+1; i <= idx; i++) ans[i] = 0;
            idx = pre_dec[idx];
            if(idx == -1) break;
            idx = pre_inc[idx];
        }
        print_vector(ans);
        return 0;
    }
    cout << "NO" << endl;
}