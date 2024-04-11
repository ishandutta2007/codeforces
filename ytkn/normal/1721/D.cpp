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
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    vector<int> u(n), v(n);
    iota(u.begin(), u.end(), 0);
    iota(v.begin(), v.end(), 0);
    vector<vector<int>> uu = {u};
    vector<vector<int>> vv = {v};
    int ans = 0;
    for(int j = 29; j >= 0; j--){
        int m = uu.size();
        int x = 1<<j;
        bool ok = true;
        vector<vector<int>> uunx, vvnx;
        int sum = 0;
        for(int idx = 0; idx < m; idx++){
            sum += uu[idx].size();
            assert(uu[idx].size() == vv[idx].size());
            vector<int> v0, v1, u0, u1;
            for(int i: vv[idx]){
                if(x&a[i]) v1.push_back(i);
                else v0.push_back(i);
            }
            for(int i: uu[idx]){
                if(x&b[i]) u1.push_back(i);
                else u0.push_back(i);
            }
            if(v0.size() == u1.size()){
                if(v0.size() > 0){
                    vvnx.push_back(v0);
                    uunx.push_back(u1);
                }

                if(v1.size() > 0){
                    vvnx.push_back(v1);
                    uunx.push_back(u0);
                }
            }else{
                ok = false;
                break;
            }
        }
        if(ok){
            assert(sum == n);
            uu = uunx;
            vv = vvnx;
            ans += x;
        }
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}