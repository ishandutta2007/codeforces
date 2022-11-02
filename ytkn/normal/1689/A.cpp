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
    int n, m, k; cin >> n >> m >> k;
    string a, b; cin >> a >> b;
    string ans;
    vector<bool> used_a(n), used_b(m);
    int cont_a = 0, cont_b = 0;
    int cnt_a = 0, cnt_b = 0;
    auto find_from_a = [&](char c){
        for(int i = 0; i < n; i++){
            if(used_a[i]) continue;
            if(a[i] == c) return i;
        }
        return -1;
    };
    auto find_from_b = [&](char c){
        for(int i = 0; i < m; i++){
            if(used_b[i]) continue;
            if(b[i] == c) return i;
        }
        return -1;
    };
    while(cnt_a != n && cnt_b != m){
        char mn = 'z';
        if(cont_a == k){
            for(int i = 0; i < m; i++){
                if(used_b[i]) continue;
                chmin(mn, b[i]);
            }
        }else if(cont_b == k){
            for(int i = 0; i < n; i++){
                if(used_a[i]) continue;
                chmin(mn, a[i]);
            }
        }else{
            for(int i = 0; i < m; i++){
                if(used_b[i]) continue;
                chmin(mn, b[i]);
            }
            for(int i = 0; i < n; i++){
                if(used_a[i]) continue;
                chmin(mn, a[i]);
            }
        }
        int i = find_from_a(mn);
        ans += mn;
        if(i != -1){
            used_a[i] = true;
            cnt_a++;
            cont_a++;
            cont_b = 0;
        }else{
            i = find_from_b(mn);
            assert(i != -1);
            used_b[i] = true;
            cnt_b++;
            cont_b++;
            cont_a = 0;
        }
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}