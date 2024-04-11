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

const int M = 1000;
const int inf = 1e9;

vector<vector<int>> g(M+1);
auto dist = vector<int>(M+1, inf);

void init(){
    int sum = 0;
    for(int a = 1; a <= 999; a++){
        set<int> st;
        for(int x = 1; x <= a; x++){
            st.insert(a+a/x);
        }
        for(int to: st) g[a].push_back(to);
        sum += st.size();
    }
    queue<int> que;
    auto push = [&](int v, int d){
        if(dist[v] == inf){
            dist[v] = d;
            que.push(v);
        }
    };
    push(1, 0);
    while(!que.empty()){
        int v = que.front(); que.pop();
        for(int to: g[v]) push(to, dist[v]+1);
    }
}

using P = pair<int, int>;

void solve(){
    int n, k; cin >> n >> k;
    vector<int> b(n), c(n);
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cin >> c[i];
    vector<int> v;
    int mx = min(12*n, k);
    auto dp = vec2d(n+1, mx+1, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= mx; j++){
            chmax(dp[i+1][j], dp[i][j]);
            if(j+dist[b[i]] <= mx){
                chmax(dp[i+1][j+dist[b[i]]], dp[i][j]+c[i]);
            }
        }
    }
    cout << *max_element(dp[n].begin(), dp[n].end()) << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    init();
    int t; cin >> t;
    while(t--) solve();
}