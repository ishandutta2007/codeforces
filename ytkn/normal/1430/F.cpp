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


// calc ceil(a/b) 
template<typename T>
T ceil_div(T a, T b){
    return (a+b-1)/b;
}

const ll inf = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    ll n, K; cin >> n >> K;
    vector<ll> l(n+1), r(n+1), a(n+1);
    for(int i = 1; i <= n; i++) cin >> l[i] >> r[i] >> a[i];
    auto dp_used = vec3d(2, n+1, 2, inf);
    auto dp_rem = vec3d(2, n+1, 2, 0ll);
    dp_used[0][0][0] = 0; 
    dp_rem[0][0][0] = K;
    auto required_reload = [&](ll init, ll x){
        if(x <= init) return 0ll;
        return ceil_div(x-init, K);
    };
    for(int i = 1; i <= n; i++){
        int cur = i%2;
        int pre = cur^1;
        for(int j = 0; j <= n; j++){
            for(int k = 0; k < 2; k++){
                dp_used[cur][j][k] = inf;
                dp_rem[cur][j][k] = 0;
            }
        }
        if(r[i-1] == l[i] && dp_used[pre][i-1][1] != inf){
            int reload = required_reload(dp_rem[pre][i-1][1], a[i]);
            if(reload <= r[i]-l[i]-1) {
                ll used = dp_used[pre][i-1][1] + a[i];
                ll rem = dp_rem[pre][i-1][1]+reload*K-a[i];
                chmin(dp_used[cur][i-1][1], used);
                dp_rem[cur][i-1][1] = rem;
                // reload
                if(reload == r[i]-l[i]-1){
                    chmin(dp_used[cur][i][1], used+rem);
                    dp_rem[cur][i][1] = K;
                }else{
                    chmin(dp_used[cur][i][0], used+rem);
                    dp_rem[cur][i][0] = K;

                    chmin(dp_used[cur][i][1], used+rem);
                    dp_rem[cur][i][1] = K;
                }
            }
        }

        for(int j = 0; j < i; j++){
            for(int k = 0; k < 2; k++){
                if(j == i-1 && k == 1 && r[i-1] == l[i]) continue;
                if(dp_used[pre][j][k] == inf) continue;
                int reload = required_reload(dp_rem[pre][j][k], a[i]);
                if(reload > r[i]-l[i]) continue;
                ll used = dp_used[pre][j][k] + a[i];
                ll rem = dp_rem[pre][j][k]+reload*K-a[i];
                chmin(dp_used[cur][j][k], used);
                dp_rem[cur][j][k] = rem;
                // reload
                if(reload == r[i]-l[i]){
                    chmin(dp_used[cur][i][1], used+rem);
                    dp_rem[cur][i][1] = K;
                }else{
                    chmin(dp_used[cur][i][0], used+rem);
                    dp_rem[cur][i][0] = K;

                    chmin(dp_used[cur][i][1], used+rem);
                    dp_rem[cur][i][1] = K;
                }
            }
        }
    } 
    ll ans = inf;
    for(int i = 0; i <= n; i++){
        for(int k = 0; k < 2; k++){
            chmin(ans, dp_used[n%2][i][k]);
        }
    }
    if(ans == inf){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
}