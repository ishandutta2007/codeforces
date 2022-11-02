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
using T = tuple<ll, int, int>;

P calc_pair(P p, char c){
    auto [x, y] = p;
    if(c == 'L') return P(x, y+1);
    if(c == 'R') return P(x, y-1);
    if(c == 'U') return P(x+1, y);
    if(c == 'D') return P(x-1, y);
}

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

const ll inf = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    ll p, q; cin >> p >> q;
    // chmin(q, 2*p);
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    auto dist = vec2d(n, m, inf);
    priority_queue<T, vector<T>, greater<T>> que;
    auto set_dist = [&](int x, int y, ll d){
        if(chmin(dist[x][y], d)){
            que.push(T(d, x, y));
        }
    };
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(s[i][j] == '.'){
                set_dist(i, j, 0);
            }
        }
    }
    auto is_in_field = [&](int x, int y){
        return 0 <= x && x < n && 0 <= y && y < m;
    };
    while(!que.empty()){
        auto [d, x, y] = que.top(); que.pop();
        if(dist[x][y] != d) continue;
        for(int k = 0; k < 4; k++){
            int xx = x+dx[k];
            int yy = y+dy[k];
            if(!is_in_field(xx, yy)) continue;

            if(s[xx][yy] == 'L' || s[xx][yy] == 'R' || s[xx][yy] == 'U' || s[xx][yy] == 'D'){
                auto [xxx, yyy] = calc_pair(P(xx, yy), s[xx][yy]);
                if(s[xxx][yyy] == '#') continue;
                ll dd = (xxx == x || yyy == y) ? q : p;
                set_dist(xxx, yyy, d+dd);
            }
        }
    }
    // for(int i = 0; i < n; i++) print_vector(dist[i]);
    ll min_dist = inf;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < 4; k++){
                int ii = i+dx[k], jj = j+dy[k];
                if(!is_in_field(ii, jj)) continue;
                if(chmin(min_dist, dist[i][j]+dist[ii][jj])){
                    // cout << i << ' ' << j << ' ' << ii << ' ' << jj << ' ' << min_dist << endl;
                }   
            }
        }
    }
    if(min_dist == inf) cout << -1 << endl;
    else cout << min_dist << endl;
}