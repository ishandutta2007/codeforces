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

const int win = 1;
const int lose = -1;

void solve(){
    int n; cin >> n;
    if(n%2 == 1){
        for(int i = 0; i < n; i++){
            int x = 1;
            for(int j = 0; j < n-i-1; j++){
                cout << x << ' ';
                x *= -1;
            }
        }
        cout << endl;
        return;
    }
    auto results = vec2d(n, n, 0);
    auto is_draw = [&](int i, int j){
        if(i == j) return true;
        return i+j == n-1;
    };
    int x = win;
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(is_draw(i, j)) continue;
            if(cnt != 0) x *= -1;
            results[i][j] = x;
            cnt++;
        }
    }
    for(int i = 0; i < n; i++){
        int sum = accumulate(results[i].begin(), results[i].end(), 0);
        assert(sum == 0);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            assert(results[i][j] + results[j][i] == 0);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++) {
            cout << results[i][j] << ' ';
        }
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) {
        solve();
    }
}