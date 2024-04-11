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

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

using P = pair<int, int>;

void solve(){
    int n, m; cin >> n >> m;
    vector<string> s(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    auto in_field = [&](int i, int j){
        return 0 <= i && i < n && 0 <= j && j < m;
    };
    auto should_block = vec2d(n, m, false);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(s[i][j] != 'B') continue;
            for(int k = 0; k < 4; k++){
                int ii = i+dx[k], jj = j+dy[k];
                if(!in_field(ii, jj)) continue;
                if(s[ii][jj] == 'G') {
                    cout << "No" << endl;
                    return;
                }
                should_block[ii][jj] = true;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(should_block[i][j]) s[i][j] = '#';
        }
    }
    auto seen = vec2d(n, m, false);
    queue<P> que;
    auto push = [&](int i, int j){
        if(s[i][j] == '#') return;
        if(seen[i][j]) return;
        que.push(P(i, j));
        seen[i][j] = true;
    };
    push(n-1, m-1);
    while(!que.empty()){
        auto [i, j] = que.front(); que.pop();
        for(int k = 0; k < 4; k++){
            int ii = i+dx[k], jj = j+dy[k];
            if(!in_field(ii, jj)) continue;
            if(s[ii][jj] == '#') continue;
            push(ii, jj);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(s[i][j] == 'G' && !seen[i][j]){
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}