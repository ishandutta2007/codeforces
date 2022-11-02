#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <functional>
#include <cassert>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;


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

void solve(){
    int n, m; cin >> n >> m;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    auto ans = s;
    int r = n%3 == 0 ? 1 : 0;
    for(int i = 0; i < n; i++){
        if(i%3 != r) continue;
        for(int j = 0; j < m; j++){
            ans[i][j] = 'X';
        }
    }
    for(int i = 0; i < n; i++){
        if((i+2)%3 != r) continue;
        auto get_pos = [&](){
            for(int j = 0; j < m; j++){
                if(s[i][j] == 'X') return j;
            }
            if(i+1 != n){
                for(int j = 0; j < m; j++){
                    if(s[i+1][j] == 'X') return j;
                }
            }
            return 0;
        };
        int j = get_pos();
        ans[i][j] = 'X';
        if(i+1 != n) ans[i+1][j] = 'X';
    }
    for(int i = 0; i < n; i++) cout << ans[i] << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}