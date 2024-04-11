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
    vector<int> a(n);
    vector<vector<int>> indices(n+1);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        indices[a[i]].push_back(i);
    }
    vector<int> nx(n, n);
    for(int i = n-2; i >= 0; i--){
        nx[i] = nx[i+1];
        auto p = upper_bound(indices[a[i]].begin(), indices[a[i]].end(), i);
        if(p != indices[a[i]].end()){
            chmin(nx[i], *p);
        }
    }
    auto ok = [&](int l, int r){
        // cout << l << ',' << r << endl;
        return nx[l] >= r;
    };
    // print_vector(nx);
    set<int> remaining;
    for(int i = -1; i <= n; i++) remaining.insert(i);
    int ans = 0;
    for(int x = 1; x <= n; x++){
        for(int i: indices[x]){
            auto p = remaining.find(i);
            int l = *prev(p);
            l++;
            int r = *next(p);
            // [l, i), [i+1, r)
            int l_len = i-l, r_len = r-(i+1);
            if(l_len < r_len){
                for(int li = l; li <= i; li++){
                    int ri = li+x;
                    // debug_value(ri);
                    if(i <= ri && ri <= r && ok(li, ri)) ans++;
                }
            }else{
                for(int ri = i+1; ri <= r; ri++){
                    int li = ri-x;
                    if(l <= li && li <= i && ok(li, ri)) ans++;
                }
            }
        }
        for(int i: indices[x]){
            remaining.erase(i);   
        }
    }
    cout << ans << endl;
}