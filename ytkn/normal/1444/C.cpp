#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size, -1) { }
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

ll n, m, k;
int c[500000];
int a[500000], b[500000];

vector<int> G[500000];
bool used[500000];
map<P, vector<int>> mp_edge;
int col[500000];
int cur_col[500000];
bool ng[500000];

void dfs(int v, int xo){
    used[v] = true;
    col[v] = cur_col[c[v]]+xo;
    for(int to : G[v]){
        if(!used[to] && c[v] == c[to]) dfs(to, xo^1);
        if(used[to] && c[v] == c[to] && col[v] == col[to]){
            ng[c[v]] = true;
            return;
        }
    }
}

void input(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        cin >> c[i]; c[i]--;
    }
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        if(c[a[i]] > c[b[i]]) {
            swap(a[i], b[i]);
        }
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
        if(c[a[i]] != c[b[i]]) {
            mp_edge[P(c[a[i]], c[b[i]])].push_back(i);
        }
    }
}

bool judge(int c1, int c2, vector<int> &v){
    set<int> st1, st2;
    map<int, int> mp1, mp2;
    for(int i : v){
        if(c1 == c[a[i]]){
            st1.insert(col[a[i]]);
            st1.insert(col[a[i]]^1);
            st2.insert(col[b[i]]);
            st2.insert(col[b[i]]^1);
        }else{
            st2.insert(col[a[i]]);
            st2.insert(col[a[i]]^1);
            st1.insert(col[b[i]]);
            st1.insert(col[b[i]]^1);
        }
    }
    int cur = 0;
    for(int i : st1){
        mp1[i] = cur;
        cur += 1;
    }

    for(int i : st2){
        mp2[i] = cur;
        cur += 1;
    }
    int m = st1.size() + st2.size();
    UnionFind uf(m);
    for(int i : v){
        if(c1 == c[a[i]]){
            int ca = col[a[i]];
            int cb = col[b[i]];
            uf.unionSet(mp1[ca]^1, mp2[cb]);
            uf.unionSet(mp1[ca], mp2[cb]^1);
        }else{
            int ca = col[b[i]];
            int cb = col[a[i]];
            uf.unionSet(mp1[ca]^1, mp2[cb]);
            uf.unionSet(mp1[ca], mp2[cb]^1);
        }
    }
    for(int i = 0; i < m; i += 2){
        if(uf.findSet(i, i+1)) return false;
    }
    return true;
}

void solve(){
    for(int i = 0; i < n; i++){
        if(!used[i]){
            dfs(i, 0);
            cur_col[c[i]] += 2;
        }
    }
    ll cnt_ng = 0;
    for(int i = 0; i < k; i++){
        if(ng[i]) {
            cnt_ng++;
        }
    }
    ll ans = ((k-cnt_ng)*(k-1-cnt_ng))/2;
    for(auto p : mp_edge){
        int c1 = p.first.first, c2 = p.first.second;
        if(ng[c1] || ng[c2]) continue;
        if(!judge(c1, c2, p.second)) ans--;
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    input();
    solve();
}