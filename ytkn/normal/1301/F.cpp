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
#include <random>

std::random_device rnd;
std::mt19937 mt(rnd());

int randint(const int l, const int r){
    return mt()%(r - l) + l;
}

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
int dist_from[1001][1001][40];
int a[1000][1000];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

const int inf = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m, k; cin >> n >> m >> k;
    vector<vector<P>> cells_by_col(k);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];a[i][j]--;
            // a[i][j] = randint(0, k);
            cells_by_col[a[i][j]].push_back(P(i, j));
        }
    }
    auto calc_from = [&](int c){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                dist_from[i][j][c] = -1;
            }
        }
        vector<bool> used_col(k);
        queue<P> que;
        auto push = [&](int i, int j, int d){
            if(dist_from[i][j][c] == -1){
                que.push(P(i, j));
                dist_from[i][j][c] = d;
            }
        };
        auto fill_col = [&](int c, int d){
            if(used_col[c]) return;
            used_col[c] = true;
            for(auto [i, j]: cells_by_col[c]){
                push(i, j, d);
            }
        };
        fill_col(c, 0);
        while(!que.empty()){
            auto [i, j] = que.front(); que.pop();
            int d = dist_from[i][j][c];
            fill_col(a[i][j], d+1);
            for(int k = 0; k < 4; k++){
                int ii = i+dx[k];
                int jj = j+dy[k];
                if(0 <= ii && ii < n && 0 <= jj && jj < m){
                    push(ii, jj, d+1);
                }
            }
        }
    };
    for(int c = 0; c < k; c++){
        calc_from(c);
    }
    int q; cin >> q;
    while(q--){
        int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
        r1--; c1--; r2--; c2--;
        int ans = abs(c2-c1)+abs(r2-r1);
        for(int c = 0; c < k; c++){
            // cout << dist_from[r1][c1][c] << ' ' << dist_from[r2][c2][c] << endl;
            int tmp = dist_from[r1][c1][c]+dist_from[r2][c2][c]+1;
            chmin(ans, tmp);
        }
        cout << ans << '\n';
    }
}