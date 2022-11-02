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

const int MOD = 32768;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<vector<int>> g(MOD);
    for(int i = 1; i < MOD; i++){
        int a = (i+1)%MOD;
        int b = (i*2)%MOD;
        g[a].push_back(i);
        g[b].push_back(i);
    }
    vector<int> dist(MOD, -1);
    queue<int> que;
    auto push = [&](int v, int d){
        if(dist[v] == -1){
            que.push(v);
            dist[v] = d;
        }
    };
    push(0, 0);
    while(!que.empty()){
        int v = que.front(); que.pop();
        for(int to: g[v]) push(to, dist[v]+1);
    }
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        cout << dist[a] << ' ';
    }
    cout << endl;
}