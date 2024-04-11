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

vector<vector<vector<bool>>> test(int n, int t){
    auto slime = vec2d(n, n, false);
    auto is_right = vec2d(n, n, true);
    slime[0][0] = true;
    auto history = vec2d(n, n, vector<bool>(1, false));
    history[0][0][0] = true;
    while(t--){
        auto next_slime = vec2d(n, n, false);
        auto next_is_right = vec2d(n, n, false);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(slime[i][j]){
                    if(is_right[i][j]){
                        if(j+1 < n) next_slime[i][j+1] = true;
                    }else{
                        if(i+1 < n) next_slime[i+1][j] = true;
                    }
                    next_is_right[i][j] = !is_right[i][j];
                }else{
                    next_is_right[i][j] = is_right[i][j];
                }
            }
        }
        next_slime[0][0] = true;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                history[i][j].push_back(next_slime[i][j]);
            }
        }
        slime = next_slime;
        is_right = next_is_right;
    }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << i << ' ' << j << endl;
    //         print_vector(history[i][j]);
    //     }
    // }
    return history;
}

const int R = 1, D = 2;

int solve(ll t, int x, int y){
    if(x+y >= 60) return false;
    if(x == 0 && y == 0){
        if(t%2 == 0) return 1;
        return 0;
    }
    ll cycle = 1ll<<(x+y);
    ll start = x;
    if(t < start) return 0;
    ll rem = cycle-start;
    rem %= cycle;
    t = rem+start;
}

ll cnt[121][121];

ll count(ll t, int x, int y){
    if(t < x+y) return 0;
    for(int i = 0; i < 120; i++){
        for(int j = 0; j < 120; j++){
            cnt[i][j] = 0;
        }
    }
    ll t0 = t-(x+y);
    cnt[0][0] = t0+1;
    for(int i = 0; i < 120; i++){
        for(int j = 0; j < 120; j++){
            cnt[i][j+1] += (cnt[i][j]+1)/2;
            cnt[i+1][j] += cnt[i][j]/2;
        }
    }
    return cnt[x][y];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int q; cin >> q;
    while(q--){
        ll t; int x, y; cin >> t >> x >> y;
        if(t < x+y){
            cout << "NO" << endl;
            continue;
        }
        if(count(t, x, y) > count(t-1, x, y)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}