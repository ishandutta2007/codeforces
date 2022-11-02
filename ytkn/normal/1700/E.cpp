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
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    auto a = vec2d(n, m, 0);
    auto cnt_small = vec2d(n, m, 0);
    vector<int> x(n*m+1), y(n*m+1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            x[a[i][j]] = i;
            y[a[i][j]] = j;
        }
    }
    int ng = 0;
    auto in_field = [&](int i, int j){
        return 0 <= i && i < n && 0 <= j && j < m;
    };
    auto ok = [&](int i, int j){
        return a[i][j] == 1 || cnt_small[i][j] > 0;
    };
    int first_ng = 0;
    auto count_smaller = [&](int i, int j){
        int ans = 0;
        for(int k = 0; k < 4; k++){
            int ii = i+dx[k], jj = j+dy[k];
            if(!in_field(ii, jj)) continue;
            if(a[i][j] > a[ii][jj]) ans++;
        }
        return ans;
    };
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cnt_small[i][j] = count_smaller(i, j);
            if(!ok(i, j)) {
                if(first_ng == 0) first_ng = a[i][j];
                ng++;
            }
        }
    }
    if(ng == 0){
        cout << 0 << endl;
        return 0;
    }
    auto ok_swap = [&](int i0, int j0, int i1, int j1) -> bool {
        int new_ng = ng;
        set<P> st;
        st.insert(P(i0, j0));
        st.insert(P(i1, j1));
        for(int k = 0; k < 4; k++){
            int ii = i0+dx[k], jj = j0+dy[k];
            if(in_field(ii, jj)) st.insert(P(ii, jj));
        }
        for(int k = 0; k < 4; k++){
            int ii = i1+dx[k], jj = j1+dy[k];
            if(in_field(ii, jj)) st.insert(P(ii, jj));
        }

        for(auto [x, y]: st){
            if(a[x][y] == 1 || cnt_small[x][y] > 0){
                new_ng++;
            }
        }
        swap(a[i0][j0], a[i1][j1]);
        for(auto [x, y]: st){
            if(a[x][y] == 1 || count_smaller(x, y) > 0){
                new_ng--;
            }
        }
        swap(a[i0][j0], a[i1][j1]);
        return new_ng == 0;
    };
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == first_ng) continue;
            if(ok_swap(i, j, x[first_ng], y[first_ng])) cnt++;
        }
    }
    for(int v = 1; v < first_ng; v++){
        for(int k = 0; k < 4; k++){
            int ii = x[first_ng]+dx[k], jj = y[first_ng]+dy[k];
            if(!in_field(ii, jj)) continue;
            if(ok_swap(ii, jj, x[v], y[v])) cnt++;
        }
    }
    if(cnt == 0){
        cout << 2 << endl;
    }else{
        cout << 1 << ' ' << cnt << endl;
    }
}