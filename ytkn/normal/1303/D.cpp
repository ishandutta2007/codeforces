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
    ll n; int m; cin >> n >> m;
    vector<ll> a(m);
    for(int i = 0; i < m; i++) cin >> a[i];
    ll a_sum = accumulate(a.begin(), a.end(), 0ll);
    if(a_sum < n){
        cout << -1 << endl;
        return;
    }
    vector<int> cnt(60);
    for(int i = 0; i < m; i++){
        for(int j = 59; j >= 0; j--){
            if(a[i]&(1ll<<j)) {
                cnt[j]++;
                break;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < 60; i++){
        if(n&(1ll<<i)){
            if(cnt[i] == 0){
                int x = 0;
                for(int j = i; j < 60; j++){
                    if(cnt[j] > 0){
                        x = j;
                        break;
                    }
                }
                ans += x-i;
                cnt[x]--;
                for(int j = i; j < x; j++){
                    cnt[j]++;
                }
            }
            cnt[i]--;
        }
        if(i+1 != 60){
            cnt[i+1] += cnt[i]/2;
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