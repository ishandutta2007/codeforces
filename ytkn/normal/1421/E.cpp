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

void test(int n){
    vector<int> v;
    for(int i = 0; i < n-1; i++) v.push_back(i);
    set<vector<int>> st;
    do{
        vector<int> x(n, 1);
        UnionFind uf(n);
        for(int i: v){
            vector<int> vl, vr;
            for(int j = 0; j < n; j++){
                if(uf.findSet(i, j)) vl.push_back(j);
                if(uf.findSet(i+1, j)) vr.push_back(j);
            }
            uf.unionSet(i, i+1);
            for(int j: vl) x[j] *= -1;
            for(int j: vr) x[j] *= -1;
        }
        st.insert(x);
    }while(next_permutation(v.begin(), v.end()));
    debug_value(st.size());
    set<int> cnt;
    for(auto v: st) {
        print_vector(v);
        int c = 0;
        for(int x: v){
            if(x == 1) c++;
        }
        cnt.insert(c);
    }
    for(int c: cnt) cout << c << ' ';
    cout << endl;
}

ll dp[200005][3][2][2];
const ll inf = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    // test(n);
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    if(n == 1){
        cout << a[0] << endl;
        return 0;
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 2; k++){
                for(int l = 0; l < 2; l++){
                    dp[i][j][k][l] = -inf;
                }
            }
        }
    }
    dp[0][0][0][0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 2; k++){
                for(int l = 0; l < 2; l++){
                    for(int p = 0; p < 2; p++){
                        int x = p == 1 ? 1 : -1;
                        int nxl = l;
                        if(nxl == 0 && i >= 1 && k == p) nxl = 1;
                        chmax(dp[i+1][(j+p)%3][p][nxl], dp[i][j][k][l]+a[i]*x);
                    }
                }
            }
        }
    }
    int r = (5-(n%3))%3;
    // debug_value(r)
    ll ans = max(dp[n][r][0][1], dp[n][r][1][1]);
    cout << ans << endl;
}