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
const int inf = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, k; cin >> n >> k;
    auto v = vec2d(n, n, 0);
    vector<P> p(n*n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> v[i][j];
            v[i][j]--;
            p[v[i][j]] = P(i+j, i-j);
        }
    }
    int x_min = -inf, x_max = inf;
    int y_min = -inf, y_max = inf;
    vector<string> ans(n, string(n, 'G'));
    auto ok = [&](int x, int y){
        return x_min <= x && x <= x_max && y_min <= y && y <= y_max;
    };
    for(int a = n*n-1; a >= 0; a--){
        auto [x, y] = p[a];
        if(ok(x, y)){
            ans[(x+y)/2][(x-y)/2] = 'M';
            chmax(x_min, x-k);
            chmin(x_max, x+k);
            chmax(y_min, y-k);
            chmin(y_max, y+k);
        }
    }
    print_vector(ans, '\n');
}