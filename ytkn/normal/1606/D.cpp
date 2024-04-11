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

using P = pair<int, int>;
using T = tuple<int, int, int>;
const int INF = 1e9;

void solve(){
    int n, m; cin >> n >> m;
    auto a = vec2d(n, m, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    auto min_left = vec2d(n, m+1, INF);
    auto max_left = vec2d(n, m+1, -INF);
    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            min_left[i][j+1] = min(min_left[i][j], a[i][j]);
            max_left[i][j+1] = max(max_left[i][j], a[i][j]);
        }
    }
    auto min_right = vec2d(n, m+1, INF);
    auto max_right = vec2d(n, m+1, -INF);
    for(int j = m-1; j >= 0; j--){
        for(int i = 0; i < n; i++){
            min_right[i][j] = min(min_right[i][j+1], a[i][j]);
            max_right[i][j] = max(max_right[i][j+1], a[i][j]);
        }
    }
    for(int j = 1; j < m; j++){
        priority_queue<T, vector<T>, greater<T>> que;
        multiset<int, greater<int>> left_lower, right_lower;
        multiset<int> left_upper, right_upper;
        for(int i = 0; i < n; i++) {
            que.push(T(max_left[i][j], min_left[i][j], i));
            left_upper.insert(min_left[i][j]);
            right_lower.insert(max_right[i][j]);
        }
        vector<int> blue;
        auto ok = [&]() -> bool{
            if(left_upper.empty()) return false;
            int lu = *left_upper.begin();
            int llo = *left_lower.begin();
            int ru = *right_upper.begin();
            int rlo = *right_lower.begin();

            // cout << "===" << endl;
            // for(int x: left_lower) cout << x << ' ';
            // cout << ':' << llo << endl;
            // for(int x: left_upper) cout << x << ' ';
            // cout << ':' << lu << endl;

            // for(int x: right_lower) cout << x << ' ';
            // cout << ':' << rlo << endl;
            // for(int x: right_upper) cout << x << ' ';
            // cout << ':' << ru << endl;

            return lu > llo && ru > rlo;
        };
        while(!que.empty()){
            auto [min_l, max_l, i] = que.top(); que.pop();
            blue.push_back(i);
            left_upper.erase(left_upper.find(min_left[i][j]));
            left_lower.insert(max_left[i][j]);

            right_lower.erase(right_lower.find(max_right[i][j]));
            right_upper.insert(min_right[i][j]);

            if(ok()){
                cout << "YES" << endl;
                string ans(n, 'R');
                for(int idx: blue) ans[idx] = 'B';
                cout << ans << ' ' << j << endl;
                return;
            }
        }
    }

    cout << "NO" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}