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
#include <bitset>

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

ll tri(ll x){
    return(x*(x+1))/2;
}

void solve(){
    ll a, b, m; cin >> a >> b >> m;
    if(a == b){
        cout << 1 << ' ' << a << endl;
        return;
    }
    for(int k = 2; k <= 50; k++){
        ll x = 1ll<<(k-2);
        if(a*x > b) {
            break;
        }
        ll d = b-a*x;
        if(x <= d && d <= m*x){
            cout << k << ' ' << a << ' ';
            vector<ll> r(k-1, m);
            ll sum = m*x;
            for(int i = 0; i < k-1; i++){
                ll cnt = i == k-2 ? 1ll : x>>(i+1);
                if(sum-d >= cnt){
                    ll y = min(m-1, (sum-d)/cnt);
                    sum -= cnt*y;
                    r[i] -= y;
                }
            }
            for(int i = 1; i < k; i++){
                ll ans = (1ll<<(i-1))*a+r[i-1];
                ll cnt = 1;
                for(int j = i-2; j >= 0; j--){
                    ans += r[j]*cnt;
                    cnt <<= 1;
                }
                cout << ans << ' ';
            }
            cout << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}