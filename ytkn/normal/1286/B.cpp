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

vector<int> g[2000];
int c[2000];
int ans[2000];

vector<int> dfs(int v, int l){
    int l0 = l;
    vector<int> ansestor;
    for(int to: g[v]){
        auto u = dfs(to, l);
        for(int x: u) ansestor.push_back(x);
        l += u.size();
    }
    if(c[v] > ansestor.size()){
        cout << "NO" << endl;
        exit(0);
    }
    ans[v] = l0+c[v];
    vector<int> w;
    for(int i = 0; i < c[v]; i++) w.push_back(ansestor[i]);
    w.push_back(v);
    for(int i = c[v]; i < ansestor.size(); i++){
        ans[ansestor[i]]++;
        w.push_back(ansestor[i]);
    }
    return w;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    int root = -1;
    for(int i = 0; i < n; i++){
        int p; cin >> p >> c[i];
        p--;
        if(p == -1) root = i;
        else g[p].push_back(i);
    }
    dfs(root, 1);
    cout << "YES" << endl;
    for(int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << endl;
}