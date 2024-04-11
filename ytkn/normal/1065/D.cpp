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

const int knight = 0;
const int bishop = 1;
const int rook = 2;

bool ok(int tp, int x0, int y0, int x1, int y1){
    int dx = abs(x1-x0);
    int dy = abs(y1-y0);
    if(tp == knight){
        if(dx == 1 && dy == 2) return true;
        if(dx == 2 && dy == 1) return true;
        return false;
    }
    if(tp == bishop) return dx == dy;
    return dx == 0 || dy == 0;
}

const int inf = 1e9;
using P = pair<int, int>;
P pinf(inf, inf);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    auto a = vec2d(n, n, 0);
    vector<P> pos(n*n, pinf);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j]; a[i][j]--;
            pos[a[i][j]] = P(i, j);
        }
    }
    auto g = vec2d(3*n*n, 3*n*n, pinf);
    auto to_idx = [&](int i, int j, int tp){
        return 3*(i*n+j)+tp;
    };
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int tp = 0; tp < 3; tp++){
                for(int next_tp = 0; next_tp < 3; next_tp++){
                    if(tp == next_tp) continue;
                    g[to_idx(i, j, tp)][to_idx(i, j, next_tp)] = P(1, 1);
                }
                for(int ii = 0; ii < n; ii++){
                    for(int jj = 0; jj < n; jj++){
                        if(ok(tp, i, j, ii, jj)) g[to_idx(i, j, tp)][to_idx(ii, jj, tp)] = P(1, 0);
                    }
                }
            }
        }
    }
    auto dist = vec2d(3*n*n, n*n, pinf);
    auto seen = vec2d(3*n*n, n*n, false);
    auto [i0, j0] = pos[0];
    for(int tp = 0; tp < 3; tp++) dist[to_idx(i0, j0, tp)][0] = P(0, 0);
    while(true){
        P min_dist = pinf;
        int min_idx = -1, min_num = -1;
        for(int idx = 0; idx < 3*n*n; idx++){
            for(int num = 0; num < n*n; num++){
                if(seen[idx][num]) continue;
                if(chmin(min_dist, dist[idx][num])) {
                    min_idx = idx;
                    min_num = num;
                }
            }
        }
        if(min_num == n*n-1) break;
        if(min_dist == pinf) break;
        int i = (min_idx/3)/n;
        int j = (min_idx/3)%n;
        int tp = min_idx%3;
        // cout << min_num << ' ' << i+1 << ' ' << j+1 <<  ' ' << tp << ": " << min_dist.first << ' ' << min_dist.second << endl;
        seen[min_idx][min_num] = true;
        for(int ii = 0; ii < n; ii++){
            for(int jj = 0; jj < n; jj++){
                int next_num = a[ii][jj] == min_num+1 ? min_num+1 : min_num;
                for(int next_tp = 0; next_tp < 3; next_tp++){
                    int next_idx = to_idx(ii, jj, next_tp);
                    P next_dist = P(min_dist.first + g[min_idx][next_idx].first, min_dist.second + g[min_idx][next_idx].second);
                    chmin(dist[next_idx][next_num], next_dist);
                }
            }
        }
    }

    P ans = pinf;
    for(int tp = 0; tp < 3; tp++){
        auto [i, j] = pos[n*n-1];
        chmin(ans, dist[to_idx(i, j, tp)][n*n-1]);
    }
    cout << ans.first << ' ' << ans.second << endl;
}