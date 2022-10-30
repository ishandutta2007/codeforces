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

vector<int> dx = {1, 1, 0, -1};
vector<int> dy = {0, 1, 1, 1};

void solve(){
    int n; cin >> n;
    vector<string> s(2);
    cin >> s[0] >> s[1];
    auto ok = vec2d(2, n, false);
    ok[0][0] = true;
    auto in = [&](int i, int j){
        return 0 <= i && i < 2 && 0 <= j && j < n;
    };
    for(int j = 0; j < n; j++){
        for(int i = 0; i < 2; i++){
            if(!ok[i][j]) continue;
            // cout << i << ' ' << j << endl;
            for(int k = 0; k < 4; k++){
                int ii = i+dx[k], jj = j+dy[k];
                if(in(ii, jj) && s[ii][jj] == '0'){
                    ok[ii][jj] = true;
                }
            }
        }
    }
    if(ok[1][n-1]) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}