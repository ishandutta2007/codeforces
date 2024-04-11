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
    for(int i = 0; i+1 < v.size(); i++) cout << v[i] << delimiter;
    cout << v.back() << endl;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    vector<int> cnt(2);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= 2;
        cnt[a[i]]++;
    }
    if(abs(cnt[0]-cnt[1]) > 1){
        cout << -1 << endl;
        return;
    }
    auto count = [&](vector<int> target){
        vector<int> u, v;
        for(int i = 0; i < n; i++){
            if(a[i] == 0) u.push_back(i);
            if(target[i] == 0) v.push_back(i);
        }
        ll ans = 0;
        int m = u.size();
        for(int i = 0; i < m; i++){
            ans += abs(u[i]-v[i]);
        }
        return ans;
    };
    ll ans = -1;
    vector<int> target(n);
    if(n%2 == 0){
        for(int i = 0; i < n; i++){
            target[i] = i%2;
        }
        ans = count(target);
        for(int i = 0; i < n; i++){
            target[i] = (i+1)%2;
        }
        chmin(ans, count(target));
    }else{
        for(int i = 0; i < n; i++){
            if(cnt[0] > cnt[1]){
                target[i] = i%2;
            }else{
                target[i] = (i+1)%2;
            }
        }
        ans = count(target);
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