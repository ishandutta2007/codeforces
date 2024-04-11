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

vector<int> dx = {-1, -1, -1, 0, 1};
vector<int> dy = {-1, 0, 1, -1, -1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    auto a = vec2d(n, m, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    auto in_field = [&](int i, int j){
        return 0 <= i && i < n && 0 <= j && j < m;
    };
    auto seen = vec2d(n, m, false);
    auto ok = [&](int i, int j){
        if(i == n-1 || j == m-1) return false;
        vector<int> v;
        for(int k = 0; k < 2; k++){
            for(int l = 0; l < 2; l++){
                if(a[i+k][j+l] != 0) v.push_back(a[i+k][j+l]);
            }
        }
        for(int i = 0; i+1 < v.size(); i++){
            if(v[i] != v[i+1]) return false;
        }
        return true;
    };
    queue<P> que;
    vector<T> ans;
    auto try_push = [&](int i, int j){
        if(!in_field(i, j)) return;
        if(seen[i][j]) return;
        if(ok(i, j)){
            que.push(P(i, j));
            seen[i][j] = true;
            int col = -1;
            for(int k = 0; k < 2; k++){
                for(int l = 0; l < 2; l++){
                    if(a[i+k][j+l] != 0) col = a[i+k][j+l];
                }
            }
            if(col != -1){
                ans.push_back(T(i, j, col));
            }
        }
    };
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            try_push(i, j);
        }
    }
    while(!que.empty()){
        auto [i, j] = que.front(); que.pop();
        for(int k = 0; k < 2; k++){
            for(int l = 0; l < 2; l++){
                a[i+k][j+l] = 0;
            }
        }
        for(int ii = i-1; ii <= i+1; ii++){
            for(int jj = j-1; jj <= j+1; jj++){
                try_push(ii, jj);
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] != 0){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(auto [i, j, col]: ans) cout << i+1 << ' ' << j+1 << ' ' << col << "\n";
}