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
    vector<vector<int>> indices(n+1);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        indices[a[i]].push_back(i);
    }
    set<int> st = {-1, n};
    vector<int> imos(n+2);
    auto set_ng = [&](int l, int r){
        imos[l]++;
        imos[r+1]--;
    };
    for(int i = 1; i <= n; i++){
        int max_len = 0;
        for(int j: indices[i]){
            auto p = st.lower_bound(j);
            int r = *p;
            int l = *prev(p);
            chmax(max_len, r-l-1);
        }
        for(int j: indices[i]) st.insert(j);
        if(max_len < n-i+1){
            set_ng(max_len+1, n-i+1);
        }
        if(max_len > n-i+1){
            set_ng(n-i+1, max_len);
        }
    }
    string ans;
    for(int i = 1; i <= n; i++){
        imos[i] += imos[i-1];
        if(imos[i] > 0) ans += '0';
        else ans += '1'; 
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}