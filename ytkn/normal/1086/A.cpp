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
const int n = 1001;
const int inf = 1e9;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    vector<int> x(3), y(3);
    for(int i = 0; i < 3; i++) {
        cin >> x[i] >> y[i];
    }
    auto infield = [&](int x, int y){
        return 0 <= x && x < n && 0 <= y && y < n;
    };
    auto dist = vec3d(3, n, n, inf);
    auto pre = vec3d(3, n, n, P(-1, -1));
    auto calc_dist = [&](int idx){
        queue<P> que;
        auto push = [&](int x, int y, int d){
            if(dist[idx][x][y] == inf){
                dist[idx][x][y] = d;
                que.push(P(x, y));
                return true;
            }
            return false;
        };
        push(x[idx], y[idx], 0);
        while(!que.empty()){
            auto [x, y] = que.front(); que.pop();
            for(int k = 0; k < 4; k++){
                int xx = x+dx[k];
                int yy = y+dy[k];
                if(!infield(xx, yy)) continue;
                if(push(xx, yy, dist[idx][x][y]+1)) pre[idx][xx][yy] = P(x, y); 
            }
        }
    };
    for(int i = 0; i < 3; i++) {
        calc_dist(i);
    }
    int ans = inf;
    int rx = -1, ry = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int tmp = 0;
            for(int k = 0; k < 3; k++) tmp += dist[k][i][j];
            tmp++;
            if(chmin(ans, tmp)){
                rx = i;
                ry = j;
            }
        }
    }
    vector<P> points = {P(rx, ry)};
    for(int i = 0; i < 3; i++){
        int cur_x = rx, cur_y = ry;
        if(cur_x == x[i] && cur_y == y[i]) continue;
        while(true){
            auto [xx, yy] = pre[i][cur_x][cur_y];
            cur_x = xx;
            cur_y = yy;
            points.push_back(P(cur_x, cur_y));
            if(cur_x == x[i] && cur_y == y[i]) break;
        }
    }
    cout << points.size() << endl;
    for(auto [x, y]: points) cout << x << ' ' << y << endl;
}