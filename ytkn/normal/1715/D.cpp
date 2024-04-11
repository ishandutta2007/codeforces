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

vector<int> calc(vector<int> l, vector<int> r, vector<int> a, int n){
    int m = l.size();
    vector<int> ans(n, -1);
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++){
        if(l[i] == r[i]){
            ans[l[i]] = a[i];
            continue;
        }
        if(a[i] == 0){
            ans[l[i]] = 0;
            ans[r[i]] = 0;
        }else{
            g[l[i]].push_back(r[i]);
            g[r[i]].push_back(l[i]);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j: g[i]){
            if(ans[j] == 0){
                ans[i] = 1;
            }
        }
        if(ans[i] == -1) ans[i] = 0;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, q; cin >> n >> q;
    vector<int> l(q), r(q), x(q);
    for(int i = 0; i < q; i++){
        cin >> l[i] >> r[i] >> x[i]; l[i]--; r[i]--;
        if(l[i] > r[i]) swap(l[i], r[i]);
    }
    vector<int> ans(n);
    for(int i = 0; i < 30; i++){
        vector<int> a(q);
        int cur_bit = 1<<i;
        for(int j = 0; j < q; j++){
            if(x[j]&cur_bit) a[j] = 1;
        }
        auto b = calc(l, r, a, n);
        for(int j = 0; j < n; j++){
            if(b[j] == 1) ans[j] += cur_bit;
        }
    }
    print_vector(ans);
}