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
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    if(n <= 3){
        cout << 1 << endl;
        return 0;
    }
    auto b = a;
    sort(b.begin(), b.end());
    auto sub_solve = [&](ll l, ll r){
        if((r-l)%(n-2) != 0) return -1;
        ll d = (r-l)/(n-2);
        if(l == r){
            int cnt = 0;
            int ans = -1;
            for(int i = 0; i < n; i++){
                if(a[i] == l) cnt++;
                else ans = i;
            }
            if(cnt == n) return 0;
            if(cnt == n-1) return ans;
            return -1;
        }
        vector<bool> ok(n-1);
        int ans = -1;
        for(int i = 0; i < n; i++){
            if((a[i]-l)%d == 0){
                int idx = (a[i]-l)/d;
                if(0 <= idx && idx <= n-2 && !ok[idx]) ok[idx] = true;
                else ans = i;
            }else{
                ans = i;
            }
        }
        for(int i = 0; i < n-1; i++){
            if(!ok[i]) return -1;
        }
        return ans;
    };
    if(sub_solve(b[0], b[n-1]) != -1){
        cout << sub_solve(b[0], b[n-1])+1 << endl;
        return 0;
    }
    if(sub_solve(b[1], b[n-1]) != -1){
        cout << sub_solve(b[1], b[n-1])+1 << endl;
        return 0;
    }
    if(sub_solve(b[0], b[n-2]) != -1){
        cout << sub_solve(b[0], b[n-2])+1 << endl;
        return 0;
    }
    cout << -1 << endl;
}