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

struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size, -1) {}
    bool unionSet(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
        if (data[y] < data[x]) swap(x, y);
        data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    bool findSet(int x, int y) {
        return root(x) == root(y);
    }
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int size(int x) {
        return -data[root(x)];
    }
};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

char op(int dx, int dy){
    if(dx == -1) return 'U';
    if(dx == 1) return 'D';
    if(dy == -1) return 'L';
    if(dy == 1) return  'R';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    auto x = vec2d(n, n, 0);
    auto y = vec2d(n, n, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> x[i][j] >> y[i][j];
            if(x[i][j] > 0){
                x[i][j]--; y[i][j]--;
            }
        }
    }
    vector<string> ans(n, string(n, 'X'));
    auto to_index = [&](int i, int j){
        return i*n+j;
    };
    auto in_field = [&](int i, int j){
        return 0 <= i && i < n && 0 <= j && j < n;
    };
    UnionFind uf(n*n);
    queue<P> que;
    auto seen = vec2d(n, n, false);
    auto push = [&](int i, int j){
        if(seen[i][j]) return;
        seen[i][j] = true;
        que.push(P(i, j));
    };
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(x[i][j] == i && y[i][j] == j) {
                push(i, j);
                continue;
            }
            if(x[i][j] == -1 && y[i][j] == -1){
                for(int k = 0; k < 4; k++){
                    int ii = i+dx[k], jj = j+dy[k];
                    if(in_field(ii, jj) && x[ii][jj] == -1 && y[ii][jj] == -1){
                        uf.unionSet(to_index(i, j), to_index(ii, jj));
                    }
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(x[i][j] == -1 || y[i][j] == -1) {
                if(uf.size(to_index(i, j)) == 1){
                    cout << "INVALID" << endl;
                    return 0;
                }
                if(uf.root(to_index(i, j)) == to_index(i, j)){
                    que.push(P(i, j));
                    for(int k = 0; k < 4; k++){
                        int ii = i+dx[k], jj = j+dy[k];
                        if(in_field(ii, jj) && x[ii][jj] == -1 && y[ii][jj] == -1){
                            ans[i][j] = op(ii-i, jj-i);
                            break;
                        }
                    }
                }
            }
        }
    }
    while(!que.empty()){
        auto [i, j] = que.front(); que.pop();
        for(int k = 0; k < 4; k++){
            int ii = i+dx[k], jj = j+dy[k];
            if(!in_field(ii, jj)) continue;
            if(seen[ii][jj]) continue;
            if(x[i][j] == x[ii][jj] && y[i][j] == y[ii][jj]){
                ans[ii][jj] = op(i-ii, j-jj);
                push(ii, jj);
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!seen[i][j]){
                cout << "INVALID" << endl;
                return 0;
            }
        }
    }
    cout << "VALID" << endl;
    print_vector(ans, '\n');
}