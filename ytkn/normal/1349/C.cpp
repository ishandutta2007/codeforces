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

vector<int> dh = {-1, 1, 0, 0};
vector<int> dw = {0, 0, -1, 1};

vector<string> nx(vector<string> s){
    int n = s.size(), m = s[0].size();
    auto infield = [&](int i, int j){
        return i >= 0 && i < n && j >= 0 && j < m;
    };
    auto ans = s;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            bool ok = true;
            for(int k = 0; k < 4; k++){
                int ito = i+dh[k], jto = j+dw[k];
                if(infield(ito, jto) && s[i][j] == s[ito][jto]) ok = false;
            }
            if(ok) ans[i][j] = s[i][j];
            else{
                int cur = s[i][j]-'0';
                ans[i][j] = '0'+(cur^1);
            }
        }
    }
    return ans;
}

const ll INF = 4e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m, t; cin >> n >> m >> t;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    auto infield = [&](int i, int j){
        return i >= 0 && i < n && j >= 0 && j < m;
    };
    auto to_idx = [&](int i, int j){
        return i*m+j;
    };
    UnionFind uf(n*m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < 4; k++){
                int ito = i+dh[k], jto = j+dw[k];
                if(infield(ito, jto) && s[i][j] == s[ito][jto]) uf.unionSet(to_idx(i, j), to_idx(ito, jto));
            }
        }
    }
    vector<ll> init(n*m, INF);
    queue<int> que;
    for(int i = 0; i < n*m; i++){
        if(uf.size(i) > 1) {
            init[i] = 1;
            que.push(i);
        }
    }
    while(!que.empty()){
        int idx = que.front(); que.pop();
        int i = idx/m, j = idx%m;
        for(int k = 0; k < 4; k++){
            int ito = i+dh[k], jto = j+dw[k];
            if(infield(ito, jto) && init[to_idx(ito, jto)] == INF){
                que.push(to_idx(ito, jto));
                init[to_idx(ito, jto)] = init[idx]+1;
            }
        }
    }
    while(t--){
        int i, j; ll p; cin >> i >> j >> p;
        i--; j--;
        int idx = to_idx(i, j);
        if(p >= init[idx]){
            int x = s[i][j]-'0';
            if((p-init[idx])%2 == 0) x^=1;
            cout << x << endl;
        }else{
            cout << s[i][j] << endl;
        }
    }
}