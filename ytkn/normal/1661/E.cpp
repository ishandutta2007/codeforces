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

template<typename T>
class Cumsum{
    public:
    Cumsum(vector<T> v): v(v){
        n = v.size();
        v_cumsum = vector<T>(n+1, T(0));
        for(int i = 0; i < n; i++) v_cumsum[i+1] = v_cumsum[i]+v[i];
    }
    /**
     * v[l] + ... + v[r-1]
     */ 
    T sum(int l, int r){
        if(r <= l) return T(0);
        if(r > n) r = n;
        if(l < 0) l = 0;
        return v_cumsum[r]-v_cumsum[l];
    }
    private:
    int n;
    vector<T> v;
    vector<T> v_cumsum;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<string> s(3);
    for(int i = 0; i < 3; i++) cin >> s[i];
    auto to_index = [&](int i, int j){
        return n*i+j;
    };
    UnionFind uf(3*n);
    vector<int> vertical_edge(n);
    for(int j = 0; j < n; j++){
        for(int i = 0; i < 2; i++){
            if(s[i][j] == '1' && s[i+1][j] == '1'){
                uf.unionSet(to_index(i, j), to_index(i+1, j));
                vertical_edge[j]++;
            }
        }
    }
    vector<int> horizontal_edge(n-1);
    for(int j = 0; j < n-1; j++){
        for(int i = 0; i < 3; i++){
            if(s[i][j] == '1' && s[i][j+1] == '1'){
                if(uf.findSet(to_index(i, j), to_index(i, j+1))) continue;
                uf.unionSet(to_index(i, j), to_index(i, j+1));
                horizontal_edge[j]++;
            }
        }
    }
    vector<int> cnt(n);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < n; j++){
            if(s[i][j] == '1') cnt[j]++;
        }
    }
    vector<int> next111(n+1, n);
    vector<int> next_non101(n+1, n);
    auto is_111 = [&](int j){
        for(int i = 0; i < 3; i++){
            if(s[i][j] != '1') return false;
        }
        return true;
    };
    auto is_101 = [&](int j){
        if(s[0][j] != '1') return false;
        if(s[1][j] != '0') return false;
        if(s[2][j] != '1') return false;
        return true;
    };
    for(int j = n-1; j >= 0; j--){
        if(is_111(j)){
            next111[j] = j;
        }else{
            next111[j] = next111[j+1];
        }
        if(!is_101(j)){
            next_non101[j] = j;
        }else{
            next_non101[j] = next_non101[j+1];
        }
    }
    auto cumsum = Cumsum<int>(cnt);
    auto cumsum_horizontal = Cumsum<int>(horizontal_edge);
    auto cumsum_vertical = Cumsum<int>(vertical_edge);
    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r; l--; r--;
        int ans = cumsum.sum(l, r+1)-cumsum_horizontal.sum(l, r)-cumsum_vertical.sum(l, r+1);
        if(is_101(l)){
            if(next111[l] == next_non101[l] && next111[l] <= r) {
                if(next111[l] != 0 && horizontal_edge[next111[l]-1] == 1) ans--;
            }
        }
        cout << ans << '\n';
    }
}