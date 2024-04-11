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
    vector<int> a_max(n), c_max(m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            chmax(a_max[i], a[i][j]);
            chmax(c_max[j], a[i][j]);
        }
    }
    vector<bool> is_row_max(n*m+1), is_col_max(n*m+1);
    for(int i = 0; i < n; i++){
        is_row_max[a_max[i]] = true;
    }
    for(int j = 0; j < m; j++){
        is_col_max[c_max[j]] = true;
    }
    int i = -1, j = -1;
    auto ans = vec2d(n, m, -1);
    queue<P> que;
    for(int x = n*m; x >= 1; x--){
        if(is_row_max[x] && is_col_max[x]){
            i++; j++;
            ans[i][j] = x;
            for(int jj = j-1; jj >= 0; jj--){
                que.push(P(i, jj));
            }
            for(int ii = i-1; ii >= 0; ii--){
                que.push(P(ii, j));
            }
        }else if(is_row_max[x]){
            i++;
            ans[i][j] = x;
            int y = x-1;
            for(int jj = j-1; jj >= 0; jj--){
                que.push(P(i, jj));
            }
        }else if(is_col_max[x]){
            j++;
            ans[i][j] = x;
            int y = x-1;
            for(int ii = i-1; ii >= 0; ii--){
                que.push(P(ii, j));
            }
        }else{
            auto [ii, jj] = que.front(); que.pop();
            ans[ii][jj] = x;
        }
    }
    for(int i = 0; i < n; i++) print_vector(ans[i]);
}