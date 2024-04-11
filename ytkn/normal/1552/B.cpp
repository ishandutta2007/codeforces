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

void solve(){
    int n; cin >> n;
    auto r = vec2d(n, 5, 0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 5; j++){
            cin >> r[i][j];
        }
    }
    auto winner = [&](int i, int j){
        int ci = 0, cj = 0;
        for(int k = 0; k < 5; k++){
            if(r[i][k] < r[j][k]) ci++;
            else cj++;
        }
        if(ci > cj) return i;
        return j;
    };
    int candidate = 0;
    for(int i = 1; i < n; i++){
        candidate = winner(candidate, i);
    }
    for(int i = 0; i < n; i++){
        if(i == candidate) continue;
        if(winner(i, candidate) != candidate) {
            cout << -1 << endl;
            return;
        }
    }
    cout << candidate+1 << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}