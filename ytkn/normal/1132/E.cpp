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

const ll N = 840;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    ll w; cin >> w;
    vector<ll> c(9);
    for(int x = 1; x <= 8; x++) cin >> c[x];
    auto sub_solve = [&](int s){
        s <<= 1;
        ll cnt = 0;
        vector<bool> ok(N*8+1);
        ok[0] = true;
        for(int x = 1; x <= 8; x++) {
            int rem = 0;
            if(s&(1<<x)){ // 840
                cnt += c[x]/(N/x);
                rem = c[x]%(N/x);
            }else{ // 840
                if(c[x]/(N/x)-1 < 0) return 0ll;
                cnt += c[x]/(N/x)-1;
                rem = N/x-1;
            }
            vector<bool> nx(N*8+1);
            for(int w = 0; w <= N*(x-1); w++){
                if(!ok[w]) continue;
                for(int i = 0; i <= rem; i++){
                    nx[w+i*x] = true;
                }
            }
            ok = nx;
        }
        ll ans = 0;
        for(ll x = 0; x <= 8*N && x <= w; x++){
            if(!ok[x]) continue;
            ll tmp = min(cnt, (w-x)/N)*N + x;
            chmax(ans, tmp);
        }
        return ans;
    };
    ll ans = 0;
    for(int s = 0; s < (1<<8); s++) {
        chmax(ans, sub_solve(s));
    }
    cout << ans << endl;
}