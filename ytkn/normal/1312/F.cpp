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

void test(int x, int y, int z){
    auto grundy = vec2d(1001, 3, 0);
    cout << x << ' ' << y << ' ' << z << endl;
    for(int cnt = 1; cnt <= 1000; cnt++){
        for(int pre = 0; pre < 3; pre++){
            vector<bool> used(5);
            used[grundy[max(0, cnt-x)][0]] = true;
            if(pre != 1) used[grundy[max(0, cnt-y)][1]] = true;
            if(pre != 2) used[grundy[max(0, cnt-z)][2]] = true;
            for(int i = 0; i < 5; i++){
                if(!used[i]){
                    grundy[cnt][pre] = i;
                    break;
                }
            }
        }
    }
    auto ok_cycle = [&](int len) -> bool {
        for(int i = 100; i < 200; i++){
            for(int j = 0; j < 3; j++){
                if(grundy[i][j] != grundy[i+len][j]) return false;
            }
        }
        return true;
    };
    auto find_cycle = [&](){
        for(int len = 1;; len++){
            if(ok_cycle(len)) return len;
        }
    };
    int cycle = find_cycle();
    debug_value(cycle);
}

void run_test(){
    for(int x = 1; x <= 5; x++){
        for(int y = 1; y <= 5; y++){
            for(int z = 1; z <= 5; z++){
                test(x, y, z);
            }
        }
    }
}

void solve(){
    int n; cin >> n;
    int x, y, z; cin >> x >> y >> z;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    auto grundy = vec2d(1001, 3, 0);
    for(int cnt = 1; cnt <= 1000; cnt++){
        for(int pre = 0; pre < 3; pre++){
            vector<bool> used(5);
            used[grundy[max(0, cnt-x)][0]] = true;
            if(pre != 1) used[grundy[max(0, cnt-y)][1]] = true;
            if(pre != 2) used[grundy[max(0, cnt-z)][2]] = true;
            for(int i = 0; i < 5; i++){
                if(!used[i]){
                    grundy[cnt][pre] = i;
                    break;
                }
            }
        }
    }
    auto ok_cycle = [&](int len) -> bool {
        for(int i = 100; i < 120; i++){
            for(int j = 0; j < 3; j++){
                if(grundy[i][j] != grundy[i+len][j]) return false;
            }
        }
        return true;
    };
    auto find_cycle = [&](){
        for(int len = 1;; len++){
            if(ok_cycle(len)) return len;
        }
    };
    int cycle = find_cycle();
    int cycle_start = 0;
    for(int i = 900; i >= 0; i--){
        for(int j = 0; j < 3; j++){
            if(grundy[i][j] != grundy[i+cycle][j]) {
                cycle_start = i+1;
                break;
            }
        }
        if(cycle_start != 0) break;
    }
    
    auto get_grundy = [&](ll cnt, int pre){
        if(cnt < cycle_start) return grundy[cnt][pre];
        ll d = (cnt-cycle_start)%cycle;
        int x = cycle_start+d;
        return grundy[x][pre];
    };
    vector<ll> v = {x, y, z};
    int xo = 0;
    for(int i = 0; i < n; i++){
        xo ^= get_grundy(a[i], 0);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            int tmp = xo;
            tmp ^= get_grundy(a[i], 0);
            ll nx = max(0ll, a[i]-v[j]);
            tmp ^= get_grundy(nx, j);
            if(tmp == 0) ans++;
        }
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    // run_test();
    int t; cin >> t;
    while(t--) solve();
}