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
    vector<int> b(n);
    vector<bool> is_b(2*n);
    for(int i = 0; i < n; i++) {
        cin >> b[i]; b[i]--;
        is_b[b[i]] = true;
    }
    vector<int> a;
    for(int i = 0; i < 2*n; i++){
        if(!is_b[i]) a.push_back(i);
    }
    auto ok_left = [&](int x){
        for(int i = 0; i < x; i++){
            int j = n-(x-1)+i-1;
            if(a[j] < b[i]) return false;
        }
        return true;
    };
    auto calc_max_left = [&](){
        if(ok_left(n)) return n;
        int l = 0, r = n;
        while(r-l > 1){
            int x = (l+r)/2;
            if(ok_left(x)) l = x;
            else r = x;
        }
        return l;
    };
    auto ok_right = [&](int x){
        for(int i = 0; i < x; i++){
            int j = n-(x-1)+i-1;
            if(b[j] < a[i]) return false;
        }
        return true;
    };
    auto calc_max_right = [&](){
        if(ok_right(n)) return n;
        int l = 0, r = n;
        while(r-l > 1){
            int x = (l+r)/2;
            if(ok_right(x)) l = x;
            else r = x;
        }
        return l;
    };
    int l = calc_max_left(), r = calc_max_right();
    cout << l+r-(n-1) << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}