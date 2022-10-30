#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
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
    vector<int> p(n);
    vector<int> cnt(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
        cnt[(i+n-p[i])%n]++;
    }
    vector<int> ans;
    auto judge = [&](int k){
        vector<int> q(n);
        UnionFind uf(n);
        for(int i = 0; i < n; i++){
            q[i] = (i-k+n)%n;
            uf.unionSet(p[i], q[i]);
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(uf.root(i) == i){
                cnt += uf.size(i)-1;
            }
        }
        return cnt <= m;
    };
    for(int k = 0; k < n; k++){
        if(cnt[k] >= n-2*m){
            if(judge(k)) ans.push_back(k);
        }
    }
    cout << ans.size() << ' ';
    for(int k: ans) cout << k << ' ';
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}