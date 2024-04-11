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
    int n, p; cin >> n >> p;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<int> cnt(n+1, 0);
    vector<bool> ng(n);
    auto set_ng = [&](int l, int r){
        chmin(r, n);
        chmax(l, 0);
        if(l >= r) return;
        cnt[l]++;
        cnt[r]--;
    };
   
    for(int i = 0; i < n; i++){
        auto calc = [&](int x){
            assert(x <= i+1);
            assert(x >= 0);
            return a[n-1]-a[i]+i+1-x;
        };
        int s = calc(i+1);
        int t = calc(0);
        if((i+1)%p == 0){
            set_ng(0, s+1);
        }
        int x = ((i+1)/p)*p;
        int k = calc(x);
        if(0 <= k && k < n) ng[k] = true;
        set_ng(t, n);
    }
    for(int i = 0; i < n; i++){
        if(ng[i] && i+p < n) ng[i+p] = true;
    }
    for(int i = 0; i < n; i++) cnt[i+1] += cnt[i];
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(cnt[i] == 0 && !ng[i]) ans++;
    }
    cout << ans << endl;
    for(int k = n-1; k >= 0; k--){
        if(cnt[k] == 0 && !ng[k]) cout << a[n-1]-k << ' ';
    }
    cout << endl;
}